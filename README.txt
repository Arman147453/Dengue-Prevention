1.	Introduction:
Dengue fever is a disease primarily found in the tropical and subtropical regions and is caused by the Aedes mosquito, impacting billions of individuals worldwide annually. Dengue causes significant challenges for public health systems around the world with estimated cases occurring at 96 million annually. 
This project is on creating a digital awareness campaign emphasizing the use of (O) ointment, (W) wipe water, (S) spray and (F) fan in order to save people from mosquito bites and prevent the spread of dengue. Interactive graphics, visualization, and infographics have been used amply to educate the public effectively in this campaign. In an effort to raise awareness among the public and take precautionary measures, the digital tool of infographics, interactive graphics, and visualization is utilized to present information in an engaging and accessible manner. However, it is a simple project but it can address a real life scenario (Dengue awareness) as well. 

	Interactive Graphics: It enables people to engage with the content in an active manner. For instance, users can locate and remove mosquito breeding grounds in a virtual environment by using a drag-and-drop interface.

	Visualization: Data visualizations that show how dengue has changed over time, for example, could convey the seriousness and urgency of the issue. Animated maps showing the affected areas are particularly effective.


	Infographics: It can be used to visually and rapidly convey important information. Examples include thorough directions for applying ointment, water wipe, wind (fan) and spray for prevention advice.

2.	Findings and Background Study:
Dengue fever is still a major global health concern, and its growth is fueled by urbanization and inadequate sanitation. Earlier approaches, including conventional awareness campaigns, have increased awareness but frequently failed to engage people, especially those with poor reading levels. Interactive movies and other digital tools have been shown to be more successful in enhancing comprehension and memory of information. Aedes mosquitoes thrive in Bangladesh due to the country's warm temperature and poor waste management. Even while there are initiatives like mosquito control programs, marginalized people are frequently left out. Digital technologies that are both accessible and culturally relevant are crucial for closing these gaps. Building on previous achievements, this initiative fills gaps in existing awareness efforts by using interactive visuals to produce an interesting and instructive medium that is suited to Bangladesh's needs.

3.	Detail explanation of my solution:

	Topic Selection and Scenario
The topic of dengue fever was selected due to its significant impact on public health, especially in tropical and subtropical regions. Dengue fever affects billions of people worldwide annually, making it a critical issue that requires widespread awareness and preventive measures. The scenario focuses on using digital tools to educate the public and promote preventive actions, leveraging the power of interactive graphics, visualization, and infographics.

	Addressing the Problem
The solution addresses the problem of dengue fever by: Raising Awareness: Educating the public about dengue fever, its transmission, and preventive measures. Engaging the Audience: Using interactive graphics to engage people in locating and removing mosquito breeding grounds in a virtual environment. Visualizing Data: Showing the changes in dengue cases over time through data visualizations to convey the seriousness of the issue. Providing Clear Instructions: Using infographics to visually and rapidly convey important information on preventive measures like applying ointment, wiping water, using fans, and spraying.
	Justification and Requirements
The solution satisfies and covers all given requirements by: Comprehensive Approach: Combining multiple digital tools to create a holistic awareness campaign. User Engagement: Ensuring that the audience is actively involved through interactive elements. Clear Communication: Using visual aids to make complex information easily understandable. Data-Driven Insights: Providing data visualizations to support the information with factual evidence.

	Technical Structure from the Code
	Header Files and Global Variables
•	The code includes necessary header files for OpenGL, standard libraries, and I/O operations.
•	Global variables are defined for mosquito positions, animation states, and other states like water presence, spray usage, ointment application, and fan state.

	Function Prototypes
•	Function prototypes are declared for display, timer, drawing functions, keypress handling, and initialization.

	Initialization Function (init)
•	Sets the background color to sky blue and initializes the orthographic projection.
•	Seeds the random number generator.

	Display Function (display)
•	Clears the screen and displays instructions.
•	Draws the water container, prevention items (spray and ointment), and mosquitoes if they are visible.
	Keypress Handling Function (handleKeypress)
•	Handles user input to wipe water, use spray, apply ointment, toggle the fan, and reset mosquito positions.
•	Updates the corresponding states based on the key pressed.

	Timer Function (timer)
•	Animates mosquito wings and updates mosquito movements.
•	Handles the ointment timer and updates the display periodically.

	Drawing Functions
•	drawMosquito: Draws the main mosquito with animated wings.
•	drawMosquito1: Draws the secondary mosquito with simple lines and circles.
•	drawWaterContainer: Draws the water container with water inside if present.
•	drawSpray: Draws the spray bottle with a nozzle and label.
•	drawOintment: Draws the ointment tube with a cap and label.
•	drawCircle: Utility function to draw filled or outlined circles.
•	drawText: Utility function to draw text on the screen.

	Main Function (main)
•	Initializes GLUT, sets display mode and window size, and creates the window.
•	Registers callback functions for display, keyboard input, and timer.
•	Calls the initialization function and enters the main loop.

	Analytical Skills:
Modular Design: The code is organized into modular functions, each responsible for a specific task, making it easier to understand and maintain.  State Management: The use of global variables to manage different states (e.g., mosquito visibility, water presence) allows for easy state transitions based on user input.  Animation Logic: The timer function handles animation and movement logic, ensuring smooth and continuous updates to the display.


	Comparison with Other Works:
•	Interactive Elements: Compared to static visualizations, this code provides interactive elements that engage the user and allow them to take preventive actions against mosquitoes.
•	Real-Time Updates: The use of a timer function for real-time updates and animations sets this code apart from simpler, non-interactive simulations.
•	Educational Value: The code not only simulates mosquito behavior but also educates users on preventive measures through interactive instructions and visual feedback.
4.	Elaborate discussion:
Bangladesh, with its tropical climate and monsoon season, is highly susceptible to dengue outbreaks. The densely populated urban areas, combined with inadequate waste management and waterlogging, create ideal breeding grounds for mosquitoes. Therefore, a digital awareness campaign using interactive graphics can play a crucial role in educating the public and promoting preventive measures.
•	Interactive graphics: Adapted to the local environment, displaying typical mosquito breeding grounds in Bangladeshi homes.
•	Ideas for charts and maps: Use animated charts and maps to show dengue hotspots in Dhaka and other large cities. These visualizations can highlight areas with high dengue incidence, helping residents understand the risk in their locality and take preventive measures.
•	Translation and Cultural Relevance: Ensure that all information graphics are translated into Bengali to make them easily comprehensible and culturally relevant. Use simple language and culturally appropriate visuals to enhance understanding and retention.
•	Infographics and Posters: Create easily shareable digital infographics and posters that can be distributed on social media and messaging apps. These resources should highlight important preventive tips and proper use of repellents. Encourage users to share these graphics within their networks to increase reach.
•	Government Health Websites: Integrate the interactive graphics into government health websites and mobile applications. This will provide a reliable source of information and ensure that the graphics reach a wide audience.
•	Community Health Centers: Display the interactive graphics on digital screens in community health centers and hospitals. This will educate visitors about dengue prevention while they wait for services, ensuring that the message reaches a diverse audience.
•	SMS Campaigns: Disseminate key information from the graphic through SMS campaigns to target specific demographics.

5.	Source Code: 

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
