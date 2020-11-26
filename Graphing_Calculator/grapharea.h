#ifndef GRAPHAREA_H
#define GRAPHAREA_H

#include <QWidget>
#include <vector>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QPaintDevice>
#include <vector>
#include <iostream>
namespace Ui {
class GraphArea;
}

class GraphArea : public QWidget
{
    Q_OBJECT

public:
    explicit GraphArea(QWidget *parent = nullptr);
    ~GraphArea();

    void drawGraph(std::vector<double>& x, std::vector<double>& y);

    void paintEvent(QPaintEvent *);

private:
    std::vector<double> x;
    std::vector<double> y;
    bool graphExist;
    Ui::GraphArea *ui;
};

#endif // GRAPHAREA_H
