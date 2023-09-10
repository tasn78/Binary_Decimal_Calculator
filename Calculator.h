#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_binary_to_decimal_rbutton_clicked();

    void on_decimal_to_binary_rbutton_clicked();

    void on_calculate_button_clicked();

private:
    Ui::MainWindow *ui;

    bool isValidBinary(const QString &input);
    bool isValidDecimal(const QString &input);
    QString decimalToBase(int number, int base);
    };
#endif // MAINWINDOW_H
