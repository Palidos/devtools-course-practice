// Copyright 2018 Okunev Boris

#include <algorithm>
#include <sstream>
#include <vector>
#include <string>

#include "include/integer_numerical_interval.h"

IntegerNumericalInterval::IntegerNumericalInterval() {
    leftBorder_ = 0;
    rightBorder_ = 0;
    isIncludeLeft_ = true;
    isIncludeRight_ = true;
}

IntegerNumericalInterval::IntegerNumericalInterval(const int leftBorder, const
    int rightBorder, const bool isIncludeLeft, const bool isIncludeRight) {

    if (!this->isInitializationCorrect(leftBorder, rightBorder, isIncludeLeft,
        isIncludeRight))
        throw("Invalid interval");
    leftBorder_ = leftBorder;
    rightBorder_ = rightBorder;
    isIncludeLeft_ = isIncludeLeft;
    isIncludeRight_ = isIncludeRight;
}

IntegerNumericalInterval::IntegerNumericalInterval(const std::string &
    interval) {
    std::stringstream ss(interval);
    char chF;
    char comma;
    char chS;
    ss >> chF >> leftBorder_ >> comma >> rightBorder_ >> chS;

    if (chF == '[') {
        isIncludeLeft_ = true;
    } else {
        if (chF == '(')
            isIncludeLeft_ = false;
        else
            throw("Wrong interval");
    }

    if (comma != ',')
        throw("Wrong interval");

    if (chS == ']') {
        isIncludeRight_ = true;
    } else {
        if (chS == ')')
            isIncludeRight_ = false;
        else
            throw("Wrong interval");
    }

    if (!isInitializationCorrect(leftBorder_, rightBorder_,
        isIncludeLeft_, isIncludeRight_))
        throw("Wrong interval");
}

IntegerNumericalInterval::IntegerNumericalInterval(const
    IntegerNumericalInterval & ni) {

    leftBorder_ = ni.leftBorder_;
    rightBorder_ = ni.rightBorder_;
    isIncludeLeft_ = ni.isIncludeLeft_;
    isIncludeRight_ = ni.isIncludeRight_;
}

bool IntegerNumericalInterval::isContainPoints(const vector<int>& points)
    const {
    vector<int> endPoints = getEndPoints();
    int begin = endPoints[0];
    int end = endPoints[1];
    int size = points.size();

    for (int i = 0; i < size; ++i)
        if (points[i] < begin || points[i] > end)
            return false;

    return true;
}

bool IntegerNumericalInterval::isHaveOverlapsRange(
    const IntegerNumericalInterval & ni) const {

    vector<int> endPoints = getEndPoints();
    vector<int> endPointsNI = ni.getEndPoints();
    if ((endPointsNI[0] >= endPoints[0] && endPointsNI[0] <= endPoints[1]) ||
        (endPointsNI[1] >= endPoints[0] && endPointsNI[1] <= endPoints[1]) ||
        (endPointsNI[0] <= endPoints[0] && endPointsNI[1] >= endPoints[1]))
        return true;
    return false;
}

bool IntegerNumericalInterval::isContainsRange(
    const IntegerNumericalInterval & ni) const {
    vector<int> endPoints = getEndPoints();
    vector<int> endPointsNI = ni.getEndPoints();
    if (endPointsNI[0] >= endPoints[0] && endPointsNI[1] <= endPoints[1])
        return true;
    else
        return false;
}

vector<int> IntegerNumericalInterval::getAllPoints() const {
    vector<int> endPoints = getEndPoints();
    int size = endPoints[1] - endPoints[0] + 1;
    vector<int> points(size);

    int num = endPoints[0];
    for (int i = 0; i < size; ++i)
        points[i] = num++;
    return points;
}

vector<int> IntegerNumericalInterval::getEndPoints() const {
    vector<int> points(2);
    isIncludeLeft_ ? points[0] = leftBorder_ : points[0] = leftBorder_ + 1;
    isIncludeRight_ ? points[1] = rightBorder_ : points[1] = rightBorder_ - 1;
    return points;
}

bool IntegerNumericalInterval::operator==(
    const IntegerNumericalInterval & ni) const {
    if ((leftBorder_ == ni.leftBorder_) && (rightBorder_ == ni.rightBorder_)
        && (isIncludeLeft_ == ni.isIncludeLeft_)
        && (isIncludeRight_ == ni.isIncludeRight_))
        return true;
    else
        return false;
}

bool IntegerNumericalInterval::operator!=(
    const IntegerNumericalInterval & ni) const {
    return !(*this == ni);
}

IntegerNumericalInterval::operator std::string() {
    std::string out;
    isIncludeLeft_ ? out += '[' : out += '(';
    out += std::to_string(leftBorder_);
    out += ',';
    out += std::to_string(rightBorder_);
    isIncludeRight_ ? out += ']' : out += ')';
    return out;
}

bool IntegerNumericalInterval::isInitializationCorrect(const int leftBorder,
    const int rightBorder, const bool isIncludeLeft,
    const bool isIncludeRight) const {

    if (rightBorder < leftBorder)
        return false;
    if (rightBorder == leftBorder && (!isIncludeLeft || !isIncludeRight))
        return false;
    if ((rightBorder - leftBorder == 1) && !isIncludeLeft && !isIncludeRight)
        return false;
    return true;
}
