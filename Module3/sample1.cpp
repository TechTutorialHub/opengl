#include <GL/glut.h> // Include the GLUT library

void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set clear color to black
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glFlush(); // Render now
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);

    // --- New Functions ---
    // Set the initial window size to 640x480 pixels
    glutInitWindowSize(640, 480);
    // Set the initial window position to 100 pixels from the left and top edges of the screen
    glutInitWindowPosition(100, 100);
    // --- End of New ---

    // Create the window with a more descriptive title
    glutCreateWindow("A Sized and Positioned Window");

    // Register the display callback function
    glutDisplayFunc(display);

    // Enter the main event loop
    glutMainLoop();

    return 0;
}
