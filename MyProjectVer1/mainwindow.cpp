#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "ownrecipe.h"

#include <iostream>

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

    bool MainWindow::logged_in = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);
    ui->favoritebox->hide();
}

MainWindow::~MainWindow()
{

    delete ui;


}


void MainWindow::on_actionApplication_triggered()
{
    QString about_app_text;
    about_app_text = "Drink maker 2022\n";
    about_app_text += "App that helps bartenders and clients to choose, edit and prepare desired cocktails.\n";
    about_app_text += "Sources of recipes: \n";
    about_app_text += "http://koktajle-drinki.pl/ \n";
    about_app_text += "https://www.pieknowdomu.pl/ \n";
    QMessageBox::information(this, "About app", about_app_text);

}


void MainWindow::on_actionAuthor_triggered()
{
    QString about_author_text;
    about_author_text = "Author: Piotr Gubala \n";
    about_author_text += "Technologie Komputerowe 2 \n";
    about_author_text += "Projekt zaliczeniowy z ZJP \n";
    QMessageBox::information(this, "About author", about_author_text);
}

//VODKA BASED

void MainWindow::on_actionWhite_Russian_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("White Russian");
    QString white_russian_ingredients;
    QString white_russian_recipe;
    white_russian_ingredients = "INGREDIENTS: \n50ml of vodka \n20ml of coffee liquor \n50ml of cream \nCouple of ice cubes \n";
    white_russian_recipe = "RECIPE: \n";
    white_russian_recipe += "1. Put vodka, coffee liquor and ice cubes in a Old Fashioned type glass \n";
    white_russian_recipe += "2. Carefully pour cream on the side of the glass to make 2 layers \n";
    white_russian_recipe += "3. Stir before drinking \n";
    QFont font = ui->actionWhite_Russian->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("White Russian");
    ui->textEdit_ingredients->setText(white_russian_ingredients);
    ui->textEdit_recipe->setText(white_russian_recipe);
    QPixmap white_russian_img(":/resources/drinks_images/whiterussian.png");
    ui->label_img->setPixmap(white_russian_img.scaled(400,500,Qt::KeepAspectRatio));

}

void MainWindow::on_actionLong_Island_Ice_Tea_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Long Island Ice Tea");
    QString long_island_ingredients;
    QString long_island_recipe;
    long_island_ingredients = "INGREDIENTS: \n25ml of vodka \n25ml of gin \n25ml of white rum"
                              " \n25ml of tequila \n25ml of Cointreau liquor \n35ml of simple syrup \n"
                              "35ml of lime(or lemon) juice \n20ml of coke \nCouple of ice cubes";
    long_island_recipe = "RECIPE: \n";
    long_island_recipe += "1. Put ice cubes into the shaker \n";
    long_island_recipe += "2. Put all ingredients (beside coke) into the shaker and shake well \n";
    long_island_recipe += "3. Pour insides of the shaker to the glass, add coke and stir before drinking \n";
    QFont font = ui->actionLong_Island_Ice_Tea->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Long Island Ice Tea");
    ui->textEdit_ingredients->setText(long_island_ingredients);
    ui->textEdit_recipe->setText(long_island_recipe);
    QPixmap long_island_img(":/resources/drinks_images/longisland.png");
    ui->label_img->setPixmap(long_island_img.scaled(400,500,Qt::KeepAspectRatio));
}

void MainWindow::on_actionSex_on_the_beach_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Sex on the beach");
    QString sexbeach_ingredients;
    QString sexbeach_recipe;
    sexbeach_ingredients = "INGREDIENTS: \n80ml of vodka \n40ml of peach liquor"
                           "\n80ml of orange juice \n80ml of cranberry juice \nCouple of ice cubes ";
    sexbeach_recipe = "RECIPE: \n";
    sexbeach_recipe += "1. Put ice cubes into a high glass \n";
    sexbeach_recipe += "2. Add your cranberry juice \n";
    sexbeach_recipe += "3. Add OJ, vodka and peach liquor into the shaker \n";
    sexbeach_recipe += "4. Carefully add insides of shaker to the glass \n";
    sexbeach_recipe += "5. Stir before drinking (color will change) \n";
    QFont font = ui->actionSex_on_the_beach->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Sex on the beach");
    ui->textEdit_ingredients->setText(sexbeach_ingredients);
    ui->textEdit_recipe->setText(sexbeach_recipe);
    QPixmap sexbeach_img(":/resources/drinks_images/sexbeach.png");
    ui->label_img->setPixmap(sexbeach_img.scaled(400,500,Qt::KeepAspectRatio));

}

//GIN BASED

void MainWindow::on_actionJohn_Collins_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("John Collins");
    QString johncollins_ingredients;
    QString johncollins_recipe;
    johncollins_ingredients = "INGREDIENTS: \n45ml of gin \n30ml of lemon juice"
                           "\n15ml of simple syrup \n60ml of sparkling water \nCouple of ice cubes ";
    johncollins_recipe = "RECIPE: \n";
    johncollins_recipe += "1. Put ice cubes into a shaker \n";
    johncollins_recipe += "2. Add gin, simple syrup and lemon juice to the shaker \n";
    johncollins_recipe += "3. Shake and pour into Collins type glass \n";
    QFont font = ui->actionJohn_Collins->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("John Collins");
    ui->textEdit_ingredients->setText(johncollins_ingredients);
    ui->textEdit_recipe->setText(johncollins_recipe);
    QPixmap johncollins_img(":/resources/drinks_images/johncollins.png");
    ui->label_img->setPixmap(johncollins_img.scaled(400,500,Qt::KeepAspectRatio));
}

void MainWindow::on_actionDry_Martini_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Dry Martini");
    QString drymartini_ingredients;
    QString drymartini_recipe;
    drymartini_ingredients = "INGREDIENTS: \n60ml of gin \n10ml of Martini vermout"
                           "\n5ml of lemon juice \nCouple of ice cubes ";
    drymartini_recipe = "RECIPE: \n";
    drymartini_recipe += "1. Add all ingredients to shaker and shake \n";
    drymartini_recipe += "2. Pour insides of shaker to Marini glass \n";
    QFont font = ui->actionDry_Martini->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Dry Martini");
    ui->textEdit_ingredients->setText(drymartini_ingredients);
    ui->textEdit_recipe->setText(drymartini_recipe);
    QPixmap drymartini_img(":/resources/drinks_images/drymartini.png");
    ui->label_img->setPixmap(drymartini_img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionBlue_Gin_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Blue Gin");
    QString bluegin_ingredients;
    QString bluegin_recipe;
    bluegin_ingredients = "INGREDIENTS: \n50ml of gin \n25ml of Blue Curacao"
                           "\nSparkling water \nCouple of ice cubes ";
    bluegin_recipe = "RECIPE: \n";
    bluegin_recipe += "1. Put gin and BC into a short glass over ice \n";
    bluegin_recipe += "2. Finish up with sparkling water \n";
    QFont font = ui->actionBlue_Gin->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Blue Gin");
    ui->textEdit_ingredients->setText(bluegin_ingredients);
    ui->textEdit_recipe->setText(bluegin_recipe);
    QPixmap bluegin_img(":/resources/drinks_images/bluegin.png");
    ui->label_img->setPixmap(bluegin_img.scaled(400,500,Qt::KeepAspectRatio));
}

//RUM BASED

void MainWindow::on_actionCuba_Libre_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Cuba Libre");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n50ml of gin \n120ml of coke \n10ml of lime juice \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Add everything to an Old Fashioned glass and stir  \n";
    QFont font = ui->actionCuba_Libre->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Cuba Libre");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/cubalibre.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionDaiquiri_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Daiquiri");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n45ml of white rum \n25ml of lime juice"
                           "\n15ml of simple syrup \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Add ice cubes to shaker \n";
    recipe += "2. Add all liquids to the shaker \n";
    recipe += "3. Pour insides of the shaker to cocktail glass \n";
    QFont font = ui->actionDaiquiri->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Daiquiri");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/daiquiri.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionBarbados_Surprise_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Barbados Surprise");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n40ml of rum \n40ml of coconut rum"
                           "\n80ml of orange juice \n80ml of pineapple juice"
                  "\n15ml of strawberry syrup \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Add everything to a shaker\n";
    recipe += "2. Pour everything into hurricane type glass \n";
    QFont font = ui->actionBarbados_Surprise->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Barbados Surprise");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/barbadossurprise.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}

//WHISKEY BASED

void MainWindow::on_actionOld_Fashioned_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Old Fashioned");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n45ml of whisky \n1 cube of sugar"
                           "\nAngostura Bitters 2-3 drops \nA little bit of water \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. To a short glass add sugar, water and angostura bitters. Muddle it. \n";
    recipe += "2. Add whisky and 2-3 ice cubes. \n";
    QFont font = ui->actionOld_Fashioned->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Old Fashioned");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/oldfashioned.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}



void MainWindow::on_actionWhiskey_Sour_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Whiskey Sour");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n40ml of whisky \n15ml of lemon or lime juice"
                           "\n15ml of simple syrup";
    recipe = "RECIPE: \n";
    recipe += "1. Put all the ingredients into a glass and stir. \n";
    QFont font = ui->actionWhiskey_Sour->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Whiskey Sour");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/whiskeysour.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}



void MainWindow::on_actionRevolver_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Revolver");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n60ml of whisky \n15ml of coffee liquor"
                           "\nCouple drops of Angostura Bitters \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Put all ingredients into a shaker and shake hard. \n";
    recipe += "2. Pour the insides of the shaker to a cocktail glass. \n";
    QFont font = ui->actionRevolver->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Revolver");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/revolver.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}

//OTHER

void MainWindow::on_actionJagerbomb_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Jagerbomb");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n50ml of Jagermeister \n150ml of energy drink (preferably Red Bull)"
                           "\nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Put all ingredients into a glass  \n";
    QFont font = ui->actionJagerbomb->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Jagerbomb");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/jagerbomb.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionAperol_Spritz_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Aperol Spritz");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n90ml of Prosecco \n60ml of Aperol"
                           "\n30ml of sparkling water \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Put all ingredients into a shaker and shake hard. \n";
    recipe += "2. Pour the insides of the shaker to a cocktail glass. \n";
    QFont font = ui->actionAperol_Spritz->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Aperol Spritz");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/aperolspritz.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionTequila_Sunrise_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Tequila Sunrise");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n60ml of tequila \n120ml of orange juice"
                           "\n20ml of grenadine \nCouple of ice cubes ";
    recipe = "RECIPE: \n";
    recipe += "1. Put orange juice and tequila into a glass, over ice cubes. \n";
    recipe += "2. Slowly pour in grenadine, for it to fall to the bottom of the drink. \n";
    QFont font = ui->actionTequila_Sunrise->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Tequila Sunrise");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/tequilasunrise.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}

//NON-ALCOHOLIC

void MainWindow::on_actionFrog_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Frog ");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n80ml of grapefruit juice \n60ml of pineapple juice"
                           "\n40ml of alcohol-free Blue Curacao \n Coconut shrims for decor ";
    recipe = "RECIPE: \n";
    recipe += "1. Put all liquids into a shaker and shake.. \n";
    recipe += "2. Pour water over the top of your glass of choice. \n";
    recipe += "3. Put coconut shrims on top of your glass for decor and pour insides of the shaker into it.";
    QFont font = ui->actionFrog->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Frog");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/frog.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionTropical_Refresher_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Tropical Refresher");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n30ml of grapefruit juice \n40ml of pineapple juice"
                           "\n30ml of yogurt \n1,5 tablespoon of cane sugar \nCrushed ice";
    recipe = "RECIPE: \n";
    recipe += "1. Put all liquids into a shaker and shake, next pour it into a 'long drink' type glass. \n";
    QFont font = ui->actionTropical_Refresher->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Tropical Refresher");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/tropicalrefresher.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionSoft_Curacao_triggered()
{
    setWindowTitle("Soft Curacao");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n100ml of tonic \n30ml of lemon juice"
                           "\n50ml of alcohol-free Blue Curacao";
    recipe = "RECIPE: \n";
    recipe += "1. Put all the ingredients into a shaker and shake, next pour it into a glass. \n";
    QFont font = ui->actionSoft_Curacao->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Soft Curacao");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/softcuracao.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionRainbow_Pineapple_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Rainbow Pineapple");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n100ml of orange juice \n100ml of pineapple juice"
                           "\n10ml of grenadine \nCouple of ice cubes";
    recipe = "RECIPE: \n";
    recipe += "1. Add ice, and juices into a shaker and shake firmly.\n";
    recipe += "2. Pour the insides of the shaker into a long glass. \n";
    recipe += "3. Carefully add grenadine to the glass to make a layer of it at the bottom.";
    QFont font = ui->actionRainbow_Pineapple->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Rainbow Pineapple");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/rainbowpineapple.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}


void MainWindow::on_actionSoft_Mojito_triggered()
{
    ui->favoritebox->show();
    setWindowTitle("Soft Mojito");
    QString ingredients;
    QString recipe;
    ingredients = "INGREDIENTS: \n2 quarters of a lime \n6 leaves of mint"
                           "\n1 tablespoon of cane sugar \nSprite \nSparkling water \nCouple of ice cubes";
    recipe = "RECIPE: \n";
    recipe += "1. Add mint, limes, sugar and ice to a short glass. \n";
    recipe += "2. Mix 2 parts of sprite with 1 part of sparkling water and add it to the glass. \n";
    QFont font = ui->actionSoft_Mojito->font();
    font.setPointSize(16);
    ui->label_title->setFont(font);
    ui->label_title->setText("Soft Mojito");
    ui->textEdit_ingredients->setText(ingredients);
    ui->textEdit_recipe->setText(recipe);
    QPixmap img(":/resources/drinks_images/softmojito.png");
    ui->label_img->setPixmap(img.scaled(400,500,Qt::KeepAspectRatio));
}

//OPTIONS

void MainWindow::on_actionPrint_recipe_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Basic_printer_name");
    QPrintDialog print_dialog(&printer, this);
    if(print_dialog.exec() == QDialog::Rejected) return;
    QString text1 = ui->textEdit_ingredients->toPlainText();
    QString text2 = ui->textEdit_recipe->toPlainText();
    QString printed_text = text1 + "\n\n" + text2;
    ui->textEdit_ingredients->setPlainText(printed_text);
    ui->textEdit_ingredients ->print(&printer);
    ui->textEdit_ingredients->setPlainText(text1);
}


void MainWindow::on_actionSave_recipe_triggered()
{
    QString filter = "Text file (*.txt)";
    QString file_name = QFileDialog::getSaveFileName(this, "Save file", "C://", filter);
    //QFile save_file("C:/Users/pietr/Desktop/Programiiki/QTMordo/MyProjectVer1/myfile.txt",);
    QFile save_file(file_name);
    if(!save_file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "ERROR", "File could not be opened");
    }
    QTextStream out(&save_file);
    QString text = ui->textEdit_ingredients->toPlainText();
    QString text2 = ui->textEdit_recipe->toPlainText();
    out << text <<"\n \n" <<text2;
    save_file.flush();
    save_file.close();
}

void MainWindow::on_actionLogin_triggered()
{

    loginwindow login;
    login.setModal(true);
    login.exec();

}


void MainWindow::on_actionCreate_own_recipe_triggered()
{
    ownrecipe add;
    add.setModal(true);
    add.exec();
}


void MainWindow::on_favoritebox_stateChanged(int arg1)
{
    if(arg1){
        QMessageBox::information(this, "Added", "Cocktail was successfully added to your favorites!");
    }
    else{
        QMessageBox::information(this, "Removed", "Cocktail was successfully removed from your favorites!");
    }
}
