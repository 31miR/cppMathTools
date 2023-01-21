#pragma once
#include<iostream>


/*
TODO:
operatori: korjenovanje, eksponentiranje, sinus, kosinus, tangens, logaritam, compleksanUeksponentu
konstruktori: konstruktor po argumentu i modulu
metodi: vrati argument, vrati modul, konjuguj, vratiSveKorijene
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
};
template<typename T>
std::ostream& operator<<(std::ostream& strm, ComplexNumber<T>& o){
    if(o.real() != 0) strm << o.real();
    if(o.imaginary() > 0) strm << "+";
    if(o.imaginary() != 0) strm << o.imaginary() << "*i";
    return strm;
}
}