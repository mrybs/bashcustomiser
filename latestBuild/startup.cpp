#include "startup.h"
#include "ui_startup.h"

#include <fstream>

using namespace std;

const string USERNAME = getenv("USER");//User`s name

startup::startup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::startup)
{
    ui->setupUi(this);
    /*reading startup.sh*/
    const string startupconfig = "/home/" + USERNAME + "/.config/bashcustomiser/startup.sh";//file`s path

    string line;
    string filestr = "";
    ifstream read(startupconfig);//opening file for read
    if (read.is_open()) {//reading file
        while (getline(read, line))
        {
            filestr += line + "\n";
        }
        ui->textEdit->setPlainText(QString(filestr.c_str()));//showing containable file
    }
    read.close();//closing file
}

startup::~startup()
{
    delete ui;
}

void startup::on_EBtn_clicked(){this->close();}//close window when exit button has been pressed


void startup::on_SBtn_clicked(){/*save changes*/
    const string startupconfig = "/home/" + USERNAME + "/.config/bashcustomiser/startup.sh";//file`s path

    ofstream write(startupconfig, ios::out);//open file for write
    write << ui->textEdit->toPlainText().toStdString().c_str();
    write.close();
}

