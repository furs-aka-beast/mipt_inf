#pragma once



class Rational final {
public:
    // int numerator() const {return m_numerator;}
    // int denominator() const {return m_denominator;}
    Rational(int numerator=0, int denominator=1){
        m_numerator=numerator;
        m_denominator=denominator;
    }
    Rational(const Rational& other) {
        m_numerator=other.m_numerator;
        m_denominator=other.m_denominator;
    }
    Rational& operator=(const Rational& other){
        if (this == &other) {
            return *this;
        }
        m_numerator=other.m_numerator;
        m_denominator=other.m_denominator;
        return *this;
    }
    double toDouble() const{
        return (double)m_numerator/m_denominator;
    }
    Rational& operator+=(const Rational& other) {
        m_numerator = other.m_denominator*m_numerator+other.m_numerator*m_denominator;
        m_denominator = other.m_denominator*m_denominator;
        return *this;
    }

    Rational& operator-=(const Rational& other) {
        m_numerator = other.m_denominator*m_numerator-other.m_numerator*m_denominator;
        m_denominator = other.m_denominator*m_denominator;
        return *this;
    }
    
    Rational& operator*=(const Rational& other) {
        m_numerator = m_numerator*other.m_numerator;
        m_denominator = other.m_denominator*m_denominator;
        return *this;
    }

    Rational& operator/=(const Rational& other) {
        m_numerator = m_numerator*other.m_denominator;
        m_denominator = other.m_numerator*m_denominator;
        return *this;
    }

    // Rational& operator++() const {
    //   return *this += 1;
    // }
    
    // Rational operator++(int) {
    //   Rational res = *this;
    //   ++(*this);
    //   return res;
    // }
    // Rational& operator--() const {
    //   return *this -= 1;
    // }
    
    // Rational operator--(int) {
    //   Rational res = *this;
    //   --(*this);
    //   return res;
    // }
    Rational operator-() const {
        Rational r(-m_numerator,m_denominator);
      return r;
    }
    Rational operator+() const {
      return *this;
    }

    friend bool operator<(const Rational &a, const Rational &b) {
        Rational copy=a;
        return ((copy-=b).m_numerator)<0;
    }
    friend bool operator> (const Rational& lhs, const Rational& rhs) { return rhs < lhs; }
    friend bool operator<=(const Rational& lhs, const Rational& rhs) { return !(lhs > rhs); }
    friend bool operator>=(const Rational& lhs, const Rational& rhs) { return !(lhs < rhs); }
    friend bool operator==(const Rational &a, const Rational &b){ return (a>=b and a<=b); }
    friend bool operator!=(const Rational &a, const Rational &b){ return !(a==b); }
    explicit operator double() const{
        return toDouble();
    }
private:
    

    int m_numerator;
    int m_denominator;
};

    Rational operator+(const Rational& a,const Rational& b) {
      Rational sum = a;
      sum += b;
      return sum;
    }
    Rational operator-(const Rational& a,const Rational& b) {
      Rational dec = a;
      dec -= b;
      return dec;
    }
    Rational operator*(const Rational& a,const Rational& b) {
      Rational prod = a;
      prod *= b;
      return prod;
    }
    Rational operator/(const Rational& a,const Rational& b) {
      Rational dev = a;
     dev /= b;
      return dev;
    }
