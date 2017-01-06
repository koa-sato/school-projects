
// Kekoa Sato, Avi Loschak, 01/14/16

#include "poly0.h"
#include <cassert>
#include <math.h>
#include <cmath>
#include <climits>

using namespace std;

namespace main_savitch_3 {
    const unsigned int polynomial::CAPACITY;
    const unsigned int polynomial::MAX_EX;

    polynomial::polynomial(double c, unsigned int exponent) {
        assert(exponent <= MAX_EX);
        clear();
        coef[exponent] = c;
        if (c != 0)
            current_degree = exponent;
    }
    void polynomial::add_to_coef(double amount, unsigned int exponent) {
        assert(exponent <= MAX_EX);
        coef[exponent] += amount;

        for (int i = CAPACITY - 1; i >= 0; i--) {
            if (coef[i] != 0 ) {
                current_degree = i;
                i = 0;
            }
        }

    }
    void polynomial::assign_coef(double coefficient, unsigned int exponent) {
        assert(exponent <= MAX_EX);
        coef[exponent] = coefficient;

        for (int i = CAPACITY - 1; i >= 0; i--) {
            if (coef[i] != 0 ) {
                current_degree = i;
                i = 0;
            }
        }
    }
    void polynomial::clear( ) {
        for (int i = 0; i < CAPACITY; i++)
            coef[i] = 0;
        current_degree = 0;
    }

    double polynomial::coefficient(unsigned int exponent) const {
        if(exponent > MAX_EX)
            return 0;
        else
            return coef[exponent];
    }

    polynomial polynomial::derivative( ) const {
        polynomial derivative;
        for (int i = 0; i < CAPACITY - 1; i++) {
            derivative.coef[i] = coef[i + 1] * (i + 1);
        }
        derivative.current_degree = current_degree - 1;
        return derivative;
    }

    double polynomial::eval(double x) const {
        double total = 0;
        for (int i = 0; i < CAPACITY; i++) {
            total += coef[i] * pow(x, i);
        }
        return total;
    }

    unsigned int polynomial::next_term(unsigned int e) const {
        for (int i = e + 1; i < CAPACITY; i++) {
            if (coef[i] != 0)
                return i;
        }
        return 0;
    }

    unsigned int polynomial::previous_term(unsigned int e) const {
        if (e > CAPACITY)
            e = CAPACITY;
        for (int i = e - 1; i >= 0; i--) {
            if (coef[i] != 0)
                return i;
        }
        return UINT_MAX;
    }

    polynomial operator +(const polynomial& p1, const polynomial& p2) {
        polynomial p3;

        for (int i = p1.degree(); i >= 0; i--) {
            p3.add_to_coef(p1.coefficient(i), i);
        }
        for (int i = p2.degree(); i >= 0; i--) {
            p3.add_to_coef(p2.coefficient(i), i);
        }
        return p3;
    }

    polynomial operator -(const polynomial& p1, const polynomial& p2) {
        polynomial p3;

        for (int i = p1.degree(); i >= 0; i--) {
            p3.add_to_coef(p1.coefficient(i), i);
        }
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
        for (int i = polynomial::CAPACITY; i >= 0; i--) {

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
