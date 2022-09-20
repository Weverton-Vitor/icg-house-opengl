#include <cstdlib>
#include <iostream>
#include <GL/glut.h>
#include <cmath>

GLint WINDOW_WIDTH = 500,
      WINDOW_HEIGHT = 500;

void init();
void draw_house();

void keybord_event(GLubyte key, GLint x, GLint y);
void keybord_special_event(GLint key, GLint x, GLint y);

void menu_test(GLint item_number);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH),
          screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
    glutCreateWindow("OpenGL manipulacao de entradas (teclado/mouse)");

    init();
    glutDisplayFunc(draw_house);
    glutKeyboardFunc(keybord_event);
    glutSpecialFunc(keybord_special_event);

    glutMainLoop();

    return EXIT_SUCCESS;
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void draw_house()
{
    glClear(GL_COLOR_BUFFER_BIT);

    std::cout << "Desenhar casa aqui\n";

    // Altera a cor do desenho para vermelho
    glColor3f(0.0f, 1.0f, 0.0f);
    glLineWidth(3.0f); // aumenta a espessura das linhas

    // Paredes
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 0);
    glVertex2f(100, 100);
    glVertex2f(400, 100);

    glVertex2f(400, 300);
    glVertex2f(100, 300);
    glEnd();

    // Teto
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 0, 0);

    glVertex2f(100 - 20, 300);
    glVertex2f(400 + 20, 300);
    glVertex2f(250, 400);
    glEnd();

    // Porta
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);

    glVertex2f(150, 100);
    glVertex2f(150, 200);

    glVertex2f(200, 200);
    glVertex2f(200, 100);

    glEnd();

    // Janela
    glBegin(GL_QUADS);
        glVertex2f(250, 130);
        glVertex2f(250, 200);

        glVertex2f(350, 200);
        glVertex2f(350, 130);
    glEnd();

    glBegin(GL_LINE_LOOP);
    int num_segments = 150000;
    glColor3ub(247, 147, 26);
    int r = 5;
    for (int ii = 0; ii < num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 
        float x = r * cosf(theta);//calculate the x component 
        float y = r * sinf(theta);//calculate the y component 
        glVertex2f(x + 190, y + 150);//output vertex 
    }
    glEnd();


    // glBegin(GL_LINE_LOOP);
    // for (size_t i = 200; i < 400; i++)
    // {   
    //     GLfloat y = pow(i, 2);
    //     // y = -y;
    //     y = -sqrt(y + 2) + 300;
    //     std::cout << i << " " << y << "\n";

    //     glVertex2f(i, y);

    // }

    // glEnd();

    glFlush();
}

void keybord_event(GLubyte key, GLint x, GLint y)
{
    GLint m = glutGetModifiers();

    std::cout << "Tecla: " << (GLint)key << " (x:" << x << ", y:" << y << ")\n";

    // ESC = 27
    if (key == 27)
        glutReshapeWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Espaço = 32
    if (key == 32)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glutPostRedisplay();
    }

    if (key != 32)
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glutPostRedisplay();
    }
}

void keybord_special_event(GLint key, GLint x, GLint y)
{

    std::cout << "Tecla especial: " << key << " (x:" << x << ", y:" << y << ")\n";

    if (key == GLUT_KEY_F11)
        glutFullScreen();

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glutPostRedisplay();
}

void menu_test(GLint item_number)
{
    std::cout << "Item " << item_number << "\n";
    glutPostRedisplay();
}
