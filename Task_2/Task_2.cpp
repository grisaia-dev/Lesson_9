#include <iostream>
#include <ostream>

class Fraction {
private:
	int numerator_;
	int denominator_;

    void reduce();
public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

    Fraction operator+(Fraction& other) {// Сложение 
        return Fraction(numerator_ * other.denominator_ + denominator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator-(Fraction& other) { // Вычитание
        return Fraction(numerator_ * other.denominator_ - denominator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator*(Fraction& other) { // Умножение
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(Fraction& other) { // Деление
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    // Инкремент
    Fraction operator++() { numerator_ += denominator_; return *this; }
    Fraction operator++(int) { Fraction temp (*this); ++*this; return temp; }

    // Декримент
    Fraction operator--() { numerator_ -= denominator_; return *this; }
    Fraction operator--(int) { Fraction temp = (*this); --*this; return temp; }

    //Сокращение дробей
    void NOD() {
        int num = numerator_;
        int den = denominator_;
        int buf;
        while (den != 0) {
            buf = den;
            den = num % den;
            num = buf;
        }
        numerator_ /= num;
        denominator_ /= num;
    }

    friend std::ostream& operator<<(std::ostream& left, Fraction& right) { return left << right.numerator_ << "/" << right.denominator_; }
};

int main() {
    int var1=0, var2=0;
    int num1=0, num2=0;

    std::cout << "Введите числитель дроби 1: ";
    std::cin >> var1;
    std::cout << "Введите знаминатель дроби 1: ";
    std::cin >> var2;

    std::cout << "Введите числитель дроби 2: ";
    std::cin >> num1;
    std::cout << "Введите знаминатель дроби 2: ";
    std::cin >> num2;

    Fraction f1(var1, var2);
    Fraction f2(num1, num2);

    Fraction f3 = f1 + f2;
    f3.NOD();
    std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;

    f3 = f1 - f2;
    //f3.NOD();
    std::cout << f1 << " - " << f2 << " = " << f3 << std::endl;

    f3 = f1 * f2;
    f3.NOD();
    std::cout << f1 << " * " << f2 << " = " << f3 << std::endl;

    f3 = f1 / f2;
    f3.NOD();
    std::cout << f1 << " / " << f2 << " = " << f3 << std::endl;

    std::cout << "++" << f1 << " * " << f2;
    f3 = ++f1 * f2;
    f3.NOD();
    std::cout << " = " << f3 << std::endl;
    std::cout << "Значение дроби 1: " << f1 <<std::endl;

    std::cout << f1 << "--" << " * " << f2; 
    f3 = f1-- * f2;
    f3.NOD();
    std::cout << " = " << f3 << std::endl;
    std::cout << "Значение дроби 1: " << f1 <<std::endl;

    return 0;
}