#pragma once

#include <iostream>
#include <string.h>
#include <deque>
#include <unordered_map>
#include <math.h>
#include <compare> // strong_ordering

#define DEFAULT_ACCURACY 50

namespace lnums {

    class LongNum {
    private:
        std::deque<char> value;
        int len_int = 0; // len of int part
        int len_float = 0; // len of float part
        int len = 0;
        bool minus_flag = false;
        // Accuracy of float nums (only affects the output)
        int accuracy = DEFAULT_ACCURACY; // accuracy res = max(num1.accuracy, num2.accuracy)

        bool is_zero() const;
        void multiply_by_10(const int);
        void increase_len_by_condition(const bool);
        void add_digit_to_index(const int, const int);
        void reset_to_default();
        void reset_to_zero();
        void to_positive();
        void erase_insignificant_zeros();
        void feel_map(std::unordered_map<char, LongNum>&);
        
        enum Operation {
            ADDITION,
            DIVISION
        };

        bool determine_sign(const LongNum&, const LongNum&, const Operation) const;

        enum CmpResult {
            BIGGER,
            SMALLER,
            EQUAL
        };

        CmpResult compare(const LongNum&) const;

    public:
        LongNum();
        /*explicit*/ LongNum(const std::string&);
        LongNum(const double);
        LongNum(const int);

        std::string get_value() const; // convert to string

        /* in progress */
        void set_accuracy_limit(const int);
        /* in progress */

        LongNum operator+() const;
        LongNum operator-() const;

        LongNum operator+(const LongNum&) const;
        LongNum operator-(const LongNum&) const;
        LongNum operator*(const LongNum&) const;
        LongNum operator/(const LongNum&) const;

        std::strong_ordering operator<=>(const LongNum&) const;
        bool operator==(const LongNum&) const;
        
        LongNum operator=(const std::string&);
        LongNum operator=(const int);
        LongNum operator=(const double);
    };
}