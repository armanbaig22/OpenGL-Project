#include "render.h"
#define  PI 3.1415926535897932

void render::triangle(float a[3], float b[3], float c[3]) {
    glBegin(GL_TRIANGLES);
    //glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(a[0], a[1], a[2]);

    //glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(b[0], b[1], b[2]);

    //glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(c[0], c[1], c[2]);

    glEnd();
}

render obj;

void render::circle(float c[3], float radius, int sections) {
    float a[3];
    float b[3] = { c[0], c[1]-radius, 0.0};
    float angle = (2*PI)/sections;

    for(int i=0;i<=sections;i++){
        
        float sn = sin(angle * i);
        float cs = cos(angle * i);
        //second vertex of old triangle is the first vertex of new triangle
        a[0] = b[0], a[1] = b[1], a[2] = b[2];
        //rotating the vertex of traingle to next position
        b[0] = c[0] + radius * sn;
        b[1] = c[1] - radius * cs;
        b[2] = 0.0;


        //calling triangle draw function
        obj.triangle(a, b, c);
    }
    
}
