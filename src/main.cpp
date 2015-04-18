#include "main.h"

BoundingBoard *board;
Striker *striker;
std::array<Pocket *, 4> pockets;
std::vector<Coin *> coins;
Player *player;
std::vector<Particles *> particles;
int STATE;
int CORRECT_STATE;
bool ended;
bool won;
bool lost;
bool moveStriker = false;
bool releaseStriker = false;

void initItems() {
	ended = won = lost = false;
	STATE = 0;
	CORRECT_STATE = 0;
	board = new BoundingBoard();
	striker = new Striker();
	player = new Player();
	pockets[0] = new Pocket(1,BOARD_WIDTH/2,BOARD_HEIGHT/2);
	pockets[1] = new Pocket(4,-BOARD_WIDTH/2,BOARD_HEIGHT/2);
	pockets[2] = new Pocket(3,-BOARD_WIDTH/2,-BOARD_HEIGHT/2);
	pockets[3] = new Pocket(2,BOARD_WIDTH/2,-BOARD_HEIGHT/2);
	coins.push_back(new Coin(2,0,0));
	for(int i = 0 , j = 0 ; i <= 360 ; i += (360 / COINS_COUNT) , j=j^1 ) {
		coins.push_back(new Coin(j, SPACING_RADIUS * cos ( M_PI * i / 180),  SPACING_RADIUS * sin ( M_PI * i / 180)));
	}
}

void refreshItems() {
	ended = won = lost = false;
	STATE = 0;
	CORRECT_STATE = 0;
	striker->reset();
	for (auto i = coins.begin(); i != coins.end(); i++) {
		delete *i;
	}
	coins.clear();
	for (auto i = particles.begin(); i != particles.end(); i++) {
		delete *i;
	}
	particles.clear();
	coins.push_back(new Coin(2,0,0));
	for(int i = 0 , j = 0 ; i <= 360 ; i += (360 / COINS_COUNT) , j=j^1 ) {
		coins.push_back(new Coin(j, SPACING_RADIUS * cos ( M_PI * i / 180),  SPACING_RADIUS * sin ( M_PI * i / 180)));
	}
	player->setScore(30);
}

void handleWallCollision(GenericCollidingChip *chip) {
	float xx = fabs(chip->getDeltaX()) * sqrt(RESTITUTION_CONSTANT);
	float yy = fabs(chip->getDeltaY()) * sqrt(RESTITUTION_CONSTANT);
	if ((chip->getPositionX() + chip->getRadius()) > (board->getWidth() / 2)) {
		chip->setDeltaX(-xx);
		particles.push_back(new Particles(chip->getPositionX() + chip->getRadius(), chip->getPositionY(), xx, yy));

		float px = xx;
		float py = yy;
		particles.push_back(new Particles(chip->getPositionX() + chip->getRadius(), chip->getPositionY(), px, py));
		px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
		py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() + chip->getRadius(), chip->getPositionY(), px, py));
		px = chip->getDeltaX() * cos(M_PI / 2) + chip->getDeltaY() * sin(M_PI / 2);
		py = chip->getDeltaY() * cos(M_PI / 2) - chip->getDeltaX() * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() + chip->getRadius(), chip->getPositionY(), px, py));
		px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
		py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() + chip->getRadius(), chip->getPositionY(), px, py));
	}
	if ((chip->getPositionX() - chip->getRadius()) < -(board->getWidth() / 2)) {
		chip->setDeltaX(xx);
		particles.push_back(new Particles(chip->getPositionX() - chip->getRadius(), chip->getPositionY(), xx, yy));

		float px = xx;
		float py = yy;
		particles.push_back(new Particles(chip->getPositionX() - chip->getRadius(), chip->getPositionY(), px, py));
		px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
		py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() - chip->getRadius(), chip->getPositionY(), px, py));
		px = chip->getDeltaX() * cos(M_PI / 2) + chip->getDeltaY() * sin(M_PI / 2);
		py = chip->getDeltaY() * cos(M_PI / 2) - chip->getDeltaX() * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() - chip->getRadius(), chip->getPositionY(), px, py));
		px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
		py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX() - chip->getRadius(), chip->getPositionY(), px, py));
	}
	if ((chip->getPositionY() + chip->getRadius()) > (board->getHeight() / 2)) {
		chip->setDeltaY(-yy);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() + chip->getRadius() , xx, yy));

		float px = xx;
		float py = yy;
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() + chip->getRadius() , px, py));
		px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
		py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() + chip->getRadius() , px, py));
		px = chip->getDeltaX() * cos(M_PI / 2) + chip->getDeltaY() * sin(M_PI / 2);
		py = chip->getDeltaY() * cos(M_PI / 2) - chip->getDeltaX() * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() + chip->getRadius() , px, py));
		px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
		py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() + chip->getRadius() , px, py));
	}
	if ((chip->getPositionY() - chip->getRadius()) < -(board->getHeight() / 2)) {
		chip->setDeltaY(yy);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() - chip->getRadius() , xx, yy));

		float px = xx;
		float py = yy;
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() - chip->getRadius() , px, py));
		px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
		py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() - chip->getRadius() , px, py));
		px = chip->getDeltaX() * cos(M_PI / 2) + chip->getDeltaY() * sin(M_PI / 2);
		py = chip->getDeltaY() * cos(M_PI / 2) - chip->getDeltaX() * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() - chip->getRadius() , px, py));
		px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
		py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
		particles.push_back(new Particles(chip->getPositionX(), chip->getPositionY() - chip->getRadius() , px, py));
	}
}

void handlePocketEncompassing(Coin *coin) {
	coin->pocketSelf();
	player->updateScore(coin->getScore());
}

void handleChipCollision(GenericCollidingChip *first , GenericCollidingChip *second) {
	double m21,dvx2,a,x21,y21,vx21,vy21,fy21,vx_cm,vy_cm;
	m21=second->getMass()/first->getMass();
	x21=second->getPositionX()-first->getPositionX();
	y21=second->getPositionY()-first->getPositionY();
	vx21=second->getDeltaX()-first->getDeltaX();
	vy21=second->getDeltaY()-first->getDeltaY();

	vx_cm = (first->getMass()*first->getDeltaX()+second->getMass()*second->getDeltaX())/(first->getMass()+second->getMass());
	vy_cm = (first->getMass()*first->getDeltaY()+second->getMass()*second->getDeltaY())/(first->getMass()+second->getMass());

	if ( (vx21*x21 + vy21*y21) >= 0) 
		return;


	fy21=1.0E-12*fabs(y21);

	if ( fabs(x21)<fy21 ) {  
		int sign; // handy hack to compute for given orientations
		if (x21<0) { 
			sign=-1; 
		} else { 
			sign=1;
		}  
		x21=fy21*sign; 
	} 

	a=y21/x21;
	dvx2= -2*(vx21 +a*vy21)/((1+a*a)*(1+m21));
	float vx2=second->getDeltaX()+dvx2;
	float vy2=second->getDeltaY()+a*dvx2;
	float vx1=first->getDeltaX()-m21*dvx2;
	float vy1=first->getDeltaY()-a*m21*dvx2;

	vx1=(vx1-vx_cm)*RESTITUTION_CONSTANT + vx_cm;
	vy1=(vy1-vy_cm)*RESTITUTION_CONSTANT + vy_cm;
	vx2=(vx2-vx_cm)*RESTITUTION_CONSTANT + vx_cm;
	vy2=(vy2-vy_cm)*RESTITUTION_CONSTANT + vy_cm;

	first->setDelta(vx1,vy1);
	second->setDelta(vx2,vy2);

	float collisionPointX = ((first->getPositionX() * second->getRadius()) + (second->getPositionX() * first->getRadius()))  / (first->getRadius() + second->getRadius());
	float collisionPointY = ((first->getPositionY() * second->getRadius()) + (second->getPositionY() * first->getRadius())) / (first->getRadius() + second->getRadius());

	particles.push_back(new Particles(collisionPointX, collisionPointY, vx_cm, vy_cm));

	float px = first->getDeltaX() * cos(M_PI / 2) - first->getDeltaY() * sin(M_PI / 2);
	float py = first->getDeltaX() * sin(M_PI / 2) + first->getDeltaY() * cos(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
	py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = first->getDeltaX() * cos(M_PI / 2) + first->getDeltaY() * sin(M_PI / 2);
	py = first->getDeltaY() * cos(M_PI / 2) - first->getDeltaX() * sin(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
	py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));

	px = second->getDeltaX() * cos(M_PI / 2) - second->getDeltaY() * sin(M_PI / 2);
	py = second->getDeltaX() * sin(M_PI / 2) + second->getDeltaY() * cos(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = px * cos(M_PI / 2) - py * sin(M_PI / 2);
	py = px * sin(M_PI / 2) + py * cos(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = second->getDeltaX() * cos(M_PI / 2) + second->getDeltaY() * sin(M_PI / 2);
	py = second->getDeltaY() * cos(M_PI / 2) - second->getDeltaX() * sin(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));
	px = px * cos(M_PI / 2) + py * sin(M_PI / 2);
	py = py * cos(M_PI / 2) - px * sin(M_PI / 2);
	particles.push_back(new Particles(collisionPointX, collisionPointY, px, py));

	return;
}

void handleFriction(GenericCollidingChip *chip) {
	float vx = chip->getDeltaX() * LINEAR_FRICTIONAL_EFFECT;
	float vy = chip->getDeltaY() * LINEAR_FRICTIONAL_EFFECT;
	chip->setDelta(vx,vy);
}

void cleanUpItems() {
	delete board;
	delete striker;
	for (auto i = pockets.begin(); i != pockets.end(); i++) {
		delete *i;
	}
	for (auto i = coins.begin(); i != coins.end(); i++) {
		delete *i;
	}
	for (auto i = particles.begin(); i != particles.end(); i++) {
		delete *i;
	}
}

void update(int value) {
	bool flag = true;
	for (auto i = coins.begin(); i != coins.end(); i++) {
		if (board->isColliding(**i))
			handleWallCollision(*i);
		if (striker->isColliding(**i))
			handleChipCollision(striker,*i);
		for (auto j = i + 1; j != coins.end(); ++j) {
			if ((*i)->isColliding(**j)) 
				handleChipCollision(*i,*j);
		}
		handleFriction(*i);
		for (auto j = pockets.begin(); j != pockets.end(); ++j) {
			if ((*j)->isFullyEncompassing(**i)) {
				handlePocketEncompassing(*i);
			}
		}
		if (!(*i)->isStopped()) {
			flag = false;
			continue;
		}
		if (!(*i)->isPocketed() and (*i)->getType() != 1) {
			continue;
		}
	}
	if (board->isColliding(*striker)) {
		handleWallCollision(striker);
	}
	handleFriction(striker);
	for (auto i = pockets.begin(); i != pockets.end(); i++) {
		if ((*i)->isFullyEncompassing(*striker)) {
			striker->reset();
			player->updateScore(-5);
		}
	}
	if (!(striker->isStopped())) {
		flag = false;
	}
	striker->moveNext();
	for (auto i = coins.begin(); i != coins.end(); i++) {
		(*i)->moveNext();
	}
	for (auto i = particles.begin(); i != particles.end(); i++) {
		(*i)->moveNext();
	}
	if (flag and striker->isFired()) {
		striker->reset();
	}

	if (CORRECT_STATE > COINS_COUNT / 2) {
		ended = true;
		won = true;
	}

	if (player->getScore() <= 0) {
		ended = true;
		lost = true;
	}

	glutTimerFunc(1, update, value + 1);
}

void drawScoreBoard() {
	glPushMatrix();
	std::string st;
	glColor4f(1,1,1,1);
	if (!ended) {
		st = "Score : \n" + std::to_string(player->getScore());
		glRasterPos3f(7.5,-5,-14);
	} else {
		if (lost) {
			st = "You have disgraced your family. Play Again? (y/n)";
		} else {
			if (won) {
				st = "You did not lose.";
			} else {
				st = "Paused. P to un-Pause. Y to Play Again. N to Quit.";		
			}
		}

		glRasterPos3f(-7.5,-5,-14);
	}

	for (auto i = st.cbegin() ; i != st.cend() ; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *i);
	}
	glPopMatrix();
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
	for (auto i = pockets.begin(); i != pockets.end(); i++) {
		(*i)->drawSelf();
	}
	striker->drawSelf();
	for (auto i = coins.begin(); i != coins.end(); i++) {
		(*i)->drawSelf();
	}
	for (auto i = particles.begin(); i != particles.end(); i++) {
		(*i)->drawSelf();
	}
	glPopMatrix();
	drawScoreBoard();
	glutSwapBuffers();
}

// Initializing some openGL 3D rendering options
void initRendering() {
	glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
	glEnable(GL_COLOR_MATERIAL);    // Enable coloring
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable( GL_LINE_SMOOTH );
	glEnable( GL_POLYGON_SMOOTH );
	glHint( GL_LINE_SMOOTH_HINT, GL_NICEST );
	glHint( GL_POLYGON_SMOOTH_HINT, GL_NICEST );
	glLineWidth(1.4);
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
#ifndef DEBUG
	if (key == 'p' or key == 'P') {
		ended = !ended;
	}
	if (!ended) {
		if (key == ' ' or key == 'w' or key == 'W') {
			striker->fire();
		}

		if (key == 'a' or key == 'A') {
			striker->updateAngle(1);
		}

		if (key == 'c' or key == 'C') {
			striker->updateAngle(-1);
		}

		if (key == 27) {
			cleanUpItems();
			exit(0);     // escape key is pressed
		}
	} else {
		if (key == 'y' || key == 'Y') {
			ended = 0;
			refreshItems();
		}

		if (key == 'n' || key == 'N') {
			cleanUpItems();
			exit(0);
		}
	}
#endif
#ifdef DEBUG
	if (key == 'w' or key == 'W') {
		striker->setDelta(0,0.1);
	}
	if (key == 'a' or key == 'A') {
		striker->setDelta(-0.1,0);
	}
	if (key == 's' or key == 'S') {
		striker->setDelta(0,-0.1);
	}
	if (key == 'd' or key == 'D') {
		striker->setDelta(0.1,0);
	}
#endif
}

void handleSpecialKeypress(int key, int x, int y) {
	if (!ended and !striker->isFired()) {
		if (key == GLUT_KEY_UP) {
			striker->updatePower(0.01);
		}
		if (key == GLUT_KEY_DOWN) {
			striker->updatePower(-0.01);
		}
		if (key == GLUT_KEY_LEFT) {
			for (auto i = coins.begin(); i != coins.end() ; i++) {
				while (striker->isColliding(**i)) {
					striker->updatePositionX(-0.1);		
				}
			}
			striker->updatePositionX(-0.1);
		}
		if (key == GLUT_KEY_RIGHT) {
			for (auto i = coins.begin(); i != coins.end() ; i++) {
				while (striker->isColliding(**i)) {
					striker->updatePositionX(0.1);
				}
			}
			striker->updatePositionX(0.1);
		}
	}
}

void handleMouseclick(int button, int state, int x, int y) {
	if (!ended and !striker->isFired()) {
		float x1 = x - 450;
		float a = 20 / (2.75 * 300);
		x1=x1*a;
		if(button == GLUT_RIGHT_BUTTON and state==GLUT_DOWN){
			moveStriker=true;
		}
		if(button==GLUT_RIGHT_BUTTON and state==GLUT_UP){
			moveStriker=false;
		}
		if(button==GLUT_RIGHT_BUTTON){
			striker->setPositionX(x1);
		}
		if(button==GLUT_LEFT_BUTTON and state== GLUT_DOWN){
			releaseStriker=true;
		}
		if(button==GLUT_LEFT_BUTTON and state == GLUT_UP){
			releaseStriker=false;
			striker->fire();
		}
	}
}

void dragHandler(int x, int y) {
	if(!ended and !striker->isFired()){
		float x1 = x - 450;
		float y1 = y - 250;

		float a = 20 / (2.75 * 300);

		y1=y1*a*(-1);
		x1=x1*a;

		float xs = striker->getPositionX();
		float ys = striker->getPositionY();

		if(moveStriker) {
			striker->updatePositionX(x);	
			moveStriker=true;
		}

		if(releaseStriker){
			float theta;
			float theta2;
			theta = atan2((y1-ys),(x1-xs));
			theta2= theta*180*M_1_PI;
			striker->setPower(sqrt((xs-x1) * (xs-x1) + (ys-y1) * (ys-y1)));
			striker->setAngle(theta2);
		}
		glutPostRedisplay();
	}
}

void timer_start(std::function<void(void)> func, unsigned int interval) {
	std::thread([func, interval]() {
			while (true) {
			func();
			std::this_thread::sleep_for(std::chrono::milliseconds(interval));
			}
			}).detach();
}


void decrementScore() {
	if (!ended) {
		player->setScore(player->getScore() - 1);
	}
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
	glutMotionFunc(dragHandler);
	glutTimerFunc(1, update, 0);
	timer_start(decrementScore,5000);
	glutMainLoop();

	cleanUpItems();
	return 0;
}
