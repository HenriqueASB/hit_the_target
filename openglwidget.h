#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>
#include <QTimer>
#include <QElapsedTimer>
#include <QFile>
#include <QVector4D>
#include <QKeyEvent>
#include <QApplication>
#include <QDebug>
#include <array>
#include <cmath>


class OpenGLWidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWidget(QWidget *parent = nullptr);
    ~OpenGLWidget();

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    GLuint vboVertices{0};
    GLuint vboColors{0};
    GLuint eboIndices{0};
    GLuint vao{0};

    std::vector<QVector4D> vertices;
    std::vector<QVector4D> colors;
    std::vector<GLuint> indices;



    GLuint shaderProgram{0};

    void createVBOs();
    void createShaders();

    void destroyVBOs();
    void destroyShaders();

    void changeDiagonal();

    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;


    float playerPosYOffset{0};
    float playerPosY{0};

    float targetPosYOffset{2.0f};
    float targetPosY{0};

    QElapsedTimer elapsedTimer;

    bool shooting{false};
    bool rapidShooting{false};
    std::array<float,2> projectilePos;
    int numHits{0};
    bool shooting2{false};
    std::array<float,2> projectilePos2;




signals:
    void updateHitsLabel(QString);

public slots:
    void animate();
    void explosion(bool);

private:
    QTimer timer;
    bool blinkFlag{false};
};

#endif // OPENGLWIDGET_H
