#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_DrawButton_clicked()
{
    ui->EquationList->addItem(ui->EnterEquation->text());
}

void MainWindow::on_EquationList_currentIndexChanged(const QString &arg1)
{
    // generate points and graph
    Interpreter III(arg1.toStdString());
    HandleVars *coords = III.getParsedEquation();
    std::vector<double> x, y;

    double input = 0;
    while (input < 500) {
        x.push_back(input);
        y.push_back(coords->getPoint(std::to_string(input)));
        input += .1;
    }
    ui->graph->drawGraph(x, y);
}
