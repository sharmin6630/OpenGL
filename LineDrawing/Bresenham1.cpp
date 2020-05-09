#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int x1, y1, x2, y2;

void Bresenham(void)
{
    int dx, dy, px, x, y;
    dx = x2-x1, dy = y2-y1, px = (2*dy)-dx, x = x1, y = y1;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.1, 0.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    int p = px;

    for(int i=0; i<dx; i++){

        if(p<0){
            x++;
            glVertex2d(x, y);
        }

        else{
            x++, y++;
            glVertex2d(x, y);
        }
    }

    glEnd();
    glFlush();
}



int main(int argc, char** argv)
{
    printf("Co-ordinates of first point: ");
    cin >> x1 >> y1;
    printf("Co-ordinates of second point: ");
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham");
    gluOrtho2D(0,640,0,480);
    glutDisplayFunc(Bresenham);
    glutMainLoop();
    return 0;
}
