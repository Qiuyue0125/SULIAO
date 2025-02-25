#include "dialog.h"
#include "ui_dialog.h"
#include "autocleartextedit.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //初始化窗口
    QIcon icon(":/pictures/suliao.png");//初始化窗口
    setWindowIcon(icon);
    setWindowFlags( Qt::FramelessWindowHint | Qt::Dialog);
    setAttribute(Qt::WA_TranslucentBackground);//允许背景透明
    //设置文本框
    setEdit();
    // 将窗口居中显示
    QWidget *topLevelParent = parent ? parent->window() : nullptr;
    if (topLevelParent) {
        int x = topLevelParent->x() + (topLevelParent->width() - width()) / 2;
        int y = topLevelParent->y() + (topLevelParent->height() - height()) / 2;
        move(x, y);
    }
}


Dialog::~Dialog()
{
    delete ui;
}


void Dialog::setEdit()//设置文本框
{
    ui->textEdit_notice->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用垂直滚动条
    ui->textEdit_notice->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//禁用水平滚动条
    ui->textEdit_notice->setReadOnly(true);//设置为只读
    ui->textEdit_notice->setAlignment(Qt::AlignCenter);
}


void Dialog::paintEvent(QPaintEvent *event)//窗口背景
{
    //调用基类方法以处理父类的绘图
    QDialog::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//反锯齿
    //设置圆角半径
    int radius = 4;//圆角半径
    //设置背景颜色
    painter.setBrush(QBrush(QColor(255, 255, 255)));
    //绘制圆角矩形背景
    painter.drawRoundedRect(rect(), radius, radius);
}


void Dialog::transText(QString text)//改变文字
{
    //设置 textEdit_notice 的文本
    ui->textEdit_notice->setText(text);
    ui->textEdit_notice->setAlignment(Qt::AlignCenter);
}


void Dialog::on_but_delete_clicked()//点击确定关闭窗口
{
    this->close();
}

