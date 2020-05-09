#include <GL/glut.h>
#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int x1, y1, x2, y2;
set <pii> mark;

void flood(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pii A = {x1, y1};
    pii B = {x1, y2};
    pii C = {x2, y2};
    pii D = {x2, y1};

    for(int i = A.first; i <= D.first; i++){
        glBegin(GL_POINTS);
        mark.insert({i, A.second});
        glVertex2f(1.0 * i, A.second * 1);
        glEnd();
    }

    for(int i = B.second; i < A.second; i++){
        glBegin(GL_POINTS);
        mark.insert({A.first, i});
        glVertex2f(1.0 * A.first, 1.0 * i);
        glEnd();
    }

    for(int i = B.first + 1; i <= C.first; i++){
        glBegin(GL_POINTS);
        mark.insert({i, B.second});
        glVertex2f(i * 1.0, 1.0 * B.second);
        glEnd();
    }

    for(int i = C.second + 1; i < D.second; i++){
        glBegin(GL_POINTS);
        mark.insert({C.first, i});
        glVertex2f(1.0 * C.first, 1.0 * i);
        glEnd();
    }

    queue <pii> qu;
    int x = (int)(round(1.0 * (x1 + x2) / 2.0));
    int y = (int)(round(1.0 * (y1 + y2) / 2.0));
    qu.push({x, y});
    mark.insert({x, y});
    glBegin(GL_POINTS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(1.0 * x, 1.0 * y);
    glEnd();

    while(!qu.empty()){
        auto prev = qu.front();
        qu.pop();
        for(int  i = 0; i < 8; ++i){
            int next_f = prev.first + dx[i];
            int next_s = prev.second + dy[i];
            if(!mark.count({next_f, next_s})){
                mark.insert({next_f, next_s});
                glBegin(GL_POINTS);
                glColor3f(0.0, 1.0, 0.0);
                glVertex2f(1.0 * next_f, 1.0 * next_s);
                glEnd();
                qu.push({next_f, next_s});
            }
        }
    }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout << "Upper-left corner of the rectangle: ";
    cin >> x1 >> y1;
    cout << "Lower-right corner of the rectangle: ";
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Rectangle with Flood filling");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(flood);
    glutMainLoop();
    return 0;
}
