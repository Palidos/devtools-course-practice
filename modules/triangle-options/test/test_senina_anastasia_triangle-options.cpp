// Copyright 2018 Senina Anastasia

#include <gtest/gtest.h>
#include <math.h>
#include "include/Triangles.h"

TEST(senina_anastasia_triangle_optionsTest, Can_add_Get_Length_Side_first) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);
  Triangles figure(a, b, c);
  double res_cur;
  double res;

  // Act
  res_cur = figure.Get_Length_side(first, second);
  res = 5;

  // Assert
  EXPECT_EQ(res, res_cur);
}

TEST(senina_anastasia_triangle_optionsTest, Can_add_Get_Length_Side_second) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(7, 5);
  Triangles figure(a, b, c);
  double res_cur;
  double res;

  // Act
  res_cur = figure.Get_Length_side(third, second);
  res = 5;

  // Assert
  EXPECT_EQ(res, res_cur);
}

TEST(senina_anastasia_triangle_optionsTest, Can_add_Get_Length_Side_third) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);
  Triangles figure(a, b, c);
  double res_cur;
  double res;
  double eps;

  // Act
  res_cur = figure.Get_Length_side(first, third);
  res = sqrt(29);
  eps = 0.001;

  // Assert
  EXPECT_NEAR(res, res_cur, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Inscribed_Circle) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);
  Triangles figure(a, b, c);
  double res_cur;
  double res;
  double eps = 0.1;

  // Act
  res_cur = figure.Get_Radius_Of_Inscribed_Circle();
  res = 0.5932515918033161;

  // Assert
  EXPECT_NEAR(res, res_cur, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Circumscribed_Circle) {
  // Arrange
  Vertex a(1, 1);
  Vertex b(3, 5);
  Vertex c(5, 4);
  Triangles figure(a, b, c);
  double res_cur;
  double res;
  double eps = 0.01;

  // Act
  res_cur = figure.Get_Radius_Of_Circumscribed_Circle();
  res = 2.5;

  // Assert
  EXPECT_NEAR(res, res_cur, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Square) {
  // Arrange
  Vertex a(1, -1);
  Vertex b(1, -5);
  Vertex c(5, -5);
  Triangles figure(a, b, c);
  double res_cur;
  double res;

  // Act
  res_cur = figure.Get_Square();
  res = 8;

  // Assert
  EXPECT_EQ(res, res_cur);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Perimeter) {
  // Arrange
  Vertex a(1, -1);
  Vertex b(1, -5);
  Vertex c(5, -5);
  Triangles figure(a, b, c);
  double res_cur;
  double res;
  double eps;

  // Act
  res_cur = figure.Get_Perimeter();
  res = 13.65685424;
  eps = 0.001;

  // Assert
  EXPECT_NEAR(res, res_cur, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Barycenter) {
  // Arrange
  Vertex a(1, -1);
  Vertex b(1, -5);
  Vertex c(7, -6);
  Triangles figure(a, b, c);
  Vertex res_cur;
  Vertex res;

  // Act
  res_cur = figure.Get_Barycenter();
  res.x = 3;
  res.y = -4;

  // Assert
  EXPECT_EQ(res.x, res_cur.x);
  EXPECT_EQ(res.y, res_cur.y);
}

TEST(senina_anastasia_triangle_optionsTest,
  Can_Get_Center_Of_Inscribed_Circle) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);
  Triangles figure(a, b, c);
  Vertex res_cur;
  Vertex res(12.026036075473412, 42.291861481294632);
  double eps;

  // Act
  res_cur = figure.Get_Center_Of_Inscribed_Circle();
  eps = 0.01;

  // Assert
  EXPECT_NEAR(res.x, res_cur.x, eps);
  EXPECT_NEAR(res.y, res_cur.y, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Copy_Triangle) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);
  Triangles figure(a, b, c);

  // Act
  Triangles figure2(figure);

  // Assert
  EXPECT_EQ(figure.Get_Vertex(first), figure2.Get_Vertex(first));
  EXPECT_EQ(figure.Get_Vertex(second), figure2.Get_Vertex(second));
  EXPECT_EQ(figure.Get_Vertex(third), figure2.Get_Vertex(third));
}

TEST(senina_anastasia_triangle_optionsTest,
  Throw_When_Try_Get_Length_Same_Vertexes) {
  // Arrange
  Vertex a(1, 5);
  Vertex b(4, 9);
  Vertex c(3, 10);

  // Act
  Triangles figure(a, b, c);

  // Assert
  ASSERT_ANY_THROW(figure.Get_Length_side(first, first));
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Angle_Of_Triangle_) {
  // Arrange
  Vertex a;
  Vertex b(6, 0);
  Vertex c(0, 5);
  double angle;
  double res;
  double eps;
  Triangles figure(a, b, c);

  // Act
  a.x = 0;
  a.y = 0;
  angle = PI / 2;
  res = figure.Get_Angle(first);
  eps = 0.001;

  // Assert
  EXPECT_NEAR(res, angle, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Can_Get_Obtuse_Angle) {
  // Arrange
  Vertex a;
  Vertex b(3, 0);
  Vertex c(-2, 2);
  double angle;
  double res;
  double eps;
  Triangles figure(a, b, c);

  // Act
  a.x = 0;
  a.y = 0;
  angle = PI / 4 + PI / 2;
  res = figure.Get_Angle(first);
  eps = 0.001;

  // Assert
  EXPECT_NEAR(res, angle, eps);
}

TEST(senina_anastasia_triangle_optionsTest, Throw_When_Uncorrected_points) {
  // Arrange
  Vertex a(2, 4);
  Vertex b(6, 2);
  Vertex c(4, 3);

  // Act & Assert
  ASSERT_ANY_THROW(Triangles(a, b, c));
}


