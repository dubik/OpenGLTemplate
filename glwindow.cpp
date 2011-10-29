#include "glwindow.h"

GLWindow::GLWindow(QWidget *parent)
    : QGLWidget(parent)
{
    bool l = texture1.load(":/textures/stone256x256.jpg");
    qDebug() << l;
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
    glEnable(GL_TEXTURE_2D);
    bindTexture(texture1);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-0.5f, 0.5f, 0);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(0.5f, 0.5f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(0.5f, -0.5f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-0.5f, -0.5f, 0.0f);
    glEnd();
}
