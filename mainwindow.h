#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   MainWindow(QWidget *parent = 0);
   ~MainWindow();
private:
   QPushButton *OpenBtn;   //кнопка Открыть
   QPushButton *ExitBtn;   //кнопка Выход

   //QPushButton *Back;

private slots:
   void openfile();
   void on_openButton_clicked(); //слот для работы кнопки открыть
};

#endif // MAINWINDOW_H
