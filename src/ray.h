#pragma once

#include "vector.h"

class Ray
{
public:
    Vector3 origin;
    Vector3 direction;

    Ray(Vector3 origin, Vector3 direction);
    Vector3 across(double distance);
    Vector3 reflect(Vector3 normal);
    bool refract(Vector3 normal, double ior, Vector3 *refractedDirection);
};