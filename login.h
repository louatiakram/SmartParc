#ifndef LOGIN_H
#define LOGIN_H
#include "mainwindow.h"
#include <QWidget>

namespace Ui
{
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pb_login_clicked();

private:
    Ui::login *ui;
    MainWindow *mainwindow;
};

#endif // LOGIN_H
