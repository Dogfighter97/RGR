#ifndef MARKET_H
#define MARKET_H

#include <QDialog>

namespace Ui {
class Market;
}

class Market : public QDialog
{
    Q_OBJECT

public:
    explicit Market(QWidget *parent = 0);
    ~Market();

private slots:

    void on_cancelPushButton_clicked();

    void on_buyPushButton_clicked();

private:
    Ui::Market *ui;
};

#endif // MARKET_H
