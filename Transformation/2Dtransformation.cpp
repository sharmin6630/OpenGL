#include <GL/glut.h>
#include <bits/stdc++.h>
#define PI 3.14159265

using namespace std;

vector < pair < int,int > > vt;
int tx, ty;
double theta;
int sx, sy;

void translation(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vt.push_back({vt[0]});
    for(int i = 0 ; i < vt.size() - 1  ; ++i)
    {
        glPointSize(5.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 1.0, vt[i].second * 1.0);
            glVertex2d(vt[i + 1].first * 1.0, vt[i + 1].second * 1.0);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(1.0 * (vt[i].first + tx), 1.0 * (vt[i].second + ty));
            glVertex2d(1.0 * (vt[i + 1].first + tx), 1.0 * (vt[i + 1].second + ty));
        glEnd();
    }
    glutSwapBuffers();
}

void rotation(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vt.push_back({vt[0]});
    for(int i = 0 ; i < vt.size() - 1  ; ++i)
    {
        glPointSize(5.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 1.0, vt[i].second * 1.0);
            glVertex2d(vt[i + 1].first * 1.0, vt[i + 1].second * 1.0);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        double xx1 = vt[i].first * cos(theta) - vt[i].second * sin(theta);
        double yy1 = vt[i].first * sin(theta) + vt[i].second * cos(theta);
        double xx2 = vt[i+1].first * cos(theta) - vt[i+1].second * sin(theta);
        double yy2 = vt[i+1].first * sin(theta) + vt[i+1].second * cos(theta);
        glBegin(GL_LINES);
            glVertex2d((1.0 * xx1), (1.0 * yy1));
            glVertex2d((1.0 * xx2), (1.0 * yy2));
        glEnd();
    }
    glutSwapBuffers();
}


void scale(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vt.push_back({vt[0]});
    for(int i = 0 ; i < vt.size() - 1  ; ++i)
    {
        glPointSize(5.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 1.0, vt[i].second * 1.0);
            glVertex2d(vt[i + 1].first * 1.0, vt[i + 1].second * 1.0);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(1.0 * (vt[i].first * sx), 1.0 * (vt[i].second * sy));
            glVertex2d(1.0 * (vt[i + 1].first * sx), 1.0 * (vt[i + 1].second * sy));
        glEnd();
    }
    glutSwapBuffers();
}

void mirrorX(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vt.push_back({vt[0]});
    for(int i = 0 ; i < vt.size() - 1  ; ++i)
    {
        glPointSize(5.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 1.0, vt[i].second * 1.0);
            glVertex2d(vt[i + 1].first * 1.0, vt[i + 1].second * 1.0);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(-1.0 * (vt[i].first), 1.0 * (vt[i].second ));
            glVertex2d(-1.0 * (vt[i + 1].first), 1.0 * (vt[i + 1].second));
        glEnd();
    }
    glutSwapBuffers();
}

void mirrorY(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    vt.push_back({vt[0]});
    for(int i = 0 ; i < vt.size() - 1  ; ++i)
    {
        glPointSize(5.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 1.0, vt[i].second * 1.0);
            glVertex2d(vt[i + 1].first * 1.0, vt[i + 1].second * 1.0);
        glEnd();
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(1.0 * (vt[i].first), -1.0 * (vt[i].second ));
            glVertex2d(1.0 * (vt[i + 1].first), -1.0 * (vt[i + 1].second));
        glEnd();
    }
    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    int type;
    cout << "Enter coordinates of the polygon vertices:"<<endl;
    for(int i = 1 ; i <= 4 ; ++i) {
        int x, y;
        cin >> x >> y;
        vt.push_back({x, y});
    }
    cout << "Enter\n 1 for translation\n 2 for rotation\n 3 for scaling\n 4 for mirroring" <<endl;
    cin >> type;
    if(type == 1)
    {
        cout << "Translation:\n Enter tx and ty:"<<endl;
        cin >> tx >> ty;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(600, 600);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("2D transformation");
        gluOrtho2D(-600, 600, -600, 600);
        glutDisplayFunc(translation);
        glutMainLoop();
        return 0;

    }
    else if(type == 2)
    {
        cout << "Rotation:\nEnter angle :" << endl;
        cin >> theta;
        theta = (theta * PI) / 180;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(600, 600);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("2D transformation");
        gluOrtho2D(-600, 600, -600, 600);;
        glutDisplayFunc(rotation);
        glutMainLoop();
    }
    else if(type == 3)
    {
        cout << "Scaling:\nEnter Sx and Sy:" << endl;
        cin >> sx >> sy;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE);
        glutInitWindowSize(600, 600);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("2D transformation");
        gluOrtho2D(-600, 600, -600, 600);;
        glutDisplayFunc(scale);
        glutMainLoop();
    }
    else
    {
        cout << "Mirroring" << endl;
        cout << "Enter option:\n 1 for mirroring with respect to X - axis\n 2 for mirroring with respect to Y - axis:" << endl;
        int opt;
        cin >> opt;
        if(opt == 1) {

            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE);
            glutInitWindowSize(600, 600);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("2D transformation");
            gluOrtho2D(-600, 600, -600, 600);
            glutDisplayFunc(mirrorX);
            glutMainLoop();
        }
        else {
            glutInit(&argc, argv);
            glutInitDisplayMode(GLUT_SINGLE);
            glutInitWindowSize(600, 600);
            glutInitWindowPosition(100, 100);
            glutCreateWindow("2D transformation");
            gluOrtho2D(-600, 600, -600, 600);
            glutDisplayFunc(mirrorY);
            glutMainLoop();
        }
    }
    return 0;
}

/*
1 1
1 200
200 200
200 1

*/

