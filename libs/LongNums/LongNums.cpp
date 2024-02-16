#include "LongNums.h"

namespace lnums {
	
	LongNum::LongNum() {
		(*this).reset_to_default();
	}

    LongNum::LongNum(const std::string& str) {
		*this = str;
	}

    LongNum::LongNum(const double num) {
		*this = num;
	}

    LongNum::LongNum(const int num) {
		*this = num;
	}


	/* CLASS PRIVATE METHODS */
	template <class variable_int>
	void LongNum::put_int(variable_int num) {
		while (num > 0) {
			if (this->minus_flag == true) {
				this->value.push_front(-1 * (num % 10));
			}
			else {
				this->value.push_front(num % 10);
			}
			++this->len_int;
			++this->len;
			num /= 10;
		}	
	}

	void LongNum::add_digit_to_index(const int digit, const int index) {
		if (index >= 0) {
			this->value[index] += digit;
		}
		else {
			this->value.push_front(digit);
			++this->len_int;
			++this->len;
		}
	}

	bool LongNum::determine_sign(const LongNum& num1, const LongNum& num2, const Operation operation) const{
		// True = negative, false = positive or 0;

		bool minus1 = num1.minus_flag;
		bool minus2 = num2.minus_flag;

		if (operation == Operation::ADDITION && \
		((minus1 == true && minus2 == true) || \
		(minus1 == false && minus2 == true && (-num2) > num1) || \
		(minus1 == true && minus2 == false && (-num1) > num2))) {
					
			return true;
		}

		else if ((operation == Operation::DIVISION) && 
			((minus1 == false && minus2 == true && num1.is_zero() == false) || \
			(minus1 == true && minus2 == false && num2.is_zero() == false))) {
			
			return true;
		}

		return false;
	}

	void LongNum::feel_map(std::unordered_map<char, LongNum>& map) {
		LongNum num_for_mult;
		num_for_mult.reset_to_zero();

		map[0] = num_for_mult;

		for (char digit = 1; digit != 10; ++digit) {
			num_for_mult = num_for_mult + *this;

			map[digit] = num_for_mult;
			map[-digit] = -num_for_mult;
		}
	}

	void LongNum::reset_to_default() {
		this->value = {};
		this->len_int = 0;
		this->len_float = 0;
		this->len = 0;
		this->minus_flag = false;
	}

	void LongNum::reset_to_zero() {
		this->value = {0};
		this->len_int = 1;
		this->len_float = 0;
		this->len = 1;
		this->minus_flag = false;
	}

	void LongNum::to_positive() {
		if (this->minus_flag == true) {
			*this = -(*this);
		}
	}

	bool LongNum::is_zero() const{
		LongNum zero;
		zero.reset_to_zero();

		return *this == zero;

	}

	void LongNum::move_dot(int n) { // == value * 10^n
		while (n != 0) {
			if (n > 0) {
				this->value.push_back(0);
				++this->len_int;
				--n;
			}
			else { // n < 0
				this->value.push_front(0);
				++this->len_float;
				++n;
			}
			++this->len;
		}
		(*this).erase_insignificant_zeros();
	}

	void LongNum::erase_insignificant_zeros() {
		if (this->len_int == 0) {
			++this->len_int;
			++this->len;
			this->value.push_front(0);
		}

		// Erase integer insignificant zeros
		while (this->value.front() == 0 && this->len_int != 1) {
			this->value.pop_front();
			--this->len_int;
			--this->len;
		}

		// Erase float insignificant zeros
		while (this->value.back() == 0 && this->len_float != 0) {
			this->value.pop_back();
			--this->len_float;
			--this->len;
		}

		if ((*this).is_zero() == true) {
			this->minus_flag = false;
		}
	}

	LongNum::CmpResult LongNum::compare(const LongNum& num2) const {
		
		if (this->len_int > num2.len_int) {
			if (this->minus_flag == true) {
				return CmpResult::SMALLER;
			}
			return CmpResult::BIGGER;
		}
		else if (this->len_int < num2.len_int){
			if (num2.minus_flag == true) {
				return CmpResult::BIGGER;
			}
			return CmpResult::SMALLER;
		}

		int ind = 0;
		while ((ind < this->len) && (ind < num2.len)) {
			if (this->value[ind] > num2.value[ind]) {
				return CmpResult::BIGGER;
			}
			else if (this->value[ind] < num2.value[ind]) {
				return CmpResult::SMALLER;
			}
			++ind;
		}

		if ((ind < this->len) && (ind == num2.len)) {
			if (this->minus_flag == true) {
				return CmpResult::SMALLER;
			}
			return CmpResult::BIGGER;
		}
		else if ((ind == this->len) && (ind < num2.len)) {
			if (this->minus_flag == true) {
				return CmpResult::BIGGER;
			}
			return CmpResult::SMALLER;
		}
		
		return CmpResult::EQUAL;
	}

	void LongNum::do_division_stage(const Stage stage, const LongNum& num1, LongNum& divisible, int& num1_ind) {
		if (num1_ind < num1.len) {
			divisible.value.push_back(num1.value[num1_ind]);
			divisible.increase_len_by_condition(num1_ind < num1.len_int);
		}
		else {
			divisible.move_dot(1);
			if (stage == Stage::INITIAL) {
				this->value.push_back(0);
				this->increase_len_by_condition(this->len_int == 0);
			}
		}
		if (stage == Stage::INCREASE) {
			this->value.push_back(0);
			this->increase_len_by_condition(num1_ind < num1.len);
		}
		++num1_ind;
	}

	/* CLASS PUBLIC METHODS */

	std::string LongNum::get_value() const{ // convert to string
		std::string result = "";

		int limit = std::min(this->len_float, DEFAULT_ACCURACY);
		int printed_num_len = this->len_int;

		// Find index on the last float digit != 0
		for (int i = this->len_int; i != this->len_int + limit; ++i) {
			printed_num_len = i + 1;
		}


		// Make string
		if (this->minus_flag == true) {
			result = "-";
		}
		for (int i = 0; i < printed_num_len; ++i) {
			if (i == this->len_int) {
				result.push_back('.');
			}
			result.push_back(std::abs(this->value[i]) + '0');
		}
		return result;
	}

	void LongNum::increase_len_by_condition(const bool condition) {
		// Shorted function for adding value len
		if (condition) {
			++this->len_int;
		}
		else {
			++this->len_float;
		}
		++this->len;
	}

	/* BOOL OPERATORS */


	std::strong_ordering LongNum::operator<=>(const LongNum& num2) const {
		CmpResult status = (*this).compare(num2);
		switch (status) {
			case CmpResult::SMALLER:
				return std::strong_ordering::less;
			case CmpResult::BIGGER:
				return std::strong_ordering::greater;
			default:
				return std::strong_ordering::equal;
		}
	}
	
	bool LongNum::operator==(const LongNum& num2) const{
		if ((*this).compare(num2) == CmpResult::EQUAL) {
			return true;
		}
		return false;
	}
	

	/* ASSIGNMENT OPERATOR */


	LongNum LongNum::operator=(const std::string& str_num) {
		bool float_part_flag = false;
		(*this).reset_to_default();

		for (int i = 0; str_num[i] != '\0'; ++i) {
			switch (str_num[i]) {
				case '-':
					this->minus_flag = true;
					break;
				case '.':
					float_part_flag = true;
					break;
				default:
					if (float_part_flag == false) {
						++this->len_int;
					}
					else {
						++this->len_float;
					}
					++this->len;

					if (this->minus_flag == true) {
						this->value.push_back(-1 * (str_num[i] - '0'));
					}
					else {
						this->value.push_back(str_num[i] - '0');
					}
			}
		}

		(*this).erase_insignificant_zeros();
		return *this;
	}

	LongNum LongNum::operator=(int num) {
		(*this).reset_to_default();

		if (num < 0) {
			this->minus_flag = true;
			num *= -1;
		}

		(*this).put_int(num);

		(*this).erase_insignificant_zeros();
		return *this;
	}

	LongNum LongNum::operator=(double num) {
		(*this).reset_to_default();

		if (num < 0) {
			this->minus_flag = true;
			num *= -1;
		}

		long long int int_part = static_cast<long long int>(num);
		(*this).put_int(int_part);

		while (this->len != DOUBLE_ACCURACY) {
			num *= 10;
			char digit = static_cast<long long int>(num) % 10;
			if (this->minus_flag == true) {
				this->value.push_back(-1 * digit);
			}
			else {
				this->value.push_back(digit);
			}
			++this->len_float;
			++this->len;

		}

		(*this).erase_insignificant_zeros();
		return *this;
	}

	/* UNARY OPERATORS */


	LongNum LongNum::operator+() const {
		return *this;
	}

	LongNum LongNum::operator-() const {
		LongNum new_num = *this;

		for (int i = 0; i != new_num.len; ++i) {
			new_num.value[i] *= -1; 
		}
		if (new_num.is_zero() == false) {
			new_num.minus_flag = !(this->minus_flag);
		}
		return new_num;
	}


	/* ARITHMETIC OPERATORS */


	LongNum LongNum::operator+(const LongNum& num2) const{
		LongNum result;
		LongNum num1(*this);

		result.len_int = std::max(num1.len_int, num2.len_int);
		result.len_float = std::max(num1.len_float, num2.len_float);
		result.len = result.len_int + result.len_float;
		result.value.resize(result.len, 0);

		bool negative_res_flag = determine_sign(num1, num2, Operation::ADDITION);

		int num1_ind = num1.len_int + result.len_float - 1;
		int num2_ind = num2.len_int + result.len_float - 1;

		for (int i = result.len - 1; i >= 0; --i) {
			if (0 <= num1_ind && num1_ind < num1.len) {
				result.value[i] += num1.value[num1_ind];
			}
			if (0 <= num2_ind && num2_ind < num2.len) {
				result.value[i] += num2.value[num2_ind];
			}

			// Check overflowing - move 1 to the next digit of the number
			if (result.value[i] >= 10 || \
				(result.value[i] > 0 && negative_res_flag == true)) {
				result.value[i] -= 10;
				result.add_digit_to_index(1, i - 1);
			}
			else if ((result.value[i] <= -10) || \
				(result.value[i] < 0 && negative_res_flag == false)) {
				result.value[i] += 10;
				result.add_digit_to_index(-1, i - 1);
			}
			
			--num1_ind;
			--num2_ind;
		}

		result.erase_insignificant_zeros();
		result.minus_flag = negative_res_flag;
		return result;
	}

	LongNum LongNum::operator-(const LongNum& num2) const{
		LongNum new_num = -num2;
		return *this + new_num;
	}

	LongNum LongNum::operator*(const LongNum& num2) const {
		LongNum num1(*this);

		std::unordered_map<char, LongNum> mult; // multiplication of a number by its digits
		num1.feel_map(mult);
		
		LongNum result;
		result.reset_to_zero();

		for (int i = 0; i != num2.len; ++i) {
			LongNum new_element = mult[num2.value[num2.len - 1 - i]];
			new_element.move_dot(i - num2.len_float);
		
			result = result + new_element;
		}

		return result;
	}

	LongNum LongNum::operator/(const LongNum& n2) const{
		LongNum result;
		LongNum num1(*this);
		LongNum num2(n2);
		LongNum divisible; // part of num1

		if (num2.is_zero()) {
			throw "Error - division by zero";
		}
		
		bool negative_res = determine_sign(num1, num2, Operation::DIVISION);

		num1.to_positive();
		num2.to_positive();
		// Discard zeros
		num1.move_dot(num2.len_float);
		num2.move_dot(num2.len_float);

		int num1_ind = 0;
		
		// Get initial number for division
		while (divisible < num2 && result.len_float < DEFAULT_ACCURACY) {
			result.do_division_stage(Stage::INITIAL, num1, divisible, num1_ind);
		}


		while (result.len_float < DEFAULT_ACCURACY && (divisible.is_zero() == false || num1_ind < num1.len)) {

			if (divisible < num2) {
				// Add next num to divisible
				result.do_division_stage(Stage::ADD_NUM, num1, divisible, num1_ind);
				
				// (Add nums to divisible) and (0 to results)
				while (divisible < num2) {
					result.do_division_stage(Stage::INCREASE, num1, divisible, num1_ind);
				}
			}

			//
			int count = 0;
			while (divisible >= num2) {
				divisible = divisible - num2;
				++count;
			}
			result.value.push_back(count);
			result.increase_len_by_condition(num1_ind <= num1.len);

		}

		result.erase_insignificant_zeros();
		if (negative_res == true) {
			result = -result;
		}
		return result;
	}

}
