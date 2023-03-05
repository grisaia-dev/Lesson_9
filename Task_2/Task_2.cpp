#include <iostream>
#include <ostream>

class Fraction {
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

    Fraction operator+(Fraction add) { return Fraction(numerator_ + add.numerator_, denominator_ + add.denominator_); } // Сложение
    Fraction operator-(Fraction sub) { return Fraction(numerator_ - sub.numerator_, denominator_ - sub.denominator_); } // Вычитание
    Fraction operator*(Fraction mult) { return Fraction(numerator_ * mult.numerator_, denominator_ * mult.denominator_); } // Умножение
    Fraction operator/(Fraction div) { return Fraction(numerator_ / div.numerator_, denominator_ / div.denominator_); } // Деление

    // Инкремент
    Fraction operator++() { numerator_++; denominator_++; return *this; }
    Fraction operator++(int) { Fraction temp = *this; ++(*this); return temp; }

    // Декримент
    Fraction operator--() { numerator_--; denominator_--; return *this; }
    Fraction operator--(int) { Fraction temp = *this; --(*this); return temp; }

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
    std::cout << f1 << " + " << f2 << " = " << f3 << std::endl;

    f3 = f1 - f2;
    std::cout << f1 << " - " << f2 << " = " << f3 << std::endl;

    f3 = f1 * f2;
    std::cout << f1 << " * " << f2 << " = " << f3 << std::endl;

    f3 = f1 / f2;
    std::cout << f1 << " / " << f2 << " = " << f3 << std::endl;


    f3 = ++f1 * f2;
    std::cout << "++" << f1 << " * " << f2 << " = " << f3 << std::endl;

    f3 = f1-- * f2;
    std::cout << f1 << "--" << " * " << f2 << " = " << f3 << std::endl;

    return 0;
}