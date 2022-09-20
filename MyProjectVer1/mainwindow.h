#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "recipe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static bool logged_in;


private slots:
    void on_actionApplication_triggered();

    void on_actionAuthor_triggered();

    void on_actionWhite_Russian_triggered();

    void on_actionPrint_recipe_triggered();

    void on_actionLong_Island_Ice_Tea_triggered();

    void on_actionSex_on_the_beach_triggered();

    void on_actionSave_recipe_triggered();

    void on_actionJohn_Collins_triggered();

    void on_actionDry_Martini_triggered();

    void on_actionBlue_Gin_triggered();

    void on_actionCuba_Libre_triggered();

    void on_actionDaiquiri_triggered();

    void on_actionBarbados_Surprise_triggered();

    void on_actionWhiskey_Sour_triggered();

    void on_actionOld_Fashioned_triggered();

    void on_actionRevolver_triggered();

    void on_actionJagerbomb_triggered();

    void on_actionAperol_Spritz_triggered();

    void on_actionTequila_Sunrise_triggered();

    void on_actionFrog_triggered();

    void on_actionTropical_Refresher_triggered();

    void on_actionSoft_Curacao_triggered();

    void on_actionRainbow_Pineapple_triggered();

    void on_actionSoft_Mojito_triggered();

    void on_actionLogin_triggered();

    void on_actionCreate_own_recipe_triggered();

    void on_checkBox_stateChanged(int arg1);

    void on_favoritebox_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    Recipe *recipe_dialog;

};
extern bool logged_in;
#endif // MAINWINDOW_H
