#ifndef OWNRECIPE_H
#define OWNRECIPE_H

#include <QDialog>

namespace Ui {
class ownrecipe;
}

class ownrecipe : public QDialog
{
    Q_OBJECT

public:
    explicit ownrecipe(QWidget *parent = nullptr);
    ~ownrecipe();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ownrecipe *ui;
};

#endif // OWNRECIPE_H
