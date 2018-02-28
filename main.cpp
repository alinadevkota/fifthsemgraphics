#include "myWindow.h"
#include "Object3d.h"

glm::vec3 camera(-10,0,-40);
//Vec3 fcamera(-5,0,-80);
int color = 1;
int wireframe = 0;
float intensity = 1;
int lightsource = 5;
glm::vec3 LookTo(0,0,0);
vector<glm::vec3> Lightposition1;
int main(int argc, char **argv)
{
    myWindow win(argc,&argv);
    Object3d model(0,0);
    model.loadObject("E:/graphics_cloned_projects/myprojects/myplant/objects/chasma3.obj");
    Lightposition1.push_back(glm::vec3(0,0,400));

    win.show();
    model.render(&win,camera,LookTo,Lightposition1,0.5,0.5,color,intensity);

    return 0;             /* ANSI C requires main to return int. */
}
