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

void GraphArea::drawGraph(const std::vector<double>& x, const std::vector<double>& y)
{
//    QPainterPath pp;
//    QPainter brush;
//    QLineF line(0,0, 300, 300);
//    QPen pen(Qt::green, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
////    brush.begin(ui);
//    brush.setPen(pen);
//    brush.drawLine(line);

//    pp.moveTo(QPointF(1,4));
//    pp.lineTo(QPointF(40, 30));
//    pp.moveTo(QPointF(40,30));
//    pp.lineTo(QPointF(40, 200));
    update();
}

void GraphArea::paintEvent(QPaintEvent *) {
//    QPainterPath pp;
    QPainter brush(this);
    QLineF line(0,0, 300, 300);
    QPen pen(Qt::green, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    brush.setPen(pen);
    brush.drawLine(line);
}
