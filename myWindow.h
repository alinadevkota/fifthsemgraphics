#ifndef WINDOW_H_
#define WINDOW_H_

#include<windows.h>
#include<GL/glew.h>
#include<glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<string>
#include "myVectors.h"
#include<iostream>
class myWindow
{
private:
    int height;
    int width;
    //string name;
    int positionx;
    int positiony;
    int ac;
    char **av;
public:
    myWindow(int argc, char ***argv,int h=1000, int w=1000, int px=0, int py=0)
    {
        height=h;
        width=w;
        //name=n;
        positionx=px;
        positiony=py;
        ac=argc;
        av=*argv;

    }
    void show()
    {
        glutInit(&ac, av);
        glutCreateWindow("my window");

        //glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMainLoop();
    }
    static void display(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);  /* blue */
        glVertex2i(0, 0);
        glColor3f(0.0, 1.0, 0.0);  /* green */
        glVertex2i(200, 200);
        glColor3f(1.0, 0.0, 0.0);  /* red */
        glVertex2i(20, 200);
        glEnd();
        glFlush();  /* Single buffered, so needs a flush. */
    }
    static void reshape(int w, int h)
    {
          /* Because Gil specified "screen coordinates" (presumably with an
             upper-left origin), this short bit of code sets up the coordinate
             system to correspond to actual window coodrinates.  This code
             wouldn't be required if you chose a (more typical in 3D) abstract
             coordinate system. */

          glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
          glMatrixMode(GL_PROJECTION);  /* Start modifying the projection matrix. */
          glLoadIdentity();             /* Reset project matrix. */
          glOrtho(0, w, 0, h, -1, 1);   /* Map abstract coords directly to window coords. */
          glScalef(1, -1, 1);           /* Invert Y axis so increasing Y goes down. */
          glTranslatef(0, -h, 0);       /* Shift origin up to upper-left corner. */
    }
    void drawLine(Vec2 v1, Vec2 v2, glm::vec3 color)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        std::cout<<color.x<<"   "<<color.y<<"  "<<color.z<<std::endl;
//        glLineWidth(2.5);
//        glColor3f(1,1,1);
//        glBegin(GL_LINES);
//        glVertex2f(v1.x,v2.y);
//        glVertex2f(v2.x,v2.y);
//        glEnd();
        display();
        std::cout<<"here it comes"<<std::endl;
        glFlush();
    }

};


#endif // WINDOW_H_

