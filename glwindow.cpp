#include "glwindow.h"

GLWindow::GLWindow(QWidget *parent)
    : QGLWidget(parent)
{
}

GLWindow::~GLWindow()
{

}

void GLWindow::initializeGL()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void GLWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (GLdouble)w / (GLdouble)h, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}

void GLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex3f(-1.0f, 1.0f, 0);
    glVertex3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}
