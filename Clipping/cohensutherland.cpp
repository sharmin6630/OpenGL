#include <GL/glut.h>
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector < pair < int,int > > vt;
int n;

struct edge {
    int x1, y1, x2, y2;
    string position = "";
};
double xmin, xmax, ymin, ymax;
edge edges[100];

string pointsClip(int x, int y)
{
    string code = "0000";
    if(y > ymax) code[0] = '1';
    if(y < ymin) code[1] = '1';
    if(x > xmax) code[2] = '1';
    if(x < xmin) code[3] = '1';
    return code;
}

bool bitwise_and(string first_point, string second_point)
{
    string rescode = "0000";
    for (int i = 0; i < 4; i++) {
        if (first_point[i] == '1' && second_point[i] == '1')
            rescode[i] = '1';
    }
    //cout << rescode << endl;
    if (rescode == "0000") return true;
    else return false;
}

void linesClip(int i)
{
    int x = 0, y = 0;
    string code = pointsClip(edges[i].x1, edges[i].y1);
    cout << "initial codes of first " << code << endl;
    double m = ((edges[i].y2 - edges[i].y1) / (edges[i].x2 - edges[i].x1));
    if (code[0] == '1') {
        x = edges[i].x1 + ((ymax - edges[i].y1) / m );

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(x * 10.0,ymax* 10.0);
            glVertex2d(edges[i].x1* 10.0, edges[i].y1* 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x1 = x;
        edges[i].y1 = ymax;

        cout << edges[i].x1 << " " << edges[i].y1 << endl;
    }

    if (code[1] == '1') {

        x = edges[i].x1 +((ymin - edges[i].y1) / m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(x* 10.0, ymin* 10.0);
            glVertex2d(edges[i].x1* 10.0, edges[i].y1* 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x1 = x;
        edges[i].y1 = ymin;

        cout << edges[i].x1 << " " << edges[i].y1 << endl;
    }

    if (code[2] == '1') {

        y = edges[i].y1 +((xmax - edges[i].x1) * m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(xmax * 10.0, y * 10.0);
            glVertex2d(edges[i].x1 * 10.0, edges[i].y1 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x1 = xmax;
        edges[i].y1 = y;

        cout << edges[i].x1 << " " << edges[i].y1 << endl;
    }

    if (code[3] == '1') {

        y = edges[i].y1 +((xmin - edges[i].x1) * m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(xmin * 10.0,y * 10.0);
            glVertex2d(edges[i].x1 * 10.0,edges[i].y1 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x1 = xmin;
        edges[i].y1 = y;

        cout << edges[i].x1 << " " << edges[i].y1 << endl;
    }

    code = pointsClip(edges[i].x1, edges[i].y1);
    cout << "final code of first: " << code << endl;

    x = 0; y = 0;
    code = pointsClip(edges[i].x2, edges[i].y2);
    cout << "initial code of second: " << code << endl;

    if (code[0] == '1') {

        x = edges[i].x2 + ((ymax - edges[i].y2) / m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(x * 10.0,ymax * 10.0);
            glVertex2d(edges[i].x2 * 10.0,edges[i].y2 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x2 = x;
        edges[i].y2 = ymax;

        cout << edges[i].x2 << " " << edges[i].y2 << endl;
    }
    code = pointsClip(edges[i].x2, edges[i].y2);
    if (code[1] == '1') {

        x = edges[i].x2 +((ymin - edges[i].y2) / m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(x * 10.0,ymin * 10.0);
            glVertex2d(edges[i].x2 * 10.0,edges[i].y2 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x2 = x;
        edges[i].y2 = ymin;

        cout << edges[i].x2 << " " << edges[i].y2 << endl;
    }
    code = pointsClip(edges[i].x2, edges[i].y2);
    if (code[2] == '1') {

        y = edges[i].y2 +((xmax - edges[i].x2) * m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(xmax * 10.0,y * 10.0);
            glVertex2d(edges[i].x2 * 10.0,edges[i].y2 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x2 = xmax;
        edges[i].y2 = y;

        cout << edges[i].x2 << " " << edges[i].y2 << endl;
    }
    code = pointsClip(edges[i].x2, edges[i].y2);
    if (code[3] == '1') {

        y = edges[i].y2 +((xmin - edges[i].x2) * m);

        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_LINES);
            glVertex2d(xmin * 10.0,y * 10.0);
            glVertex2d(edges[i].x2 * 10.0,edges[i].y2 * 10.0);
        glEnd();
        glutSwapBuffers();

        edges[i].x2 = xmin;
        edges[i].y2 = y;

        cout << edges[i].x2 << " " << edges[i].y2 << endl;
    }

    code = pointsClip(edges[i].x2, edges[i].y2);
    cout << "final code of second: " << code << endl;
}

string check_points() {

    for (int i = 0; i < n; i++) {

        string first_point = pointsClip(edges[i].x1, edges[i].y1);
        string second_point = pointsClip(edges[i].x2, edges[i].y2);

        if (first_point == "0000" && second_point == "0000")
            edges[i].position = "inside";
        else if (!bitwise_and(first_point, second_point)) {
            edges[i].position = "outside";
            cout << "outside" << endl;
        }
        else {
            linesClip(i);

            first_point = pointsClip(edges[i].x1, edges[i].y1);
            second_point = pointsClip(edges[i].x2, edges[i].y2);

            if (first_point == "0000" && second_point == "0000"){
                edges[i].position = "inside"; cout<<" ok "<<endl;}
            else
                edges[i].position = "outside";
        }
    }
}

void finallines() {
    for (int i = 0; i < n; i++) {
        if (edges[i].position == "inside") {
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_LINES);
                glVertex2d(edges[i].x1 * 10.0, edges[i].y1 * 10.0);
                glVertex2d(edges[i].x2 * 10.0, edges[i].y2 * 10.0);
            glEnd();
            glutSwapBuffers();
            cout<< "Oh" <<endl;
        }
        else {
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_LINES);
                glVertex2d(edges[i].x1 * 10.0,edges[i].y1 * 10.0);
                glVertex2d(edges[i].x2 * 10.0,edges[i].y2 * 10.0);
            glEnd();
            glutSwapBuffers();
        }
    }
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
     glutSwapBuffers();
     if(n>0){
        check_points();
        finallines();
     }


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

    xmin = min(vt[0].first,vt[2].first);
    xmax = max(vt[0].first,vt[2].first);
    ymin = min(vt[0].second,vt[2].second);
    ymax = max(vt[0].second,vt[2].second);

    cout << "Enter the number of edges:"<<endl;
    cin >> n;
    cout << "Enter coordinates of " << n << " edges:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> edges[i].x1;
        cin >> edges[i].y1;
        cin >> edges[i].x2;
        cin >> edges[i].y2;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Point Clipping");
    gluOrtho2D(-600, 600, -600, 600);
    glutDisplayFunc(clipping);
    glutMainLoop();
    return 0;
}

/*
5 5
50 50
4
1 15 40 15
1 35 60 35
1  51 40 51
5 25 40 25
*/
