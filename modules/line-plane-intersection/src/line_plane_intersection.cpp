// Copyright 2018 Kulikova Svetlana

#include "include/line_plane_intersection.h"

LinePlaneIntersection::LinePlaneIntersection() :
    NotIntersectPlaneLine(true) {}

Dot LinePlaneIntersection::CreateVector(Dot A, Dot B) {
    Dot CreateVector;

    CreateVector.x = B.x - A.x;
    CreateVector.y = B.y - A.y;
    CreateVector.z = B.z - A.z;

    return CreateVector;
}

Dot LinePlaneIntersection::VectorProduct(Dot A, Dot B) {
    Dot VP;

    VP.x = A.y * B.z - B.y * A.z;
    VP.y = A.z * B.x - B.z * A.x;
    VP.z = A.x * B.y - B.x * A.y;

    return VP;
}

double LinePlaneIntersection::DotProduct(Dot A, Dot B) {
    double SP;

    SP = A.x * B.x + A.y * B.y + A.z * B.z;

    return SP;
}

void LinePlaneIntersection::Normalize(Dot A) {
    double mlr;

    mlr = sqrt(A.x * A.x + A.y * A.y + A.z * A.z);
    A.x = A.x / mlr;
    A.y = A.y / mlr;
    A.z = A.z / mlr;
}

bool LinePlaneIntersection::IncorrectLine(Dot A, Dot B) {
    if (A.x == B.x && A.y == B.y && A.z == B.z)
        return true;
    return false;
}

bool LinePlaneIntersection::IncorrectPlane(Dot A, Dot B, Dot C) {
    if (A.x == B.x && A.y == B.y && A.z == B.z)
        return true;
    if (A.x == C.x && A.y == C.y && A.z == C.z)
        return true;
    if (C.x == B.x && C.y == B.y && C.z == B.z)
        return true;
    return false;
}

Dot LinePlaneIntersection::PlaneIntersectLine(Dot A,
    Dot B, Dot C, Dot X, Dot Y) {
    Dot N, V, W, PlaneIntersectLine = { 0, 0, 0 };
    double e, d;

    NotIntersectPlaneLine = true;

    if (IncorrectLine(X, Y))
        throw "Incorrect Line";

    if (IncorrectPlane(A, B, C))
        throw "Incorrect Plane";

    N = VectorProduct(CreateVector(A, B), CreateVector(A, C));
    Normalize(N);
    V = CreateVector(X, A);
    d = DotProduct(N, V);
    W = CreateVector(X, Y);
    e = DotProduct(N, W);

    if (e != 0) {
        PlaneIntersectLine.x = X.x + W.x * d / e;
        PlaneIntersectLine.y = X.y + W.y * d / e;
        PlaneIntersectLine.z = X.z + W.z * d / e;
        NotIntersectPlaneLine = false;
    }

    return PlaneIntersectLine;
}

bool LinePlaneIntersection::GetNotIntersectPlaneLine() {
    return NotIntersectPlaneLine;
}
