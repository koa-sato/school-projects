
// Kekoa Sato, Avi Loschak, 01/28/16

#include "poly1.h"
#include <algorithm>
#include <math.h>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

namespace main_savitch_4 {
    const unsigned int polynomial::DEFAULT_CAPACITY;

    polynomial::polynomial(double c, unsigned int exponent) {
        coef = new double[DEFAULT_CAPACITY];
        size = DEFAULT_CAPACITY;
        clear();
        coef[exponent] = c;
        if (c != 0)
            current_degree = exponent;
    }

    polynomial::polynomial(const polynomial& source) {
        coef = new double[source.size];
        size = source.size;
        current_degree = source.current_degree;        
        copy(source.coef, source.coef + size, coef);
    }

    polynomial::~polynomial() {
        delete [] coef;
    }

    polynomial& polynomial::operator =(const polynomial& source) {
        if (this == &source)
            return *this;
        else if(source.size != size){
            double *coef2 = new double[source.size];
            delete [] coef;
            coef = coef2; 
        }
        size = source.size;
        current_degree = source.current_degree;
        copy(source.coef, source.coef + size, coef);
        return *this;
    }

    void polynomial::add_to_coef(double amount, unsigned int exponent) {
        if(size <= exponent){
            double *coef2 = new double[exponent + 1];
            copy(coef, coef + size, coef2);
            coef = coef2;
            size = exponent + 1;
        }
        coef[exponent] += amount;

        for (int i = size - 1; i >= 0; i--) {
            if (coef[i] != 0 ) {
                current_degree = i;
                i = 0;
            }
        }
    }
    void polynomial::assign_coef(double coefficient, unsigned int exponent) {
        if(size <= exponent){
            double *coef2 = new double[exponent + 1];
            copy(coef, coef + size, coef2);
            coef = coef2;
            size = exponent + 1;
        }
        coef[exponent] = coefficient;

        for (int i = size - 1; i >= 0; i--) {
            if (coef[i] != 0 ) {
                current_degree = i;
                i = 0;
            }
        }
    }
    void polynomial::clear( ) {
        for (int i = 0; i < size; i++)
            coef[i] = 0;
        current_degree = 0;
    }

    void polynomial::reserve(unsigned int number) {
        if(current_degree > number)
            return;
        else { 
            double *coef2 = new double[number];
            copy(coef, coef + current_degree, coef2);
            coef = coef2;
            size = number;           
        }
    }

    double polynomial::coefficient(unsigned int exponent) const {
        if(exponent > size - 1)
            return 0;
        else
            return coef[exponent];
    }

    polynomial polynomial::derivative( ) const {
        polynomial derivative = *this;
        for (int i = 0; i < size; i++) {
            derivative.coef[i] = coef[i + 1] * (i + 1);
        }
        derivative.current_degree = current_degree - 1;
        return derivative;
    }

    double polynomial::eval(double x) const {
        double total = 0;
        for (int i = 0; i < size; i++) {
            total += coef[i] * pow(x, i);
        }
        return total;
    }

    void polynomial::find_root(double& answer, bool& success, unsigned int& iterations, 
                               double guess, unsigned int maximum_iterations, double epsilon) const {
        assert(epsilon > 0);
        polynomial derivative (this -> derivative());
        answer = guess;
        double f = eval(answer);
        double fprime = derivative.eval(answer);
        iterations = 0;
        for(iterations; iterations < maximum_iterations; iterations++){
            if(abs(f) <= epsilon || abs(fprime) <= epsilon){
                success = false;
                break;          
            } 
            answer = answer - (f / fprime);
            f = eval(answer);
            fprime = derivative.eval(answer);
        }
        if(abs(f) < epsilon)
            success = true;
        else
            success = false;
        

    }

    unsigned int polynomial::next_term(unsigned int e) const {
        for (int i = e + 1; i < size; i++) {
            if (coef[i] != 0)
                return i;
        }
        return 0;
    }

    unsigned int polynomial::previous_term(unsigned int e) const {
        if (e > size)
            e = size;
        for (int i = e - 1; i >= 0; i--) {
            if (coef[i] != 0)
                return i;
        }
        return UINT_MAX;
    }

    polynomial operator +(const polynomial& p1, const polynomial& p2) {
        polynomial p3 = p1;

        for (int i = p2.degree(); i >= 0; i--) {
            p3.add_to_coef(p2.coefficient(i), i);
        }
        return p3;
    }

    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial p3 = p1;

        for (int i = p2.degree(); i >= 0; i--) {
            p3.add_to_coef(-p2.coefficient(i), i);
        }
        return p3;
    }
    polynomial operator *(const polynomial& p1, const polynomial& p2) {
        polynomial p3;

        for (int i = p1.degree(); i >= 0; i--) {
            for (int j = p2.degree(); j >= 0; j--) {
                p3.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i + j);
            }
        }
        return p3;
    }

    std::ostream& operator << (std::ostream& out, const polynomial& p) {
        for (int i = p.degree(); i >= 0; i--) {

            if(p.coefficient(i) != 0) {
                if(i == 0) {
                    if (p.coefficient(i) < 0 && i == p.degree())
            out << "-" << p.coefficient(i);
            else if (p.coefficient(i) < 0)
                        out << " - " << p.coefficient(i);
                    else if (p.coefficient(i) > 0 && i == p.degree())
                        out << p.coefficient(i);
                    else 
                        out << " + " << p.coefficient(i);
                }
        else if (i == 1) {
            if (p.coefficient(i) < 0 && i == p.degree())
                        out << "-" << p.coefficient(i) << "x";
                    else if (p.coefficient(i) < 0)
                        out << " - " << p.coefficient(i) << "x";
                    else if (p.coefficient(i) > 0 && i == p.degree())
                        out << p.coefficient(i) << "x";
                    else
                        out << " + " << p.coefficient(i) << "x";
        }
                else {
                    if(p.coefficient(i) < 0 && i == p.degree())
                        out << "-" << abs(p.coefficient(i)) << "x^" << i;
            else if(p.coefficient(i) < 0)
                        out << " - " << abs(p.coefficient(i)) << "x^" << i;
                    else if (p.coefficient(i) > 0 && i == p.degree())
                        out <<  p.coefficient(i) << "x^" << i;
                    else if (p.coefficient(i) > 0)
                        out << " + " <<  p.coefficient(i) << "x^" << i;
                }
            }
        }
        cout << endl;
        return out;
    }
}
