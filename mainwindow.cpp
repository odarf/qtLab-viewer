#include "mainwindow.h"
#include "secondform.h"
#include "thirdform.h"


MainWindow::MainWindow(QWidget *parent)
   : QMainWindow(parent)
{
   setMinimumSize(400,400);
   setMaximumSize(600,600);
   setWindowTitle("Main window");
   //resize(QDesktopWidget().availableGeometry(this).size() * 0.2);
   OpenBtn = new QPushButton("Design-time",this);
   ExitBtn = new QPushButton("Run-time",this);
   QHBoxLayout *hLayout = new QHBoxLayout(this);
   hLayout->addWidget(OpenBtn);
   hLayout->addWidget(ExitBtn);
   QWidget *centralWidget = new QWidget(this);
   centralWidget->setLayout(hLayout);
   setCentralWidget(centralWidget);

   connect(ExitBtn,SIGNAL(clicked(bool)), this,SLOT(openfile()));
   connect(OpenBtn,SIGNAL(clicked(bool)), this,SLOT(on_openButton_clicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::openfile()
{
    ThirdForm* ThForm = new ThirdForm(this);
    ThForm->show();    //показать дочернее окно
    hide();             //скрыть основное окно
}

void MainWindow::on_openButton_clicked()
{
   SecondForm* ScnForm = new SecondForm(this);
   ScnForm->show();    //показать дочернее окно
   hide();             //скрыть основное окно
}
