#include "ownrecipe.h"
#include "ui_ownrecipe.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>
#include <QPixmap>
#include <QDir>

ownrecipe::ownrecipe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ownrecipe)
{
    ui->setupUi(this);
}

ownrecipe::~ownrecipe()
{
    delete ui;
}

void ownrecipe::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.gif)"));

    if (QString::compare(filename, QString()) != 0){ //sprawdzam czy uzytkownik cos wybral, jak rozne od zera to dzialamy
        QImage image; //zawiera image
        bool success = image.load(filename); //sprawdzam czy loading dziala, jesli tak to dzialamy ofc
        if(success){
            image = image.scaledToWidth(ui->user_image->width(), Qt::SmoothTransformation); //skalowanie obrazu
            image =  image.scaledToHeight(ui->user_image->height(), Qt::SmoothTransformation);
            ui->user_image->setPixmap(QPixmap::fromImage(image));
        }
        else{
            QMessageBox::warning(this, "Error", "An error has occured, please try again");
        }
    }
}


void ownrecipe::on_pushButton_2_clicked()
{
    QString filter = "Text file (*.txt)";
    QString file_name = QFileDialog::getSaveFileName(this, "Save file", "C://", filter);
    QFile save_file(file_name);
    if(!save_file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "File could not be opened");
    }
    QTextStream out(&save_file);
    QString name = ui->textEdit_name->toPlainText();
    QString text = ui->textEdit_ingredients->toPlainText();
    QString text2 = ui->textEdit_recipe->toPlainText();
    out << "My own recipe for "<< name << "\n\n" << "Ingredients: \n" << text <<"\n \n" << "Recipe: \n"<<text2;
    save_file.flush();
    save_file.close();
    close();
}

