#ifndef STARTUP_H
#define STARTUP_H

#include <QDialog>

namespace Ui {
class startup;
}

class startup : public QDialog
{
    Q_OBJECT

public:
    explicit startup(QWidget *parent = nullptr);
    ~startup();

private slots:
    void on_EBtn_clicked();

    void on_SBtn_clicked();

private:
    Ui::startup *ui;
};

#endif // STARTUP_H
