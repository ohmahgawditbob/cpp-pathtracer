#pragma once

#include "vector.h"
#include "object.h"

class Intersection
{
public:
    bool hit;
    double distance;
    Vector3 collisionPoint;
    Object *object = nullptr;

    Intersection(bool hit, double distance, Vector3 collisionPoint, Object *object);
};