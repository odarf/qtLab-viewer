#ifndef SECONDFORM_H
#define SECONDFORM_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class SecondForm;
}

class SecondForm : public QDialog       //в качестве базового взят класс QDialog
{
   Q_OBJECT

public:
   explicit SecondForm(QWidget *parent = nullptr);
   ~SecondForm();

private:
   QLabel *ScnFrmLbl;      //надпись
   QPushButton *ExitBtn;   //кнопка выход
   QPushButton *Paint;
   QPushButton *Calculator;
   QPushButton *Notepad;
   QPushButton *Ok;
   QComboBox *lv;
   int flag;

private slots:
   void on_exitButton_2_clicked();
   void on_exitButton_3_clicked();
   void on_exitButton_4_clicked();
   void on_exitButton_clicked();   //слот для работы кнопки выход
   int on_exitButton_6_clicked(int index);
   int currentIndexChanged();
   void savefile();
  // void openfile();
   void keyPressEvent(QKeyEvent *event);
};

#endif // SECONDFORM_H
