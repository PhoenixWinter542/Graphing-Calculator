#ifndef GRAPHAREA_H
#define GRAPHAREA_H

#include <QWidget>

namespace Ui {
class GraphArea;
}

class GraphArea : public QWidget
{
    Q_OBJECT

public:
    explicit GraphArea(QWidget *parent = nullptr);
    ~GraphArea();

private:
    Ui::GraphArea *ui;
};

#endif // GRAPHAREA_H
