#include "app.h"

namespace vsite::oop::v8
{
	int input_num(std::istream& in) {
		int number;
		// Gledamo jeli unos(in) je broj (dali moze uci >> u int)
		if (!(in >> number)) {
			throw not_number();
		}
		// netriba dodatni in>>number obavljeno je u if
		return number;
	}
	
	char input_op(std::istream& in) {
		char oper;
		// Gledamo jeli unos(in) je operator (dali moze uci >> u char)
		if (!(in >> oper)) {
			throw not_operator();
		}
		// gledamo jeli je operator jedan od cetiri mogucih
		if (oper != '+' && oper != '-' && oper != '*' && oper != '/' ) {
			throw not_operator();
		}
		return oper;
	}
	
	
	double calc(int number1, char oper, int number2) {
		switch (oper)
		{
			case '+':
				return number1 + number2;

			case '-':
				return number1 - number2;
			case '*':
				return number1 * number2;
			case '/':
				if (number2 == 0) {
					throw divide_zero();
				}
				return static_cast<double>(number1) / number2;
			default:
				throw not_operator();
		}
	}
}