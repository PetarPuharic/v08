#pragma once
#include <sstream>

namespace vsite::oop::v8
{
	// Basic funkcije kalkulatora
	int input_num(std::istream& in);
	char input_op(std::istream& in);
	double calc(int number1, char oper, int number2);


	// Apstraktna klasa za izuzetke kalkulatora
	class calculator_exception {
	public:
		virtual const std::string what() const noexcept = 0;
		virtual ~calculator_exception() = default;
	};


	//	Vrste Exceptiona:
	//	invalid operation
	//	not a number
	//	divide by zero

	class not_operator : public calculator_exception {
	public:
		const std::string what() const noexcept override {
			return "Not a valid operator";
		}
	};

	class not_number : public calculator_exception {
		public:
		const std::string what() const noexcept override {
			return "Not a valid number";
		}
	};

	class divide_zero : public calculator_exception {
		public:
		const std::string what() const noexcept override {
			return "Division by zero";
		}
	};
}