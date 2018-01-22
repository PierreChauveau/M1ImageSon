#include "integrator.h"
#include "scene.h"

class FlatIntegrator : public Integrator {
public:
    FlatIntegrator(const PropertyList &props) {
        /* No parameters this time */
    }

    Color3f Li(const Scene *scene, const Ray &ray) const {
        /** TODO : Find the surface that is visible in the requested direction
                   Return its ambiant color */
        Hit *hit = new Hit();
        Color3f color = scene->backgroundColor();
        scene->intersect(ray, *hit);
        if(hit->shape()){
            color = hit->shape()->material()->ambientColor();
        }
        return color;
    }

    std::string toString() const {
        return "FlatIntegrator[]";
    }
};

REGISTER_CLASS(FlatIntegrator, "flat")
