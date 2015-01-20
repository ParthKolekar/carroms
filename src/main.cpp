#include "main.h"

BoundingBoard *board;
Striker *striker;
std::array<Pocket *, 4> pockets;
std::vector<Coin *> coins;

void initItems() {
    board = new BoundingBoard();
    striker = new Striker();
    pockets[0] = new Pocket(1,5,5);
    pockets[1] = new Pocket(4,-5,5);
    pockets[2] = new Pocket(3,-5,-5);
    pockets[3] = new Pocket(2,5,-5);
}

void cleanUpItems() {
    delete board;
    delete striker;
    for (auto i = pockets.begin(); i != pockets.end(); ++i) {
        delete *i;
    }
    for (auto i = coins.begin(); i != coins.end(); ++i) {
        delete *i;
    }
}

void update(int value) {

    if (board->isColliding(*striker))
        std::cerr << "touch";

//TODO: Handle Collisions here
    striker->moveNext();
    for (auto i = coins.begin(); i != coins.end(); ++i) {
        (*i)->moveNext();
    }

    glutTimerFunc(1, update, 0);
}

// Function to draw objects on the screen
void drawScene() {
    glClearColor(0.035,0.035,0.035,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(0, 0, -15);

    board->drawSelf();
    
    for (auto i = pockets.begin(); i != pockets.end(); ++i) {
        (*i)->drawSelf();
    }

    striker->drawSelf();

    for (auto i = coins.begin(); i != coins.end(); ++i) {
        (*i)->drawSelf();
    }


    glPopMatrix();
    glutSwapBuffers();
}

// Initializing some openGL 3D rendering options
void initRendering() {
    glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
    glEnable(GL_COLOR_MATERIAL);    // Enable coloring
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // glEnable(GL_LINE_SMOOTH);
}

// Function called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 27) {
        cleanUpItems();
        exit(0);     // escape key is pressed
    }
}

void handleSpecialKeypress(int key, int x, int y) {
    if (key == GLUT_KEY_UP) {
        striker->setDelta(0,0.01);
    }
    if (key == GLUT_KEY_DOWN) {
        striker->setDeltaNext(0,-0.01);
    }
    if (key == GLUT_KEY_LEFT) {
        striker->setDeltaNext(-0.01,0);
    }
    if (key == GLUT_KEY_RIGHT) {
        striker->setDeltaNext(0.01,0);
    }
}

void handleMouseclick(int button, int state, int x, int y) {
}

int main(int argc, char **argv) {
    initItems();

    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    int windowWidth = w * 2 / 3;
    int windowHeight = h * 2 / 3;

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

    glutCreateWindow("Carrom");  // Setup the window
    initRendering();

    // Register callbacks
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(handleSpecialKeypress);
    glutMouseFunc(handleMouseclick);
    glutReshapeFunc(handleResize);
    glutTimerFunc(1, update, 0);

    glutMainLoop();

    cleanUpItems();
    return 0;
}
