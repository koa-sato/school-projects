public class Rational {

    private int num;
    private int denom;

    /** 
        greatest common divisor of a and b
        @param a first number
        @param b second number
        @return gcd of a and b
    */
    public static int gcd(int a, int b) {
        if (a==0)
            return b;
        else if (b==0)
            return a;
        else
            return gcd(b%a, a);
    }

    public Rational() {
        this.num = 1;
        this.denom = 1;
    }

    public Rational(int num, int denom) {
        if (denom == 0) {
            throw new IllegalArgumentException("denominator may not be zero");
        }
        this.num = num;
        this.denom = denom;
        if (num != 0) {
            int gcd = Rational.gcd(num,denom);
            this.num /= gcd;
            this.denom /= gcd;
        }
        
        if (this.denom < 0) {
            this.num *= -1;
            this.denom *= -1;
        }
          
    }

    public String toString() {
        if (denom == 1 || num == 0)
            return "" + num;
        return num + "/" + denom;
    }

    public int getNumerator() { return this.num; }
    public int getDenominator() { return this.denom; }

    public static int lcm(int a, int b) {
        int gcd = Rational.gcd(a, b);
        return Math.abs(a * b) / gcd;

    }
    
    public Rational plus(Rational r) {
        int numerator = this.num * r.denom + r.num * this.denom;
        int denominator = this.denom * r.denom;
        return new Rational(numerator, denominator);
    }

    public static Rational sum(Rational a, Rational b) {
        return a.plus(b);
    }

    public Rational minus(Rational r) {
        Rational answer = this.plus(product(r, new Rational(-1, 1)));
        return answer;
    }

    public static Rational difference(Rational a, Rational b) {
        return a.minus(b);
    }

    public Rational reciprocalOf() {
        if (this.num != 0)
            return new Rational(this.denom, this.num);
        throw new ArithmeticException("denominator may not be zero");
    }

    public Rational times(Rational r) {
        return new Rational(this.num * r.num,
                            this.denom * r.denom);
    }

    public static Rational product(Rational a, Rational b) {
        return new Rational(a.num * b.num,
                            a.denom * b.denom);
    }

    public Rational dividedBy(Rational r) {
        return product(this, r.reciprocalOf());
    }

    public static Rational quotient(Rational a, Rational b) {
        return Rational.product(a, b.reciprocalOf());
    }


    /** 
        For testing getters.  
        @param args unused
     */

    public static void main (String [] args) {
        Rational r = new Rational(5,7);
        System.out.println("r.getNumerator()=" + r.getNumerator());
        System.out.println("r.getDenominator()=" + r.getDenominator());
    }
}
