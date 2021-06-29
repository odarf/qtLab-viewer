#ifndef THIRDFORM_H
#define THIRDFORM_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class ThirdForm;
}

class ThirdForm : public QDialog       //в качестве базового взят класс QDialog
{
   Q_OBJECT

public:
   explicit ThirdForm(QWidget *parent = nullptr);
   ~ThirdForm();
protected:
private:
    int flag;

};
#endif // THIRDFORM_H
