#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //在MainWindow 的构造函数中
    //调用了setWindowTitle()，设置主窗口的标题,文本使用tr()函数，这是一个用于 Qt 国际化的函数
    setWindowTitle(tr("Main Window"));
    //在堆上创建了openAction对象,在QAction构造函数，我们传入了一个图标、一个文本和 this 指针
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    statusBar() ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
