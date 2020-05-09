#include <GL/glut.h>
#include <bits/stdc++.h>
#define pdd pair<double, double>
#define pii pair<int, int>
#define pb push_back
using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
int x, y, r;
set <pii> mark;

bool check(pii &prev)
{
    return (prev.first * prev.first + prev.second * prev.second < r * r);
}

vector < pdd > sym(double x, double y)
{
    vector < pdd > pix;
    pix.pb({y, x});
    pix.pb({x, y});
    pix.pb({x, -1.0 * y});
    pix.pb({y, -1.0 * x});
    pix.pb({-1.0 * y, -1.0 * x});
    pix.pb({-1.0 * x, -1.0 * y});
    pix.pb({-1.0 * x, y});
    pix.pb({-1.0 * y, x});
    return pix;
}

void BresCircle(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    x = 0, y = r;
    int d =  3 - (2 * r);
    auto z = sym(x, y);
    for(auto i : z){
        glBegin(GL_POINTS);
        glColor3f(0.5f, 0.0f, 1.0f);
        glVertex2f(1.0 * i.first, 1.0 * i.second);
        mark.insert({(int)(i.first), (int)(i.second)});
        glEnd();
    }
    while(x<=y){
        if(d < 0){
            d += (d + 4 * x + 6);
        }
        else{
            d += (d + 4 *(x - y) + 10);
            --y;
        }
        ++x;
        z = sym(x, y);
        for(auto i : z){
            glBegin(GL_POINTS);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex2f(1.0 * i.first, 1.0 * i.second);
            mark.insert({(int)(i.first), (int)(i.second)});
            glEnd();
        }
    }

    queue < pii > Q;
    Q.push({0, 0});
    mark.insert({0, 0});
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();
    while(!Q.empty()){
        auto prev = Q.front();
        Q.pop();
        for(int i = 0 ; i < 8 ; ++i){
            int next_f = prev.first + dx[i], next_s = prev.second + dy[i];
            pii now = {next_f, next_s};
            if(check(now)){
                if(mark.count({next_f, next_s}) == false){
                    mark.insert({next_f, next_s});
                    Q.push({next_f, next_s});
                    glColor3f(0.0, 1.0, 0.0);
                    glBegin(GL_POINTS);
                    glVertex2f(next_f, next_s);
                    glEnd();
                }
            }
        }
    }
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout << "Radius of the circle: ";
    cin >> r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Circle using Flood Fill");
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glutDisplayFunc(BresCircle);
    glutMainLoop();
    return 0;
}
