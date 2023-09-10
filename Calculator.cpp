#include "Calculator.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Checks to see if string is vaid binary number
bool MainWindow::isValidBinary(const QString &input){
    // Check if the input is empty
    if (input.isEmpty()){
        return false;
    }

    for (const QChar &ch : input){
        if (ch != '0' && ch != '1')
            return false;
    }

    return true;
}


// Checks to see if string is a valid decimal number
bool MainWindow::isValidDecimal(const QString &input){
    // Check if the input is empty
    if (input.isEmpty()){
        return false;
    }

    for (const QChar &ch : input) {
        // Check if the character is a digit
        if (!ch.isDigit())
            return false;
    }
    return true;
}


// Function to convert from base 10 to bases 2-16
QString MainWindow::decimalToBase(int number, int base) {    // Code derived from Eder Sayd - "Number conversion to any base, C++"
    // from YouTube https://www.youtube.com/watch?v=0a8kIrIzXac
    QString basesUsed = "0123456789ABCDEF";      // We also spoke of this same code and method in CS201 SI on 2/2/23 and 2/7/23
    QString result = "";

    while (number > 0) {
        result = basesUsed[number % base] + result;   // Modulo the decimal integer and add it to the result
        number /= base;                               // Divide the number by the base
    }
    return result;
}


// Clears input, result and original number input/output on radio button change
void MainWindow::on_binary_to_decimal_rbutton_clicked()
{
    ui->user_input->clear();
    ui->result->clear();
    ui->original_number->clear();
}


// Clears input, result and original number input/output on radio button change
void MainWindow::on_decimal_to_binary_rbutton_clicked()
{
    ui->user_input->clear();
    ui->result->clear();
    ui->original_number->clear();
}


// Function to calculate user input to or from base 2 and 10, outputs results based on radio buttons and check
void MainWindow::on_calculate_button_clicked()
{
    QString input = ui->user_input->text();
    int converted_num;
    bool ok;                                //Used from ChatGPT

    // decimal to binary radio button
    if (ui->decimal_to_binary_rbutton->isChecked()){
        if (isValidDecimal(input)){
           ui->result->setText("PASS");
            converted_num = input.toInt(&ok, 10);                // &ok used from ChatGPT
            if (ok){
                ui->result->setText(decimalToBase(converted_num, 2));
            }
            else{
            ui->result->setText("Input was not a valid decimal number");
            }
        }
    }

    // binary to decimal radio button
    if (ui->binary_to_decimal_rbutton->isChecked()){
        if (isValidBinary(input)){
            ui->result->setText("PASS");
            converted_num = input.toInt(&ok, 2);
            if (ok){
                ui->result->setText(decimalToBase(converted_num, 10));
            }
            else {
            ui->result->setText("Input was not a valid binary number");
            }
        }
    }

    // CheckBox on/off
    if(ui->checkBox->isChecked()){
        ui->original_number->setText("Original number : " + input);
    }
    else{
        ui->original_number->setText("");
    }
}

