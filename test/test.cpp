#include "LongNums.h"
#include "CalcPi.h"
#include <gtest/gtest.h>


TEST(Assignment_operator, assignment) {
    lnums::LongNum num1;
    lnums::LongNum num2;
    lnums::LongNum num3;

    num1 = "234798238989.8912389";
    num2 = -359;
    num3 = 456.7911;

    EXPECT_EQ(num1.get_value(), "234798238989.8912389");
    EXPECT_EQ(num2.get_value(), "-359");
    EXPECT_EQ(num3.get_value(), "456.7911");
    EXPECT_EQ(num4.get_value(), "0");
}

TEST(Constructor, constructor) {
    lnums::LongNum num1("-233333333333333337.23232");
    lnums::LongNum num2(225522);
    lnums::LongNum num3(-1389.001903007);

    EXPECT_EQ(num1.get_value(), "-233333333333333337.23232");
    EXPECT_EQ(num2.get_value(), "225522");
    EXPECT_EQ(num3.get_value(), "-1389.001903007");
}


TEST(Unary_arithmetic_operator, plus) {
    lnums::LongNum num1("63834031.9238");
    lnums::LongNum num2("-98239.99");
    lnums::LongNum num3("0");

    EXPECT_EQ((+num1).get_value(), "63834031.9238");
    EXPECT_EQ((+num2).get_value(), "-98239.99");
    EXPECT_EQ((+num3).get_value(), "0");
}

TEST(Unary_arithmetic_operator, minus) {
    lnums::LongNum num1("312234324.819");
    lnums::LongNum num2("-7654802.112");
    lnums::LongNum num3("0");

    EXPECT_EQ((-num1).get_value(), "-312234324.819");
    EXPECT_EQ((-num2).get_value(), "7654802.112");
    EXPECT_EQ((-num3).get_value(), "0");
}

TEST(Binary_arithmetic_operator, addition) {
    lnums::LongNum num1("111222333444555666.99999988");
    lnums::LongNum num2("100000000000000000.00031");
    lnums::LongNum num3("-34.9999999999999999999");
    lnums::LongNum num4("-89755555.7777777777777");
    lnums::LongNum num5("89000000000000000000000");
    lnums::LongNum num6("-0.00000000000000000001");
    lnums::LongNum num7("101999999.9999");
    lnums::LongNum num8("0.0001");
    lnums::LongNum num9("9898989898.9898989898");
    lnums::LongNum num10("1212121212.1212121212");

    EXPECT_EQ((num1 + num2).get_value(), "211222333444555667.00030988");
    EXPECT_EQ((num3 + num4).get_value(), "-89755590.7777777777776999999");
    EXPECT_EQ((num5 + num6).get_value(), "88999999999999999999999.99999999999999999999");
    EXPECT_EQ((num7 + num8).get_value(), "102000000");
    EXPECT_EQ((num9 + num10).get_value(), "11111111111.111111111");

}

TEST(Binary_arithmetic_operator, subtraction) {
    lnums::LongNum num1("-190190190190.8181818181");
    lnums::LongNum num2("1000000000000.456");
    lnums::LongNum num3("12000000000001.999");
    lnums::LongNum num4("40001.0001");
    lnums::LongNum num5("8920789");
    lnums::LongNum num6("2222100000");
    lnums::LongNum num7("0.0000000004");
    lnums::LongNum num8("0.0000000005");
    lnums::LongNum num9("10000000000");
    lnums::LongNum num10("0.0000000001");

    EXPECT_EQ((num1 - num2).get_value(), "-1190190190191.2741818181");
    EXPECT_EQ((num3 - num4).get_value(), "11999999960000.9989");
    EXPECT_EQ((num5 - num6).get_value(), "-2213179211");
    EXPECT_EQ((num7 - num8).get_value(), "-0.0000000001");
    EXPECT_EQ((num9 - num10).get_value(), "9999999999.9999999999");
}

TEST(Binary_arithmetic_operator, composition) {
    lnums::LongNum num1("123456789.9");
    lnums::LongNum num2("-1000001");
    lnums::LongNum num3("3124121421421421");
    lnums::LongNum num4("0");
    lnums::LongNum num5("-888883.123");
    lnums::LongNum num6("123456789");
    lnums::LongNum num7("3");
    lnums::LongNum num8("0.33333333333334");
    lnums::LongNum num9("-123.456");
    lnums::LongNum num10("-8810.499122");

    EXPECT_EQ((num1 * num2).get_value(), "-123456913356789.9");
    EXPECT_EQ((num3 * num4).get_value(), "0");
    EXPECT_EQ((num5 * num6).get_value(), "-109738656161872.047");
    EXPECT_EQ((num7 * num8).get_value(), "1.00000000000002");
    EXPECT_EQ((num9 * num10).get_value(), "1087708.979605632");
}

TEST(Binary_arithmetic_operator, division) {
    lnums::LongNum num1("10000000000000000");
    lnums::LongNum num2("3");
    lnums::LongNum num3("839104231");
    lnums::LongNum num4("-56789");
    lnums::LongNum num5("45000");
    lnums::LongNum num6("1800000");
    lnums::LongNum num7("9999");
    lnums::LongNum num8("11");
    lnums::LongNum num9("-123.55");
    lnums::LongNum num10("0");

    EXPECT_EQ((num1 / num2).get_value(), "3333333333333333.33333333333333333333333333333333333333333333333333");
    EXPECT_EQ((num3 / num4).get_value(), "-14775.82332846149782528306538238039056859603092148127278");
    EXPECT_EQ((num5 / num6).get_value(), "0.025");
    EXPECT_EQ((num7 / num8).get_value(), "909");
    EXPECT_ANY_THROW(num9 / num10);
}

TEST(Relational_operator, bigger) {
    lnums::LongNum num1("123456.7891");
    lnums::LongNum num2("123456.789");
    lnums::LongNum num3("-3400");
    lnums::LongNum num4("-855.423");
    lnums::LongNum num5("30.31");
    lnums::LongNum num6("30.31");

    EXPECT_EQ((num1 > num2), true);
    EXPECT_EQ((num3 > num4), false);
    EXPECT_EQ((num5 > num6), false);
}

TEST(Relational_operator, smaller) {
    lnums::LongNum num1("2024.2023");
    lnums::LongNum num2("2077");
    lnums::LongNum num3("-81");
    lnums::LongNum num4("-855.91");
    lnums::LongNum num5("457.001");
    lnums::LongNum num6("457.001");

    EXPECT_EQ((num1 < num2), true);
    EXPECT_EQ((num3 < num4), false);
    EXPECT_EQ((num5 < num6), false);
}

TEST(Relational_operator, bigger_or_equal) {
    lnums::LongNum num1("781.420");
    lnums::LongNum num2("781.420");
    lnums::LongNum num3("199.99");
    lnums::LongNum num4("200");
    lnums::LongNum num5("-81");
    lnums::LongNum num6("81");

    EXPECT_EQ((num1 >= num2), true);
    EXPECT_EQ((num3 >= num4), false);
    EXPECT_EQ((num5 >= num6), false);
}

TEST(Relational_operator, smaller_or_equal) {
    lnums::LongNum num1("811");
    lnums::LongNum num2("945");
    lnums::LongNum num3("91293.111111111");
    lnums::LongNum num4("-0.000000000000042");
    lnums::LongNum num5("333");
    lnums::LongNum num6("3.33");

    EXPECT_EQ((num1 <= num2), true);
    EXPECT_EQ((num3 <= num4), false);
    EXPECT_EQ((num5 <= num6), false);
}

TEST (Relational_operator, equal) {
    lnums::LongNum num1("1232");
    lnums::LongNum num2("1232");
    lnums::LongNum num3("415");
    lnums::LongNum num4("-415");
    lnums::LongNum num5("228");
    lnums::LongNum num6("22.8");

    EXPECT_EQ((num1 == num2), true);
    EXPECT_EQ((num3 == num4), false);
    EXPECT_EQ((num5 == num6), false);
}

TEST (Relational_operator, not_equal) {
    lnums::LongNum num1("1232");
    lnums::LongNum num2("19823.123");
    lnums::LongNum num3("-890.002");
    lnums::LongNum num4("-890.002");
    lnums::LongNum num5("0");
    lnums::LongNum num6("0");


    EXPECT_EQ((num1 != num2), true);
    EXPECT_EQ((num3 != num4), false);
    EXPECT_EQ((num5 != num6), false);
}

TEST (Pi_calculating, accuracy) {
    EXPECT_EQ(cpi::calculate_pi(0), "");
    EXPECT_EQ(cpi::calculate_pi(1), "3");
    EXPECT_EQ(cpi::calculate_pi(2), "3.1");
    EXPECT_EQ(cpi::calculate_pi(100), \
     "3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067");
}