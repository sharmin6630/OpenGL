#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

double x1, y1, x2, y2;

void DDA(void)
{
    double dx, dy, m;
    dx = (x2-x1), dy = (y2-y1);

    float xi, yi, x, y;
    x = x1, y = y1;

    if(abs(dx)>abs(dy))
        m = abs(dx);
    else
        m = abs(dy);

    xi = dx/(float)m, yi = dy/(float)m;


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);

    for(int i=0; i<m; i++){
        x+= xi;
        y+= yi;
        glVertex2d(round(x), round(y));
    }

    glEnd();
    glFlush();
}

float round(float r)
{
    return floor(r + 0.5);
}


int main(int argc, char** argv)
{
    printf("Co-ordinates of first point: ");
    cin >> x1 >> y1;
    printf("Co-ordinates of first point: ");
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA");
    gluOrtho2D(0, 640, 0, 480);
    glutDisplayFunc(DDA);
    glutMainLoop();
}
