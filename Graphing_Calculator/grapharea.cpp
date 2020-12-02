#include "grapharea.h"
#include "ui_grapharea.h"

GraphArea::GraphArea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphArea)
{
    ui->setupUi(this);
}

GraphArea::~GraphArea()
{
    delete ui;
}

void GraphArea::drawGraph(std::vector<double>& x, std::vector<double>& y)
{
    this->x = x;
    this->y = y;
    update();
}

void GraphArea::paintEvent(QPaintEvent *) {
    QPainter brush(this);
    QPen pen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    brush.setPen(pen);

    if (x.size() > 0) {
        for (unsigned long i = 0; i < x.size() - 1; ++i) {
            QLineF line(x.at(i), y.at(i), x.at(i+1), y.at(i+1));
            brush.drawLine(line);
        }
    }
}

void GraphArea::reset() {
    this->x.clear();
    this->y.clear();
    update();
}
