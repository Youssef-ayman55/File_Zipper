#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cpp-code/compression.cpp"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1000,750);
    explorer = new QFileSystemModel(this);
    explorer->setRootPath("::{20D04FE0-3AEA-1069-A2D8-08002B30309D}");
    ui->treeView->setModel(explorer);
    ui->treeView->setColumnWidth(0, 500);
    selected_path = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->treeView->selectionModel()->selectedIndexes().size()){
        QModelIndex index = ui->treeView->selectionModel()->selectedIndexes()[0];
        selected_path = explorer->filePath(index);
        ui->selected->setText("Selected File: " + index.data().toString());
        ui->notify->setText("");
        ui->size->setText("");
    }
}


void MainWindow::on_Compress_clicked()
{
    if(selected_path == ""){
        ui->notify->setText("Error: Please Select a File");
        return;
    }
    QString temp = selected_path;
    if(temp.size() < 4){
    ui->notify->setText("Error: Please Select a '.txt' File");
        return;
    }
    std::reverse(temp.begin(), temp.end());
    if(temp[0] != 't' || temp[1] != 'x' || temp[2] != 't' || temp[3] != '.'){
        ui->notify->setText("Error: Please Select a '.txt' File");
        return;
    }
    ui->selected->setText("No File Selected");
    string size = compressFile(selected_path.toStdString());
    ui->notify->setText("Compression Succesful!");
    ui->size->setText(QString::fromStdString(size));
    selected_path = "";
}


void MainWindow::on_Decompress_clicked()
{
    if(selected_path == ""){
        ui->notify->setText("Error: Please Select a File");
        return;
    }
    QString temp = selected_path;
    if(temp.size() < 7){
        ui->notify->setText("Error: Please Select a '.hassan' File");
        return;
    }
    std::reverse(temp.begin(), temp.end());
    if(temp[0] != 'n' || temp[1] != 'a' || temp[2] != 's' || temp[3] != 's' || temp[4] != 'a' || temp[5] != 'h' || temp[6] != '.'){
        ui->notify->setText("Error: Please Select a '.hassan' File");
        return;
    }
    ui->selected->setText("No File Selected");
    string size = decompressFile(selected_path.toStdString());
    ui->notify->setText("Decompression Succesful!");
    ui->size->setText(QString::fromStdString(size));
    selected_path = "";
}

