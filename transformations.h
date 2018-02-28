#ifndef transformations_H_
#define transformations_H_
#include<glm/glm.hpp>
#include "myVectors.h"

Vec2 World_To_Pixel(const glm::vec3& source ,          //World pofloat to convert floato pixel pofloat
                        const glm::vec3& camera,       //Point from where you are watching
                        const glm::vec3& LookTo,       //Where are we looking at from the camera pos
                        float planeWidth,         //width of the perspective plane
                        float planeHeight,        //height of the perspectice plane
                        float winWidth,           //width of the screen window
                        float winHeight);         //height of the screen window




#endif // transformations_H_
