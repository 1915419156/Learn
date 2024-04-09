/*** 
 * @Author: LK
 * @Date: 2024-04-04 17:02:41
 * @LastEditTime: 2024-04-09 10:32:12
 * @LastEditors: LK
 * @Description: 
 * @FilePath: /Learn/mainwindow.h
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief 主窗口类
 *
 * MainWindow 类继承自 QMainWindow，实现了一个基本的图形用户界面主窗口。它包含了与用户界面交互的私有成员函数 `open()` 和私有数据成员 `openAction`。
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief 构造函数
     * @param parent 父级 QWidget，可选，默认为 nullptr
     * 构造一个 MainWindow 实例，初始化其内部成员，并可能与指定的父级组件关联。
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief 析构函数
     * 负责清理 MainWindow 对象所占用的资源，包括释放 UI 数据结构。
     */
    ~MainWindow();

private:
    /**
     * @brief 用户界面数据结构指针
     * 包含由 Qt 设计器生成的用户界面布局及相关控件。
     */
    Ui::MainWindow *ui;


    /**
     * @brief 私有函数：执行“打开”操作，在MainWindow类中，添加私有函数open()
     * 此函数定义了“打开”相关功能的具体逻辑，但具体实现未在此头文件中给出。
     */
    void open();

    /**
     * @brief 私有数据成员：“打开”动作对象指针，添加私有变量openAction
     * 存储一个指向 QAction 对象的指针，该对象代表一个可触发“打开”操作的动作（如菜单项、工具栏按钮等）。
     */
    QAction *openAction;

};
#endif // MAINWINDOW_H
