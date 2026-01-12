#include "app.h"
#include <iostream>

// read and evaluate expression inside endless loop 
// break after first exception (use one catch clause), show error description


using namespace vsite::oop::v8;
int main()
{
	while (true) {
		try {
			std::cout << "Enter expression (number operator number): ";
			int num1 = input_num(std::cin);
			char oper = input_op(std::cin);
			int num2 = input_num(std::cin);
			double result = calc(num1, oper, num2);
			std::cout << num1 << oper << num2 << "=" << result << std::endl;
		}
		catch (const calculator_exception& e) {
			std::cout << "Error: " << e.what() << std::endl;
			break;
		}
	}

}
