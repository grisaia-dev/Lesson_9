﻿#include <iostream>

class Fraction {
private:
	double numerator_;
	double denominator_;

public:
	Fraction(int numerator, int denominator) {
		numerator_ = numerator;
		denominator_ = denominator;
	}

	bool operator<(Fraction& right) {
		if ((numerator_ / denominator_) < (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}

	bool operator==(Fraction& right) {
		if ((numerator_ / denominator_) == (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}

	bool operator!=(Fraction& right) {
		if ((numerator_ / denominator_) != (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}

	bool operator>(Fraction& right) {
		if ((numerator_ / denominator_) > (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}

	bool operator<=(Fraction& right) {
		if ((numerator_ / denominator_) <= (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}

	bool operator>=(Fraction& right) {
		if ((numerator_ / denominator_) >= (right.numerator_ / right.denominator_))
			return true;
		else
			return false;
	}
};

int main() {
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}
