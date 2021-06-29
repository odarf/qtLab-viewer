#include "secondform.h"

#include <QWidget>
#include <QtWidgets>
#include <QFile>
#include <QFileDialog>

SecondForm::SecondForm(QWidget *parent) :
   QDialog (parent)
{
   resize(QDesktopWidget().availableGeometry(this).size() * 0.3);
   setAttribute(Qt::WA_DeleteOnClose,true);        //устанавливаем свойство "удалить виджет по завершении"
   setWindowTitle("Design-time");

   Paint = new QPushButton("Paint",this);
   Paint->setGeometry(10,10,100,30);
   connect(Paint,SIGNAL(clicked(bool)), this,SLOT(on_exitButton_2_clicked()));

   Calculator = new QPushButton("Calculator",this);
   Calculator->setGeometry(10,60,100,30);
   connect(Calculator,SIGNAL(clicked(bool)), this,SLOT(on_exitButton_4_clicked()));

   Notepad = new QPushButton("Notepad",this);
   Notepad->setGeometry(10,110,100,30);
   connect(Notepad,SIGNAL(clicked(bool)), this,SLOT(on_exitButton_3_clicked()));

   ExitBtn = new QPushButton("Back to main window",this);
   ExitBtn->setGeometry(190,270,200,30);
   connect(ExitBtn,SIGNAL(clicked(bool)), this,SLOT(on_exitButton_clicked()));

   lv = new QComboBox(this);
   lv->setGeometry(450,10,100,40);
   lv->insertItem(0,"paint");
   lv->insertItem(1,"notepad");
   lv->insertItem(2,"calculator");

   Ok = new QPushButton("Ok",this);
   Ok->setGeometry(450,60,100,30);

   connect(Ok,&QAbstractButton::clicked,this,&SecondForm::currentIndexChanged);

}

void SecondForm::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Escape)
    {
        savefile();
        close();
    }
}

void SecondForm::savefile()
{   
    QFile file("proba.xml");
    if(!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "ERROR!";
    }
    else
    {
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("Choice");
        if (flag==0|flag==1|flag==2)
        {
            xmlWriter.writeStartElement("view_1");
            xmlWriter.writeAttribute("flag",QString::number(flag));
        }
        else
        {
            xmlWriter.writeStartElement("view_2");
            xmlWriter.writeAttribute("flag",QString::number(flag));
        }
        //xmlWriter.writeCharacters(choice);
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
        file.close();
    }

}

int SecondForm::on_exitButton_6_clicked(int index)
{
    if(index==1)
    {
        on_exitButton_3_clicked();
    }
    else
    {
        static const QString PROGRAM_NAME = "notepad";
        QProcess::startDetached( PROGRAM_NAME );
    }
    return 0;
}

SecondForm::~SecondForm()
{
}

void SecondForm::on_exitButton_clicked()
{
   parentWidget()->show(); //показать родительское окно
   close();                //закрыть данное окно
}

void SecondForm::on_exitButton_2_clicked()
{
    flag=0;
    static const QString PROGRAM_NAME = "mspaint";
    QProcess::startDetached( PROGRAM_NAME );
}

void SecondForm::on_exitButton_3_clicked()
{
    flag=1;
    static const QString PROGRAM_NAME = "notepad";
    QProcess::startDetached( PROGRAM_NAME );
}

void SecondForm::on_exitButton_4_clicked()
{
    flag=2;
    static const QString PROGRAM_NAME = "win32calc";
    QProcess::startDetached( PROGRAM_NAME );
}

int SecondForm::currentIndexChanged()
{
    if (lv->currentIndex()==0)
    {
        flag=3;
        static const QString PROGRAM_NAME = "mspaint";
        QProcess::startDetached( PROGRAM_NAME );
    }
    else
        if (lv->currentIndex()==1)
        {
            flag=4;
            static const QString PROGRAM_NAME = "notepad";
            QProcess::startDetached( PROGRAM_NAME );
        }
        else
            {
            flag=5;
            static const QString PROGRAM_NAME = "win32calc";
            QProcess::startDetached( PROGRAM_NAME );
            }
    return 0;
}
