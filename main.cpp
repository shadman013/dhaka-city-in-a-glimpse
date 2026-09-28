#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
# define PI           3.14159265358979323846




// Group information
struct Member
{
    const char* slno;
    const char* name;
    const char* id;
    const char* contribution;
    const char* key;
};

Member members[5] =
{
    {"31.", "MOABIA",                "23-55531-3", "20%", "Press 1"},
    {"30.", "MD. JARIFUR RAHMAN",    "23-55463-3", "20%", "Press 2"},
    {"18.", "ISRAT JAHAN SINGDHA",   "23-54089-3", "20%", "Press 3"},
    {"15.", "DHRUBO ROY",            "23-53492-3", "20%", "Press 4"},
    {"8.",  "SHADMAN HASAN",         "23-51552-2", "20%", "Press 5"}
};


void renderBitmapString(float x, float y, void *font, const char *string)
{
    glRasterPos2f(x, y);

    while(*string)
    {
        glutBitmapCharacter(font, *string);
        string++;
    }
}


void coverPage()
{
    glColor3f(0.0f, 0.0f, 0.0f);

    renderBitmapString(-0.18f, 0.58f,
                       GLUT_BITMAP_TIMES_ROMAN_24,
                       "Dhaka City in a Glimplse");
     glPopMatrix();


    renderBitmapString(-0.18f, 0.45f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Submitted to :");


    renderBitmapString(-0.05f, 0.45f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Mahfujur Rahman");


    renderBitmapString(-0.12f, 0.41f,
                       GLUT_BITMAP_HELVETICA_18,
                       "(Assistant Professor)");

     renderBitmapString(-0.08f, 0.34f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Section : F");

    renderBitmapString(-0.08f, 0.29f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Group: 3");

    renderBitmapString(-0.75f, 0.10f,
                       GLUT_BITMAP_HELVETICA_18,
                       "SL No");

    renderBitmapString(-0.60f, 0.10f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Name");

    renderBitmapString(-0.10f, 0.10f,
                       GLUT_BITMAP_HELVETICA_18,
                       "ID");

    renderBitmapString(0.30f, 0.10f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Contribution");

    renderBitmapString(0.60f, 0.10f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Check Project");

    renderBitmapString(-0.17f, -0.36f,
                       GLUT_BITMAP_HELVETICA_18,
                       "Back to Home: Press 0 key");



    float y = 0.02f;

    for(int i = 0; i < 5; ++i, y -= 0.071f)
    {
        renderBitmapString(-0.75f, y,
                           GLUT_BITMAP_HELVETICA_18,
                           members[i].slno);

        renderBitmapString(-0.60f, y,
                           GLUT_BITMAP_HELVETICA_18,
                           members[i].name);

        renderBitmapString(-0.10f, y,
                           GLUT_BITMAP_HELVETICA_18,
                           members[i].id);

        renderBitmapString(0.30f, y,
                           GLUT_BITMAP_HELVETICA_18,
                           members[i].contribution);

        renderBitmapString(0.60f, y,
                           GLUT_BITMAP_HELVETICA_18,
                           members[i].key);
    }
}



void display();

void displayCover()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0.8, 0.8, -0.5, 0.7, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    coverPage();

    glFlush();
}








 GLfloat position = 0.0f;
GLfloat speed = 0.0015f;

void updateCloud(int value)
{
    if(position > 1.0)
        position = -1.0f;

    position = position + speed;

	glutPostRedisplay();
	glutTimerFunc(100, updateCloud, 0);
}

//trafic light
int trafficLight = 0;   // 0 = Red, 1 = Green

void updateTrafficLight(int value)
{
    if(trafficLight == 0)
    {
        trafficLight = 1;
        glutPostRedisplay();
        glutTimerFunc(5000, updateTrafficLight, 0);
    }
    else
    {
        trafficLight = 0;

        glutPostRedisplay();
        glutTimerFunc(3000, updateTrafficLight, 0);
    }
}



GLfloat carPosition = 0.0f;
GLfloat carPosition2 = 0.00f;

GLfloat carSpeed = 0.005f;
GLfloat carSpeed2 = 0.00215f;


void updateCar(int value)
{
    if(trafficLight == 0 && carPosition >= 0.35f && carPosition <= 0.45f)
    {
        // Car stops
    }
    else
    {
        carPosition = carPosition + carSpeed;
        carPosition2 = carPosition2 + carSpeed2;
    }

    if(carPosition > 0.8f)
    {
        carPosition = 0.0f;
        carPosition2 = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(100, updateCar, 0);
}

GLfloat car2Position = 0.0f;
GLfloat car2Position2 = 0.0f;

GLfloat car2Speed = 0.005f;
GLfloat car2Speed2 = 0.00215f;

void updateCar2(int value)
{
    if(trafficLight == 0 && car2Position >= 0.20f && car2Position <= 0.25f)
    {
        // Stop
    }
    else
    {
        car2Position = car2Position + car2Speed;
        car2Position2 = car2Position2 + car2Speed2;
    }

    if(car2Position > 1.0f)
    {
        car2Position = 0.0f;
        car2Position2 = 0.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(100, updateCar2, 0);
}




//Jarif's Part


GLfloat JA_position = 0.0f;

GLfloat JA_speed = 0.02f;

// moves the clouds from left to right

void JA_updateCloud(int JA_value)

{

    if(JA_position > 10.0f)

        JA_position = -7.0f;

    JA_position = JA_position + JA_speed;

    glutPostRedisplay();

    glutTimerFunc(100, JA_updateCloud, 0);

}


// red car movement values

GLfloat JA_carPosition = 0.0f;

GLfloat JA_carPosition2 = 0.0f;

GLfloat JA_carSpeed = 0.004f;

GLfloat JA_carSpeed2 = 0.010f;


// blue car movement values

GLfloat JA_car2Position = 0.0f;

GLfloat JA_car2Position2 = 0.0f;

GLfloat JA_car2Speed = 0.004f;

GLfloat JA_car2Speed2 = 0.00046f;


// wheel rotation angles

GLfloat JA_wheelAngle1 = 0.0f;

GLfloat JA_wheelAngle2 = 0.0f;

// horn light indicators

int JA_redHornLight = 0;

int JA_blueHornLight = 0;


// moves the red car and stops after it leaves the screen

void JA_updateCar(int JA_value)

{

    if(JA_carPosition2 < 9.0f)

    {

        JA_carPosition = JA_carPosition + JA_carSpeed;

        JA_carPosition2 = JA_carPosition2 + JA_carSpeed2;

        // rotate red car wheels

        JA_wheelAngle1 = JA_wheelAngle1 + 12.0f;

        if(JA_wheelAngle1 >= 360.0f)

            JA_wheelAngle1 = JA_wheelAngle1 - 360.0f;

        glutPostRedisplay();

        glutTimerFunc(

            20,

            JA_updateCar,

            0

        );

    }

}


// moves the blue car and stops after it leaves the screen

void JA_updateCar2(int JA_value)

{

    if(JA_car2Position < 9.6f)

    {

        JA_car2Position = JA_car2Position + JA_car2Speed;

        JA_car2Position2 = JA_car2Position2 + JA_car2Speed2;

        // rotate blue car wheels

        JA_wheelAngle2 = JA_wheelAngle2 + 8.0f;

        if(JA_wheelAngle2 >= 360.0f)

            JA_wheelAngle2 = JA_wheelAngle2 - 360.0f;

        glutPostRedisplay();

        glutTimerFunc(

            20,

            JA_updateCar2,

            0

        );

    }

}


// turns off the red car horn light

void JA_stopRedHornLight(int JA_value)

{

    JA_redHornLight = 0;

    glutPostRedisplay();

}


// turns off the blue car horn light

void JA_stopBlueHornLight(int JA_value)

{

    JA_blueHornLight = 0;

    glutPostRedisplay();

}



// used for the car wheels

void JA_drawFilledCircle(float JA_cx, float JA_cy, float JA_r)

{

    int JA_i;

    float JA_angle;

    glBegin(GL_POLYGON);

    for(JA_i = 0; JA_i < 40; JA_i++)

    {

        JA_angle = 2.0f * 3.1416f * JA_i / 40.0f;

        glVertex2f(

            JA_cx + JA_r * cos(JA_angle),

            JA_cy + JA_r * sin(JA_angle)

        );

    }

    glEnd();

}


// small red line that makes wheel rotation visible

void JA_drawWheelMark()

{

    glLineWidth(3.0f);

    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);

    glVertex2f(0.0f, 0.0f);

    glVertex2f(0.0f,-0.10f);

    glEnd();

    glLineWidth(1.0f);

}


// one small building used in the background

void JA_drawBackBuilding(float JA_x)

{

    int JA_row;

    float JA_top = 1.16f;

    float JA_bottom = 3.26f;

    // main building body

    glBegin(GL_QUADS);

    glColor3f(0.88f, 0.88f, 0.85f);

    glVertex2f(JA_x, JA_top);

    glVertex2f(JA_x + 0.80f, JA_top);

    glVertex2f(JA_x + 0.80f, JA_bottom);

    glVertex2f(JA_x, JA_bottom);

    glEnd();


    // blue strip in the middle

    glBegin(GL_QUADS);

    glColor3f(0.25f, 0.44f, 0.54f);

    glVertex2f(JA_x + 0.30f, JA_top);

    glVertex2f(JA_x + 0.50f, JA_top);

    glVertex2f(JA_x + 0.50f, JA_bottom);

    glVertex2f(JA_x + 0.30f, JA_bottom);

    glEnd();


    // windows for each floor

    for(JA_row = 0; JA_row < 8; JA_row++)

    {

        float JA_y = JA_top + 0.20f + JA_row * 0.22f;

        glBegin(GL_QUADS);

        glColor3f(0.16f, 0.21f, 0.22f);

        glVertex2f(JA_x + 0.08f, JA_y);

        glVertex2f(JA_x + 0.18f, JA_y);

        glVertex2f(JA_x + 0.18f, JA_y + 0.10f);

        glVertex2f(JA_x + 0.08f, JA_y + 0.10f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.16f, 0.21f, 0.22f);

        glVertex2f(JA_x + 0.34f, JA_y);

        glVertex2f(JA_x + 0.46f, JA_y);

        glVertex2f(JA_x + 0.46f, JA_y + 0.10f);

        glVertex2f(JA_x + 0.34f, JA_y + 0.10f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.16f, 0.21f, 0.22f);

        glVertex2f(JA_x + 0.62f, JA_y);

        glVertex2f(JA_x + 0.72f, JA_y);

        glVertex2f(JA_x + 0.72f, JA_y + 0.10f);

        glVertex2f(JA_x + 0.62f, JA_y + 0.10f);

        glEnd();

    }

}


// places the same small building several times

void JA_drawBackgroundBuildings()

{

    JA_drawBackBuilding(3.30f);

    JA_drawBackBuilding(4.10f);

    JA_drawBackBuilding(4.90f);

    JA_drawBackBuilding(5.70f);

    JA_drawBackBuilding(6.50f);

    JA_drawBackBuilding(7.30f);

    JA_drawBackBuilding(8.10f);

}


// large building on the left side

void JA_drawLeftBuilding()

{

    int JA_row;

    // main wall

    glBegin(GL_QUADS);

    glColor3f(0.88f, 0.88f, 0.85f);

    glVertex2f(0.56f, 0.98f);

    glVertex2f(3.36f, 0.90f);

    glVertex2f(3.48f, 4.00f);

    glVertex2f(0.70f, 4.20f);

    glEnd();


    // first red vertical strip

    glBegin(GL_QUADS);

    glColor3f(0.40f, 0.11f, 0.16f);

    glVertex2f(1.20f, 0.98f);

    glVertex2f(1.98f, 0.96f);

    glVertex2f(2.06f, 4.10f);

    glVertex2f(1.28f, 4.16f);

    glEnd();


    // second red vertical strip

    glBegin(GL_QUADS);

    glColor3f(0.40f, 0.11f, 0.16f);

    glVertex2f(2.46f, 0.94f);

    glVertex2f(2.96f, 0.92f);

    glVertex2f(3.04f, 4.04f);

    glVertex2f(2.56f, 4.08f);

    glEnd();


    // repeat windows from top to bottom

    for(JA_row = 0; JA_row < 10; JA_row++)

    {

        float JA_y = 1.16f + JA_row * 0.28f;

        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.18f, 0.19f);

        glVertex2f(0.82f, JA_y);

        glVertex2f(1.02f, JA_y);

        glVertex2f(1.02f, JA_y + 0.14f);

        glVertex2f(0.82f, JA_y + 0.14f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.17f, 0.18f);

        glVertex2f(1.40f, JA_y);

        glVertex2f(1.60f, JA_y);

        glVertex2f(1.60f, JA_y + 0.14f);

        glVertex2f(1.40f, JA_y + 0.14f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.17f, 0.18f);

        glVertex2f(1.76f, JA_y);

        glVertex2f(1.96f, JA_y);

        glVertex2f(1.96f, JA_y + 0.14f);

        glVertex2f(1.76f, JA_y + 0.14f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.18f, 0.19f);

        glVertex2f(2.14f, JA_y);

        glVertex2f(2.34f, JA_y);

        glVertex2f(2.34f, JA_y + 0.14f);

        glVertex2f(2.14f, JA_y + 0.14f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.17f, 0.18f);

        glVertex2f(2.64f, JA_y);

        glVertex2f(2.84f, JA_y);

        glVertex2f(2.84f, JA_y + 0.14f);

        glVertex2f(2.64f, JA_y + 0.14f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.18f, 0.19f);

        glVertex2f(3.14f, JA_y);

        glVertex2f(3.32f, JA_y);

        glVertex2f(3.32f, JA_y + 0.14f);

        glVertex2f(3.14f, JA_y + 0.14f);

        glEnd();

    }

}


// large building on the right side

void JA_drawRightBuilding()

{

    int JA_row;

    // main wall

    glBegin(GL_QUADS);

    glColor3f(0.87f, 0.87f, 0.85f);

    glVertex2f(9.52f, 0.54f);

    glVertex2f(14.12f, 0.12f);

    glVertex2f(14.06f, 5.94f);

    glVertex2f(9.40f, 5.40f);

    glEnd();


    // first blue vertical strip

    glBegin(GL_QUADS);

    glColor3f(0.24f, 0.43f, 0.54f);

    glVertex2f(10.00f, 0.50f);

    glVertex2f(10.52f, 0.46f);

    glVertex2f(10.50f, 5.52f);

    glVertex2f(9.98f, 5.46f);

    glEnd();


    // second blue vertical strip

    glBegin(GL_QUADS);

    glColor3f(0.24f, 0.43f, 0.54f);

    glVertex2f(11.32f, 0.38f);

    glVertex2f(11.84f, 0.34f);

    glVertex2f(11.82f, 5.68f);

    glVertex2f(11.30f, 5.62f);

    glEnd();


    // third blue vertical strip

    glBegin(GL_QUADS);

    glColor3f(0.24f, 0.43f, 0.54f);

    glVertex2f(12.64f, 0.26f);

    glVertex2f(13.16f, 0.22f);

    glVertex2f(13.14f, 5.84f);

    glVertex2f(12.62f, 5.76f);

    glEnd();


    // windows are placed row by row

    for(JA_row = 0; JA_row < 13; JA_row++)

    {

        float JA_y = 0.76f + JA_row * 0.36f;

        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.19f, 0.20f);

        glVertex2f(9.68f, JA_y);

        glVertex2f(9.90f, JA_y);

        glVertex2f(9.90f, JA_y + 0.16f);

        glVertex2f(9.68f, JA_y + 0.16f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.13f, 0.18f, 0.20f);

        glVertex2f(10.14f, JA_y - 0.04f);

        glVertex2f(10.38f, JA_y - 0.04f);

        glVertex2f(10.38f, JA_y + 0.12f);

        glVertex2f(10.14f, JA_y + 0.12f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.19f, 0.20f);

        glVertex2f(10.72f, JA_y - 0.08f);

        glVertex2f(10.96f, JA_y - 0.08f);

        glVertex2f(10.96f, JA_y + 0.08f);

        glVertex2f(10.72f, JA_y + 0.08f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.13f, 0.18f, 0.20f);

        glVertex2f(11.46f, JA_y - 0.12f);

        glVertex2f(11.70f, JA_y - 0.12f);

        glVertex2f(11.70f, JA_y + 0.04f);

        glVertex2f(11.46f, JA_y + 0.04f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.19f, 0.20f);

        glVertex2f(12.08f, JA_y - 0.16f);

        glVertex2f(12.32f, JA_y - 0.16f);

        glVertex2f(12.32f, JA_y);

        glVertex2f(12.08f, JA_y);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.13f, 0.18f, 0.20f);

        glVertex2f(12.78f, JA_y - 0.20f);

        glVertex2f(13.04f, JA_y - 0.20f);

        glVertex2f(13.04f, JA_y - 0.04f);

        glVertex2f(12.78f, JA_y - 0.04f);

        glEnd();


        glBegin(GL_QUADS);

        glColor3f(0.14f, 0.19f, 0.20f);

        glVertex2f(13.44f, JA_y - 0.24f);

        glVertex2f(13.70f, JA_y - 0.24f);

        glVertex2f(13.70f, JA_y - 0.08f);

        glVertex2f(13.44f, JA_y - 0.08f);

        glEnd();

    }

}


// red car

void JA_drawCar()

{

    GLfloat JA_scale;

    glPushMatrix();

    // moves the car along Road 3

    glTranslatef(

        5.70f + JA_carPosition2,

        4.40f + JA_carPosition,

        0.0f

    );

    // keeps the car aligned with the road

    glRotatef(

        22.0f,

        0.0f,

        0.0f,

        1.0f

    );

    // small size change while moving forward

    JA_scale = 1.0f + JA_carPosition2 * 0.025f;

    if(JA_scale > 1.20f)

    {

        JA_scale = 1.20f;

    }

    glScalef(

        0.65f * JA_scale,

        0.50f * JA_scale,

        1.0f

    );


    // car body

    glBegin(GL_POLYGON);

    glColor3f(0.82f, 0.08f, 0.08f);

    glVertex2f(-0.60f, 0.05f);

    glVertex2f(-0.50f,-0.10f);

    glVertex2f(-0.30f,-0.15f);

    glVertex2f( 0.35f,-0.15f);

    glVertex2f( 0.55f,-0.05f);

    glVertex2f( 0.65f, 0.05f);

    glVertex2f( 0.60f, 0.20f);

    glVertex2f( 0.45f, 0.25f);

    glVertex2f(-0.45f, 0.25f);

    glVertex2f(-0.60f, 0.15f);

    glEnd();


    // roof

    glBegin(GL_POLYGON);

    glColor3f(0.70f, 0.05f, 0.06f);

    glVertex2f(-0.25f,-0.14f);

    glVertex2f(-0.10f,-0.34f);

    glVertex2f( 0.20f,-0.34f);

    glVertex2f( 0.38f,-0.14f);

    glEnd();


    // left window

    glBegin(GL_QUADS);

    glColor3f(0.55f, 0.80f, 0.92f);

    glVertex2f(-0.20f,-0.15f);

    glVertex2f(-0.08f,-0.30f);

    glVertex2f( 0.02f,-0.30f);

    glVertex2f( 0.02f,-0.15f);

    glEnd();


    // right window

    glBegin(GL_QUADS);

    glColor3f(0.55f, 0.80f, 0.92f);

    glVertex2f(0.06f,-0.15f);

    glVertex2f(0.06f,-0.30f);

    glVertex2f(0.17f,-0.30f);

    glVertex2f(0.31f,-0.15f);

    glEnd();


    // window divider

    glBegin(GL_QUADS);

    glColor3f(0.12f,0.12f,0.12f);

    glVertex2f(0.02f,-0.30f);

    glVertex2f(0.06f,-0.30f);

    glVertex2f(0.06f,-0.15f);

    glVertex2f(0.02f,-0.15f);

    glEnd();


    // front light

    glBegin(GL_QUADS);


        glColor3f(0.35f, 0.30f, 0.08f);

    glVertex2f(0.54f,-0.03f);

    glVertex2f(0.62f,0.02f);

    glVertex2f(0.61f,0.09f);

    glVertex2f(0.54f,0.06f);

    glEnd();


    // back light

    // becomes bright while the red car horn is playing

    glBegin(GL_QUADS);

    if(JA_redHornLight == 1)

        glColor3f(1.0f, 1.0f, 0.15f);

    else

    glColor3f(1.0f,0.20f,0.10f);

    glVertex2f(-0.59f,0.03f);

    glVertex2f(-0.52f,0.02f);

    glVertex2f(-0.52f,0.10f);

    glVertex2f(-0.59f,0.11f);

    glEnd();


    // tyres

    glColor3f(0.04f,0.04f,0.04f);

    JA_drawFilledCircle(-0.35f,0.23f,0.12f);

    JA_drawFilledCircle(0.38f,0.23f,0.12f);


    // wheel centers

    glColor3f(0.65f,0.65f,0.65f);

    JA_drawFilledCircle(-0.35f,0.23f,0.055f);

    JA_drawFilledCircle(0.38f,0.23f,0.055f);


    // rotating red marks on the two wheels

    glPushMatrix();

    glTranslatef(-0.35f, 0.23f, 0.0f);

    glRotatef(JA_wheelAngle1, 0.0f, 0.0f, 1.0f);

    JA_drawWheelMark();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.38f, 0.23f, 0.0f);

    glRotatef(JA_wheelAngle1, 0.0f, 0.0f, 1.0f);

    JA_drawWheelMark();

    glPopMatrix();

    glPopMatrix();

}


// blue car

void JA_drawCar2()

{

    GLfloat JA_scale2;

    glPushMatrix();

    // moves the car to the left on Road 1

    glTranslatef(

        8.50f - JA_car2Position,

        3.60f + JA_car2Position2,

        0.0f

    );

    // follows the angle of Road 1

    glRotatef(

        -7.0f,

        0.0f,

        0.0f,

        1.0f

    );

    // slight size change during movement

    JA_scale2 = 1.0f + JA_car2Position * 0.005f;

    if(JA_scale2 > 1.05f)

    {

        JA_scale2 = 1.05f;

    }

    glScalef(

        -0.52f * JA_scale2,

         0.40f * JA_scale2,

         1.0f

    );


    // car body

    glBegin(GL_POLYGON);

    glColor3f(0.10f, 0.40f, 0.80f);

    glVertex2f(-0.60f, 0.05f);

    glVertex2f(-0.50f,-0.10f);

    glVertex2f(-0.30f,-0.15f);

    glVertex2f( 0.35f,-0.15f);

    glVertex2f( 0.55f,-0.05f);

    glVertex2f( 0.65f, 0.05f);

    glVertex2f( 0.60f, 0.20f);

    glVertex2f( 0.45f, 0.25f);

    glVertex2f(-0.45f, 0.25f);

    glVertex2f(-0.60f, 0.15f);

    glEnd();


    // roof

    glBegin(GL_POLYGON);

    glColor3f(0.05f, 0.25f, 0.60f);

    glVertex2f(-0.25f,-0.14f);

    glVertex2f(-0.10f,-0.34f);

    glVertex2f( 0.20f,-0.34f);

    glVertex2f( 0.38f,-0.14f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.55f, 0.80f, 0.92f);

    glVertex2f(-0.20f,-0.15f);

    glVertex2f(-0.08f,-0.30f);

    glVertex2f( 0.02f,-0.30f);

    glVertex2f( 0.02f,-0.15f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.55f, 0.80f, 0.92f);

    glVertex2f(0.06f,-0.15f);

    glVertex2f(0.06f,-0.30f);

    glVertex2f(0.17f,-0.30f);

    glVertex2f(0.31f,-0.15f);

    glEnd();


    glBegin(GL_QUADS);

    glColor3f(0.12f,0.12f,0.12f);

    glVertex2f(0.02f,-0.30f);

    glVertex2f(0.06f,-0.30f);

    glVertex2f(0.06f,-0.15f);

    glVertex2f(0.02f,-0.15f);

    glEnd();


    // front light

    glBegin(GL_QUADS);


        glColor3f(0.35f, 0.30f, 0.08f);

    glVertex2f(0.54f,-0.03f);

    glVertex2f(0.62f,0.02f);

    glVertex2f(0.61f,0.09f);

    glVertex2f(0.54f,0.06f);

    glEnd();

    // back light

    // becomes bright while the blue car horn is playing

    glBegin(GL_QUADS);

    if(JA_blueHornLight == 1)

        glColor3f(1.0f, 1.0f, 0.15f);

    else

    glColor3f(1.0f,0.20f,0.10f);

    glVertex2f(-0.59f,0.03f);

    glVertex2f(-0.52f,0.02f);

    glVertex2f(-0.52f,0.10f);

    glVertex2f(-0.59f,0.11f);

    glEnd();


    // door outline

    glBegin(GL_LINE_LOOP);

    glColor3f(0.03f,0.15f,0.35f);

    glVertex2f(-0.03f,-0.12f);

    glVertex2f(0.32f,-0.12f);

    glVertex2f(0.34f,0.18f);

    glVertex2f(-0.04f,0.18f);

    glEnd();


    glColor3f(0.04f,0.04f,0.04f);

    JA_drawFilledCircle(-0.35f,0.23f,0.12f);

    JA_drawFilledCircle(0.38f,0.23f,0.12f);


    glColor3f(0.65f,0.65f,0.65f);

    JA_drawFilledCircle(-0.35f,0.23f,0.055f);

    JA_drawFilledCircle(0.38f,0.23f,0.055f);


    // rotating red marks on the two wheels

    glPushMatrix();

    glTranslatef(-0.35f, 0.23f, 0.0f);

    glRotatef(JA_wheelAngle2, 0.0f, 0.0f, 1.0f);

    JA_drawWheelMark();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.38f, 0.23f, 0.0f);

    glRotatef(JA_wheelAngle2, 0.0f, 0.0f, 1.0f);

    JA_drawWheelMark();

    glPopMatrix();

    glPopMatrix();

}


// green field areas

void JA_drawFields()

{

    glColor3f(0.071f, 0.431f, 0.196f);

    // small narrow field in front of left building

    glBegin(GL_POLYGON);

       glColor3f(0.071f, 0.431f, 0.196f);   // RGB 18,110,50

         glVertex2f(0.0f, 4.2f);

         glVertex2f(3.6f, 3.9f);

         glVertex2f(3.6f, 4.2f);

         glVertex2f(0.0f, 4.6f);

         glEnd();

    // field behind the main road

    glBegin(GL_POLYGON);

        glVertex2f(3.4f, 3.2f);

        glVertex2f(9.5f, 3.2f);

        glVertex2f(9.5f, 3.8f);

        glVertex2f(3.4f, 4.2f);

    glEnd();

    // large middle field

    glBegin(GL_POLYGON);

        glVertex2f(0.3f, 4.5f);

        glVertex2f(5.2f, 3.8f);

        glVertex2f(13.0f, 7.0f);

        glVertex2f(2.0f, 7.0f);

    glEnd();

    // left bottom field

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f, 4.6f);

        glVertex2f(0.0f, 7.0f);

        glVertex2f(2.2f, 7.0f);

    glEnd();

    // field near the center road

    glBegin(GL_POLYGON);

        glVertex2f(5.0f, 3.8f);

        glVertex2f(9.6f, 3.4f);

        glVertex2f(9.6f, 5.7f);

        glVertex2f(9.0f, 5.8f);

        glVertex2f(5.5f, 4.4f);

    glEnd();

    // narrow field near the right building

    glBegin(GL_POLYGON);

        glVertex2f(9.2f, 5.2f);

        glVertex2f(14.4f, 5.8f);

        glVertex2f(14.4f, 6.2f);

        glVertex2f(9.0f, 5.7f);

    glEnd();

    // bottom right field

    glBegin(GL_POLYGON);

        glVertex2f(10.0f, 5.9f);

        glVertex2f(14.4f, 6.0f);

        glVertex2f(14.4f, 7.0f);

        glVertex2f(12.5f, 7.0f);

    glEnd();

}

// one small grass shape

void JA_drawGrassTuft()

{

    glBegin(GL_LINES);

    glColor3f(0.10f, 0.55f, 0.10f);

    glVertex2f(-0.3f, -0.2f);

    glVertex2f( 0.0f,  0.0f);

    glVertex2f(-0.2f, -0.3f);

    glVertex2f( 0.0f,  0.0f);

    glVertex2f(-0.1f, -0.2f);

    glVertex2f( 0.0f,  0.0f);

    glVertex2f( 0.0f, -0.3f);

    glVertex2f( 0.0f,  0.0f);

    glVertex2f( 0.1f, -0.2f);

    glVertex2f( 0.0f,  0.0f);

    glVertex2f( 0.2f, -0.3f);

    glVertex2f( 0.0f,  0.0f);

    glEnd();

}


// place grass in different field areas

void JA_drawFieldGrasses()

{

    // grass in field 1

    glPushMatrix();

    glTranslatef(4.0f, 3.7f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(4.8f, 3.6f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(5.6f, 3.6f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(6.4f, 3.5f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(7.2f, 3.5f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();


    // grass in field 2

    glPushMatrix();

    glTranslatef(1.4f, 5.3f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(2.4f, 5.2f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(3.4f, 5.1f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(4.4f, 5.0f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(2.0f, 6.0f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(3.0f, 6.0f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(4.0f, 5.9f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(5.0f, 5.8f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(3.0f, 6.7f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(4.2f, 6.6f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(5.4f, 6.5f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(6.4f, 6.4f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(7.4f, 6.3f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();


    // grass in field 3

    glPushMatrix();

    glTranslatef(0.4f, 5.7f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.6f, 6.3f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(0.8f, 6.8f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();


    // grass in field 4

    glPushMatrix();

    glTranslatef(6.4f, 4.4f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(7.2f, 4.3f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(8.0f, 4.2f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(8.7f, 4.2f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(7.4f, 4.9f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(8.2f, 4.8f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(8.8f, 5.1f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();


    // no grass in the narrow right field

    /*glPushMatrix();

    glTranslatef(10.0f, 5.7f, 0.0f);

    drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(11.0f, 5.8f, 0.0f);

    drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(12.0f, 5.9f, 0.0f);

    drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(13.0f, 6.0f, 0.0f);

    drawGrassTuft();

    glPopMatrix();*/


    // grass in field 6

    glPushMatrix();

    glTranslatef(11.4f, 6.5f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(12.3f, 6.6f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(13.2f, 6.6f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(14.0f, 6.7f, 0.0f);

    JA_drawGrassTuft();

    glPopMatrix();

}




void Jarif_display()
{

   // clear the previous frame

    glClearColor(

        0.80f,

        0.85f,

        0.88f,

        1.0f

    );

    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();


    // Sky

    glBegin(GL_QUADS);

    glColor3f(0.22f, 0.55f, 0.81f);

    glVertex2f(0.0f,0.0f);

    glVertex2f(14.40f,0.0f);

    glVertex2f(14.40f,3.10f);

    glVertex2f(0.0f,3.10f);

    glEnd();


    // Cloud 1

    glPushMatrix();

    glTranslatef(

        JA_position + 4.0f,

        0.0f,

        0.0f

    );

    int JA_i;

    GLfloat JA_twicePi = 2.0f * 3.1415926f;

    int JA_triangleAmount = 50;

    glColor3f(1.0f, 1.0f, 1.0f);

    GLfloat JA_x = 0.0f;

    GLfloat JA_y = 1.0f;

    GLfloat JA_radius = 0.4f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();


    JA_x = 0.6f;

    JA_y = 0.9f;

    JA_radius = 0.5f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();


    JA_x = 1.2f;

    JA_y = 1.0f;

    JA_radius = 0.4f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();

    glPopMatrix();


    // Cloud 2

    glPushMatrix();

    glTranslatef(

        JA_position + 7.0f,

        0.0f,

        0.0f

    );

    glScalef(

        0.9f,

        0.9f,

        1.0f

    );

    glColor3f(1.0f, 1.0f, 1.0f);


    JA_x = 0.0f;

    JA_y = 1.0f;

    JA_radius = 0.4f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();


    JA_x = 0.6f;

    JA_y = 0.9f;

    JA_radius = 0.5f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();


    JA_x = 1.2f;

    JA_y = 1.0f;

    JA_radius = 0.4f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(JA_x, JA_y);

    for(JA_i = 0; JA_i <= JA_triangleAmount; JA_i++)

    {

        glVertex2f(

            JA_x + JA_radius * cos(JA_i * JA_twicePi / JA_triangleAmount),

            JA_y + JA_radius * sin(JA_i * JA_twicePi / JA_triangleAmount)

        );

    }

    glEnd();

    glPopMatrix();


    // dark base behind the lower scene

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(0.0f,2.90f);

    glVertex2f(14.40f,2.90f);

    glVertex2f(14.40f,7.00f);

    glVertex2f(0.0f,7.00f);

    glEnd();


    // draw all green field parts

    JA_drawFields();


    // buildings in the back

    JA_drawBackgroundBuildings();


    // Road 1

    glBegin(GL_QUADS);

    glColor3f(0.57f,0.57f,0.54f);

    glVertex2f(0.0f, 4.4f);

    glVertex2f(9.4f, 3.3f);

    glVertex2f(9.4f, 3.7f);

    glVertex2f(0.0f, 4.8f);

    glEnd();


    // Road 2

    glBegin(GL_QUADS);

    glColor3f(0.57f,0.57f,0.54f);

    glVertex2f(0.0f, 4.7f);

    glVertex2f(2.0f, 7.4f);

    glVertex2f(2.4f, 7.2f);

    glVertex2f(0.5f, 4.5f);

    glEnd();


    // Road 3

    glBegin(GL_QUADS);

    glColor3f(0.57f,0.57f,0.54f);

      glVertex2f(4.7f,4.2f);

      glVertex2f(12.7f,7.5f);

      glVertex2f(12.9f,7.1f);

      glVertex2f(4.9f,3.9f);

    glEnd();


    // Road 4

    glBegin(GL_QUADS);

    glColor3f(0.57f,0.57f,0.54f);

     glVertex2f(8.8f, 5.9f);

     glVertex2f(14.4f, 6.5f);

     glVertex2f(14.4f, 6.1f);

     glVertex2f(8.8f, 5.5f);

    glEnd();


    // add grass on top of the fields

    JA_drawFieldGrasses();


    // front buildings

    JA_drawLeftBuilding();

    JA_drawRightBuilding();

    // moving cars

    JA_drawCar();

    JA_drawCar2();


    glFlush();

}

void JA_reshape(int JA_width, int JA_height)

{

    glViewport(

        0,

        0,

        JA_width,

        JA_height

    );

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    // project coordinates: x = 0..14.4, y = 0..7

    gluOrtho2D(

        0.0,

        14.40,

        7.00,

        0.0

    );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}





//Israt's part




 float ManzilCarPosition = -1.3f;

float ManzilCarSpeed = 0.005f;

float ManzilCloudPosition = 0.0f;

float ManzilCloudSpeed = 0.0015f;

// Traffic Light & Wheel Variables

bool ManzilIsGreenLight = true;

float ManzilWheelAngle = 0.0f;

// Circle Function

void ManzilDrawCircle(GLfloat x, GLfloat y, GLfloat radius,

                GLfloat r, GLfloat g, GLfloat b,

                GLfloat startAngle = 0.0f,

                GLfloat endAngle = 2.0f * PI)

{

    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(x, y);

        int segments = 100;

        for (int i = 0; i <= segments; i++)

        {

            float angle = startAngle +

                          (endAngle - startAngle) * i / segments;

            glVertex2f(

                x + radius * cos(angle),

                y + radius * sin(angle)

            );

        }

    glEnd();

}

// Rectangle

void ManzilDrawRect(GLfloat x1, GLfloat y1,

              GLfloat x2, GLfloat y2,

              GLfloat r, GLfloat g, GLfloat b)

{

    glColor3f(r, g, b);

    glBegin(GL_QUADS);

        glVertex2f(x1, y1);

        glVertex2f(x2, y1);

        glVertex2f(x2, y2);

        glVertex2f(x1, y2);

    glEnd();

}

// Small Grass

void ManzilDrawSmallGrass(GLfloat x, GLfloat y, GLfloat scale)

{

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glScalef(scale, scale, 1.0f);

    // Left leaf

    glColor3f(0.10f, 0.50f, 0.15f);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f, 0.0f);

        glVertex2f(-0.04f, 0.0f);

        glVertex2f(-0.05f, 0.12f);

    glEnd();

    // Middle leaf

    glColor3f(0.15f, 0.60f, 0.20f);

    glBegin(GL_TRIANGLES);

        glVertex2f(-0.02f, 0.0f);

        glVertex2f(0.02f, 0.0f);

        glVertex2f(0.0f, 0.15f);

    glEnd();

    // Right leaf

    glColor3f(0.08f, 0.45f, 0.12f);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f, 0.0f);

        glVertex2f(0.04f, 0.0f);

        glVertex2f(0.05f, 0.11f);

    glEnd();

    glPopMatrix();

}

/* Palm Tree */

void ManzilDrawPalmTree(GLfloat x, GLfloat y, GLfloat scale)

{

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glScalef(scale, scale, 1.0f);

    // Trunk

    ManzilDrawRect(

        -0.025f, 0.0f,

         0.025f, 0.38f,

         0.36f, 0.24f, 0.12f

    );

    // Top base

    ManzilDrawCircle(

        0.0f, 0.39f, 0.055f,

        0.05f, 0.30f, 0.08f

    );

    // Leaves

    glColor3f(0.06f, 0.35f, 0.10f);

    glBegin(GL_TRIANGLES);

        glVertex2f(0.0f, 0.40f);

        glVertex2f(-0.28f, 0.48f);

        glVertex2f(-0.10f, 0.37f);

        glVertex2f(0.0f, 0.41f);

        glVertex2f(-0.20f, 0.62f);

        glVertex2f(-0.06f, 0.43f);

        glVertex2f(0.0f, 0.42f);

        glVertex2f(0.02f, 0.70f);

        glVertex2f(0.06f, 0.43f);

        glVertex2f(0.0f, 0.41f);

        glVertex2f(0.22f, 0.62f);

        glVertex2f(0.08f, 0.43f);

        glVertex2f(0.0f, 0.40f);

        glVertex2f(0.30f, 0.49f);

        glVertex2f(0.10f, 0.37f);

        glVertex2f(0.0f, 0.39f);

        glVertex2f(0.24f, 0.29f);

        glVertex2f(0.08f, 0.38f);

        glVertex2f(0.0f, 0.39f);

        glVertex2f(-0.24f, 0.29f);

        glVertex2f(-0.08f, 0.38f);

    glEnd();

    glPopMatrix();

}

/* National Flag */

void ManzilDrawFlag(GLfloat x, GLfloat y, GLfloat scale)

{

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glScalef(scale, scale, 1.0f);

    // Base

    ManzilDrawRect(

        -0.02f, 0.0f,

         0.02f, 0.04f,

         0.30f, 0.30f, 0.30f

    );

    // Pole

    ManzilDrawRect(

        -0.008f, 0.04f,

         0.008f, 0.55f,

         0.70f, 0.70f, 0.70f

    );

    // Green body

    ManzilDrawRect(

        0.008f, 0.33f,

        0.26f, 0.52f,

        0.00f, 0.42f, 0.22f

    );

    // Red circle

    ManzilDrawCircle(

        0.13f, 0.425f, 0.055f,

        0.85f, 0.10f, 0.10f

    );

    // Top head of pole

    ManzilDrawCircle(

        0.0f, 0.555f, 0.012f,

        0.90f, 0.75f, 0.20f

    );

    glPopMatrix();

}

/* Cloud Shape */

void ManzilDrawCloudShape(GLfloat scale, GLfloat whiteness)

{

    // Left circle

    ManzilDrawCircle(

        -0.07f * scale, 0.0f,

        0.050f * scale,

        whiteness, whiteness, whiteness,

        0, 2 * PI

    );

    // Middle circle

    ManzilDrawCircle(

        0.0f, 0.025f * scale,

        0.070f * scale,

        whiteness, whiteness, whiteness,

        0, 2 * PI

    );

    // Right circle

    ManzilDrawCircle(

        0.07f * scale, 0.0f,

        0.050f * scale,

        whiteness, whiteness, whiteness,

        0, 2 * PI

    );

}

/* Moving Cloud */

void ManzilDrawMovingCloud(GLfloat cx, GLfloat cy,

                     GLfloat scale, GLfloat whiteness)

{

    glPushMatrix();

    float currentX = cx + ManzilCloudPosition;

    if (currentX > 1.3f)

    {

        currentX -= 2.6f;

    }

    glTranslatef(currentX, cy, 0.0f);

    ManzilDrawCloudShape(scale, whiteness);

    glPopMatrix();

}

/* Building Arch */

void ManzilDrawArch(GLfloat x, GLfloat bottom,

              GLfloat width, GLfloat height)

{

    GLfloat half = width / 2.0f;

    GLfloat rectTop = bottom + height * 0.60f;

    ManzilDrawRect(

        x - half, bottom,

        x + half, rectTop,

        0.12f, 0.22f, 0.28f

    );

    ManzilDrawCircle(

        x, rectTop, half,

        0.12f, 0.22f, 0.28f,

        0.0f, PI

    );

}

/* Pillar Column */

void ManzilDrawColumn(GLfloat x, GLfloat bottom, GLfloat height)

{

    // Column

    ManzilDrawRect(

        x - 0.012f, bottom,

        x + 0.012f, bottom + height,

        0.78f, 0.38f, 0.50f

    );

    // Top

    ManzilDrawRect(

        x - 0.022f,

        bottom + height - 0.015f,

        x + 0.022f,

        bottom + height,

        0.68f, 0.30f, 0.42f

    );

    // Bottom

    ManzilDrawRect(

        x - 0.020f, bottom,

        x + 0.020f, bottom + 0.015f,

        0.68f, 0.30f, 0.42f

    );

}

/* Bush Shape */

void ManzilDrawBush(GLfloat x, GLfloat y, GLfloat scale)

{

    ManzilDrawCircle(

        x, y, 0.045f * scale,

        0.08f, 0.38f, 0.10f,

        0, 2 * PI

    );

    ManzilDrawCircle(

        x - 0.035f * scale,

        y + 0.01f * scale,

        0.035f * scale,

        0.10f, 0.45f, 0.12f,

        0, 2 * PI

    );

    ManzilDrawCircle(

        x + 0.035f * scale,

        y + 0.01f * scale,

        0.035f * scale,

        0.07f, 0.34f, 0.09f,

        0, 2 * PI

    );

}

/* Human-Drawn Style Car */

void ManzilDrawCar()

{

    glPushMatrix();

    glTranslatef(ManzilCarPosition, -0.82f, 0.0f);

    // Car Silhouette (More detailed polynomial shape)

    glColor3f(0.85f, 0.2f, 0.2f);

    glBegin(GL_POLYGON);

        glVertex2f(-0.16f, 0.02f);

        glVertex2f(-0.16f, 0.06f);

        glVertex2f(-0.10f, 0.07f);

        glVertex2f(-0.04f, 0.12f);

        glVertex2f(0.04f,  0.12f);

        glVertex2f(0.12f,  0.07f);

        glVertex2f(0.16f,  0.06f);

        glVertex2f(0.16f,  0.02f);

    glEnd();

    // Back Window

    glColor3f(0.6f, 0.8f, 1.0f);

    glBegin(GL_POLYGON);

        glVertex2f(-0.09f, 0.075f);

        glVertex2f(-0.04f, 0.11f);

        glVertex2f(-0.01f, 0.11f);

        glVertex2f(-0.01f, 0.075f);

    glEnd();

    // Front Window

    glBegin(GL_POLYGON);

        glVertex2f(0.01f, 0.075f);

        glVertex2f(0.01f, 0.11f);

        glVertex2f(0.04f, 0.11f);

        glVertex2f(0.09f, 0.075f);

    glEnd();

    // Left Wheel (with Triangle Spokes)

    glPushMatrix();

    glTranslatef(-0.09f, 0.02f, 0.0f);

    glRotatef(ManzilWheelAngle, 0.0f, 0.0f, 1.0f);

    ManzilDrawCircle(0.0f, 0.0f, 0.035f, 0.1f, 0.1f, 0.1f, 0, 2 * PI);

    // Spokes

    glColor3f(0.7f, 0.7f, 0.7f);

    for(int i = 0; i < 5; i++) {

        float angle = i * 2.0f * PI / 5.0f;

        glBegin(GL_TRIANGLES);

            glVertex2f(0.0f, 0.0f);

            glVertex2f(0.025f * cos(angle - 0.2f), 0.025f * sin(angle - 0.2f));

            glVertex2f(0.025f * cos(angle + 0.2f), 0.025f * sin(angle + 0.2f));

        glEnd();

    }

    glPopMatrix();

    // Right Wheel (with Triangle Spokes)

    glPushMatrix();

    glTranslatef(0.09f, 0.02f, 0.0f);

    glRotatef(ManzilWheelAngle, 0.0f, 0.0f, 1.0f);

    ManzilDrawCircle(0.0f, 0.0f, 0.035f, 0.1f, 0.1f, 0.1f, 0, 2 * PI);

    // Spokes

    glColor3f(0.7f, 0.7f, 0.7f);

    for(int i = 0; i < 5; i++) {

        float angle = i * 2.0f * PI / 5.0f;

        glBegin(GL_TRIANGLES);

            glVertex2f(0.0f, 0.0f);

            glVertex2f(0.025f * cos(angle - 0.2f), 0.025f * sin(angle - 0.2f));

            glVertex2f(0.025f * cos(angle + 0.2f), 0.025f * sin(angle + 0.2f));

        glEnd();

    }

    glPopMatrix();

    glPopMatrix();

}

/* Vertical Crosswalk */

void ManzilDrawCrosswalk() {

    // Drawing horizontal stripes spanning the road height vertically

    for (float cy = -0.98f; cy <= -0.72f; cy += 0.04f) {

        ManzilDrawRect(0.45f, cy, 0.65f, cy + 0.02f, 1.0f, 1.0f, 1.0f);

    }

}

/* Traffic Light */

void ManzilDrawTrafficLight() {

    // Pole

    ManzilDrawRect(0.72f, -0.75f, 0.74f, -0.3f, 0.2f, 0.2f, 0.2f);

    // Box

    ManzilDrawRect(0.68f, -0.3f, 0.78f, 0.0f, 0.1f, 0.1f, 0.1f);

    // Red Light

    if (!ManzilIsGreenLight) ManzilDrawCircle(0.73f, -0.10f, 0.04f, 1.0f, 0.0f, 0.0f);

    else ManzilDrawCircle(0.73f, -0.10f, 0.04f, 0.3f, 0.0f, 0.0f);

    // Green Light

    if (ManzilIsGreenLight) ManzilDrawCircle(0.73f, -0.22f, 0.04f, 0.0f, 1.0f, 0.0f);

    else ManzilDrawCircle(0.73f, -0.22f, 0.04f, 0.0f, 0.3f, 0.0f);

}




void Israt_display()
 {

     glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Sky

    ManzilDrawRect(

        -1.0f, -0.15f,

         1.0f, 1.0f,

         0.40f, 0.65f, 0.88f

    );

    // Clouds

    ManzilDrawMovingCloud(-0.75f, 0.78f, 0.60f, 0.98f);

    ManzilDrawMovingCloud(-0.35f, 0.88f, 0.75f, 1.00f);

    ManzilDrawMovingCloud( 0.05f, 0.72f, 0.60f, 0.97f);

    ManzilDrawMovingCloud( 0.45f, 0.88f, 0.75f, 1.00f);

    ManzilDrawMovingCloud( 0.80f, 0.65f, 0.50f, 0.95f);

    // Grass lawn

    ManzilDrawRect(

        -1.0f, -0.70f,

         1.0f, -0.15f,

         0.16f, 0.55f, 0.20f

    );

    // Building colors

    GLfloat pinkR = 0.91f;

    GLfloat pinkG = 0.50f;

    GLfloat pinkB = 0.64f;

    GLfloat darkR = 0.73f;

    GLfloat darkG = 0.34f;

    GLfloat darkB = 0.46f;

    GLfloat trimR = 0.98f;

    GLfloat trimG = 0.85f;

    GLfloat trimB = 0.70f;

    // Main walls

    ManzilDrawRect(

        -0.90f, -0.15f,

        -0.25f, 0.30f,

        pinkR, pinkG, pinkB

    );

    ManzilDrawRect(

         0.25f, -0.15f,

         0.90f, 0.30f,

         pinkR, pinkG, pinkB

    );

    ManzilDrawRect(

        -0.32f, -0.15f,

         0.32f, 0.40f,

         pinkR, pinkG, pinkB

    );

    ManzilDrawRect(

        -0.18f, 0.38f,

         0.18f, 0.68f,

         pinkR, pinkG, pinkB

    );

    ManzilDrawRect(

        -0.82f, 0.30f,

        -0.25f, 0.36f,

        pinkR, pinkG, pinkB

    );

    ManzilDrawRect(

         0.25f, 0.30f,

         0.82f, 0.36f,

         pinkR, pinkG, pinkB

    );

    // Decorative trims

    ManzilDrawRect(

        -0.92f, 0.29f,

         0.92f, 0.31f,

         darkR, darkG, darkB

    );

    ManzilDrawRect(

        -0.92f, 0.31f,

         0.92f, 0.325f,

         trimR, trimG, trimB

    );

    ManzilDrawRect(

        -0.90f, 0.35f,

         0.90f, 0.365f,

         darkR, darkG, darkB

    );

    ManzilDrawRect(

        -0.34f, 0.39f,

         0.34f, 0.41f,

         trimR, trimG, trimB

    );

    // Dome base

    ManzilDrawRect(

        -0.20f, 0.67f,

         0.20f, 0.71f,

         darkR, darkG, darkB

    );

    ManzilDrawRect(

        -0.21f, 0.69f,

         0.21f, 0.705f,

         trimR, trimG, trimB

    );

    // Ornaments

    for (int i = -8; i <= 8; i++)

    {

        ManzilDrawCircle(

            i * 0.105f, 0.335f, 0.009f,

            0.60f, 0.27f, 0.37f,

            0, 2 * PI

        );

        ManzilDrawCircle(

            i * 0.105f, 0.335f, 0.005f,

            trimR, trimG, trimB,

            0, 2 * PI

        );

    }

    // Dome

    ManzilDrawCircle(

        0.0f, 0.69f, 0.20f,

        0.94f, 0.58f, 0.70f,

        0, PI

    );

    // Arches

    ManzilDrawArch(-0.78f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(-0.60f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(-0.42f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(0.42f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(0.60f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(0.78f, -0.10f, 0.10f, 0.27f);

    ManzilDrawArch(0.0f, -0.10f, 0.13f, 0.42f);

    // Pillars

    ManzilDrawColumn(-0.84f, 0.17f, 0.15f);

    ManzilDrawColumn(-0.70f, 0.17f, 0.15f);

    ManzilDrawColumn(-0.56f, 0.17f, 0.15f);

    ManzilDrawColumn(-0.42f, 0.17f, 0.15f);

    ManzilDrawColumn(0.42f, 0.17f, 0.15f);

    ManzilDrawColumn(0.56f, 0.17f, 0.15f);

    ManzilDrawColumn(0.70f, 0.17f, 0.15f);

    ManzilDrawColumn(0.84f, 0.17f, 0.15f);

    // Upper arches

    ManzilDrawArch(-0.10f, 0.42f, 0.07f, 0.20f);

    ManzilDrawArch( 0.10f, 0.42f, 0.07f, 0.20f);

    // Stairs

    int steps = 20;

    GLfloat bottomY = -0.65f;

    GLfloat topY = -0.15f;

    GLfloat bottomWidth = 0.48f;

    GLfloat topWidth = 0.11f;

    for (int i = 0; i < steps; i++)

    {

        GLfloat t0 = (GLfloat)i / steps;

        GLfloat t1 = (GLfloat)(i + 1) / steps;

        GLfloat y0 = bottomY + (topY - bottomY) * t0;

        GLfloat y1 = bottomY + (topY - bottomY) * t1;

        GLfloat w0 = bottomWidth +

                     (topWidth - bottomWidth) * t0;

        GLfloat w1 = bottomWidth +

                     (topWidth - bottomWidth) * t1;

        glColor3f(0.43f, 0.40f, 0.34f);

        glBegin(GL_QUADS);

            glVertex2f(-w0, y0);

            glVertex2f( w0, y0);

            glVertex2f( w1, y1);

            glVertex2f(-w1, y1);

        glEnd();

    }

    // Side grass

    ManzilDrawSmallGrass(-0.49f, -0.64f, 0.5f);

    ManzilDrawSmallGrass(-0.41f, -0.54f, 0.45f);

    ManzilDrawSmallGrass(-0.33f, -0.44f, 0.4f);

    ManzilDrawSmallGrass(-0.25f, -0.34f, 0.35f);

    ManzilDrawSmallGrass(-0.18f, -0.24f, 0.3f);

    ManzilDrawSmallGrass(0.47f, -0.64f, 0.5f);

    ManzilDrawSmallGrass(0.39f, -0.54f, 0.45f);

    ManzilDrawSmallGrass(0.31f, -0.44f, 0.4f);

    ManzilDrawSmallGrass(0.23f, -0.34f, 0.35f);

    ManzilDrawSmallGrass(0.16f, -0.24f, 0.3f);

    // Palm trees

    ManzilDrawPalmTree(-0.95f, -0.15f, 0.90f);

    ManzilDrawPalmTree(-0.78f, -0.15f, 0.75f);

    ManzilDrawPalmTree(0.80f, -0.15f, 0.80f);

    ManzilDrawPalmTree(0.97f, -0.15f, 0.90f);

    // Flag

    ManzilDrawFlag(-0.68f, -0.42f, 0.85f);

    // Bushes

    ManzilDrawBush(-0.60f, -0.60f, 0.9f);

    ManzilDrawBush(0.60f, -0.60f, 0.9f);

    // Road

    ManzilDrawRect(

        -1.0f, -1.0f,

         1.0f, -0.70f,

         0.25f, 0.25f, 0.28f

    );

    // Road dividers

    for (float rx = -0.9f; rx < 1.0f; rx += 0.35f)

    {

        ManzilDrawRect(

            rx, -0.86f,

            rx + 0.18f, -0.84f,

            1.0f, 1.0f, 1.0f

        );

    }

    // Crosswalk and Traffic Light

    ManzilDrawCrosswalk();

    ManzilDrawTrafficLight();

    // Car

    ManzilDrawCar();

    glutSwapBuffers();


 }

void ManzilUpdate(int value)

{

    bool carMoved = false;

    // Car Movement Logic based on Traffic Light

    if (ManzilIsGreenLight || ManzilCarPosition < 0.2f || ManzilCarPosition > 0.45f) {

        ManzilCarPosition += ManzilCarSpeed;

        carMoved = true;

        if (ManzilCarPosition > 1.3f)

        {

            ManzilCarPosition = -1.3f;

        }

    }

    // Wheel Rotation Logic

    if (carMoved) {

        ManzilWheelAngle -= 5.0f;

        if (ManzilWheelAngle <= -360.0f) {

            ManzilWheelAngle += 360.0f;

        }

    }

    // Cloud

    ManzilCloudPosition += ManzilCloudSpeed;

    if (ManzilCloudPosition > 2.6f)

    {

        ManzilCloudPosition -= 2.6f;

    }

    glutPostRedisplay();

    glutTimerFunc(16, ManzilUpdate, 0);

}

// Auto Traffic Light Timer

void ManzilTrafficLightTimer(int value) {

    ManzilIsGreenLight = !ManzilIsGreenLight;

    // Toggle every 5000 ms (5 seconds)

    glutTimerFunc(5000, ManzilTrafficLightTimer, 0);

}

/* Initialization */

void ManzilInit()

{

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(

        -1.0f, 1.0f,

        -1.0f, 1.0f

    );

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}





//Dhurovbo's part



GLfloat topBlue_x = -120.0f;

GLfloat topRed_x  = -160.0f;

// Bottom Lane (Right to Left)

GLfloat bottomRed_x  = 120.0f;

GLfloat bottomBlue_x = 160.0f;

GLfloat cloud_offset = -50.0f;

// Unified Speeds

GLfloat topSpeed    =  0.5f;

GLfloat bottomSpeed = -0.5f;

GLfloat cloud_speed =  0.1f;

// Traffic Light & Wheel Variables

bool isGreenLight = true;

GLfloat wheelAngle = 0.0f;


// UPDATE ANIMATION FUNCTION

void SangsadUpdate(int value) {

    bool anyCarMoved = false;

    // Top Blue Car - Stops at x = -15.0

    if (isGreenLight || topBlue_x < -15.0f || topBlue_x > -5.0f) {

        topBlue_x += topSpeed;

        if (topBlue_x > 120.0f) topBlue_x = -120.0f;

        anyCarMoved = true;

    }

    // Top Red Car - Stops at x = -55.0 (Queues behind Blue Car)

    if (isGreenLight || topRed_x < -55.0f || topRed_x > -45.0f) {

        topRed_x += topSpeed;

        if (topRed_x > 120.0f) topRed_x = -120.0f;

        anyCarMoved = true;

    }

    // Bottom Red Car - Stops at x = 30.0

    if (isGreenLight || bottomRed_x > 30.0f || bottomRed_x < 20.0f) {

        bottomRed_x += bottomSpeed;

        if (bottomRed_x < -120.0f) bottomRed_x = 120.0f;

        anyCarMoved = true;

    }

    // Bottom Blue Car - Stops at x = 70.0 (Queues behind Red Car)

    if (isGreenLight || bottomBlue_x > 70.0f || bottomBlue_x < 60.0f) {

        bottomBlue_x += bottomSpeed;

        if (bottomBlue_x < -120.0f) bottomBlue_x = 120.0f;

        anyCarMoved = true;

    }

    // Rotate the wheels only if at least one car is moving

    if (anyCarMoved) {

        wheelAngle -= 10.0f;

        if (wheelAngle <= -360.0f) wheelAngle += 360.0f;

    }

    // Clouds (Left to Right) move regardless of traffic light

    cloud_offset += cloud_speed;

    if (cloud_offset > 200.0f) {

        cloud_offset = -150.0f;

    }

    glutPostRedisplay();

    glutTimerFunc(20, SangsadUpdate, 0);

}




// TRAFFIC LIGHT

void SangsadDrawTrafficLight() {

    glPushMatrix();

    glTranslatef(0.0f, -10.0f, 0.0f); // Positioned near the platform/grass

    // Pole

    glColor3f(0.1f, 0.1f, 0.1f);

    glBegin(GL_QUADS);

    glVertex2f(-1.0f, -15.0f);

    glVertex2f(1.0f, -15.0f);

    glVertex2f(1.0f, 0.0f);

    glVertex2f(-1.0f, 0.0f);

    glEnd();

    // Box

    glColor3f(0.2f, 0.2f, 0.2f);

    glBegin(GL_QUADS);

    glVertex2f(-4.0f, 0.0f);

    glVertex2f(4.0f, 0.0f);

    glVertex2f(4.0f, 16.0f);

    glVertex2f(-4.0f, 16.0f);

    glEnd();

    int segments = 30;

    GLfloat r = 2.5f;

    // Red Light

    if (!isGreenLight) glColor3f(1.0f, 0.0f, 0.0f); // Bright Red (ON)

    else glColor3f(0.3f, 0.0f, 0.0f);               // Dim Red (OFF)

    glBegin(GL_POLYGON);

    for(int i = 0; i < segments; i++) {

        float theta = 2.0f * PI * i / segments;

        glVertex2f(0.0f + r * cos(theta), 11.5f + r * sin(theta));

    }

    glEnd();

    // Green Light

    if (isGreenLight) glColor3f(0.0f, 1.0f, 0.0f);  // Bright Green (ON)

    else glColor3f(0.0f, 0.3f, 0.0f);               // Dim Green (OFF)

    glBegin(GL_POLYGON);

    for(int i = 0; i < segments; i++) {

        float theta = 2.0f * PI * i / segments;

        glVertex2f(0.0f + r * cos(theta), 4.5f + r * sin(theta));

    }

    glEnd();

    glPopMatrix();

}


// CLOUD

void SangsadDrawClouds(GLfloat offset) {

    int i, k;

    GLfloat twicePi = 2.0f * PI;

    GLfloat c1_x[] = {-68.0f, -60.0f, -52.0f};

    GLfloat c1_y[] = {70.0f, 73.0f, 70.0f};

    GLfloat c1_r[] = {5.0f, 7.0f, 5.0f};

    glPushMatrix();

    glTranslatef(offset, 0.0f, 0.0f);

    //Cloud 1 (Left side)

    glColor3f(1.0f, 1.0f, 1.0f);

    for(k = 0; k < 3; k++) {

        glBegin(GL_POLYGON);

        for(i = 0; i <= 100; i++) {

            glVertex2f(c1_x[k] + (c1_r[k] * cos(i * twicePi / 100)),

                       c1_y[k] + (c1_r[k] * sin(i * twicePi / 100)));

        }

        glEnd();

    }

    // Flat bottom for Cloud 1

    glBegin(GL_QUADS);

    glVertex2f(-70.0f, 70.0f);

    glVertex2f(-50.0f, 70.0f);

    glVertex2f(-50.0f, 68.0f);

    glVertex2f(-70.0f, 68.0f);

    glEnd();

    //Cloud 2 (Right side)

    glPushMatrix();

    glTranslatef(110.0f, -10.0f, 0.0f);

    for(k = 0; k < 3; k++) {

        glBegin(GL_POLYGON);

        for(i = 0; i <= 100; i++) {

            glVertex2f(c1_x[k] + (c1_r[k] * cos(i * twicePi / 100)),

                       c1_y[k] + (c1_r[k] * sin(i * twicePi / 100)));

        }

        glEnd();

    }

    // Flat bottom for Cloud 2

    glBegin(GL_QUADS);

    glVertex2f(-70.0f, 70.0f);

    glVertex2f(-50.0f, 70.0f);

    glVertex2f(-50.0f, 68.0f);

    glVertex2f(-70.0f, 68.0f);

    glEnd();

    glPopMatrix();

    glPopMatrix();

}


// CAR

void SangsadDrawRedCar(GLfloat x, GLfloat y, bool faceLeft) {

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glScalef(60.0f, 60.0f, 1.0f);

    if (faceLeft) {

        glScalef(-1.0f, 1.0f, 1.0f);

    }

    glTranslatef(0.0f, 0.715f, 0.0f);

    glColor3f(0.90f, 0.05f, 0.08f);

    glBegin(GL_QUADS);

    glVertex2f(-0.15f, -0.67f);

    glVertex2f( 0.16f, -0.67f);

    glVertex2f( 0.12f, -0.58f);

    glVertex2f(-0.10f, -0.58f);

    glEnd();

    glColor3f(0.15f, 0.25f, 0.45f);

    glBegin(GL_QUADS);

    glVertex2f(-0.07f, -0.58f);

    glVertex2f( 0.08f, -0.58f);

    glVertex2f( 0.04f, -0.52f);

    glVertex2f(-0.03f, -0.52f);

    glEnd();

    glColor3f(0.95f, 0.98f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(-0.055f, -0.575f);

    glVertex2f(-0.005f, -0.575f);

    glVertex2f(-0.005f, -0.535f);

    glVertex2f(-0.025f, -0.535f);

    glVertex2f( 0.005f, -0.575f);

    glVertex2f( 0.075f, -0.575f);

    glVertex2f( 0.045f, -0.535f);

    glVertex2f( 0.005f, -0.535f);

    glEnd();

    // BACK WHEEL (with rotation and spokes)

    glPushMatrix();

    glTranslatef(-0.08f, -0.67f, 0.0f);

    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Rotate around center

    glColor3f(0.03f, 0.03f, 0.03f); // Tire

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

    }

    glEnd();

    glColor3f(0.70f, 0.75f, 0.78f); // Hubcap

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.018f * cos(angle), 0.018f * sin(angle));

    }

    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f); // Spokes

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    for(int i = 0; i < 4; i++) {

        float angle = PI * i / 4.0f;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

        glVertex2f(-0.045f * cos(angle), -0.045f * sin(angle));

    }

    glEnd();

    glPopMatrix();

    // FRONT WHEEL (with rotation and spokes)

    glPushMatrix();

    glTranslatef(0.09f, -0.67f, 0.0f);

    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f); // Rotate around center

    glColor3f(0.03f, 0.03f, 0.03f); // Tire

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

    }

    glEnd();

    glColor3f(0.70f, 0.75f, 0.78f); // Hubcap

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.018f * cos(angle), 0.018f * sin(angle));

    }

    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f); // Spokes

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    for(int i = 0; i < 4; i++) {

        float angle = PI * i / 4.0f;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

        glVertex2f(-0.045f * cos(angle), -0.045f * sin(angle));

    }

    glEnd();

    glPopMatrix();

    glPopMatrix();

}

void SangsadDrawBlueCar(GLfloat x, GLfloat y, bool faceLeft) {

    glPushMatrix();

    glTranslatef(x, y, 0.0f);

    glScalef(60.0f, 60.0f, 1.0f);

    if (faceLeft) {

        glScalef(-1.0f, 1.0f, 1.0f);

    }

    glTranslatef(0.0f, 0.615f, 0.0f);

    glColor3f(0.10f, 0.18f, 0.70f);

    glBegin(GL_QUADS);

    glVertex2f(-0.16f, -0.57f);

    glVertex2f( 0.15f, -0.57f);

    glVertex2f( 0.11f, -0.49f);

    glVertex2f(-0.11f, -0.49f);

    glEnd();

    glColor3f(0.12f, 0.20f, 0.40f);

    glBegin(GL_QUADS);

    glVertex2f(-0.08f, -0.49f);

    glVertex2f( 0.08f, -0.49f);

    glVertex2f( 0.04f, -0.43f);

    glVertex2f(-0.03f, -0.43f);

    glEnd();

    glColor3f(0.90f, 0.98f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(-0.06f, -0.485f);

    glVertex2f(-0.01f, -0.485f);

    glVertex2f(-0.01f, -0.445f);

    glVertex2f(-0.03f, -0.445f);

    glVertex2f( 0.00f, -0.485f);

    glVertex2f( 0.07f, -0.485f);

    glVertex2f( 0.04f, -0.445f);

    glVertex2f( 0.00f, -0.445f);

    glEnd();

    // BACK WHEEL (with rotation and spokes)

    glPushMatrix();

    glTranslatef(-0.09f, -0.57f, 0.0f);

    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.03f, 0.03f, 0.03f); // Tire

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

    }

    glEnd();

    glColor3f(0.70f, 0.75f, 0.78f); // Hubcap

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.018f * cos(angle), 0.018f * sin(angle));

    }

    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f); // Spokes

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    for(int i = 0; i < 4; i++) {

        float angle = PI * i / 4.0f;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

        glVertex2f(-0.045f * cos(angle), -0.045f * sin(angle));

    }

    glEnd();

    glPopMatrix();

    // FRONT WHEEL (with rotation and spokes)

    glPushMatrix();

    glTranslatef(0.09f, -0.57f, 0.0f);

    glRotatef(wheelAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.03f, 0.03f, 0.03f); // Tire

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

    }

    glEnd();

    glColor3f(0.70f, 0.75f, 0.78f); // Hubcap

    glBegin(GL_POLYGON);

    for(int i = 0; i < 50; i++) {

        float angle = 2 * PI * i / 50;

        glVertex2f(0.018f * cos(angle), 0.018f * sin(angle));

    }

    glEnd();

    glColor3f(0.1f, 0.1f, 0.1f); // Spokes

    glLineWidth(1.5f);

    glBegin(GL_LINES);

    for(int i = 0; i < 4; i++) {

        float angle = PI * i / 4.0f;

        glVertex2f(0.045f * cos(angle), 0.045f * sin(angle));

        glVertex2f(-0.045f * cos(angle), -0.045f * sin(angle));

    }

    glEnd();

    glPopMatrix();

    glPopMatrix();

}


void SangsadMainBuilding() {

    glLineWidth(1.0f);

    //Building TOP

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-23.0f, 32.0f);

    glVertex2f(-23.0f, 39.0f);

    glVertex2f(-18.0f, 41.0f);

    glVertex2f(-18.0f, 31.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(-23.0f, 32.0f);

    glVertex2f(-23.0f, 39.0f);

    glVertex2f(-18.0f, 41.0f);

    glVertex2f(-18.0f, 31.0f);

    glVertex2f(-23.0f, 32.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-18.0f, 41.0f);

    glVertex2f(-18.0f, 31.0f);

    glVertex2f(-13.0f, 30.0f);

    glVertex2f(-13.0f, 40.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(-18.0f, 41.0f);

    glVertex2f(-18.0f, 31.0f);

    glVertex2f(-13.0f, 30.0f);

    glVertex2f(-13.0f, 40.0f);

    glVertex2f(-18.0f, 41.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-13.0f, 40.0f);

    glVertex2f(-9.0f, 41.0f);

    glVertex2f(-9.0f, 36.0f);

    glVertex2f(-13.0f, 36.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(-13.0f, 40.0f);

    glVertex2f(-9.0f, 41.0f);

    glVertex2f(-9.0f, 36.0f);

    glVertex2f(-13.0f, 36.0f);

    glVertex2f(-13.0f, 40.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-9.0f, 36.0f);

    glVertex2f(-9.0f, 42.0f);

    glVertex2f(4.0f, 42.0f);

    glVertex2f(4.0f, 36.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(-9.0f, 36.0f);

    glVertex2f(-9.0f, 42.0f);

    glVertex2f(4.0f, 42.0f);

    glVertex2f(4.0f, 35.0f);

    glVertex2f(-9.0f, 36.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(10.0f, 41.0f);

    glVertex2f(4.0f, 41.0f);

    glVertex2f(4.0f, 35.0f);

    glVertex2f(10.0f, 35.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(10.0f, 41.0f);

    glVertex2f(4.0f, 41.0f);

    glVertex2f(4.0f, 35.0f);

    glVertex2f(10.0f, 35.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(4.0f, 38.0f);

    glVertex2f(16.0f, 38.0f);

    glEnd();

    //Circle TOP1

    int j;

    GLfloat cx2 = -20.84f;

    GLfloat cy2 = 35.36f;

    GLfloat rx2 = 1.5f;

    GLfloat ry2 = 3.45f;

    int triangleAmount2 = 100;

    GLfloat twicePi2 = 2.0f * PI;

    glColor3f(0.4902f, 0.4824f, 0.4863f); //Dark Gray

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx2, cy2); // center of ellipse

        for(j = 0; j <= triangleAmount2; j++) {

            glVertex2f(

                cx2 + (rx2 * cos(j * twicePi2 / triangleAmount2)),

                cy2 + (ry2 * sin(j * twicePi2 / triangleAmount2))

            );

        }

    glEnd();

    //Circle TOP2

    int k;

    GLfloat cx3 = -2.89f;

    GLfloat cy3 = 36.26f;

    GLfloat radius3 = 5.21f;

    int triangleAmount3 = 100;

    GLfloat twicePi3 = 2.0f * PI;

    glColor3f(0.4902f, 0.4824f, 0.4863f); //Dark Gray

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx3, cy3); // center of circle

        for(k = 0; k <= triangleAmount3; k++) {

            glVertex2f(

                cx3 + (radius3 * cos(k * twicePi3 / triangleAmount3)),

                cy3 + (radius3 * sin(k * twicePi3 / triangleAmount3))

            );

        }

    glEnd();

    //Left Building

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-74.0f, 1.0f);

    glVertex2f(-74.0f, 27.0f);

    glVertex2f(-63.0f, 28.0f);

    glVertex2f(-63.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); // Black

    glVertex2f(-74.0f, 1.0f);

    glVertex2f(-74.0f, 27.0f);

    glVertex2f(-63.0f, 28.0f);

    glVertex2f(-63.0f, 1.0f);

    glVertex2f(-74.0f, 1.0f);

    glEnd();

    //Left 2nd Building (Gap)

    glBegin(GL_QUADS);

    glColor3f(0.4902f, 0.4824f, 0.4863f); //Dark Gray

    glVertex2f(-63.0f, 26.0f);

    glVertex2f(-61.0f, 26.0f);

    glVertex2f(-61.0f, 1.0f);

    glVertex2f(-63.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-63.0f, 26.0f);

    glVertex2f(-61.0f, 26.0f);

    glVertex2f(-61.0f, 1.0f);

    glVertex2f(-63.0f, 1.0f);

    glVertex2f(-63.0f, 26.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(-61.0f, 28.0f);

    glVertex2f(-58.0f, 28.0f);

    glVertex2f(-58.0f, 1.0f);

    glVertex2f(-62.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-61.0f, 28.0f);

    glVertex2f(-58.0f, 28.0f);

    glVertex2f(-58.0f, 1.0f);

    glVertex2f(-62.0f, 1.0f);

    glVertex2f(-61.0f, 28.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(-58.0f, 29.0f);

    glVertex2f(-42.0f, 30.0f);

    glVertex2f(-43.0f, 1.0f);

    glVertex2f(-58.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-58.0f, 29.0f);

    glVertex2f(-42.0f, 30.0f);

    glVertex2f(-43.0f, 1.0f);

    glVertex2f(-58.0f, 1.0f);

    glVertex2f(-58.0f, 29.0f);

    glEnd();

    //6th Building

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(-40.0f, 30.0f);

    glVertex2f(-24.0f, 32.0f);

    glVertex2f(-25.0f, 1.0f);

    glVertex2f(-41.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-40.0f, 30.0f);

    glVertex2f(-24.0f, 32.0f);

    glVertex2f(-25.0f, 1.0f);

    glVertex2f(-41.0f, 1.0f);

    glVertex2f(-40.0f, 30.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(-24.0f, 32.0f);

    glVertex2f(-13.0f, 31.0f);

    glVertex2f(-13.0f, 1.0f);

    glVertex2f(-25.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-24.0f, 32.0f);

    glVertex2f(-13.0f, 31.0f);

    glVertex2f(-13.0f, 1.0f);

    glVertex2f(-25.0f, 1.0f);

    glVertex2f(-24.0f, 32.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(-13.0f, 36.0f);

    glVertex2f(5.0f, 36.0f);

    glVertex2f(5.0f, 1.0f);

    glVertex2f(-13.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-13.0f, 36.0f);

    glVertex2f(5.0f, 36.0f);

    glVertex2f(5.0f, 1.0f);

    glVertex2f(-13.0f, 1.0f);

    glVertex2f(-13.0f, 36.0f);

    glEnd();

    //Middle Half

    glBegin(GL_QUADS);

    glColor3f(0.7373f, 0.7608f, 0.7608f);

    glVertex2f(5.0f, 35.0f);

    glVertex2f(10.0f, 35.0f);

    glVertex2f(10.0f, 1.0f);

    glVertex2f(5.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(5.0f, 35.0f);

    glVertex2f(10.0f, 35.0f);

    glVertex2f(10.0f, 1.0f);

    glVertex2f(5.0f, 1.0f);

    glVertex2f(5.0f, 35.0f);

    glEnd();

    // Center dividing line

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(10.0f, 35.0f);

    glVertex2f(10.0f, 1.0f);

    glEnd();

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-74.0f, 26.0f);

    glVertex2f(-63.0f, 27.0f);

    glVertex2f(-74.0f, 22.0f);

    glVertex2f(-63.0f, 23.0f);

    glVertex2f(-74.0f, 19.0f);

    glVertex2f(-63.0f, 20.0f);

    glVertex2f(-74.0f, 16.0f);

    glVertex2f(-63.0f, 17.0f);

    glVertex2f(-74.0f, 12.0f);

    glVertex2f(-63.0f, 13.0f);

    glVertex2f(-74.0f, 9.0f);

    glVertex2f(-63.0f, 10.0f);

    glVertex2f(-74.0f, 5.0f);

    glVertex2f(-63.0f, 6.0f);

    glVertex2f(-74.0f, 2.0f);

    glVertex2f(-63.0f, 3.0f);

    // Vertical

    glVertex2f(-70.0f, 27.0f);

    glVertex2f(-70.0f, 1.0f);

    glVertex2f(-67.0f, 27.0f);

    glVertex2f(-67.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    // Horizontal

    glVertex2f(-61.0f, 27.0f);

    glVertex2f(-58.0f, 26.0f);

    glVertex2f(-61.0f, 23.0f);

    glVertex2f(-58.0f, 22.0f);

    glVertex2f(-61.0f, 20.0f);

    glVertex2f(-58.0f, 19.0f);

    glVertex2f(-61.0f, 17.0f);

    glVertex2f(-58.0f, 16.0f);

    glVertex2f(-61.0f, 13.0f);

    glVertex2f(-58.0f, 12.0f);

    glVertex2f(-62.0f, 3.0f);

    glVertex2f(-58.0f, 2.0f);

    // Vertical

    glVertex2f(-60.0f, 28.0f);

    glVertex2f(-60.0f, 1.0f);

    glVertex2f(-59.0f, 28.0f);

    glVertex2f(-59.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-58.0f, 28.0f);

    glVertex2f(-42.0f, 29.0f);

    glVertex2f(-58.0f, 24.0f);

    glVertex2f(-42.0f, 25.0f);

    glVertex2f(-58.0f, 20.0f);

    glVertex2f(-42.0f, 21.0f);

    glVertex2f(-58.0f, 16.0f);

    glVertex2f(-42.0f, 17.0f);

    glVertex2f(-58.0f, 12.0f);

    glVertex2f(-42.0f, 13.0f);

    glVertex2f(-58.0f, 8.0f);

    glVertex2f(-42.0f, 9.0f);

    glVertex2f(-58.0f, 4.0f);

    glVertex2f(-42.0f, 5.0f);

    // Vertical

    glVertex2f(-53.0f, 29.0f);

    glVertex2f(-53.0f, 1.0f);

    glVertex2f(-48.0f, 29.0f);

    glVertex2f(-48.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-40.0f, 29.0f);

    glVertex2f(-24.0f, 31.0f);

    glVertex2f(-40.0f, 25.0f);

    glVertex2f(-24.0f, 27.0f);

    glVertex2f(-40.0f, 21.0f);

    glVertex2f(-24.0f, 23.0f);

    glVertex2f(-40.0f, 17.0f);

    glVertex2f(-24.0f, 19.0f);

    glVertex2f(-40.0f, 13.0f);

    glVertex2f(-24.0f, 15.0f);

    glVertex2f(-41.0f, 9.0f);

    glVertex2f(-25.0f, 11.0f);

    glVertex2f(-41.0f, 5.0f);

    glVertex2f(-25.0f, 7.0f);

    // Vertical

    glVertex2f(-35.0f, 30.0f);

    glVertex2f(-35.0f, 1.0f);

    glVertex2f(-29.0f, 31.0f);

    glVertex2f(-29.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-24.0f, 31.0f);

    glVertex2f(-13.0f, 30.0f);

    glVertex2f(-24.0f, 27.0f);

    glVertex2f(-13.0f, 26.0f);

    glVertex2f(-24.0f, 23.0f);

    glVertex2f(-13.0f, 22.0f);

    glVertex2f(-24.0f, 19.0f);

    glVertex2f(-13.0f, 18.0f);

    glVertex2f(-24.0f, 15.0f);

    glVertex2f(-13.0f, 14.0f);

    glVertex2f(-25.0f, 11.0f);

    glVertex2f(-13.0f, 10.0f);

    glVertex2f(-25.0f, 7.0f);

    glVertex2f(-13.0f, 6.0f);

    glVertex2f(-25.0f, 3.0f);

    glVertex2f(-13.0f, 2.0f);

    // Vertical

    glVertex2f(-21.0f, 31.0f);

    glVertex2f(-21.0f, 1.0f);

    glVertex2f(-17.0f, 31.0f);

    glVertex2f(-17.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-13.0f, 34.0f);

    glVertex2f(5.0f, 34.0f);

    glVertex2f(-13.0f, 30.0f);

    glVertex2f(5.0f, 30.0f);

    glVertex2f(-13.0f, 26.0f);

    glVertex2f(5.0f, 26.0f);

    glVertex2f(-13.0f, 22.0f);

    glVertex2f(5.0f, 22.0f);

    glVertex2f(-13.0f, 18.0f);

    glVertex2f(5.0f, 18.0f);

    glVertex2f(-13.0f, 14.0f);

    glVertex2f(5.0f, 14.0f);

    glVertex2f(-13.0f, 10.0f);

    glVertex2f(5.0f, 10.0f);

    glVertex2f(-13.0f, 6.0f);

    glVertex2f(5.0f, 6.0f);

    glVertex2f(-13.0f, 2.0f);

    glVertex2f(5.0f, 2.0f);

    // Vertical

    glVertex2f(-7.0f, 36.0f);

    glVertex2f(-7.0f, 1.0f);

    glVertex2f(-1.0f, 36.0f);

    glVertex2f(-1.0f, 1.0f);

    glEnd();

    glBegin(GL_LINES);

    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(5.0f, 33.0f);

    glVertex2f(10.0f, 33.0f);

    glVertex2f(5.0f, 29.0f);

    glVertex2f(10.0f, 29.0f);

    glVertex2f(5.0f, 25.0f);

    glVertex2f(10.0f, 25.0f);

    glVertex2f(5.0f, 21.0f);

    glVertex2f(10.0f, 21.0f);

    glVertex2f(5.0f, 17.0f);

    glVertex2f(10.0f, 17.0f);

    glVertex2f(5.0f, 13.0f);

    glVertex2f(10.0f, 13.0f);

    glVertex2f(5.0f, 9.0f);

    glVertex2f(10.0f, 9.0f);

    glVertex2f(5.0f, 5.0f);

    glVertex2f(10.0f, 5.0f);

    glEnd();

    glLineWidth(1.0f);

    // 5th Building

    glBegin(GL_QUADS);

    glColor3f(0.4902f, 0.4824f, 0.4863f);

    glVertex2f(-42.0f, 30.0f);

    glVertex2f(-40.0f, 30.0f);

    glVertex2f(-41.0f, 1.0f);

    glVertex2f(-43.0f, 1.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f);

    glVertex2f(-42.0f, 30.0f);

    glVertex2f(-40.0f, 30.0f);

    glVertex2f(-41.0f, 1.0f);

    glVertex2f(-43.0f, 1.0f);

    glVertex2f(-42.0f, 30.0f);

    glEnd();

    //Triangles of the Buildings middle

    glBegin(GL_TRIANGLES);

    glColor3f(0.4902f, 0.4824f, 0.4863f); //Dark Gray

    glVertex2f(-55.0f, 9.0f);

    glVertex2f(-52.0f, 25.0f);

    glVertex2f(-50.0f, 10.0f);

    glEnd();

    //Triangles

    glBegin(GL_TRIANGLES);

    glColor3f(0.4902f, 0.4824f, 0.4863f); //Dark Gray

    glVertex2f(-31.0f, 9.0f);

    glVertex2f(-28.0f, 25.0f);

    glVertex2f(-26.0f, 10.0f);

    glEnd();

    //QUADS of the Buildings middle

    glBegin(GL_QUADS);

    glColor3f(0.4902f, 0.4824f, 0.4863f);

    glVertex2f(-55.0f, 1.0f);

    glVertex2f(-55.0f, 5.0f);

    glVertex2f(-50.0f, 6.0f);

    glVertex2f(-50.0f, 1.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.4902f, 0.4824f, 0.4863f);

    glVertex2f(-31.0f, 1.0f);

    glVertex2f(-31.0f, 5.0f);

    glVertex2f(-26.0f, 6.0f);

    glVertex2f(-26.0f, 1.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.4902f, 0.4824f, 0.4863f);

    glVertex2f(6.0f, 1.0f);

    glVertex2f(6.0f, 5.0f);

    glVertex2f(10.0f, 5.0f);

    glVertex2f(10.0f, 1.0f);

    glEnd();

    //Circle of the Buildings middle

    int i;

    GLfloat cx = -19.8f;

    GLfloat cy = 9.4f;

    GLfloat rx = 3.26f;

    GLfloat ry = 6.5f;

    int triangleAmount = 100;

    GLfloat twicePi = 2.0f * PI;

    glColor3f(0.4902f, 0.4824f, 0.4863f);

    glBegin(GL_TRIANGLE_FAN);

        glVertex2f(cx, cy); // center of ellipse

        for(i = 0; i <= triangleAmount; i++) {

            glVertex2f(

                cx + (rx * cos(i * twicePi / triangleAmount)),

                cy + (ry * sin(i * twicePi / triangleAmount))

            );

        }

    glEnd();

}



void Dhrubo_display()
{
    //Sky Background

    glClearColor(0.24f, 0.67f, 0.88f, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    //CLOUDS

    SangsadDrawClouds(cloud_offset);

    glLoadIdentity();

    //BACKGROUND TREES

    glColor3f(0.13f, 0.55f, 0.13f);

    // Left Trees

    glBegin(GL_POLYGON);

    glVertex2f(-100.0f, 1.0f);

    glVertex2f(-100.0f, 12.0f);

    glVertex2f(-85.0f, 14.0f);

    glVertex2f(-75.0f, 9.0f);

    glVertex2f(-70.0f, 1.0f);

    glEnd();

    glLoadIdentity();

    glScalef(-1.0f, 1.0f, 1.0f);

    // Right Trees

    glBegin(GL_POLYGON);

    glVertex2f(-100.0f, 1.0f);

    glVertex2f(-100.0f, 12.0f);

    glVertex2f(-85.0f, 14.0f);

    glVertex2f(-75.0f, 9.0f);

    glVertex2f(-70.0f, 1.0f);

    glEnd();

    glLoadIdentity();

    // THE BUILDING

    glPushMatrix();

    SangsadMainBuilding();

    glPopMatrix();

    glPushMatrix();

    glTranslatef(10.0f, 0.0f, 0.0f);

    glScalef(-1.0f, 1.0f, 1.0f);

    glTranslatef(-10.0f, 0.0f, 0.0f);

    SangsadMainBuilding();

    glPopMatrix();

    // Big Triangle

    glBegin(GL_POLYGON);

    glColor3f(0.7373f, 0.7608f, 0.7608f); //Gray

    glVertex2f(-61.0f, 16.0f);

    glVertex2f(-58.0f, 12.0f);

    glVertex2f(-58.0f, 5.0f);

    glVertex2f(-71.0f, 5.0f);

    glVertex2f(-63.0f, 16.0f);

    glEnd();

    glBegin(GL_LINE_STRIP);

    glColor3f(0.0f, 0.0f, 0.0f); //Black outline

    glVertex2f(-61.0f, 16.0f);

    glVertex2f(-58.0f, 12.0f);

    glVertex2f(-58.0f, 5.0f);

    glVertex2f(-71.0f, 5.0f);

    glVertex2f(-63.0f, 16.0f);

    glVertex2f(-61.0f, 16.0f);

    glEnd();


    //PLATFORM / BRICK

    glColor3f(0.75f, 0.34f, 0.22f); // Reddish-brown Brick Color

    glBegin(GL_QUADS);

    glVertex2f(-100.0f, -15.0f);

    glVertex2f(100.0f, -15.0f);

    glVertex2f(100.0f, 1.0f);

    glVertex2f(-100.0f, 1.0f);

    glEnd();

    // Horizontal black lines for platform tiers

    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(-100.0f, 1.0f);

    glVertex2f(100.0f, 1.0f);

    glVertex2f(-100.0f, -3.0f);

    glVertex2f(100.0f, -3.0f);

    glVertex2f(-100.0f, -7.0f);

    glVertex2f(100.0f, -7.0f);

    glVertex2f(-100.0f, -11.0f);

    glVertex2f(100.0f, -11.0f);

    glVertex2f(-100.0f, -15.0f);

    glVertex2f(100.0f, -15.0f);

    glEnd();

    // White diagonal stair lines on the platform

    glColor3f(1.0f, 1.0f, 1.0f);

    glLineWidth(3.0f);

    glBegin(GL_LINES);

    glVertex2f(-30.0f, -15.0f);

    glVertex2f(-20.0f, 1.0f);

    glVertex2f(75.0f, -15.0f);

    glVertex2f(65.0f, 1.0f);

    glEnd();


    //GRASS AREA

    glColor3f(0.18f, 0.61f, 0.29f); // Bright Green

    glBegin(GL_QUADS);

    glVertex2f(-100.0f, -28.0f);

    glVertex2f(100.0f, -28.0f);

    glVertex2f(100.0f, -15.0f);

    glVertex2f(-100.0f, -15.0f);

    glEnd();

    // Small black posts

    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(4.0f);

    glBegin(GL_LINES);

    for(float p = -90.0f; p < 100.0f; p += 30.0f) {

        glVertex2f(p, -15.0f);

        glVertex2f(p, -10.0f);

    }

    glEnd();


    //ROAD

    glColor3f(0.42f, 0.44f, 0.46f); // Dark Grey

    glBegin(GL_QUADS);

    glVertex2f(-100.0f, -60.0f);

    glVertex2f(100.0f, -60.0f);

    glVertex2f(100.0f, -28.0f);

    glVertex2f(-100.0f, -28.0f);

    glEnd();

    // White borders of the road

    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);

    glVertex2f(-100.0f, -30.0f);

    glVertex2f(100.0f, -30.0f);

    glVertex2f(100.0f, -28.0f);

    glVertex2f(-100.0f, -28.0f);

    glVertex2f(-100.0f, -60.0f);

    glVertex2f(100.0f, -60.0f);

    glVertex2f(100.0f, -58.0f);

    glVertex2f(-100.0f, -58.0f);

    glEnd();

    // White dashed lines down the middle of the road

    glColor3f(1.0f, 1.0f, 1.0f);

    for(float d = -90.0f; d < 100.0f; d += 25.0f) {

        glBegin(GL_QUADS);

        glVertex2f(d, -45.0f);

        glVertex2f(d + 12.0f, -45.0f);

        glVertex2f(d + 12.0f, -43.0f);

        glVertex2f(d, -43.0f);

        glEnd();

    }

    // CROSSWALK (Added right beside the traffic light position at x=0)

    glColor3f(1.0f, 1.0f, 1.0f); // White stripes

    for(float cw = -57.0f; cw < -30.0f; cw += 5.0f) {

        glBegin(GL_QUADS);

        glVertex2f(0.0f, cw);

        glVertex2f(10.0f, cw);

        glVertex2f(10.0f, cw + 3.0f);

        glVertex2f(0.0f, cw + 3.0f);

        glEnd();

    }

    // Black outlines for the road borders

    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(2.0f);

    glBegin(GL_LINES);

    glVertex2f(-100.0f, -28.0f);

    glVertex2f(100.0f, -28.0f);

    glVertex2f(-100.0f, -30.0f);

    glVertex2f(100.0f, -30.0f);

    glVertex2f(-100.0f, -58.0f);

    glVertex2f(100.0f, -58.0f);

    glVertex2f(-100.0f, -60.0f);

    glVertex2f(100.0f, -60.0f);

    glEnd();


    // RENDER TRAFFIC LIGHT

    SangsadDrawTrafficLight();


    //CARS

    // TOP LANE (left-to-right) at identical speed (faceLeft = false)

    SangsadDrawBlueCar(topBlue_x, -40.0f, false);

    SangsadDrawRedCar(topRed_x, -40.0f, false);

    // BOTTOM LANE (right-to-left) at identical speed (faceLeft = true)

    SangsadDrawRedCar(bottomRed_x, -55.0f, true);

    SangsadDrawBlueCar(bottomBlue_x, -55.0f, true);


    //STREETLIGHTS

    GLfloat lamp_x[] = {-45.0f, 35.0f, 85.0f};

    // Black Poles

    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(3.0f);

    glBegin(GL_LINES);

    for(int l = 0; l < 3; l++) {

        glVertex2f(lamp_x[l], -15.0f);

        glVertex2f(lamp_x[l], 5.0f);

    }

    glEnd();

    GLfloat lamp_r = 1.8f;

    for(int l = 0; l < 3; l++) {

        glColor3f(1.0f, 1.0f, 1.0f);

        glBegin(GL_POLYGON);

        for(int j = 0; j <= 30; j++) {

            glVertex2f(lamp_x[l] + (lamp_r * cos(j * 2.0f * PI / 30)),

                       6.0f + (lamp_r * sin(j * 2.0f * PI / 30)));

        }

        glEnd();

        glColor3f(0.0f, 0.0f, 0.0f);

        glLineWidth(2.0f);

        glBegin(GL_LINE_LOOP);

        for(int j = 0; j <= 30; j++) {

            glVertex2f(lamp_x[l] + (lamp_r * cos(j * 2.0f * PI / 30)),

                       6.0f + (lamp_r * sin(j * 2.0f * PI / 30)));

        }

        glEnd();

    }

    // BANGLADESH'S FLAG

    glBegin(GL_QUADS);

    glColor3f(0.3f, 0.3f, 0.3f); // Silver/Light Gray

    glVertex2f(21.6f, 1.0f);  glVertex2f(22.0f, 1.0f);

    glVertex2f(22.0f, 27.0f); glVertex2f(21.6f, 27.0f);

    glEnd();

    glBegin(GL_QUADS);

    glColor3f(0.0f, 0.42f, 0.24f);

    glVertex2f(22.0f, 21.0f); glVertex2f(30.0f, 21.0f);

    glVertex2f(30.0f, 26.0f); glVertex2f(22.0f, 26.0f);

    glEnd();

    int flagLines = 100;

    GLfloat cx_flag = 25.6f;

    GLfloat cy_flag = 23.5f;

    GLfloat r_flag = 1.6f;

    glColor3f(0.96f, 0.16f, 0.21f);

    glBegin(GL_POLYGON);

    for(int k_idx = 0; k_idx <= flagLines; k_idx++) {

        glVertex2f(

            cx_flag + (r_flag * cos(k_idx * 2.0f * PI / flagLines)),

            cy_flag + (r_flag * sin(k_idx * 2.0f * PI / flagLines))

        );

    }

    glEnd();

    glFlush();

}

void SangsadInit() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -60, 90);
    glMatrixMode(GL_MODELVIEW);
}



//Sadman Part

const int sadarGhatW = 1400;

const int sadarGhatH = 1120;

float sadarGhatCloudMove = 0.0f;

float sadarGhatBoatMove1 = 0.0f;

float sadarGhatBoatMove2 = 0.0f;

float sadarGhatBoatMove3 = 0.0f;

float sadarGhatSmallBoatMove1 = 0.0f;

float sadarGhatSmallBoatMove2 = 0.0f;

void SadarGhatRect(float x1, float y1, float x2, float y2, float r, float g, float b)

{

    glColor3f(r, g, b);

    glBegin(GL_QUADS);

    glVertex2f(x1, y1);

    glVertex2f(x2, y1);

    glVertex2f(x2, y2);

    glVertex2f(x1, y2);

    glEnd();

}

void SadarGhatPolygon(float r, float g, float b, int n, float p[])

{

    glColor3f(r, g, b);

    glBegin(GL_POLYGON);

    for (int i = 0; i < n; i++)

    {

        glVertex2f(p[i * 2], p[i * 2 + 1]);

    }

    glEnd();

}

void SadarGhatCircle(float x, float y, float r, float R, float G, float B)

{

    glColor3f(R, G, B);

    glBegin(GL_POLYGON);

    for (int i = 0; i < 60; i++)

    {

        float a = 2.0f * PI * i / 60.0f;

        glVertex2f(x + r * cos(a), y + r * sin(a));

    }

    glEnd();

}

void SadarGhatCloud(float x, float y)

{

    SadarGhatCircle(x, y, 25, 1, 1, 1);

    SadarGhatCircle(x + 30, y - 12, 32, 1, 1, 1);

    SadarGhatCircle(x + 65, y - 15, 34, 1, 1, 1);

    SadarGhatCircle(x + 100, y - 8, 29, 1, 1, 1);

    SadarGhatCircle(x + 120, y, 20, 1, 1, 1);

    SadarGhatRect(x - 5, y, x + 125, y + 15, 1, 1, 1);

}

void SadarGhatTree(float x, float y, float s)

{

    SadarGhatRect(x - 7 * s, y, x + 7 * s, y + 55 * s, 0.42f, 0.23f, 0.04f);

    SadarGhatCircle(x, y - 5 * s, 32 * s, 0.0f, 0.55f, 0.02f);

    SadarGhatCircle(x - 23 * s, y + 5 * s, 26 * s, 0.0f, 0.55f, 0.02f);

    SadarGhatCircle(x + 24 * s, y + 5 * s, 26 * s, 0.0f, 0.55f, 0.02f);

}

void SadarGhatWindowBox(float x, float y)

{

    SadarGhatRect(x, y, x + 15, y + 17, 0.20f, 0.20f, 0.20f);

}

void SadarGhatHouse(float x, float y, float w, float h, float br, float bg, float bb, float rr, float rg, float rb)

{

    SadarGhatRect(x, y, x + w, y + h, br, bg, bb);

    float roof[6] =

    {

        x - 5, y,

        x + w / 2, y - 35,

        x + w + 5, y

    };

    SadarGhatPolygon(rr, rg, rb, 3, roof);

    SadarGhatWindowBox(x + 20, y + 30);

    SadarGhatWindowBox(x + w - 35, y + 30);

    if (h > 110)

    {

        SadarGhatWindowBox(x + 20, y + 70);

        SadarGhatWindowBox(x + w - 35, y + 70);

    }

    if (h > 170)

    {

        SadarGhatWindowBox(x + 20, y + 110);

        SadarGhatWindowBox(x + w - 35, y + 110);

    }

}

void SadarGhatTallBuilding()

{

    SadarGhatRect(220, 125, 377, 445, 0.43f, 0.43f, 0.43f);

    for (int r = 0; r < 7; r++)

    {

        for (int c = 0; c < 4; c++)

        {

            SadarGhatRect(238 + c * 36, 153 + r * 43, 252 + c * 36, 170 + r * 43, 0.20f, 0.20f, 0.20f);

        }

    }

}

void SadarGhatRiver()

{

    float p[20] =

    {

        0, 160,

        650, 160,

        750, 180,

        850, 205,

        980, 230,

        1120, 265,

        1280, 310,

        1400, 350,

        1400, 1120,

        350, 1120

    };

    SadarGhatPolygon(0.0f, 0.35f, 0.96f, 10, p);

}

void SadarGhatLand()

{

    float p[20] =

    {

        0, 250,

        375, 250,

        405, 330,

        425, 430,

        410, 530,

        390, 650,

        375, 780,

        365, 900,

        350, 1120,

        0, 1120

    };

    SadarGhatPolygon(0.84f, 0.70f, 0.39f, 10, p);

}

void SadarGhatRoad()

{

    float p[18] =

    {

        375, 300,

        415, 325,

        420, 390,

        395, 470,

        370, 555,

        350, 650,

        340, 760,

        335, 870,

        350, 1000

    };

    SadarGhatPolygon(0.06f, 0.06f, 0.06f, 9, p);

    SadarGhatRect(390, 335, 397, 365, 1, 1, 1);

    SadarGhatRect(378, 420, 385, 450, 1, 1, 1);

    SadarGhatRect(361, 505, 368, 535, 1, 1, 1);

    SadarGhatRect(348, 595, 355, 625, 1, 1, 1);

    SadarGhatRect(340, 690, 347, 720, 1, 1, 1);

    SadarGhatRect(335, 790, 342, 820, 1, 1, 1);

    SadarGhatRect(334, 895, 341, 925, 1, 1, 1);

    SadarGhatRect(340, 1000, 347, 1030, 1, 1, 1);

}

void SadarGhatFarBank()

{

    float p[18] =

    {

        620, 160,

        700, 160,

        800, 165,

        900, 175,

        1000, 190,

        1100, 210,

        1200, 230,

        1300, 250,

        1400, 270

    };

    SadarGhatPolygon(0.84f, 0.69f, 0.37f, 9, p);

    SadarGhatRect(680, 150, 1400, 220, 0.0f, 0.45f, 0.02f);

    SadarGhatCircle(720, 170, 42, 0.0f, 0.45f, 0.02f);

    SadarGhatCircle(805, 170, 45, 0.0f, 0.45f, 0.02f);

    SadarGhatCircle(900, 170, 43, 0.0f, 0.45f, 0.02f);

    SadarGhatCircle(1200, 175, 50, 0.0f, 0.45f, 0.02f);

    SadarGhatCircle(1300, 170, 55, 0.0f, 0.45f, 0.02f);

    SadarGhatRect(738, 130, 775, 165, 1, 1, 1);

    SadarGhatRect(850, 135, 885, 170, 0.50f, 0.50f, 0.50f);

    SadarGhatRect(888, 110, 923, 175, 0.95f, 0.48f, 0.45f);

    SadarGhatRect(945, 110, 985, 177, 1.0f, 0.94f, 0.15f);

    SadarGhatRect(1028, 136, 1066, 188, 0.95f, 0.55f, 0.48f);

    SadarGhatRect(1090, 140, 1128, 194, 0.72f, 0.67f, 0.88f);

}

void SadarGhatRightHouses()

{

    SadarGhatHouse(1195, 240, 110, 65, 0.96f, 0.96f, 0.96f, 0.90f, 0.05f, 0.03f);

    SadarGhatHouse(1280, 260, 110, 70, 0.96f, 0.96f, 0.96f, 0.05f, 0.25f, 0.90f);

    SadarGhatRect(1250, 280, 1268, 315, 0.45f, 0.28f, 0.04f);

}

void SadarGhatPier(float x, float y)

{

    SadarGhatRect(x, y, x + 125, y + 20, 0.43f, 0.25f, 0.04f);

    SadarGhatRect(x + 20, y + 20, x + 36, y + 55, 0.35f, 0.20f, 0.03f);

    SadarGhatRect(x + 95, y + 20, x + 111, y + 55, 0.35f, 0.20f, 0.03f);

}

void SadarGhatBoat(float x, float y, float s, bool red)

{

    float p[14] =

    {

        x, y + 25 * s,

        x + 13 * s, y + 42 * s,

        x + 100 * s, y + 42 * s,

        x + 125 * s, y + 25 * s,

        x + 107 * s, y + 10 * s,

        x + 20 * s, y + 10 * s,

        x + 7 * s, y + 16 * s

    };

    SadarGhatPolygon(1, 1, 1, 7, p);

    if (red)

    {

        SadarGhatRect(x + 18 * s, y, x + 105 * s, y + 17 * s, 0.90f, 0.03f, 0.02f);

    }

    else

    {

        SadarGhatRect(x + 18 * s, y, x + 105 * s, y + 17 * s, 0.0f, 0.48f, 0.03f);

    }

    SadarGhatRect(x + 20 * s, y - 16 * s, x + 44 * s, y, 1, 1, 1);

    SadarGhatRect(x + 27 * s, y - 11 * s, x + 39 * s, y - 3 * s, 0.04f, 0.04f, 0.04f);

    SadarGhatRect(x + 34 * s, y - 19 * s, x + 44 * s, y - 11 * s, 0.04f, 0.04f, 0.04f);

    for (int i = 0; i < 6; i++)

    {

        SadarGhatRect(x + (24 + i * 14) * s, y + 22 * s, x + (33 + i * 14) * s, y + 32 * s, 0.03f, 0.03f, 0.03f);

    }

}

void SadarGhatSmallBoat(float x, float y, float s, bool red)

{

    float p[12] =

    {

        x, y + 20 * s,

        x + 18 * s, y + 36 * s,

        x + 82 * s, y + 36 * s,

        x + 108 * s, y + 21 * s,

        x + 83 * s, y + 8 * s,

        x + 18 * s, y + 8 * s

    };

    SadarGhatPolygon(1, 1, 1, 6, p);

    if (red)

    {

        SadarGhatRect(x + 12 * s, y, x + 84 * s, y + 12 * s, 0.90f, 0.03f, 0.02f);

    }

    else

    {

        SadarGhatRect(x + 12 * s, y, x + 84 * s, y + 12 * s, 0.0f, 0.48f, 0.03f);

    }

    SadarGhatRect(x + 66 * s, y - 16 * s, x + 83 * s, y, 1, 1, 1);

    SadarGhatRect(x + 69 * s, y - 21 * s, x + 83 * s, y - 16 * s, 0.04f, 0.04f, 0.04f);

}

void SadarGhatLargeBoat(float x, float y)

{

    float p[16] =

    {

        x, y + 55,

        x + 20, y + 32,

        x + 42, y + 12,

        x + 165, y + 12,

        x + 200, y + 35,

        x + 192, y + 65,

        x + 175, y + 75,

        x + 30, y + 75

    };

    SadarGhatPolygon(1, 1, 1, 8, p);

    SadarGhatRect(x + 35, y, x + 165, y + 25, 0.0f, 0.48f, 0.03f);

    SadarGhatRect(x + 50, y - 20, x + 150, y, 1, 1, 1);

    SadarGhatRect(x + 118, y - 42, x + 145, y - 20, 1, 1, 1);

    SadarGhatRect(x + 125, y - 50, x + 140, y - 42, 0.04f, 0.04f, 0.04f);

    SadarGhatRect(x + 123, y - 57, x + 143, y - 50, 0.90f, 0.04f, 0.02f);

    for (int i = 0; i < 8; i++)

    {

        SadarGhatRect(x + 22 + i * 20, y + 37, x + 34 + i * 20, y + 51, 0.03f, 0.03f, 0.03f);

    }

    for (int i = 0; i < 7; i++)

    {

        SadarGhatRect(x + 40 + i * 19, y + 58, x + 52 + i * 19, y + 70, 0.03f, 0.03f, 0.03f);

    }

}

void SadarGhatUpdate(int value)

{

    sadarGhatCloudMove += 0.7f;

    sadarGhatBoatMove1 += 0.7f;

    sadarGhatBoatMove2 += 0.7f;

    sadarGhatBoatMove3 += 0.7f;

    sadarGhatSmallBoatMove1 += 0.4f;

    sadarGhatSmallBoatMove2 += 0.4f;

    if (sadarGhatCloudMove > 1500)

        sadarGhatCloudMove = -250;

    if (sadarGhatBoatMove1 > 100)

        sadarGhatBoatMove1 = -100;

    if (sadarGhatBoatMove2 > 100)

        sadarGhatBoatMove2 = -100;

    if (sadarGhatBoatMove3 > 80)

        sadarGhatBoatMove3 = -80;

    if (sadarGhatSmallBoatMove1 > 80)

        sadarGhatSmallBoatMove1 = -80;

    if (sadarGhatSmallBoatMove2 > 80)

        sadarGhatSmallBoatMove2 = -80;

    glutPostRedisplay();

    glutTimerFunc(30, SadarGhatUpdate, 0);

}



void Sadman_display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    SadarGhatRect(0, 0, sadarGhatW, sadarGhatH, 0.48f, 0.79f, 0.95f);

    glPushMatrix();

    glTranslatef(sadarGhatCloudMove, 0, 0);

    SadarGhatCloud(110, 55);

    SadarGhatCloud(480, 55);

    SadarGhatCloud(1140, 55);

    glPopMatrix();

    SadarGhatRiver();

    SadarGhatLand();

    SadarGhatFarBank();

    SadarGhatTallBuilding();

    SadarGhatHouse(0, 250, 95, 120, 1.0f, 0.80f, 0.35f, 0.95f, 0.30f, 0.05f);

    SadarGhatHouse(115, 250, 90, 130, 0.96f, 0.96f, 0.96f, 0.70f, 0.85f, 0.94f);

    SadarGhatHouse(45, 385, 120, 105, 0.95f, 0.95f, 0.95f, 0.62f, 0.55f, 0.90f);

    SadarGhatHouse(0, 480, 115, 100, 0.95f, 0.65f, 0.65f, 0.90f, 0.35f, 0.35f);

    SadarGhatHouse(180, 445, 125, 145, 0.98f, 0.98f, 0.98f, 0.95f, 0.35f, 0.35f);

    SadarGhatHouse(78, 620, 115, 105, 0.76f, 0.76f, 0.90f, 0.55f, 0.45f, 0.80f);

    SadarGhatHouse(0, 705, 135, 120, 1.0f, 0.90f, 0.25f, 0.95f, 0.45f, 0.08f);

    SadarGhatHouse(92, 850, 145, 145, 0.98f, 0.98f, 0.98f, 0.95f, 0.45f, 0.30f);

    SadarGhatTree(110, 390, 0.95f);

    SadarGhatTree(270, 430, 0.85f);

    SadarGhatTree(85, 545, 0.85f);

    SadarGhatTree(300, 610, 0.85f);

    SadarGhatTree(255, 735, 0.85f);

    SadarGhatTree(105, 815, 0.85f);

    SadarGhatTree(210, 965, 0.90f);

    SadarGhatRoad();

    SadarGhatPier(420, 470);

    SadarGhatPier(420, 580);

    SadarGhatPier(420, 690);

    SadarGhatPier(420, 800);

    SadarGhatPier(420, 910);

    glPushMatrix();

    glTranslatef(sadarGhatBoatMove1, 0, 0);

    SadarGhatBoat(525, 455, 0.95f, false);

    SadarGhatBoat(505, 675, 0.95f, false);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(sadarGhatBoatMove2, 0, 0);

    SadarGhatBoat(520, 565, 0.95f, true);

    SadarGhatBoat(505, 785, 0.95f, true);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(sadarGhatBoatMove3, 0, 0);

    SadarGhatBoat(500, 895, 0.95f, false);

    SadarGhatBoat(545, 1005, 0.95f, true);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(sadarGhatSmallBoatMove1, 0, 0);

    SadarGhatSmallBoat(450, 185, 0.45f, true);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(sadarGhatSmallBoatMove2, 0, 0);

    SadarGhatSmallBoat(575, 220, 0.45f, true);

    glPopMatrix();

    SadarGhatLargeBoat(885, 445);

    glPushMatrix();

    glTranslatef(sadarGhatBoatMove1, 0, 0);

    SadarGhatBoat(1010, 285, 1.0f, false);

    SadarGhatBoat(1095, 335, 1.0f, true);

    glPopMatrix();

    glPushMatrix();

    glTranslatef(sadarGhatBoatMove2, 0, 0);

    SadarGhatSmallBoat(1075, 870, 0.90f, true);

    glPopMatrix();

    SadarGhatRightHouses();

    glFlush();

}

void SadarGhatReshape(int w, int h)

{

    if (h == 0)

        h = 1;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, sadarGhatW, sadarGhatH, 0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}

void SadarGhatInit()

{

    glClearColor(0.48f, 0.79f, 0.95f, 1.0f);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    gluOrtho2D(0, sadarGhatW, sadarGhatH, 0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

}






void reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0.8, 0.8, -0.5, 0.7, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void switchPage(unsigned char key, int x, int y)
{

    if(key == '0')
    {

        glutDisplayFunc(displayCover);
        glutPostRedisplay();
    }

    if(key == '1')
    {
        glutDisplayFunc(display);
        int width = glutGet(GLUT_WINDOW_WIDTH);
        int height = glutGet(GLUT_WINDOW_HEIGHT);
        reshape(width, height);
        glutPostRedisplay();
    }


        if(key == '2')
    {

        glutDisplayFunc(Jarif_display);
        glutReshapeFunc(JA_reshape);

        int width = glutGet(GLUT_WINDOW_WIDTH);
        int height = glutGet(GLUT_WINDOW_HEIGHT);

        JA_reshape(width, height);

        glutPostRedisplay();
    }


    if(key == '3')
                  {
    ManzilInit();

    glutDisplayFunc(Israt_display);

    int width = glutGet(GLUT_WINDOW_WIDTH);
    int height = glutGet(GLUT_WINDOW_HEIGHT);

    // Israt uses -1 to 1 projection
    glViewport(0, 0, width, height);

    glutPostRedisplay();
}


     if(key == '4')
    {
        SangsadInit();
        glutDisplayFunc(Dhrubo_display);
        glutPostRedisplay();
    }



    //Sadman's control

    if(key == '5')
    {
        SadarGhatInit();

        glutDisplayFunc(Sadman_display);
        glutReshapeFunc(SadarGhatReshape);

        int width = glutGet(GLUT_WINDOW_WIDTH);
        int height = glutGet(GLUT_WINDOW_HEIGHT);

        SadarGhatReshape(width, height);

        glutPostRedisplay();
    }


    // Jarif's control
    // N = Red car horn
    if(key == 'n' || key == 'N')
    {
        JA_redHornLight = 1;
        glutPostRedisplay();

        mciSendStringA(
            "close JA_redHorn",
            NULL,
            0,
            NULL
        );

        mciSendStringA(
           "open \"D:\\AIUB\\Computer Graphics\\PracticeGlut\\Dhaka City in a gilmpse\\Red Car Horn.mp3\" type mpegvideo alias JA_redHorn",
           NULL,
           0,
           NULL
            );

        mciSendStringA(
            "play JA_redHorn from 0",
            NULL,
            0,
            NULL
        );

        glutTimerFunc(1000, JA_stopRedHornLight, 0);
    }


    // M = Blue car horn
    if(key == 'm' || key == 'M')
    {
        JA_blueHornLight = 1;
        glutPostRedisplay();

        mciSendStringA(
            "close JA_blueHorn",
            NULL,
            0,
            NULL
        );

      mciSendStringA(
    "open \"D:\\AIUB\\Computer Graphics\\PracticeGlut\\Dhaka City in a gilmpse\\Blue Car Horn.mp3\" type mpegvideo alias JA_blueHorn",
         NULL,
          0,
          NULL
          );

        mciSendStringA(
            "play JA_blueHorn from 0",
            NULL,
            0,
            NULL
        );

        glutTimerFunc(1000, JA_stopBlueHornLight, 0);
    }


    //Dhrubo's Control
    if (key == 'r' || key == 'R') {

        isGreenLight = false;

    } else if (key == 'g' || key == 'G') {

        isGreenLight = true;

    }
}





void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


    glBegin(GL_QUADS);
	glColor3f(0.53f, 0.81f, 0.98f); // sky

	glVertex2f(-0.8f, 0.7f);
	glVertex2f( 0.8f, 0.7f);
	glVertex2f( 0.8f, 0.4f);
	glVertex2f(-0.8f, 0.4f);
    glEnd();

    //Cloud 1

    glPushMatrix();
    glTranslatef(position+0.5, 0.0f, 0.0f);

    int i;

    GLfloat twicePi = 2.0f * 3.1415926f;

    int triangleAmount = 50;

    glColor3f(1.0f, 1.0f, 1.0f);


     // Cloud Circle 1

    GLfloat x = -0.30f;
    GLfloat y = 0.55f;
    GLfloat radius = 0.06f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
    {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
   }

    glEnd();

// Cloud Circle 2

   x = -0.22f;
   y = 0.57f;
   radius = 0.08f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
    {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
    }
glEnd();

   // Cloud Circle 3
   x = -0.12f;
   y = 0.55f;
    radius = 0.06f;

   glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
     {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
     }
     glEnd();
     glPopMatrix();


     //   Cloud 2


    glPushMatrix();
    glTranslatef(position-0.4, 0.0f, 0.0f);
    glScalef(0.9f, 0.9f, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);


     // Cloud Circle 1

     x = -0.30f;
     y = 0.55f;
     radius = 0.06f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
    {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
   }

    glEnd();

// Cloud Circle 2

   x = -0.22f;
   y = 0.57f;
   radius = 0.08f;

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
    {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
    }
glEnd();

   // Cloud Circle 3
   x = -0.12f;
   y = 0.55f;
    radius = 0.06f;

   glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for(i = 0; i <= triangleAmount; i++)
     {
    glVertex2f(
        x + (radius * cos(i * twicePi / triangleAmount)),
        y + (radius * sin(i * twicePi / triangleAmount))
    );
     }
     glEnd();
     glPopMatrix();


    glBegin(GL_QUADS);//main
	//glColor3f(0.55f, 0.52f, 0.45f);
	//glColor3f(0.1f, 0.7f, 0.1f);   // Natural green
	 glColor3f(0.30f, 0.75f, 0.30f);

	glVertex2f(-0.8f, 0.4f);
	glVertex2f( 0.8f, 0.4f);
	glVertex2f( 0.8f, -0.5f);
	glVertex2f(-0.8f, -0.5f);
    glEnd();

    glBegin(GL_QUADS); //main road
    glColor3f(0.27f, 0.23f, 0.18f); //road color

	glVertex2f( 0.00f, 0.4f);
	glVertex2f( 0.04f, 0.4f);
	glVertex2f( 0.52f, -0.5f);
	glVertex2f(-0.48f,-0.5f);
    glEnd();


    glBegin(GL_QUADS); //right most
	glColor3f(0.0f, 0.4f, 0.8f); //water

	glVertex2f( 0.04f, 0.4f);
	glVertex2f( 0.06f, 0.4f);
	glVertex2f( 0.8f, -0.5f);
	glVertex2f( 0.54f,-0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left Most
	glColor3f(0.0f, 0.4f, 0.8f); //water

	glVertex2f( 0.00f, 0.4f);
	glVertex2f( -0.02f, 0.4f);
	glVertex2f( -0.8f, -0.5f);
	glVertex2f( -0.52f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //Left
	glColor3f(0.918f, 0.255f, 0.255f); //red

	glVertex2f( 0.00f, 0.4f);
	glVertex2f( -0.52f,-0.5f);
	glVertex2f( -0.48f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //Left
	glColor3f(0.024f, 0.384f, 0.024f); //green

	glVertex2f( -0.02f, 0.4f);
	glVertex2f( -0.8f,-0.35f);
	glVertex2f( -0.8f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //right
	glColor3f(0.918f, 0.255f, 0.255f); //red

	glVertex2f( 0.04f, 0.4f);
	glVertex2f( 0.54f,-0.5f);
	glVertex2f( 0.52f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //right
	glColor3f(0.024f, 0.384f, 0.024f); //green

	glVertex2f( 0.06f, 0.4f);
	glVertex2f( 0.8f,-0.4f);
	glVertex2f( 0.8f,-0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left sub road
	glColor3f(0.27f, 0.23f, 0.18f); //road color

	glVertex2f( -0.22f, -0.02f);
	glVertex2f( -0.8f, -0.02f);
	glVertex2f( -0.8f,  0.04f);
	glVertex2f( -0.18f, 0.04f);
    glEnd();


    glBegin(GL_QUADS); //right sub road
	glColor3f(0.27f, 0.23f, 0.18f); //road color

	glVertex2f( 0.22f, 0.04f);
	glVertex2f( 0.8f, 0.04f);
	glVertex2f( 0.8f,  -0.02f);
	glVertex2f( 0.24f, -0.02f);
    glEnd();

    glBegin(GL_TRIANGLES); //center
	glColor3f(0.737f, 0.737f, 0.188f); // yellow

	glVertex2f( 0.01f, 0.4f);
	glVertex2f( 0.012f,-0.5f);
	glVertex2f( -0.012f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //center side
	glColor3f(0.933f, 0.933f, 0.933f); //white

	glVertex2f( 0.01f, 0.32f);
	glVertex2f( -0.23f,-0.5f);
	glVertex2f( -0.25f,-0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //center side
	glColor3f(0.933f, 0.933f, 0.933f); //white

	glVertex2f( 0.01f, 0.32f);
	glVertex2f( 0.30f,-0.5f);
	glVertex2f( 0.28f,-0.5f);

    glEnd();


    //buldings & window left 1st

glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.88f, 0.72f, 0.65f);

	glVertex2f( 0.78f, 0.5);
	glVertex2f( 0.78f, 0.1f);
	glVertex2f( 0.63f,  0.1f);
	glVertex2f( 0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

	glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();

    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    glLoadIdentity();

    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    glLoadIdentity();





    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

	glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();



    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    //glLoadIdentity();

    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    glLoadIdentity();

glLoadIdentity();



    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

	glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();



    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    //glLoadIdentity();

    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    glLoadIdentity();

glLoadIdentity();



glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

	glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();



    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    //glLoadIdentity();

    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.12f, 0.12f);

    glVertex2f( 0.672f, 0.16);
	glVertex2f( 0.672f, 0.12);
	glVertex2f( 0.65f,  0.12);
	glVertex2f( 0.65f, 0.16);
    glEnd();
    glLoadIdentity();

glLoadIdentity();



//left 8th buildings

glScalef(0.33,0.19,0);
 glTranslatef(-0.25f, 1.59f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.70f, 0.69f, 0.70f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.25f, 0.24f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop





//left 7th buildings

glScalef(0.55,0.28,0);
 glTranslatef(-0.338f, 0.92f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.70f, 0.78f, 0.70f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.17f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop


//left 6th buildings

glScalef(0.55,0.36,0);
 glTranslatef(-0.26f, 0.6f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.74f, 0.78f, 0.84f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.20f, 0.28f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop




//left 5th buildings

glScalef(0.55,0.50,0);
 glTranslatef(-0.18f, 0.3f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.86f, 0.78f, 0.65f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.15f, 0.12f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop





 //left 4th buildings

glScalef(0.79,0.65,0);
 glTranslatef(-0.25f, 0.14f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.91f, 0.84f, 0.68f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.30f, 0.20f, 0.10f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop






 //left 3rd buildings

glScalef(1,0.9,0);
 glTranslatef(-0.27f, -0.02f, 0.0f);
 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.84f, 0.78f, 0.88f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.20f, 0.14f, 0.25f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop


 //left 2nd buildings

glTranslatef(-0.15f, -0.055f, 0.0f);

 glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.78f, 0.5f);
    glVertex2f(0.78f, 0.1f);
    glVertex2f(0.63f, 0.1f);
    glVertex2f(0.63f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //Left side buildings
    glColor3f(0.72f, 0.82f, 0.72f);

	glVertex2f(0.78f, 0.5f);
	glVertex2f(0.78f, 0.1f);
	glVertex2f(0.63f, 0.1f);
	glVertex2f(0.63f, 0.5f);
    glEnd();


    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();


    glPushMatrix();
    glTranslatef(+0.04f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.0f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.1f, 0.0f);// left 2 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.1f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.2f, 0.0f);// left 3 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.2f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.0f, 0.3f, 0.0f);// left 4 window....
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

	glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.04f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(+0.08f, 0.3f, 0.0f);
    glBegin(GL_QUADS); //Left building Window
    glColor3f(0.12f, 0.22f, 0.16f);

    glVertex2f(0.672f, 0.16f);
	glVertex2f(0.672f, 0.12f);
	glVertex2f(0.65f, 0.12f);
	glVertex2f(0.65f, 0.16f);
    glEnd();
    glPopMatrix();


 glLoadIdentity();//buldings loop



    //right trees


   glBegin(GL_QUADS);
   glColor3f(0.35f, 0.20f, 0.08f);
   glVertex2f(0.64f, -0.14f);
   glVertex2f(0.66f, -0.14f);
   glVertex2f(0.66f, -0.24f);
   glVertex2f(0.64f, -0.24f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.10f, 0.45f, 0.12f);
   glVertex2f(0.60f, -0.14f);
   glVertex2f(0.70f, -0.14f);
   glVertex2f(0.65f, -0.04f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.08f, 0.38f, 0.10f);
   glVertex2f(0.61f, -0.09f);
   glVertex2f(0.69f, -0.09f);
   glVertex2f(0.65f, 0.00f);
   glEnd();


   glPushMatrix();
   glTranslatef(0.18f, -0.02f, 0.0f);
   glScalef(0.63f, 0.63f, 1.0f);

   glBegin(GL_QUADS);
   glColor3f(0.35f, 0.20f, 0.08f);
   glVertex2f(0.64f, -0.14f);
   glVertex2f(0.66f, -0.14f);
   glVertex2f(0.66f, -0.24f);
   glVertex2f(0.64f, -0.24f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.10f, 0.45f, 0.12f);
   glVertex2f(0.60f, -0.14f);
   glVertex2f(0.70f, -0.14f);
   glVertex2f(0.65f, -0.04f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.08f, 0.38f, 0.10f);
   glVertex2f(0.61f, -0.09f);
   glVertex2f(0.69f, -0.09f);
   glVertex2f(0.65f, 0.00f);
   glEnd();
   glPopMatrix();


   glPushMatrix();
   glTranslatef(0.08f, 0.00f, 0.0f);
   glScalef(1.0f, 1.0f, 1.0f);

   glBegin(GL_QUADS);
   glColor3f(0.35f, 0.20f, 0.08f);
   glVertex2f(0.64f, -0.14f);
   glVertex2f(0.66f, -0.14f);
   glVertex2f(0.66f, -0.24f);
   glVertex2f(0.64f, -0.24f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.10f, 0.45f, 0.12f);
   glVertex2f(0.60f, -0.14f);
   glVertex2f(0.70f, -0.14f);
   glVertex2f(0.65f, -0.04f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.08f, 0.38f, 0.10f);
   glVertex2f(0.61f, -0.09f);
   glVertex2f(0.69f, -0.09f);
   glVertex2f(0.65f, 0.00f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.1f, -0.1f, 0.0f);
   glScalef(1.0f, 1.0f, 1.0f);

   glBegin(GL_QUADS);
   glColor3f(0.35f, 0.20f, 0.08f);
   glVertex2f(0.64f, -0.14f);
   glVertex2f(0.66f, -0.14f);
   glVertex2f(0.66f, -0.24f);
   glVertex2f(0.64f, -0.24f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.10f, 0.45f, 0.12f);
   glVertex2f(0.60f, -0.14f);
   glVertex2f(0.70f, -0.14f);
   glVertex2f(0.65f, -0.04f);
   glEnd();

   glBegin(GL_TRIANGLES);
   glColor3f(0.08f, 0.38f, 0.10f);
   glVertex2f(0.61f, -0.09f);
   glVertex2f(0.69f, -0.09f);
   glVertex2f(0.65f, 0.00f);
   glEnd();
   glPopMatrix();



//Left Side Grass



   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();


   glPushMatrix();
   glTranslatef(0.04f, 0.01f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.08f, 0.02f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   //2nd line grass

    glPushMatrix();
    glTranslatef(-0.01f, -0.06f, 0.0f);

   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();


   glPushMatrix();
   glTranslatef(0.04f, 0.01f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.08f, 0.02f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();
glPopMatrix();


//3rd line grass

    glPushMatrix();
    glTranslatef(-0.06f, -0.12f, 0.0f);

   glPushMatrix();
   glTranslatef(0.04f, -0.06f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();
   glPopMatrix();


   glPushMatrix();
   glTranslatef(0.04f, 0.01f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.08f, 0.02f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();
glPopMatrix();


//left side grass

 glPushMatrix();
 glTranslatef(0.3f, 0.4f, 0.0f);

     glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();


   glPushMatrix();
   glTranslatef(0.3f, 0.03f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.26f, 0.001f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   //2nd line grass

    glPushMatrix();
    glTranslatef(-0.01f, -0.06f, 0.0f);

   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();


   glPushMatrix();
   glTranslatef(0.04f, 0.01f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.08f, 0.02f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();
glPopMatrix();


//3rd line grass

    glPushMatrix();
    glTranslatef(-0.06f, -0.12f, 0.0f);

   glPushMatrix();
   glTranslatef(0.04f, -0.06f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();
   glPopMatrix();


   glPushMatrix();
   glTranslatef(0.04f, 0.01f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.08f, 0.02f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();

   glPushMatrix();
   glTranslatef(0.13f, 0.00f, 0.0f);
   glBegin(GL_LINES);
   glColor3f(0.10f, 0.55f, 0.10f);

   glVertex2f(-0.78f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.76f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.74f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.72f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.70f, -0.04f);
   glVertex2f(-0.74f, -0.1f);

   glVertex2f(-0.68f, -0.04f);
   glVertex2f(-0.74f, -0.1f);
   glEnd();

   glPopMatrix();
glPopMatrix();

glPopMatrix();


//Left-side buildings

     glBegin(GL_QUADS);
    glColor3f(0.30f, 0.18f, 0.10f);

    glVertex2f(-0.8f, 0.04f);
    glVertex2f(-0.8f, 0.06f);
    glVertex2f(-0.44f, 0.06f);
    glVertex2f(-0.44f, 0.04f);

    glEnd();

     glBegin(GL_QUADS);
    glColor3f(0.75f, 0.35f, 0.20f);

    glVertex2f(-0.6f, 0.48f);
    glVertex2f(-0.48f, 0.4f);
    glVertex2f(-0.48f, 0.06f);
    glVertex2f(-0.6f, 0.06f);

    glEnd();

     glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.22f, 0.12f);

    glVertex2f(-0.74f, 0.24f);
    glVertex2f(-0.74f, 0.4f);
    glVertex2f(-0.6f, 0.48f);
    glVertex2f(-0.6f, 0.06f);
    glVertex2f(-0.76f, 0.06f);
    glVertex2f(-0.76f, 0.2f);

    glEnd();

    // Windows - Left side building


    glBegin(GL_QUADS);
    glColor3f(0.30f, 0.85f, 0.90f);


    glVertex2f(-0.56f, 0.40f);
    glVertex2f(-0.5f, 0.36f);
    glVertex2f(-0.5f, 0.14f);
    glVertex2f(-0.56f, 0.14f);
    glEnd();


    // Hospital + sign on left polygon

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.685f, 0.22f);
    glVertex2f(-0.655f, 0.22f);
    glVertex2f(-0.655f, 0.32f);
    glVertex2f(-0.685f, 0.32f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);

    glVertex2f(-0.71f, 0.245f);
    glVertex2f(-0.63f, 0.245f);
    glVertex2f(-0.63f, 0.295f);
    glVertex2f(-0.71f, 0.295f);
    glEnd();





//trees with hospital

    glBegin(GL_QUADS);// Tree trunk
    glColor3f(0.35f, 0.20f, 0.08f);

    glVertex2f(-0.43f, 0.06f);
    glVertex2f(-0.40f, 0.06f);
    glVertex2f(-0.40f, 0.16f);
    glVertex2f(-0.43f, 0.16f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10f, 0.45f, 0.12f);

    glVertex2f(-0.47f, 0.14f);
    glVertex2f(-0.36f, 0.14f);
    glVertex2f(-0.415f, 0.25f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.08f, 0.38f, 0.10f);

    glVertex2f(-0.45f, 0.21f);
    glVertex2f(-0.38f, 0.21f);
    glVertex2f(-0.415f, 0.32f);
    glEnd();


    glPushMatrix();
    glTranslatef(0.08f, 0.06f, 0.0f);

    glBegin(GL_QUADS);// Tree trunk
    glColor3f(0.35f, 0.20f, 0.08f);

    glVertex2f(-0.43f, 0.06f);
    glVertex2f(-0.40f, 0.06f);
    glVertex2f(-0.40f, 0.16f);
    glVertex2f(-0.43f, 0.16f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10f, 0.45f, 0.12f);

    glVertex2f(-0.47f, 0.14f);
    glVertex2f(-0.36f, 0.14f);
    glVertex2f(-0.415f, 0.25f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.08f, 0.38f, 0.10f);

    glVertex2f(-0.45f, 0.21f);
    glVertex2f(-0.38f, 0.21f);
    glVertex2f(-0.415f, 0.32f);
    glEnd();
    glPopMatrix();

    //3rd tree hospital
    glPushMatrix();
    glTranslatef(0.16f, 0.13f, 0.0f);

    glBegin(GL_QUADS);// Tree trunk
    glColor3f(0.35f, 0.20f, 0.08f);

    glVertex2f(-0.43f, 0.06f);
    glVertex2f(-0.40f, 0.06f);
    glVertex2f(-0.40f, 0.16f);
    glVertex2f(-0.43f, 0.16f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10f, 0.45f, 0.12f);

    glVertex2f(-0.47f, 0.14f);
    glVertex2f(-0.36f, 0.14f);
    glVertex2f(-0.415f, 0.25f);

    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.08f, 0.38f, 0.10f);

    glVertex2f(-0.45f, 0.21f);
    glVertex2f(-0.38f, 0.21f);
    glVertex2f(-0.415f, 0.32f);
    glEnd();
    glPopMatrix();






//left another building







// carrr


glPushMatrix();
glTranslatef(0.38f-carPosition2, -0.43f + carPosition, 0.0f);

GLfloat scale = 1.0f - (carPosition + carPosition2) * 0.45f;

if(scale < 0.4f)
    scale = 0.4f;

glScalef(0.50f * scale, 0.70f * scale, 1.0f);


// Car Body

glBegin(GL_QUADS);
glColor3f(0.95f, 0.05f, 0.05f);

glVertex2f(-0.11f, -0.06f);
glVertex2f( 0.11f, -0.06f);
glVertex2f( 0.10f,  0.04f);
glVertex2f(-0.10f,  0.04f);
glEnd();


// Car Top

glBegin(GL_QUADS);
glColor3f(0.85f, 0.03f, 0.03f);

glVertex2f(-0.07f, 0.04f);
glVertex2f( 0.07f, 0.04f);
glVertex2f( 0.05f, 0.10f);
glVertex2f(-0.05f, 0.10f);
glEnd();


// Blue Windshield

glBegin(GL_QUADS);
glColor3f(0.20f, 0.70f, 0.90f);

glVertex2f(-0.05f, 0.045f);
glVertex2f( 0.05f, 0.045f);
glVertex2f( 0.035f, 0.085f);
glVertex2f(-0.035f, 0.085f);
glEnd();


// Left Tail Light

glBegin(GL_QUADS);
glColor3f(1.0f, 0.75f, 0.05f);

glVertex2f(-0.095f, -0.01f);
glVertex2f(-0.055f, -0.01f);
glVertex2f(-0.055f, 0.015f);
glVertex2f(-0.095f, 0.015f);
glEnd();

// Right Tail Light

glBegin(GL_QUADS);
glColor3f(1.0f, 0.75f, 0.05f);

glVertex2f(0.055f, -0.01f);
glVertex2f(0.095f, -0.01f);
glVertex2f(0.095f, 0.015f);
glVertex2f(0.055f, 0.015f);
glEnd();


// Number Plate

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);

glVertex2f(-0.035f, -0.045f);
glVertex2f( 0.035f, -0.045f);
glVertex2f( 0.035f, -0.025f);
glVertex2f(-0.035f, -0.025f);
glEnd();

// Left Wheel

glBegin(GL_QUADS);

glColor3f(0.02f, 0.02f, 0.02f);

glVertex2f(-0.095f, -0.08f);
glVertex2f(-0.06f, -0.08f);
glVertex2f(-0.06f, -0.045f);
glVertex2f(-0.095f, -0.045f);

glEnd();


// Right Wheel

glBegin(GL_QUADS);

glColor3f(0.02f, 0.02f, 0.02f);

glVertex2f(0.06f, -0.08f);
glVertex2f(0.095f, -0.08f);
glVertex2f(0.095f, -0.045f);
glVertex2f(0.06f, -0.045f);

glEnd();
glPopMatrix();

//Left car



glPushMatrix();
glTranslatef(-0.005f-car2Position2, 0.3f - car2Position, 0.0f);
 scale = 0.8f + (car2Position + car2Position2) * 2.0f;

if(scale > 3.3f)
    scale = 3.2f;

glScalef(0.20f * scale, 0.30f * scale, 1.0f);

// Body

glBegin(GL_QUADS);
glColor3f(0.10f, 0.45f, 0.80f);

glVertex2f(-0.12f, -0.06f);
glVertex2f( 0.12f, -0.06f);
glVertex2f( 0.12f,  0.04f);
glVertex2f(-0.12f,  0.04f);
glEnd();


// Front Window

glBegin(GL_QUADS);
glColor3f(0.05f, 0.25f, 0.45f);

glVertex2f(-0.08f, 0.04f);
glVertex2f( 0.08f, 0.04f);
glVertex2f( 0.06f, 0.10f);
glVertex2f(-0.06f, 0.10f);
glEnd();


// Left Window

glBegin(GL_QUADS);
glColor3f(0.30f, 0.75f, 0.90f);

glVertex2f(-0.055f, 0.048f);
glVertex2f(-0.005f, 0.048f);
glVertex2f(-0.005f, 0.085f);
glVertex2f(-0.045f, 0.085f);
glEnd();


// Right Window

glBegin(GL_QUADS);
glColor3f(0.30f, 0.75f, 0.90f);

glVertex2f(0.005f, 0.048f);
glVertex2f(0.055f, 0.048f);
glVertex2f(0.045f, 0.085f);
glVertex2f(0.005f, 0.085f);
glEnd();


// Left Headlight

glBegin(GL_QUADS);
glColor3f(1.0f, 0.85f, 0.10f);

glVertex2f(-0.105f, -0.005f);
glVertex2f(-0.065f, -0.005f);
glVertex2f(-0.065f, 0.02f);
glVertex2f(-0.105f, 0.02f);
glEnd();


// Right Headlight

glBegin(GL_QUADS);
glColor3f(1.0f, 0.85f, 0.10f);

glVertex2f(0.065f, -0.005f);
glVertex2f(0.105f, -0.005f);
glVertex2f(0.105f, 0.02f);
glVertex2f(0.065f, 0.02f);
glEnd();


// Front Grill

glBegin(GL_QUADS);
glColor3f(0.02f, 0.15f, 0.25f);

glVertex2f(-0.055f, -0.045f);
glVertex2f(0.055f, -0.045f);
glVertex2f(0.055f, -0.025f);
glVertex2f(-0.055f, -0.025f);
glEnd();


// Left Wheel

glBegin(GL_QUADS);
glColor3f(0.02f, 0.02f, 0.02f);

glVertex2f(-0.11f, -0.08f);
glVertex2f(-0.065f, -0.08f);
glVertex2f(-0.065f, -0.045f);
glVertex2f(-0.11f, -0.045f);
glEnd();


// Right Wheel

glBegin(GL_QUADS);
glColor3f(0.02f, 0.02f, 0.02f);

glVertex2f(0.065f, -0.08f);
glVertex2f(0.11f, -0.08f);
glVertex2f(0.11f, -0.045f);
glVertex2f(0.065f, -0.045f);
glEnd();


// Bumper

glBegin(GL_QUADS);
glColor3f(0.05f, 0.20f, 0.35f);

glVertex2f(-0.125f, -0.065f);
glVertex2f(0.125f, -0.065f);
glVertex2f(0.125f, -0.045f);
glVertex2f(-0.125f, -0.045f);
glEnd();

glPopMatrix();




//trafic light

glPushMatrix();

glTranslatef(-0.23f, -0.023f, 0.0f);
glScalef(0.355f, 0.355f, 1.0f);


// Traffic Light Pole

glBegin(GL_LINES);
glColor3f(0.1f, 0.1f, 0.1f);

glVertex2f(0.0f, 0.0f);
glVertex2f(0.0f, 0.60f);

glEnd();


// Traffic Light Box
// Box is now on TOP of the pole

glBegin(GL_QUADS);
glColor3f(0.15f, 0.15f, 0.15f);

glVertex2f(-0.06f, 0.55f);
glVertex2f( 0.06f, 0.55f);
glVertex2f( 0.06f, 0.75f);
glVertex2f(-0.06f, 0.75f);

glEnd();


// Red Light

glBegin(GL_QUADS);
if(trafficLight == 0)
    glColor3f(1.0f, 0.0f, 0.0f);   // Red ON
else
    glColor3f(0.0f, 0.0f, 0.0f);   // Red OFF

glVertex2f(-0.04f, 0.66f);
glVertex2f( 0.04f, 0.66f);
glVertex2f( 0.04f, 0.72f);
glVertex2f(-0.04f, 0.72f);

glEnd();


// Green Light

glBegin(GL_QUADS);
if(trafficLight == 1)
    glColor3f(0.0f, 1.0f, 0.0f);   // Green ON
else
    glColor3f(0.0f, 0.0f, 0.0f);   // Green OFF

glVertex2f(-0.04f, 0.57f);
glVertex2f( 0.04f, 0.57f);
glVertex2f( 0.04f, 0.63f);
glVertex2f(-0.04f, 0.63f);

glEnd();


glPopMatrix();


glFlush();  // Render now
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitWindowSize(720, 350);
    glutInitWindowPosition(50,50);

    glutCreateWindow("Vertex, Primitive & Color");
    glutDisplayFunc(displayCover);


    glutKeyboardFunc(switchPage);
    glutReshapeFunc(reshape);
    glutTimerFunc(2000, updateCloud, 0);
    glutTimerFunc(100, updateCar, 0);
    glutTimerFunc(100, updateCar2,0);
    glutTimerFunc(2000, updateTrafficLight, 0);

    //Jarif
    glutTimerFunc(2000, JA_updateCloud, 0);
    glutTimerFunc(20, JA_updateCar, 0);
    glutTimerFunc(20, JA_updateCar2, 0);

    //Israt
    glutTimerFunc(16, ManzilUpdate, 0);
    glutTimerFunc(5000, ManzilTrafficLightTimer, 0);
    //Dhrubo
    glutTimerFunc(20, SangsadUpdate, 0);
    //Shadman
    glutTimerFunc(30, SadarGhatUpdate, 0);

    glutMainLoop();

    return 0;
}
