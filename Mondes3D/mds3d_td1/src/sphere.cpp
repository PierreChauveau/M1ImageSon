#include "sphere.h"
#include <iostream>

Sphere::Sphere(float radius)
    : m_radius(radius)
{
}

Sphere::Sphere(const PropertyList &propList)
{
    m_radius = propList.getFloat("radius",1.f);
    m_center = propList.getPoint("center",Point3f(0,0,0));
}

Sphere::~Sphere()
{
}

bool Sphere::intersect(const Ray& ray, Hit& hit) const
{
    /// TODO: compute ray-sphere intersection
    float a = ray.direction.dot(ray.direction);
    float b = 2 * ray.direction.dot(ray.origin - this->m_center);
    Vector3f tmp = ray.origin - this->m_center;
    float c = tmp.dot(tmp) - this->m_radius*this->m_radius;

    float delta = b * b - 4 * a * c;
    if(delta >= 0){
        float x1 = (-b - sqrt(delta))/ (2* a);
        float x2 = (-b + sqrt(delta))/ (2* a);
        printf("ici");
        if(x1 >= 0 && (x2 < 0 || x1 <= x2)){
            hit.setT(x1);
            hit.setShape(this);
            return true;
        }
        else if(x2 >= 0 && (x1 < 0 || x2 <= x1)){
            hit.setT(x2);
            hit.setShape(this);
            return true;
        }
    }
    return false;
}

REGISTER_CLASS(Sphere, "sphere")
