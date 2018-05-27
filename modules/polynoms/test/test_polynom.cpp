// Copyright 2018 Galochkin Boris

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/monom.h"
#include "include/polynom.h"

class PolynomTest : public ::testing::Test {};

TEST_F(PolynomTest, Empty_Poly_Equals_Test) {
    // Arrange
    Polynom p1;
    Polynom p2;

    // Act & Assert
    EXPECT_EQ(p1, p2);
}

TEST_F(PolynomTest, Poly_And_Monom_Def_Cnstrctr_Test) {
    // Arrange
    Polynom p1(1.0);
    Polynom p2;
    Monom m;

    // Act
    p2.AddMonom(m);

    // Assert
    EXPECT_EQ(p1, p2);
}

TEST_F(PolynomTest, Can_Create_With_Int_Coefs) {
    // Arrange
    Polynom p1("2x + 2y");
    Polynom p2("2.0x + 2.0y");

    // Act & Assert
    EXPECT_EQ(p1, p2);
}

TEST_F(PolynomTest, Monom_Clear_Check) {
    // Arrange
    Polynom p1("2x + 2y");
    Polynom p2("2.0x + 2.0y");

    // Act
    Polynom p3 = p1 - p2;

    // Assert
    EXPECT_EQ(p3, Polynom());
}

TEST_F(PolynomTest, Can_Create_By_Summ) {
    // Arrange
    Polynom p("2x + 2y - 3z");
    Polynom p1("2.0x");
    Polynom p2("2.0y");
    Polynom p3("-3z");

    // Act
    Polynom res = p1 + p2 + p3;

    // Assert
    EXPECT_EQ(p, res);
}

TEST_F(PolynomTest, Can_Multiplication_Polynom) {
    // Arrange
    Polynom p1("2.0x");
    Polynom p2("2.0y + 1");

    // Act
    Polynom p = p1 * p2;

    // Assert
    Polynom expected_p("4xy + 2x");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Can_Division_Polynom) {
    // Arrange
    // Arrange
    Polynom p1("2.0x");
    Polynom p2("2.0y + 1");
    Monom m("2x");

    // Act
    Polynom p = p1 * p2 / m;

    // Assert
    Polynom expected_p("2y + 1");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Polynom p("2.0x");
    Monom m(0.0);

    // Act & Assert
    EXPECT_THROW(p/m, std::string);
}

TEST_F(PolynomTest, Can_Correct_Multiple_Operation) {
    // Arrange
    Polynom p1("0.5x");

    // Act
    Polynom p = p1 + p1 - p1 + p1 + p1 * Polynom(4) / Monom();

    // Assert
    Polynom expected_p("3x");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Test_Copy_Constructor) {
    // Arrange
    Polynom p1("0.5x");
    Polynom p2(p1);

    // Act
    Polynom p = p1 + p2;

    // Assert
    Polynom expected_p("x");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Test_String_Constructo_Zero) {
    // Arrange
    Polynom p1("0x");
    Polynom p2("a + b + c + 100d^32");

    // Act
    Polynom p = p1 * p2;

    // Assert
    Polynom expected_p(0);
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Devision_On_Contrary) {
    // Arrange
    Polynom p("x^100");
    Polynom m2("x^-100");
    Monom m1("x^100");

    // Act
    Polynom p1 = p / m1;
    Polynom p2 = p * m2;

    // Assert
    EXPECT_EQ(p1, p2);
}

TEST_F(PolynomTest, Simple_Monom_Qual_Test) {
    // Arrange
    Monom m2("1x^100");
    Monom m1("0.1x^100");

    // Act & Assert
    EXPECT_TRUE(m1 != m2);
}

TEST_F(PolynomTest, Empty_String_Init) {
    // Arrange
    Polynom p("");

    // Assert
    EXPECT_EQ(p, Polynom());
}

TEST_F(PolynomTest, Trash_String_Init) {
    // Arrange
    Polynom p("#@$^!#@#%$^!@%^#!$^%@%#&*^@*!(&#");

    // Assert
    EXPECT_EQ(p, Polynom());
}

TEST_F(PolynomTest, Simple_Pow_Test) {
    // Arrange
    Polynom p1("x^2");
    Polynom p2("5x^10");

    // Act
    Polynom p = p1 * p2;

    // Assert
    Polynom expected_p("5x^12");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, To_String_Test) {
    // Arrange
    Polynom p(std::string("-4a^4b^24c^-4s^8z^8") +
        std::string(" + 8a^2b^12c^-2s^4x^1z^4") +
        std::string(" - 4a^2b^12c^-2s^4z^4"));

    // Act & Assert
    EXPECT_EQ(std::string("(-4a^4b^24c^-4s^8z^8) + (8a^2b^12c^-"
        "2s^4x^1z^4) + (-4a^2b^12c^-2s^4z^4)"), p.ToString());
}

TEST_F(PolynomTest, Copy_Operator_Test) {
    // Arrange
    Polynom p1("x^2");
    Polynom p2 = p1;

    // Act
    Polynom p = p1 * p2;

    // Assert
    Polynom expected_p("x^4");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Not_Equal_Test) {
    // Arrange
    Polynom p1("3x^2");
    Polynom p;

    // Act
    p = p1 * p1;

    // Assert
    EXPECT_TRUE(p != p1);
}

TEST_F(PolynomTest, Not_Equal_Test_Different_Vars_Same_Coff) {
    // Arrange
    Polynom p1("3x^2");
    Polynom p2("3y^2");

    // Act & Assert
    EXPECT_TRUE(p2 != p1);
}

TEST_F(PolynomTest, Not_Equal_Test_Different_Sizes) {
    // Arrange
    Polynom p1("3x^2");
    Polynom p2("3x^2 + 3y");

    // Act & Assert
    EXPECT_FALSE(p2 == p1);
}

TEST_F(PolynomTest, Different_Vars_Division) {
    // Arrange
    Polynom p1("3x^2");
    Monom p2("3y^2");
    // Act
    Polynom p = p1/p2;

    // Assert
    Polynom expected_p("x^2y^-2");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Different_Monoms_Minus) {
    // Arrange
    Polynom p1("3x^2");
    Polynom p2("3y^2");
    // Act
    Polynom p = p1 - p2;

    // Assert
    Polynom expected_p("3x^2 - 3y^2");
    EXPECT_EQ(expected_p, p);
}

TEST_F(PolynomTest, Check_Calculate) {
    // Arrange
    Polynom p1("3x^9");
    Polynom p2("3y^10");
    // Act
    Polynom p = p1 + p2;
    auto vars = p.GetVarsList();
    for (auto& v : vars)
        v.second = 2.0;

    // Assert
    EXPECT_NEAR(p.CalculateResult(vars), 4608.0, 0.00001);
}

TEST_F(PolynomTest, Add_Different_Monom) {
    // Arrange
    Polynom p1("3x^9");
    Monom m("3y^10");
    Polynom p2("3y^10");

    // Act
    Polynom p = p1 + p2;
    p1.AddMonom(m);

    // Assert
    EXPECT_EQ(p, p1);
}


TEST_F(PolynomTest, Add_Same_Monom) {
    // Arrange
    Polynom p1("3x^10");
    Monom m("3x^10");

    // Act
    p1.AddMonom(m);

    // Assert
    Polynom p2("6x^10");
    EXPECT_EQ(p2, p1);
}
