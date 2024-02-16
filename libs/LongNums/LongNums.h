#pragma once

#include <iostream>
#include <string.h>
#include <deque>
#include <unordered_map>
#include <math.h>
#include <compare> // strong_ordering

#define DEFAULT_ACCURACY 50 // max accuracy of all LongNums
#define DOUBLE_ACCURACY 15 // accuracy of converting double to LongNum

namespace lnums {

    class LongNum {
    private:
        template <class variable_int>
        void put_int(variable_int);

        std::deque<char> value;
        int len_int = 0; // len of int part
        int len_float = 0; // len of float part
        int len = 0;
        bool minus_flag = false;

        bool is_zero() const;
        void increase_len_by_condition(const bool);
        void add_digit_to_index(const int, const int);
        void move_dot(int);
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

        enum  Stage{
            INITIAL,
            ADD_NUM,
            INCREASE
        };
        void do_division_stage(const Stage, const LongNum&, LongNum&, int&);

    public:
        LongNum();
        /*explicit*/ LongNum(const std::string&);
        LongNum(const double);
        LongNum(const int);

        std::string get_value() const; // convert to string

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