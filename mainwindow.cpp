#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>

#include <mlk/log/log.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_pbBrowse_clicked()
{
    ui->lePath->setText(QFileDialog::getOpenFileName(this, "Open Map", "", "Map file (*.map)"));
	
	if(mMapParser.open(ui->lePath->text().toStdString())) {
		ui->lbStatusMsg->setText("Valid mapheader, ready to fix");
		ui->pbFixMap->setEnabled(true);
	} else {
		ui->lbStatusMsg->setText("Invlid mapheader, can not fix");
		ui->pbFixMap->setEnabled(false);
	}
}

void MainWindow::on_pbFixMap_clicked()
{
    if(mMapParser.save()) ui->lbStatusMsg->setText("MAP FIXED!");
	else ui->lbStatusMsg->setText("Could not fix map");
}
