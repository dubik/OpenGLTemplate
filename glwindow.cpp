#include "glwindow.h"
#include <glu.h>

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

    vertexShader = new QGLShader(QGLShader::Vertex, context(), this);
    vertexShader->compileSourceFile(":/shaders/solidColor.vert");
    if(!vertexShader->isCompiled()) {
        qDebug() << fragmentShader->log();
    }

    fragmentShader = new QGLShader(QGLShader::Fragment, context(), this);
    fragmentShader->compileSourceFile(":/shaders/solidColor.frag");
    if(!fragmentShader->isCompiled()) {
        qDebug() << fragmentShader->log();
    }

    program = new QGLShaderProgram(context(), this);
    program->addShader(vertexShader);
    program->addShader(fragmentShader);
    program->link();
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
    program->bind();
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glEnd();
    program->release();
}
