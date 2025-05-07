#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

// Mosquito position and animation variables
// Variables for animation states
float mosquito1X = -0.2f, mosquito1Y = 0.2f; // Mosquito position
float mosquitoSpeedX = 0.004f, mosquitoSpeedY = 0.002f;
float mosquitoX = -0.5, mosquitoY = 0.5;
float mosquitoWingAngle = 0;
bool isMosquitoVisible = true;
bool isMosquito1Visible = true;
// Water container state
bool isWaterPresent = true;

// Other states
bool isSprayUsed = false;
bool isOintmentApplied = false;
bool isFanOn = false;
int ointmentTimer = 0;

// Function prototypes
void display();
void timer(int);
void drawMosquito(float cx, float cy);
void drawMosquito1(float x, float y);
void drawWaterContainer();
void drawSpray();
void drawOintment();
void handleKeypress(unsigned char key, int x, int y);
void drawCircle(float cx, float cy, float r, int num_segments, bool filled);
void drawText(float x, float y, const char *text);

void init() {
    glClearColor(0.5, 0.8, 1.0, 1.0); // Sky blue background
    glOrtho(-1, 1, -1, 1, -1, 1);
    srand(time(0));
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Display instructions
    glColor3f(0, 0, 0);
    glRasterPos2f(-0.9, 0.9);
    const char *text = "Press 'W' to wipe water, 'S' to spray, 'O' for ointment, 'F' for fan.";
    for (const char *c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }

    // Draw water container
    drawWaterContainer();

    // Draw prevention items
    drawSpray();
    drawOintment();

    // Draw mosquito if visible
    if (isMosquitoVisible) {
        drawMosquito(mosquitoX, mosquitoY);
    }
    if (isMosquito1Visible) {
        drawMosquito1(mosquito1X, mosquito1Y);
    }

    glutSwapBuffers();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'w' || key == 'W') {
        isWaterPresent = false; // Water wiped
        isMosquito1Visible = false;
    }
    if (key == 's' || key == 'S') {
        isMosquitoVisible = false; // Spray kills mosquito
        isMosquito1Visible = false;
    }
    if (key == 'o' || key == 'O') {
        isOintmentApplied = true;
        isMosquito1Visible = false; // Apply ointment
    }
    if (key == 'f' || key == 'F') {
        isFanOn = !isFanOn; // Toggle fan state
    }
    if (key == 'r' || key == 'R') {
        isMosquitoVisible = true;
        isMosquito1Visible = true;
        // Reset mosquito positions
        mosquitoX = -0.5;
        mosquitoY = 0.5;
        mosquito1X = -0.2;
        mosquito1Y = 0.2;
    }
    glutPostRedisplay();
}

void timer(int) {
    // Animate mosquito wings
    mosquitoWingAngle += 10;
    if (mosquitoWingAngle > 360) mosquitoWingAngle -= 360;

    // Update mosquito movements
    if (isMosquitoVisible) {
        if (isFanOn) {
            mosquitoX += 0.02; // Fan pushes mosquito to the right
        } else {
            mosquitoX += (rand() % 3 - 1) * 0.01;
            mosquitoY += (rand() % 3 - 1) * 0.01;
        }
        // Keep mosquito within bounds
        if (mosquitoX > 0.9) mosquitoX = 0.9;
        if (mosquitoX < -0.9) mosquitoX = -0.9;
        if (mosquitoY > 0.9) mosquitoY = 0.9;
        if (mosquitoY < -0.9) mosquitoY = -0.9;
    }

    if (isMosquito1Visible) {
        if (isFanOn) {
            mosquito1X += 0.02; // Fan pushes mosquito to the right
        } else {
            mosquito1X += (rand() % 3 - 1) * 0.01;
            mosquito1Y += (rand() % 3 - 1) * 0.01;
        }
        // Keep mosquito within bounds
        if (mosquito1X > 0.9) mosquito1X = 0.9;
        if (mosquito1X < -0.9) mosquito1X = -0.9;
        if (mosquito1Y > 0.9) mosquito1Y = 0.9;
        if (mosquito1Y < -0.9) mosquito1Y = -0.9;
    }

    // Handle ointment timer
    if (isOintmentApplied) {
        ointmentTimer++;
        if (ointmentTimer > 100) {
            isOintmentApplied = false;
            ointmentTimer = 0;
        }
    }

    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void drawWaterContainer() {
    if (isWaterPresent) {
        // Draw water container
        glColor3f(0.6, 0.3, 0.0); // Brown container
        glBegin(GL_POLYGON);
        glVertex2f(-0.3, -0.5);
        glVertex2f(0.3, -0.5);
        glVertex2f(0.25, -0.7);
        glVertex2f(-0.25, -0.7);
        glEnd();

        // Draw water inside container
        glColor3f(0.0, 0.0, 1.0); // Blue water
        glBegin(GL_POLYGON);
        glVertex2f(-0.25, -0.5);
        glVertex2f(0.25, -0.5);
        glVertex2f(0.2, -0.65);
        glVertex2f(-0.2, -0.65);
        glEnd();
    }
}

void drawSpray() {
    // Draw spray bottle
    glColor3f(0.8, 0.1, 0.1); // Red spray bottle
    glBegin(GL_POLYGON);
    glVertex2f(-0.8, -0.3);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.7, -0.5);
    glVertex2f(-0.8, -0.5);
    glEnd();

    // Spray nozzle
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_POLYGON);
    glVertex2f(-0.75, -0.3);
    glVertex2f(-0.73, -0.3);
    glVertex2f(-0.73, -0.25);
    glVertex2f(-0.75, -0.25);
    glEnd();

    // Add "Spray" text
    drawText(-0.78, -0.4, "Spray");
}

void drawOintment() {
    // Draw ointment tube
    glColor3f(0.1, 0.6, 0.1); // Green ointment tube
    glBegin(GL_POLYGON);
    glVertex2f(0.7, -0.4);
    glVertex2f(0.9, -0.4);
    glVertex2f(0.85, -0.5);
    glVertex2f(0.75, -0.5);
    glEnd();

    // Cap
    glColor3f(0.8, 0.8, 0.8);
    glBegin(GL_POLYGON);
    glVertex2f(0.8, -0.35);
    glVertex2f(0.85, -0.35);
    glVertex2f(0.85, -0.4);
    glVertex2f(0.8, -0.4);
    glEnd();

    // Add "Ointment" text
    drawText(0.73, -0.45, "Ointment");
}

void drawText(float x, float y, const char *text) {
    glColor3f(0, 0, 0); // Black text
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void drawMosquito1(float x, float y) {
     mosquito1X += mosquitoSpeedX;
        mosquito1Y += mosquitoSpeedY;
    glColor3f(0.0, 0.0, 0.0); // Black for body
    glBegin(GL_LINES);
    // Body
    glVertex2f(x - 0.02f, y);
    glVertex2f(x + 0.02f, y);
    // Wings
    glVertex2f(x, y + 0.01f);
    glVertex2f(x - 0.05f, y + 0.05f);
    glVertex2f(x, y + 0.01f);
    glVertex2f(x + 0.05f, y + 0.05f);
    // Legs
    glVertex2f(x - 0.01f, y - 0.01f);
    glVertex2f(x - 0.05f, y - 0.05f);
    glVertex2f(x + 0.01f, y - 0.01f);
    glVertex2f(x + 0.05f, y - 0.05f);
    glEnd();

    // Head
    drawCircle(x + 0.02f, y, 0.01f, 20, true);

    // Eyes
    drawCircle(x + 0.023f, y + 0.005f, 0.003f, 20, true); // Red eyes
    drawCircle(x + 0.023f, y - 0.005f, 0.003f, 20, true);
}

void drawMosquito(float cx, float cy) {
    // Body
    glColor3f(0.3, 0.2, 0.1);
    glBegin(GL_LINES);
    glVertex2f(cx - 0.15, cy);
    glVertex2f(cx + 0.15, cy);
    glEnd();

    // Head
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(cx + 0.18, cy, 0.03, 20, true);

    // Eyes
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(cx + 0.2, cy + 0.01, 0.01, 10, true);
    drawCircle(cx + 0.2, cy - 0.01, 0.01, 10, true);

    // Wings (animated)
    glColor3f(0.7, 0.7, 0.7);
    glPushMatrix();
    glTranslatef(cx, cy, 0.0);
    glRotatef(mosquitoWingAngle, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.2, 0.15);
    glVertex2f(-0.05, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cx, cy, 0.0);
    glRotatef(-mosquitoWingAngle, 0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.2, 0.15);
    glVertex2f(0.05, 0.0);
    glEnd();
    glPopMatrix();

    // Legs
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(cx - 0.05, cy);
    glVertex2f(cx - 0.2, cy - 0.05);

    glVertex2f(cx + 0.05, cy);
    glVertex2f(cx + 0.2, cy - 0.05);

    glVertex2f(cx - 0.05, cy);
    glVertex2f(cx - 0.15, cy - 0.15);

    glVertex2f(cx + 0.05, cy);
    glVertex2f(cx + 0.15, cy - 0.15);
    glEnd();

    // Proboscis
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(cx + 0.18, cy);
    glVertex2f(cx + 0.25, cy);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments, bool filled) {
    float theta = 2 * 3.1415926 / float(num_segments);
    float tangential_factor = tanf(theta);
    float radial_factor = cosf(theta);
    float x = r;
    float y = 0;

    if (filled)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

    for (int i = 0; i < num_segments; i++) {
        glVertex2f(x + cx, y + cy);
        float tx = -y;
        float ty = x;
        x += tx * tangential_factor;
        y += ty * tangential_factor;
        x *= radial_factor;
        y *= radial_factor;
    }
    glEnd();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Dengue Prevention Simulation");
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(100, timer, 0);
    init();
    glutMainLoop();
    return 0;
}
