#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::LoginClass ui;
};
