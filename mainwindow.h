#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_Compress_clicked();

    void on_Decompress_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel * explorer;
    QString selected_path;
};
#endif // MAINWINDOW_H
