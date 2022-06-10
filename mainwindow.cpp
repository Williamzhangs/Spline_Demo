#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    high << "26" << "28" << "27" << "27" << "26" << "27" << "31" << "34" << "34"<< "34" <<"31" << "32"<<"33" <<"33" << "31"<<
           "26" << "28" << "27" << "27" << "26" << "27" << "31" << "34" << "34"<< "34" <<"31" << "32"<<"33" <<"33" << "31";
    low << "19" << "19" <<"17" << "16" <<"17" << "20" << "21" << "23" << "23" << "22" << "23" << "24" << "21" << "22" << "21"<<
           "19" << "19" <<"17" << "16" <<"17" << "20" << "21" << "23" << "23" << "22" << "23" << "24" << "21" << "22" << "19";
    QVector<double> x(30),y(30);
    QVector<double> x1(30),y1(30);
    for(int i = 0; i < 30; i++)
    {
       x[i]=i+1;
       y[i]= high.at(i).toDouble();
       x1[i]=i+1;
       y1[i]= low.at(i).toDouble();
    }


    ui->Qcp->addGraph();  //添加画布
    ui->Qcp->graph(0)->setData(x,y);
    ui->Qcp->graph(0)->setPen(QPen(Qt::blue)); // 曲线的颜色
    ui->Qcp->addGraph();  //添加画布
    ui->Qcp->graph(1)->setData(x1,y1);
    ui->Qcp->graph(1)->setPen(QPen(Qt::green)); // 曲线的颜色

    ui->Qcp->xAxis->setRange(1,30);  //设置横坐标数据范围
    ui->Qcp->yAxis->setRange(0,40);  //设置纵坐标数据范围

    ui->Qcp->xAxis->setLabel("x");  //设置x轴标签
    ui->Qcp->yAxis->setLabel("y");  //
}

MainWindow::~MainWindow()
{
    delete ui;
}

