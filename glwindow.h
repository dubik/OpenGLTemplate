#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QtGui/QWidget>
#include <QtOpenGL/QtOpenGL>

class GLWindow : public QGLWidget
{
    Q_OBJECT

public:
    GLWindow(QWidget *parent = 0);
    ~GLWindow();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
};

#endif // GLWINDOW_H
