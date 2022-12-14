#ifndef RECIPE_H
#define RECIPE_H

#include <QDialog>

namespace Ui {
class Recipe;
}

class Recipe : public QDialog
{
    Q_OBJECT

public:
    explicit Recipe(QWidget *parent = nullptr);
    ~Recipe();

private slots:
    void on_drinkname_linkActivated(const QString &link);

private:
    Ui::Recipe *ui;
};

#endif // RECIPE_H
