#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWin; }
QT_END_NAMESPACE

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    MainWin(QWidget *parent = nullptr);
    ~MainWin();

private slots:
    void on_apply_clicked();

    void on_clearBtn_clicked();

    void on_seqCB_currentIndexChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_addSeqBtn_clicked();

    void on_actionHelp_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionEdit_triggered();

private:
    Ui::MainWin *ui;
};
#endif // MAINWIN_H
