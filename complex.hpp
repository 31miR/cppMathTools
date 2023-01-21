#pragma once
#include<iostream>
#include<cmath>


/*
TODO:
operatori: korjenovanje, eksponentiranje, sinus, kosinus, tangens, logaritam, compleksanUeksponentu
konstruktori: konstruktor po argumentu i modulu
metodi: vratiSveKorijene
*/




namespace complex{
template<typename T>
class ComplexNumber{
private:
    T re_;
    T im_;
public:
    ComplexNumber() : re_{0}, im_{0} {};
    ComplexNumber(const ComplexNumber& o){
        re_ = o.re_;
        im_ = o.im_;
    }
    ComplexNumber(T R, T I){
        re_ = R;
        im_ = I;
    }
    //mozda jos koji konstruktor lololol?
    T& real() {return re_;}
    T& imaginary() {return im_;}
    ComplexNumber& operator=(const ComplexNumber& o){
        re_ = o.re_;
        im_ = o.im_;
        return *this;
    }
    ComplexNumber operator+(const ComplexNumber& o) const {
        return ComplexNumber(re_ + o.re_, im_ + o.im_);
    }
    ComplexNumber operator-(const ComplexNumber& o) const {
        return ComplexNumber(re_ - o.re_, im_ - o.im_);
    }
    ComplexNumber operator*(const ComplexNumber& o) const {
        return ComplexNumber(re_*o.re_ - im_*o.im_, re_*o.im_ + im_*o.re_);
    }
    ComplexNumber operator/(const ComplexNumber& o) const {
        return ComplexNumber((re_*o.re_ + im_*o.im_)/(o.re_*o.re_ + o.im_*o.im_), (im_*o.re_ - re_*o.im_)/(o.re_*o.re_ + o.im_*o.im_));
    }
    ComplexNumber& operator+=(const ComplexNumber& o){
        re_ += o.re_;
        im_ += o.im_;
        return *this;
    }
    ComplexNumber& operator-=(const ComplexNumber& o){
        re_ -= o.re_;
        im_ -= o.im_;
        return *this;
    }
    T modulo() const {return sqrt(re_*re_ + im_*im_);}
    ComplexNumber conjugate() const {return ComplexNumber(re_,-im_);}
    T argument() const {
        if ( (re_ == 0)&&(im_ == 0) ) return 0;
        if ( (re_ == 0)&&(im_ > 0) ) return 3.14159265/2;
        if ( (re_ == 0)&&(im_ < 0) ) return -3.14159265/2;
        if (re_ > 0) return atan(im_/re_);
        return atan(im_/re_)+3.14159265;
    }
};
template<typename T>
std::ostream& operator<<(std::ostream& strm, ComplexNumber<T> o){
    if(o.real() != 0) strm << o.real();
    if(o.imaginary() > 0) strm << "+";
    if(o.imaginary() != 0) strm << o.imaginary() << "*i";
    return strm;
}
}