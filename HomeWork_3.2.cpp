#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Figure {
public:
    virtual void area() = 0;
};

class Parallelogram : public Figure {
protected:
    int Side;
    int High;
public:
    Parallelogram(int x, int y) : Side(x), High(y) {};
    void area() override {
        cout << "Parallelogram: S = " << Side * High << " cm^2" << endl;
    };

};

class Rectangle : Parallelogram{
public:
    Rectangle(int x, int y) : Parallelogram(x, y) {};
    void area() override {
        cout << "Rectangle: S = " << Parallelogram::Side * Parallelogram::High << " cm^2" << endl;
    };
};

class Square : Parallelogram {
public:
    Square(int x) : Parallelogram(x, x) {};
    void area() override {
        cout << "Square: S = " << pow(Parallelogram::Side, 2) << " cm^2" << endl;
    };
};

class Rhombus : Parallelogram {
public:
    Rhombus(int x, int y) : Parallelogram(x, y) {};
    void area() override {
        cout << "Rhombus: S = " << (Parallelogram::Side * Parallelogram::High) / 2 << " cm^2" << endl;
    };
};

class Circle : public Figure {
private:
    int Rad;
    double const P = 3.141592653589793;
public:
    Circle(int r) : Rad(r) {};
    void area() {
        cout << "Circle: S = " << P * pow(Rad, 2) << " cm^2" << endl;
    };

};

class Car {
protected:
    string Company;
    string Model;
public:
    Car(string c, string m) : Company(c), Model(m) {};
    virtual void print() {
        cout << "Cmpany: " << Company << endl;
        cout << "Model: " << Model << endl;
    };
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(string c, string m) : Car(c, m) {};
    void print() override {
        cout << "Company: " << Company << endl;
        cout << "Model: " << Model << endl << endl;
    };
};

class Bus : virtual public Car {
public:
    Bus(string c, string m) : Car(c,m) {};
    void print() override {
        cout << "Company: " << Company << endl;
        cout << "model: " << Model << endl << endl;
    };
};

class Miniven : public PassengerCar, public Bus {
public:
    Miniven(string c, string m) : Car(c, m), PassengerCar(c, m), Bus(c,m) {};
    void print() override {
        cout << "Company: " << Company << endl;
        cout << "Model: " << Model << endl << endl;
    };

};

class Fraction {
private:
    float Frac;
public:
    Fraction(float f) : Frac(f) {};
    friend Fraction operator + (const Fraction & S1, const Fraction & S2);
    friend Fraction operator * (const Fraction& Mu1, const Fraction& Mu2);
    double getFraction() const {
        return Frac;
    };
    Fraction operator-(const Fraction& other)
    {
        return Fraction(Frac - other.Frac);
    };
};

Fraction operator*(const Fraction& Mu1, const Fraction& Mu2) {
    return Fraction(Mu1.Frac * Mu2.Frac);
};
Fraction operator+(const Fraction& S1, const Fraction& S2) {
    return Fraction(S1.Frac + S2.Frac);
};
Fraction operator / (const Fraction & F1, const Fraction & F2) {
    return Fraction(F1.getFraction() / F2.getFraction());
};

int main()
{
    Parallelogram P(10, 20);
    P.area();

    Rectangle R(5, 30);
    R.area();

    Square S(10);
    S.area();

    Rhombus Romb(10, 16);
    Romb.area();

    Circle C(10);
    C.area();
//------------------------------------//
    cout << endl;
    cout << "//------------------------------------//" << endl;
    cout << endl;
//------------------------------------//
    
    PassengerCar lite("BMW", "X5");
    lite.print();

    Bus B("VolgaBus", "Delta");
    B.print();

    Miniven M("Miniven", "Alpha");
    M.print();
    
//------------------------------------//
    cout << endl;
    cout << "//------------------------------------//" << endl;
    cout << endl;
 //------------------------------------//

    Fraction F1(3), F2(1);
    Fraction F3 = F1 / F2;
    cout << "Fraction: " <<  F3.getFraction() << endl;

    Fraction S1(3), S2(1);
    Fraction S3 = S1 + S2;
    cout << "Summ: " << S3.getFraction() << endl;

    Fraction M1(3), M2(1);
    Fraction M3 = M1 - M2;
    cout << "Minus: " << M3.getFraction() << endl;
    
    Fraction Mu1(3), Mu2(1);
    Fraction Mu3 = Mu1 * Mu2;
    cout << "Multiplication: " << Mu3.getFraction() << endl;
    return 0;
};
