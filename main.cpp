#include <iostream>
// #include "LongNums.h"
// #include "CalcPi.h"
#include "libs/LongNums/LongNums.h"
#include "libs/LongNums/LongNums.cpp"
#include "libs/CalcPi/CalcPi.h"
#include "libs/CalcPi/CalcPi.cpp"

int main(void) {
    std::cout << cpi::calculate_pi(100, true) << "\n\n";

    lnums::LongNum num1("9999");
    lnums::LongNum num2("11");

    std::cout << (num1 / num2).get_value() << '\n'; // 123456913356789.9
	return 0;
}