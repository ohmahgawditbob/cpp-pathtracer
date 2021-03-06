#include <iostream>
#include "scene.h"
#include "object.h"

Scene::Scene() {}

void Scene::setSkybox(Skybox *skybox)
{
    this->skybox = skybox;
}

void Scene::addObject(std::unique_ptr<Object> object)
{
    objects.emplace_back(std::move(object));
}

Intersection Scene::castRay(Ray ray)
{
    Object *object = nullptr;
    double closestDistance = -1;

    for (int i = 0, l = objects.size(); i < l; i++)
    {
        double dist = objects[i].get()->calculateIntersection(ray);

        if (dist >= 0 && (dist < closestDistance || closestDistance < 0))
        {
            closestDistance = dist;
            object = objects[i].get();
        }
    }

    return Intersection(closestDistance > -1, closestDistance, ray.across(closestDistance), object);
}