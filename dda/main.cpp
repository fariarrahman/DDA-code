#include <windows.h>
#include <GL/gl.h>   // OpenGL library
#include <GL/glut.h> // GLUT library
#include <iostream>
#include <math.h>
using namespace std;

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background to white
    glClear(GL_COLOR_BUFFER_BIT);        // Clear the color buffer


    int x1;
    int y1;
    int x2;
    int y2;
    cout << "Enter the first point (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second point (x2, y2): ";
    cin >> x2 >> y2;



    int dx = x2 - x1;
    int dy = y2 - y1;
    float m= (float)dy/dx;


    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 1.0f, 1.0f);

    if (m == 1) {
        while (x1 <= x2 && y1 <= y2) {
            glVertex2f(x1, y1); // Plot first plot
            x1++;
            y1++;
        }
    }
    else if (m < 1) {
        float x = x1;
        float y = y1;
        while (x <= x2) {
            glVertex2f(x, round(y));
            x++;
            y =y+m;

        }
    }
    else {
        float x = x1;
        float y = y1;
        while (y <= y2) {
        glVertex2f(round(x), y);
        y1++;
        x=x+ 1.0 / m;

        }
    }

    glEnd();
    glFlush(); // Render the output
}



void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20, 20, -20, 20);
}


/* Program entry point */
/* Main function: GLUT runs as a console application starting at main() */

int main(int argc, char *argv[])
{
    //Full code for window opening
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500); // Set the window's initial width & height
    glutInitWindowPosition(200, 100);  // Set the window's initial position according to the monitor
    glutCreateWindow("DDA"); // Create a window with the given title
    init();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop(); // Enter the event-processing loop
    return 0;


}
