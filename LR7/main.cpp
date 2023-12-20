#include "mainwindow.h"

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent){
   //     setFixedSize(200, 200);
        squareRect = QRect(50, 50, 50, 50);
    }
protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setBrush(Qt::green);
        painter.drawRect(squareRect);
    }

    void mousePressEvent(QMouseEvent *event) override {
        if(event->button() == Qt::LeftButton) {
            if(squareRect.contains(event->pos())) {
                isDragging = true;
                dragOffset = event->pos() - squareRect.topLeft();
            }
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if(isDragging) {
            squareRect.moveTo(event->pos() - dragOffset);
            update();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        Q_UNUSED(event);
        isDragging = false;
    }

private:
    QRect squareRect;
    bool isDragging = false;
    QPoint dragOffset;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget widget;
    widget.show();

    return a.exec();
}
