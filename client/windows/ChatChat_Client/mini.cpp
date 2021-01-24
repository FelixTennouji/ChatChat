#include "mini.h"
#include "ui_mini.h"

Mini::Mini(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mini)
{
    ui->setupUi(this);
}

Mini::~Mini()
{
    delete ui;
}

