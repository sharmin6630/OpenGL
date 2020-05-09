#include <GL/glut.h>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector < pair < int,int > > vt, points;
int n;

inline double round(double x)
{
    return floor(x+0.5);
}

void clipping()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     for(int i = 0 ; i <= 3 ; ++i) {
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_LINES);
            glVertex2d(vt[i].first * 10.0, vt[i].second * 10.0);
            glVertex2d(vt[i+1].first * 10.0, vt[i+1].second * 10.0);
        glEnd();
     }
     for(int i = 0 ; i < n ; ++i) {
        pair < int,int > pt = points[i];
        if(pt.first > min(vt[0].first,vt[2].first) and pt.first < max(vt[0].first,vt[2].first)) {
            if(pt.second > min(vt[0].second,vt[2].second) and  pt.second < max(vt[0].second,vt[2].second)) {
                glPointSize(5.0);
                glColor3f(0.0, 1.0, 0.0);
                glBegin(GL_POINTS);
                    glVertex2d(pt.first * 10.0, pt.second * 10.0);
                glEnd();
            }
        }
     }
     glutSwapBuffers();

}

int main(int argc, char** argv)
{
    cout << "Enter lower left and upper right coordinates of the window: "<<endl;
    vt.resize(4);
    cin >>  vt[0].first >> vt[0].second;
    cin >> vt[2].first >> vt[2].second;
    vt[1] = {vt[0].first, vt[2].second};
    vt[3] = {vt[2].first, vt[0].second};
    vt.push_back(vt[0]);
    cout << "Enter the number of points:"<<endl;
    cin >> n;
    cout << "Enter coordinates of " << n << " points:"<<endl;
    for(int i = 0 ; i < n ; ++i) {
        int x, y;
        cin >> x >> y;
        points.pb({x, y});
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Point Clipping");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(clipping);
    glutMainLoop();
    return 0;
}

/*
1 1
15 15
4
10 20
4 4
25 20
2 3
*/
