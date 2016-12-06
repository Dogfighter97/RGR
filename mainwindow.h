#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_marketButton_clicked();

    void on_actionNewGame_triggered();

    void on_saveButton_clicked();

    void on_actionSave_triggered();

    void on_loadButton_clicked();

    void on_endTurnButton_clicked();

public slots:
    void gameUpdate();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
