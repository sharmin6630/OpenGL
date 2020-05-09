#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

vector < pair < int,int > > poly;
int tx, ty;
int ang;
int sx, sy;
int n;
vector < pair < int,int > > vt;

typedef pair < int,int > pii;

bool cross(pii a, pii b, pii c)
{
    return ((b.first - a.first)*(c.second - a.second) - (b.second - a.second)*(c.first - a.first)) > 0? true : false;
}

void windowDraw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(5.0);
  glColor3f(1.0, 0.0, 0.0);
  for(int i = 0 ; i < vt.size() - 1 ;  ++i) {
    glBegin(GL_LINES);
      glVertex2d(vt[i].first * 10.0, vt[i].second * 10.0);
      glVertex2d(vt[i + 1].first * 10.0, vt[i + 1].second * 10.0);
    glEnd();
  }
  for(int i = 0 ; i < poly.size() ; ++i) {
    int inside = 0;
    for(int j = 0 ; j < vt.size() - 1 ; ++j) {
      if(!cross(vt[j], vt[j + 1], poly[i])) {
        inside++;
      }
      else {
        inside = 0;
        break;
      }
    }
   // inside = 1;
    if(inside) {
      cout << i + 1 <<  " -> Inside\n";
      glBegin(GL_POINTS);
        glVertex2d(10.0 * poly[i].first, 10.0 * poly[i].second);
      glEnd();
    }

  }
  glutSwapBuffers();
}


void polyDraw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(5.0);
  ///glColor3f(1.0, 0.0, 0.0);
  for(int i = 0 ; i < vt.size() - 1 ;  ++i) {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
      glVertex2d(vt[i].first * 10.0, vt[i].second * 10.0);
      glVertex2d(vt[i + 1].first * 10.0, vt[i + 1].second * 10.0);
    glEnd();
  }
  for(int i = 0 ; i < poly.size() ; ++i) {
    int inside = 0;
    for(int j = 0 ; j < vt.size() - 1 ; ++j) {
      if(!cross(vt[j], vt[j + 1], poly[i])) {
        inside++;
      }
      else {
        inside = 0;
        break;
      }
    }
   // inside = 1;
    if(inside) {
     /// cout << i + 1 <<  " -> Inside\n";
      glColor3f(1.0, 0.0, 0.0);
      glBegin(GL_POINTS);
        glVertex2d(10.0 * poly[i].first, 10.0 * poly[i].second);
      glEnd();
    }
    else {
      glColor3f(0.0, 1.0, 0.0);
      glBegin(GL_POINTS);
        glVertex2d(10.0 * poly[i].first, 10.0 * poly[i].second);
      glEnd();
    }

  }
  glutSwapBuffers();
}


int main(int argc, char** argv)
{
    cout << "Enter the vertices of polygon:" <<endl;
    for (int i = 0 ; i < 6;  i++) {
      int x, y;
      cin >> x >> y;
      vt.push_back({x, y});
    }
    vt.push_back(vt[0]);
    cout << "Enter  the total number of points:"<<endl;
    cin >> n;
    cout << "Enter " << n << " Points:"<<endl;
    for(int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      poly.push_back({x, y});
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000, 1000);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Polygon");
    gluOrtho2D(-1000, 1000, -1000, 1000);
    glutDisplayFunc(polyDraw);
    glutMainLoop();
  }
  return 0;
}
