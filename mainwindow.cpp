/*** 
 * @Author: LK
 * @Date: 2024-04-09 09:52:45
 * @LastEditTime: 2024-04-09 10:21:39
 * @LastEditors: LK
 * @Description: 
 * @FilePath: /Learn/mainwindow.cpp
 */
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow的构造函数
 * @param parent 父QWidget，通常是nullptr
 * 主窗口的构造函数初始化了用户界面，设置了窗口标题，并添加了“打开”动作到文件菜单和工具栏。
 */
MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //在MainWindow 的构造函数中调用了setWindowTitle()，设置主窗口的标题,文本使用tr()函数，这是一个用于 Qt 国际化的函数
    // 设置主窗口标题
    setWindowTitle(tr("Main Window"));

    //在堆上创建了openAction对象,在QAction构造函数，我们传入了一个图标、一个文本和 this 指针
    // 创建并配置“打开”动作
    openAction = new QAction(QIcon(":/images/document-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    // 连接“打开”动作的触发信号到open()槽
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    // 在菜单栏添加“文件”菜单并加入“打开”动作
    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    // 在工具栏添加“打开”动作
    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    // 初始化状态栏
    statusBar() ;
}

/**
 * @brief MainWindow的析构函数
 * 主要作用是释放由new分配的内存。
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief “打开”动作的槽函数
 * 当“打开”动作被触发时，此函数会被调用，目前只是弹出一个信息框。
 */
void MainWindow::open()
{
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
