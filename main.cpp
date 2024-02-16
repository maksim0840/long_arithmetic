#include <iostream>
// #include "LongNums.h"
// #include "CalcPi.h"
#include "libs/LongNums/LongNums.h"
#include "libs/LongNums/LongNums.cpp"
#include "libs/CalcPi/CalcPi.h"
#include "libs/CalcPi/CalcPi.cpp"

int main(void) {

    std::cout << cpi::calculate_pi(100, true) << "\n";  

	return 0;
}