#include "gtest.h"
#include "..\mp2-lab3-stack\TCalc.h"
#include <iostream>

TEST(TCalc, check_brackets_1_true)
{
	TCalc tmp;
	tmp.SetInfix("()");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalc, check_brackets_2_true)
{
	TCalc tmp;
	tmp.SetInfix("(())");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalc, check_brackets_3_true)
{
	TCalc tmp;
	tmp.SetInfix("()()");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalc, check_brackets_4_true)
{
	TCalc tmp;
	tmp.SetInfix("(()())");
	EXPECT_EQ(true, tmp.CheckBrackets());
}

TEST(TCalc, check_brakets_1_false)
{
	TCalc tmp;
	tmp.SetInfix("(");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalc, check_brakets_2_false)
{
	TCalc tmp;
	tmp.SetInfix(")");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalc, check_brakets_3_false)
{
	TCalc tmp;
	tmp.SetInfix("(()");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalc, check_brakets_4_false)
{
	TCalc tmp;
	tmp.SetInfix("())");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalc, check_brakets_5_false)
{
	TCalc tmp;
	tmp.SetInfix("()(");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalc, check_brakets_6_false)
{
	TCalc tmp;
	tmp.SetInfix("((()");
	EXPECT_EQ(false, tmp.CheckBrackets());
}
TEST(TCalculator, check_brakets_7_false)
{
	TCalc tmp;
	tmp.SetInfix("(()))");
	EXPECT_EQ(false, tmp.CheckBrackets());
}

TEST(TCalc, check_empty_string)
{
	TCalc tmp;
	EXPECT_ANY_THROW(tmp.CheckBrackets());
}
TEST(TCalc, simple_example_plus)
{
	TCalc tmp;
	tmp.SetInfix("2+2");
	tmp.ToPostFix();
	EXPECT_EQ("2 2+", tmp.GetPostfix());
	EXPECT_EQ(4, tmp.Calc());
}

TEST(TCalc, simple_example_minus)
{
	TCalc tmp;
	tmp.SetInfix("2-2");
	tmp.ToPostFix();
	EXPECT_EQ("2 2-", tmp.GetPostfix());
	EXPECT_EQ(0, tmp.Calc());
}
TEST(TCalc, simple_example_multiplication)
{
	TCalc tmp;
	tmp.SetInfix("2*3");
	tmp.ToPostFix();
	EXPECT_EQ("2 3*", tmp.GetPostfix());
	EXPECT_EQ(6, tmp.Calc());
}
TEST(TCalc, simple_example_division)
{
	TCalc tmp;
	tmp.SetInfix("2/4");
	tmp.ToPostFix();
	EXPECT_EQ("2 4/", tmp.GetPostfix());
	EXPECT_EQ(0.5, tmp.Calc());

}
TEST(TCalc, simple_example_degree)
{
	TCalc tmp;
	tmp.SetInfix("2^3");
	tmp.ToPostFix();
	EXPECT_EQ("2 3^", tmp.GetPostfix());
	EXPECT_EQ(8, tmp.Calc());
}
TEST(TCalc, example_1)
{
	TCalc tmp;
	tmp.SetInfix("(2+2)*3");
	tmp.ToPostFix();
	EXPECT_EQ("2 2+ 3*", tmp.GetPostfix());
	EXPECT_EQ(12, tmp.Calc());
}

TEST(TCalc, example_2)
{
	TCalc tmp;
	tmp.SetInfix("2/(2+2)+2");
	tmp.ToPostFix();
	EXPECT_EQ("2 2 2+ /2+", tmp.GetPostfix());
	EXPECT_EQ(2.5, tmp.Calc());
}
TEST(TCalc, example_3)
{
	TCalc tmp;
	tmp.SetInfix("1/(1+1)^3+2");
	tmp.ToPostFix();
	EXPECT_EQ("1 1 1+ 3 ^/2+", tmp.GetPostfix());
	EXPECT_EQ(2.125, tmp.Calc());
}

TEST(TCalc, example_4)
{
	TCalc tmp;
	tmp.SetInfix("(5+7)/40*2^5");
	tmp.ToPostFix();
	EXPECT_EQ("5 7+ 40 /2 5^*", tmp.GetPostfix());
	EXPECT_EQ(9.6, tmp.Calc());
}
TEST(TCalc, example_5)
{
	TCalc tmp;
	tmp.SetInfix("256-12^2/2");
	tmp.ToPostFix();
	EXPECT_EQ("256 12 2 ^2/-", tmp.GetPostfix());
	EXPECT_EQ(184, tmp.Calc());
}
TEST(TCalc, test_sin)
{
	TCalc tmp;
	bool check;
	tmp.SetInfix("sin(30)");
	tmp.ToPostFix();
	if (abs(0.5 - tmp.Calc()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("30s", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}

TEST(TCalcr, test_cos)
{
	TCalc tmp;
	bool check;
	tmp.SetInfix("cos(60)");
	tmp.ToPostFix();
	if (abs(0.5 - tmp.Calc()) < pow(10, -10))
		check = true;
	else
		check = false;
	EXPECT_EQ("60c", tmp.GetPostfix());
	EXPECT_EQ(true, check);
}

TEST(TCalc, error_symbol)
{
	TCalc tmp;
	tmp.SetInfix("son(35)");
	EXPECT_ANY_THROW(tmp.ToPostFix());
	
}