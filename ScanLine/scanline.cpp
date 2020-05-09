#include <GL/glut.h>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
const double inf = 1000000000.0;

struct edge
{
    double ymax, ymin, inversem, x;
};

vector < edge > edges;
vector < pair < double, double > > points;

double minvs;

bool inslope(pair < double, double > st, pair < double, double > en)
{
    if(st.second == en.second)
    {
        return false;
    }
    minvs = (st.first - en.first) / (st.second - en.second);
    return true;
}

bool comp(pair < int,int > &fs, pair < int,int > &ss)
{
    return fs.first < ss.first;
}

void scanline(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    double ylow = 100000000.0, yup = 0.0;
    for(int i = 0 ; i < (int)edges.size() ; ++i) {
        ylow = min(ylow, edges[i].ymin);
        yup = max(yup, edges[i].ymax);
    }
    int l = (int)(ylow), r = (int)(yup);
    for(int y = l ; y <= r ; ++y) {
        vector < pair < int,int > > on;
        for(int i = 0 ; i < edges.size() ; ++i) {
            if(y > (int)(edges[i].ymin) and y <= (int)(edges[i].ymax)) {
                if(edges[i].inversem == inf) {
                    on.pb({(int)edges[i].x, y});
                }
                else {
                    int x = (int)((edges[i].inversem * (y - edges[i].ymin)) + edges[i].x);
                    on.pb({x, y});
                }
            }
        }
        sort(on.begin(),on.end(),comp);
        for(int i = 0 ; i < on.size() ; i += 2) {
            if(i + 1 == on.size()) {
                break;
            }
            for(int p = on[i].first ; p <= on[i + 1].first ; ++p) {
                glBegin(GL_POINTS);
                glColor3f(0.0, 1.0, 0.0);
                glVertex2f(1.0 * p, 1.0 * on[i].second);
                glEnd();
            }
        }
    }
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    cout << "Enter the total number of points:" << endl;
    cin >> n;
    double x, y;
    cout << "Enter points: " << endl;
    for(int i = 1 ; i <= n; ++i) {
        cin >> x >> y;
        x *= 10.0;
        y *= 10.0;
        points.pb({x, y});
    }
    points.pb(points[0]);
    for(int i = 0 ; i < n ; ++i) {
        pair < double, double > st = points[i];
        pair < double, double > en = points[i + 1];
        double ymax = max(st.second, en.second);
        double ymin = min(st.second, en.second);
        bool flag = inslope(st, en);
        if(!flag) {
            minvs = inf;
        }
        double xmin = 0.0;
        if(st.second < en.second) {
            xmin = st.first;
        }
        else {
            xmin =  en.first;
        }
        edges.pb({ymax, ymin, minvs, xmin});
    }

    for(int i = 0 ; i < n ; ++i) {
        edge st = edges[i];
        edge en = edges[i + 1];
        if(st.inversem == inf) {
            continue;
        }
        if(st.ymax == en.ymax) {
            edges[i].ymax--;
            continue;
        }
        if(st.ymin == en.ymin) {
            edges[i].ymin++;
        }
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("ScanLine algorithm");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(scanline);
    glutMainLoop();
    return 0;
}

/*
5
10 40
5 20
40 10
50 30
40 50
*/
