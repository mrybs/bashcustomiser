#include "mainwin.h"
#include "ui_mainwin.h"
#include "help.h"
#include "startup.h"

#include <fstream>
#include <QMessageBox>

using namespace std;

const string USERNAME = getenv("USER");//User`s name
const int seqCount = 11;
const int colCount = 15;

string bashrcconf;

QString sequencesText[seqCount+1] = {
    "Select sequence",
    "Username",
    "Hostname",
    "Date",
    "Time 24h hh:mm:ss",
    "Time 12h hh:mm:ss",
    "Time 12h am/pm",
    "Time 24h hh:mm",
    "Current working directory",
    "Name of current working directory",
    "Version of bash",
    "New line"
};
QString sequences[seqCount] = {
    "u",
    "H",
    "d",
    "t",
    "T",
    "@",
    "A",
    "w",
    "W",
    "v",
    "n"
};
QString colorsText[colCount] = {
    "White",
    "Red",
    "Green",
    "Yellow",
    "Blue",
    "Magneta",
    "Cyan",
    "Gray",
    "Light red",
    "Light green",
    "Light yellow",
    "Light blue",
    "Light magneta",
    "Light cyan",
    "Light gray"
};
QString colors[colCount] = {
    "39",/*white*/
    "31",/*red*/
    "32",/*green*/
    "33",/*yellow*/
    "34",/*blue*/
    "35",/*magneta*/
    "36",/*cyan*/
    "37",/*gray*/
    "38",/*light red*/
    "92",/*light green*/
    "93",/*light yellow*/
    "94",/*light blue*/
    "95",/*light magneta*/
    "96",/*light cyan*/
    "97",/*light gray*/
};

MainWin::MainWin(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWin){
    ui->setupUi(this);
    /*initializing QComboBoxes*/
    for(int i = 0; i < seqCount+1; i++){
        ui->seqCB->addItem(sequencesText[i]);
    }
    for(int i = 0; i < colCount; i++){
        ui->colorCB->addItem(colorsText[i]);
    }
    for(int i = 0; i < colCount; i++){
        ui->defColCB->addItem(colorsText[i]);
    }
}

MainWin::~MainWin(){
    delete ui;
}


void MainWin::on_addSeqBtn_clicked(){
    /*getting QComboBoxes indexes*/
    int selColID = ui->colorCB->currentIndex();
    int selSeqID = ui->seqCB->currentIndex();


    /*adding text into seqTE(will be loaded to bash.bashrc)*/
    if(selSeqID != 0){
        ui->seqTE->setPlainText(ui->seqTE->toPlainText() + "\\[\\e[" + colors[selColID] + "m\\]" + "\\" + sequences[selSeqID-1] + "\\[\\e[0m\\]");
    }if(ui->lineEdit->text() != "" && ui->lineEdit->text() != new QString()){
        ui->seqTE->setPlainText(ui->seqTE->toPlainText() + "\\[\\e[" + colors[selColID] + "m\\]" + ui->lineEdit->text() + "\\[\\e[0m\\]");
    }


    /*resetting lineEdit and QComboBoxes*/
    ui->lineEdit->setText("");
    ui->colorCB->setCurrentIndex(0);
    ui->seqCB->setCurrentIndex(0);
}

void MainWin::on_seqCB_currentIndexChanged(int index){//clearing lineEdit
    int selSeqID = ui->seqCB->currentIndex();
    if(selSeqID != 0){
        ui->lineEdit->setText("");
    }
    ui->seqCB->setCurrentIndex(selSeqID);
}


void MainWin::on_lineEdit_textChanged(const QString &arg1){ui->seqCB->setCurrentIndex(0);}


void MainWin::on_clearBtn_clicked(){/*clearing all*/
    ui->seqTE->setPlainText("");
    ui->lineEdit->setText("");
    ui->colorCB->setCurrentIndex(0);
    ui->seqCB->setCurrentIndex(0);
    ui->defColCB->setCurrentIndex(0);
}

void MainWin::on_apply_clicked(){//write all changes
    string PS1 = ui->seqTE->toPlainText().toStdString() + "" + colors[ui->defColCB->currentIndex()].toStdString();
    try {
        string bashrcpath = "/home/" + USERNAME + "/.bashrc";//bashrc file

        ofstream fout(bashrcpath, ios::out); /*open file for writing*/
        fout << "PS1='" + PS1 + "'";
        fout << "\nsh ~/.config/bashcustomiser/startup.sh";

        /*closing file*/
        fout.close();
        ui->statusbar->showMessage("Successfully aplied");//OK
    }  catch (exception e) {
       ui->statusbar->showMessage(e.what());//error
    }
}

void MainWin::on_actionHelp_triggered(){//open help window
    help *h;
    h = new help();
    h->setWindowTitle("Bash customiser - Help");
    h->show();}


void MainWin::on_actionAbout_QT_triggered(){QMessageBox::aboutQt(this, "About QT framework");}//about QT



void MainWin::on_actionEdit_triggered(){//open startup.sh edit window
    startup *s;
    s = new startup();
    s->setWindowTitle("Bash customiser - '~/.config/bashcustomiser/startup.sh'");
    s->show();}

