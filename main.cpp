#include <iostream>
// #include "LongNums.h"
// #include "CalcPi.h"
#include "libs/LongNums/LongNums.h"
#include "libs/LongNums/LongNums.cpp"
#include "libs/CalcPi/CalcPi.h"
#include "libs/CalcPi/CalcPi.cpp"

int main(void) {
	lnums::LongNum a(200);
	lnums::LongNum b(201);

    std::cout << cpi::calculate_pi(100, true) << '\n';
	return 0;
}