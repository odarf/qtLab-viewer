#include "thirdform.h"
#include "secondform.h"

#include <QFile>
#include <QFileDialog>
#include <QByteArray>
#include <QString>

ThirdForm::ThirdForm(QWidget *parent) :   QDialog (parent)
{
    setAttribute(Qt::WA_DeleteOnClose,true);
    setMinimumSize(400,400);
    setMaximumSize(600,600);
    setWindowTitle("Saved!");
    // Открывает файл для Чтения с помощью пути, указанного в lineEditWrite
    QFile file("proba.xml");
    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << "ERROR!";
    }
    else
    {
        QXmlStreamReader xmlReader(&file);
        while(!xmlReader.atEnd())
        {
            xmlReader.readNext();
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name() == "view_1")
                {
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "flag")
                        {
                            QString attribute_value = attr.value().toString();
                            flag =QString(attribute_value).toInt();
                            if (flag==0)
                            {
                                static const QString PROGRAM_NAME = "mspaint";
                                QProcess::startDetached( PROGRAM_NAME );
                            }
                            else if (flag==1)
                            {
                                static const QString PROGRAM_NAME = "notepad";
                                QProcess::startDetached( PROGRAM_NAME );
                            }
                            else if (flag==2)
                            {
                                static const QString PROGRAM_NAME = "win32calc";
                                QProcess::startDetached( PROGRAM_NAME );
                            }

                        }
                    }
                }
                else
                    foreach(const QXmlStreamAttribute &attr, xmlReader.attributes())
                    {
                        if (attr.name().toString() == "flag")
                        {
                            QString attribute_value = attr.value().toString();
                            flag =QString(attribute_value).toInt();
                            if (flag==3)
                            {
                                static const QString PROGRAM_NAME = "mspaint";
                                QProcess::startDetached( PROGRAM_NAME );
                            }
                            else if (flag==4)
                            {
                                static const QString PROGRAM_NAME = "notepad";
                                QProcess::startDetached( PROGRAM_NAME );
                            }
                            else if (flag==5)
                            {
                                static const QString PROGRAM_NAME = "win32calc";
                                QProcess::startDetached( PROGRAM_NAME );
                            }

                        }
                    }
                }
        }
    file.close();
    }
}

ThirdForm::~ThirdForm()
{
}
