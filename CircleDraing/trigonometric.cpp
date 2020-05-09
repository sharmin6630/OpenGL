#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
int r;

inline double round(double x)
{
    return floor(x+0.5);
}

void trigonometric(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    for(double i = 90.0 ; i >= 45.0  ; i -= 0.02)
    {
        double x = 1.0 * r * cos(i), y = 1.0 * r * sin(i);
        glColor3f(0.5f, 0.0f, 1.0f);
        glBegin(GL_POINTS);
        glVertex2f(round(y), round(x));
        glVertex2f(round(x), round(y));
        glVertex2f(round(x), round(-1.0 * y));
        glVertex2f(round(y), round(-1.0 * x));
        glVertex2f(round(-1.0 * y), round(-1.0 * x));
        glVertex2f(round(-1.0 * x), round(-1.0 * y));
        glVertex2f(round(-1.0 * x), round(y));
        glVertex2f(round(-1.0 * y), round(x));
        glEnd();
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
    glutCreateWindow("Trigonometric algorithm");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(trigonometric);
    glutMainLoop();
    return 0;
}
