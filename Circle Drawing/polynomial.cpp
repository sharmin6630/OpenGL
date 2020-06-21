#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

int r;

inline double round(double x)
{
    return floor(x+0.5);
}

void polynomial(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    double mx = r / sqrt(2.0);
    for(double x = 0.0 ; x <= mx ; x += 0.1)
    {
        double y = sqrt(r * r - x * x);
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
    glutCreateWindow("Polynomial algorithm");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(polynomial);
    glutMainLoop();
    return 0;
}
