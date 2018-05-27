// Copyright 2018 Mezina Margarita

#include <gtest/gtest.h>
#include "include/Graph.h"

TEST(Graph, can_create_null_graph) {
    // Act & Assert
    ASSERT_NO_THROW(Graph g);
}

TEST(Graph, can_create_graph_with_matrix) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act & Assert
    ASSERT_NO_THROW(Graph g(2, matrix));
}

TEST(Graph, can_not_create_graph_with_negative_count) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act & Assert
    ASSERT_ANY_THROW(Graph g(-2, matrix));
}

TEST(Graph, can_not_create_graph_with_negative_weight) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = -1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act & Assert
    ASSERT_ANY_THROW(Graph g(2, matrix));
}

TEST(Graph, can_copy_graph) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_NO_THROW(Graph(g));
}

TEST(Graph, can_get_count) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    EXPECT_EQ(g.GetCount(), 2);
}

TEST(Graph, can_get_weight) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    EXPECT_EQ(g.GetWeight(2, 1), 1);
}

TEST(Graph, can_not_get_weight_with_negative_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.GetWeight(-1, 0));
}

TEST(Graph, can_not_get_weight_with_non_existent_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.GetWeight(1, 4));
}

TEST(Graph, can_add_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);
    g.AddVertex();

    // Assert
    EXPECT_EQ(g.GetCount(), 3);
}

TEST(Graph, can_add_edge) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);
    g.AddVertex();
    g.AddEdge(3, 1, 4);

    // Assert
    EXPECT_EQ(g.GetWeight(3, 1), 4);
}

TEST(Graph, can_not_add_edge_with_negative_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.AddEdge(3, -1, 4));
}

TEST(Graph, can_not_add_edge_with_non_exist_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.AddEdge(5, 1, 4));
}

TEST(Graph, can_not_add_edge_with_negative_weight) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.AddEdge(2, 1, -4));
}

TEST(Graph, can_delete_edge) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);
    g.AddVertex();
    g.DeleteEdge(3, 1);

    // Assert
    EXPECT_EQ(g.GetWeight(3, 1), 0);
}

TEST(Graph, can_not_delete_edge_with_negative_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.DeleteEdge(3, -1));
}

TEST(Graph, can_not_delete_edge_with_non_exist_vertex) {
    // Arrange
    double** matrix = new double*[2];
    matrix[0] = new double[2];
    matrix[1] = new double[2];
    matrix[0][0] = 0; matrix[0][1] = 1;
    matrix[1][0] = 1; matrix[1][1] = 0;

    // Act
    Graph g(2, matrix);

    // Assert
    ASSERT_ANY_THROW(g.DeleteEdge(5, 1));
}

TEST(Graph, can_delete_vertex) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);
    g.DeleteVertex(2);

    // Assert
    EXPECT_EQ(g.GetCount(), 2);
    EXPECT_EQ(g.GetWeight(2, 2), 4);
}

TEST(Graph, can_not_delete_negative_vertex) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    ASSERT_ANY_THROW(g.DeleteVertex(0));
}

TEST(Graph, can_not_delete_non_exist_vertex) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    ASSERT_ANY_THROW(g.DeleteVertex(5));
}

TEST(Graph, can_find_distance_throw_edge) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    EXPECT_EQ(g.FindDistance(1, 2), 1);
}

TEST(Graph, can_find_distance_no_throw_edge) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 100; matrix[0][2] = 2;
    matrix[1][0] = 100; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    EXPECT_EQ(g.FindDistance(1, 2), 5);
}

TEST(Graph, can_not_find_distance_with_negative_vertex) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    ASSERT_ANY_THROW(g.FindDistance(0, 2));
}

TEST(Graph, can_not_find_distance_with_non_exist_vertex) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g(3, matrix);

    // Assert
    ASSERT_ANY_THROW(g.FindDistance(1, 7));
}

TEST(Graph, return_true_with_compare_graph) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g1(3, matrix);
    Graph g2(g1);

    // Assert
    ASSERT_TRUE(g1 == g2);
}

TEST(Graph, return_false_with_different_count) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g1(3, matrix);
    Graph g2(2, matrix);

    // Assert
    ASSERT_FALSE(g1 == g2);
}

TEST(Graph, return_false_with_different_weight) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g1(3, matrix);
    matrix[1][0] = 2;
    Graph g2(3, matrix);

    // Assert
    ASSERT_FALSE(g1 == g2);
}

TEST(Graph, can_equate_graphs) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g1(3, matrix);
    Graph g2(2, matrix);

    // Assert
    ASSERT_NO_THROW(g1 = g2);
}

TEST(Graph, can_equate_itself) {
    // Arrange
    double** matrix = new double*[3];
    matrix[0] = new double[3];
    matrix[1] = new double[3];
    matrix[2] = new double[3];
    matrix[0][0] = 0; matrix[0][1] = 1; matrix[0][2] = 2;
    matrix[1][0] = 1; matrix[1][1] = 0; matrix[1][2] = 3;
    matrix[2][0] = 2; matrix[2][1] = 3; matrix[2][2] = 4;

    // Act
    Graph g1(3, matrix);

    // Assert
    ASSERT_NO_THROW(g1 = g1);
}

