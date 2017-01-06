// stats.cxx - implements statistician class as defined in stats.h
// Kekoa Sato 01/10/16

#include <cassert>  // provides assert
#include "stats.h"  // defines what must be implemented

namespace main_savitch_2C
{
    statistician::statistician() {
        count = 0;
        total = 0;
    }

    void statistician::next(double r) {
        if(count == 0) {
            tiniest = r;
            largest = r;
        }
        else {
            if (tiniest > r)
                tiniest = r;
            if (largest < r)
                largest = r;
        }

        count++;
        total += r;
    }

    void statistician::reset() {
        count = 0;
        total = 0;
    }

    double statistician::mean() const {
        assert(count > 0);
        return total/count;
    }

    double statistician::minimum() const {
        assert(count > 0);
        return tiniest;
    }

    double statistician::maximum() const {
        assert(count > 0);
        return largest;
    }

    statistician operator + (const statistician& s1, const statistician& s2) {
        statistician s3;
        s3.count = s1.length() + s2.length();
        s3.total = s1.total + s2.total;

        if (s1.length() == 0 && s2.length() == 0)
            s3.count = 0;
        else if (s1.length() == 0) {
            s3.count = s2.length();
            s3.tiniest = s2.minimum();
            s3.largest = s2.maximum();
        }
        else if (s2.length() == 0) {
            s3.count = s1.length();
            s3.tiniest = s1.minimum();
            s3.largest = s1.maximum();
        }
        else {
            if (s1.minimum() < s2.minimum())
                s3.tiniest = s1.minimum();
            else
                s3.tiniest = s2.minimum();
            if (s1.maximum() > s2.maximum())
                s3.largest = s1.maximum();
            else
                s3.largest = s2.maximum();
        }
        return s3;
    }

    statistician operator * (double scale, const statistician& s) {

        statistician s3 = s;
        if (scale >= 0) {
            s3.total *= scale;
            s3.tiniest *= scale;
            s3.largest *= scale;
        }
        else {
            s3.total *= scale;
            double smallest = s3.tiniest;
            s3.tiniest = s3.largest * scale;
            s3.largest = smallest * scale;
        }

        return s3;
    }

    bool operator ==(const statistician& s1, const statistician& s2) {
        if(s1.length() == 0 && s2.length() == 0)
            return true;
        else if (s1.length() == 0 || s2.length() == 0) {
            return false;
        }
        else {
            if(s1.length() == s2.length() &&
               s1.sum() == s2.sum() &&
               s1.minimum() == s2.minimum() &&
               s1.maximum() == s2.maximum())
                return true;
            else 
                return false;
        }
    }

}