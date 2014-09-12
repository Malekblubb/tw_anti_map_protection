#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "map_parser.hpp"

#include <QMainWindow>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	MapParser mMapParser;
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();
	
private slots:
	void on_pbBrowse_clicked();
	
	void on_pbFixMap_clicked();
	
private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
