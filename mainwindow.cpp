#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "z.h"

bla ii;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);// Устанавливаем сглаживание
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер

    ui->pushButton->setStyleSheet("*{background-color: #000000;}");
    ui->pushButton_2->setStyleSheet("*{background-color: #84888c;}");
    ui->pushButton_3->setStyleSheet("*{background-color: #000384;}");
    ui->pushButton_4->setStyleSheet("*{background-color: #007f80;}");
    ui->pushButton_5->setStyleSheet("*{background-color: #007e00;}");
    ui->pushButton_6->setStyleSheet("*{background-color: #7f7e00;}");
    ui->pushButton_7->setStyleSheet("*{background-color: #800300;}");
    ui->pushButton_8->setStyleSheet("*{background-color: #3f3f3f;}");
    ui->pushButton_9->setStyleSheet("*{background-color: #ffffff;}");
    ui->pushButton_10->setStyleSheet("*{background-color: #0007f4;}");
    ui->pushButton_11->setStyleSheet("*{background-color: #05e2f8;}");
    ui->pushButton_12->setStyleSheet("*{background-color: #01d200;}");
    ui->pushButton_13->setStyleSheet("*{background-color: #f9ec04;}");
    ui->pushButton_14->setStyleSheet("*{background-color: #f20b00;}");
    ui->pushButton_20->setStyleSheet("*{background-color: #f01af0;}");
    ui->pushButton_19->setStyleSheet("*{background-color: #7f0c7d;}");
    ui->pushButton_15->setStyleSheet("*{background-color: #000000;}");
    ui->pushButton_17->setEnabled(false);
    ii.col=Qt::black;
    ii.val=1;
    ii.n=1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width(), ui->graphicsView->height());
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #000000;}");
    ii.col=Qt::black;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #84888c;}");
    ii.col=Qt::gray;
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #000384;}");
    ii.col=Qt::darkBlue;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #007f80;}");
    ii.col=Qt::darkCyan;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #007e00;}");
    ii.col=Qt::darkGreen;
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #7f7e00;}");
    ii.col=Qt::darkYellow;
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #800300;}");
    ii.col=Qt::darkRed;
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #7f0c7d;}");
    ii.col=Qt::darkMagenta;
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #3f3f3f;}");
    ii.col=Qt::darkGray;
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #ffffff;}");
    ii.col=Qt::white;
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #0007f4;}");
    ii.col=Qt::blue;
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #05e2f8;}");
    ii.col=Qt::cyan;
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #01d200;}");
    ii.col=Qt::green;
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #f9ec04;}");
    ii.col=Qt::yellow;
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #f20b00;}");
    ii.col=Qt::red;
}

void MainWindow::on_pushButton_20_clicked()
{
    ui->pushButton_15->setStyleSheet("*{background-color: #f01af0;}");
    ii.col=Qt::magenta;
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0)
    scene->setTypeFigure(PaintScene::LineT);
    else if (index == 1)
    scene->setTypeFigure(PaintScene::CurveT);
    else if (index == 2)
    scene->setTypeFigure(PaintScene::SquareT);
    else if (index == 3)
    scene->setTypeFigure(PaintScene::ElipseT);

}

void MainWindow::on_pushButton_18_clicked()
{
    scene->clear();
    scene->update(QRectF(0,0,this->width(), this->height()));
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ii.val = arg1;
}

void MainWindow::on_pushButton_16_clicked()
{
    if (ii.n-1 < ii.y.size())
    {
        scene->removeItem(ii.y[ii.y.size()-ii.n]);
        scene->update(QRectF(0,0,this->width(), this->height()));
        if (ii.y.size()>ii.n)
        ii.n++;
        ui->pushButton_17->setEnabled(true);
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    if (ii.n>0)
    {
        scene->addItem(ii.y[ii.y.size()-ii.n]);
        scene->update(QRectF(0,0,this->width(), this->height()));
        if (ii.n>1)
        ii.n--;
    }
}
