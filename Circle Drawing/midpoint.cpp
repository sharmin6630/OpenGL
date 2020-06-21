#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int r;

void mid_point(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int x = 0, y = (int)r, d = 1 -  r;
    while(x<=y)
    {
        glColor3f(0.5f, 0.0f, 1.0f);
        glBegin(GL_POINTS);
        glVertex2f(y, x);
        glVertex2f(x, y);
        glVertex2f(x, -1.0 * y);
        glVertex2f(y, -1.0 * x);
        glVertex2f(-1.0 * y, -1.0 * x);
        glVertex2f(-1.0 * x, -1.0 * y);
        glVertex2f(-1.0 * x, y);
        glVertex2f(-1.0 * y, x);
        glEnd();

        if(d < 0){
            d += (d + 2 * x + 3);
        }
        else{
            d += (d + 2 *(x - y) + 5);
            --y;
        }
        ++x;
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout << "Radius: ";
    cin >> r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint algorithm");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(mid_point);
    glutMainLoop();
    return 0;
}
