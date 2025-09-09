/*
Student Activity: Build a House!

Objective:
Apply the concepts you've learned from the previous examples (sample1 to sample8)
to draw a simple house and add text.

Concepts Used:
- Window creation, sizing, and positioning
- Display callback
- Clearing the screen
- Drawing with primitives (GL_QUADS, GL_TRIANGLES, GL_LINES)
- Adding Colors (glColor3f)
- Rendering Text (glRasterPos2f, glutBitmapCharacter)
- Specifying vertices (glVertex2f)
- Flushing the render pipeline (glFlush)

Instructions:
1.  Read through the code and the comments to understand how the house is drawn and how the text is rendered.
2.  Try to modify the code:
    - Change the text or its color and position.
    - Change the font of the text.
    - Add more details to the house.
*/

#include <GL/glut.h> // Include the FreeGLUT library

// Function to render bitmap text
void renderText(float x, float y, void* font, const char* string) {
    glRasterPos2f(x, y); // Set the raster position for the text
    for (const char* c = string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c); // Draw each character
    }
}

// The display callback function where all the drawing happens.
void display() {
    // Set the clear color to a light blue (sky color)
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // --- Draw the House Body (a brown square) ---
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.6f);
        glVertex2f(0.5f, -0.6f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(-0.5f, 0.2f);
    glEnd();

    // --- Draw the Roof (a red triangle) ---
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.6f, 0.2f);
        glVertex2f(0.6f, 0.2f);
        glVertex2f(0.0f, 0.8f);
    glEnd();

    // --- Draw the Door (a dark brown rectangle) ---
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, -0.6f);
        glVertex2f(0.15f, -0.6f);
        glVertex2f(0.15f, -0.1f);
        glVertex2f(-0.15f, -0.1f);
    glEnd();

    // --- Draw a Window (using lines) ---
    glColor3f(1.0f, 1.0f, 0.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        // Window frame
        glVertex2f(0.25f, -0.1f); glVertex2f(0.45f, -0.1f);
        glVertex2f(0.25f, -0.3f); glVertex2f(0.45f, -0.3f);
        glVertex2f(0.25f, -0.1f); glVertex2f(0.25f, -0.3f);
        glVertex2f(0.45f, -0.1f); glVertex2f(0.45f, -0.3f);
        // Window cross
        glVertex2f(0.35f, -0.1f); glVertex2f(0.35f, -0.3f);
        glVertex2f(0.25f, -0.2f); glVertex2f(0.45f, -0.2f);
    glEnd();

    // --- Add the text "Home sweet Home" ---
    // Set color to black for the text
    glColor3f(0.0f, 0.0f, 0.0f);
    // Set the position and render the text.
    // The position (-0.3f, 0.9f) is chosen to be above the roof.
    renderText(-0.3f, 0.9f, GLUT_BITMAP_HELVETICA_18, "Home sweet Home");


    // Flush the drawing commands to the screen
    glFlush();
}

// The main function, where the program starts.
int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // Set window size and position
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);

    // Create the window with a title
    glutCreateWindow("Student Activity: Draw a House with Text");

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the main event loop
    glutMainLoop();

    return 0;
}