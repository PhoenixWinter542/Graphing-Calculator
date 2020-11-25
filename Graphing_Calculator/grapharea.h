#ifndef GRAPHAREA_H
#define GRAPHAREA_H

#include <QWidget>
#include <vector>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <QPaintDevice>
namespace Ui {
class GraphArea;
}

class GraphArea : public QWidget
{
    Q_OBJECT

public:
    explicit GraphArea(QWidget *parent = nullptr);
    ~GraphArea();

    void drawGraph(const std::vector<double>& x, const std::vector<double>& y);

    void paintEvent(QPaintEvent *);

private:
    Ui::GraphArea *ui;
};

#endif // GRAPHAREA_H
