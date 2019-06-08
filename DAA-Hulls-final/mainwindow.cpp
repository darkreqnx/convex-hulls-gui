//!  Class for the GUI
/*!
  Class that holds all the GUI elements and slots/signals.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.h"
#include "graph.h"
#include "graham.h"
#include "kps.h"
#include "clickablelabel.h"

static int STATUS=0;
static int Count;
static int i=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->canvas, SIGNAL(clicked()), this, SLOT(mouse_pos()));
    ui->radioButton_graham->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    if(STATUS==0){
        if(ui->radioButton_kirk->isChecked()) setMode(KIRK);
        if(ui->radioButton_graham->isChecked()) setMode(GRAHAM);
        if(ui->radioButton_jarvis->isChecked()) setMode(JARVIS);
        std:: string x = std::to_string(getMode());
        QString qstr = QString::fromStdString(x);
        ui->label->setText(qstr);

        Graph& g = getGraph();
        std::vector<Point> np = g.getNormalPoints();
        if(np.size()<3){
            reset();
            ui->label->setText("Number of Points is less than three!!");
            return;
        }

        if(getMode()==GRAHAM){
            //Code For Graham Scan
            Count = Graham::GrahamScan();
            ui->label->setText("Graham Scan Successfull. Check Iterations");
            STATUS = 1;
        }else if (getMode()==JARVIS) {
            Count = Jarvis::JarvisHull();
            ui->label->setText("Jarvis Successfull. Check Iterations");
            STATUS = 1;
        }else if (getMode()==KIRK) {
            Count = KPS::KPSScan();
            ui->label->setText("KPS Successfull. Check Iterations");
            STATUS = 1;
        }
    }else{
        ui->label->setText("Algorithm already Running. Please Reset.");
    }

    return;
}

void MainWindow::on_pushButton_clicked()
{
    if(getMode()==GRAHAM){
        if(i<Count){
            if(Graham::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("End of Iterations");
        }
    }else if (getMode()==JARVIS) {
        if(i<Count){
            if(Jarvis::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("End of Iterations");
        }
    }else if (getMode()==KIRK) {
        if(i<Count){
            if(KPS::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("End of Iterations");
        }
    }
}
void MainWindow::on_pushButton_3_clicked()
{
    if(getMode()==GRAHAM){
        i-=2;
        //    std::cout<<"i value: "<<i<< std::endl;
        if(i>=0){
            if(Graham::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("First Iteration");
            i=0;
        }
    }else if (getMode()==JARVIS) {
        i-=2;
        //    std::cout<<"i value: "<<i<< std::endl;
        if(i>=0){
            if(Jarvis::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("First Iteration");
            i=0;
        }
    }else if (getMode()==KIRK) {
        i-=2;
        //    std::cout<<"i value: "<<i<< std::endl;
        if(i>=0){
            if(KPS::Iteration(i)){
                Paint();
            }else {
                std::cout<<"Error in Reading Iteration"<<std::endl;
            }
            i++;
        }else{
            ui->label->setText("First Iteration");
            i=0;
        }
}
}
void MainWindow::mouse_pos()
{
//    std::cout<< ui->canvas->x << " " << ui->canvas->y << std::endl;

    if(STATUS ==0){;

        Graph& g = getGraph();
        g.addNormalPoint(ui->canvas->x,ui->canvas->y);
        Paint();

    }
}

void MainWindow::Paint(){

    int w = ui->canvas->width();
    int h = ui->canvas->height();
//    std::cout<<w <<" "<<h << std::endl;
    QPixmap pixmap(w,h);
    pixmap.fill(QColor("transparent"));

    QPainter painter(&pixmap);

    QPen pointPen(Qt::blue);
    pointPen.setCapStyle(Qt::RoundCap);
    pointPen.setWidth(10);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(pointPen);

    Graph& g = getGraph();
    std::vector<Point> np = g.getNormalPoints();
    for(auto i : np){
//      std::cout<< i.x << " " << i.y << std::endl;
      painter.drawPoint(i.x,i.y);
    }

    QPen linepen(Qt::blue);
    linepen.setCapStyle(Qt::FlatCap);
    linepen.setWidth(1);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(linepen);
//        for (int i=0;i<(int)np.size()-1;i++) {
//            painter.drawLine(np[i].x,np[i].y, np[i+1].x,np[i+1].y);

//        }
    std::vector<Line> nl = g.getNormalLines();
    for(auto i:nl){
        painter.drawLine(i.p1.x,i.p1.y,i.p2.x,i.p2.y);
    }

    QPen bpointPen(Qt::red);
    bpointPen.setCapStyle(Qt::RoundCap);
    bpointPen.setWidth(15);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(bpointPen);

    std::vector<Point> bp = g.getBoldPoints();
    for(auto i : bp){
//      std::cout<< i.x << " " << i.y << std::endl;
      painter.drawPoint(i.x,i.y);
    }

    QPen blinepen(Qt::red);
    blinepen.setCapStyle(Qt::FlatCap);
    blinepen.setWidth(2);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(blinepen);

    std::vector<Line> bl = g.getBoldLines();
    for(auto i:bl){
        painter.drawLine(i.p1.x,i.p1.y,i.p2.x,i.p2.y);
    }

    ui->canvas->setPixmap(pixmap);
    QString qstr = QString::fromStdString(g.Message);
    ui->label->setText(qstr);
}




void MainWindow::on_pushButton_4_clicked()
{

    reset();
}

void MainWindow::reset(){
    STATUS = 0;
    Graph g;
    Graph& x = getGraph();
    x = g;
    Paint();
}
