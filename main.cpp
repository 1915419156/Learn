/*** 
 * @Author: LK
 * @Date: 2024-04-04 14:52:28
 * @LastEditTime: 2024-04-09 10:26:33
 * @LastEditors: LK
 * @Description: 
 * @FilePath: /Learn/main.cpp
 */
#include "mainwindow.h"
#include <QApplication>

/**
 * @brief 主程序入口
 * @param argc 命令行参数个数
 * @param argv 命令行参数列表
 * @return 返回应用程序执行结果（通常为0表示正常退出）
 *
 * 本函数作为程序的主入口，负责初始化Qt应用环境、创建并显示主窗口（MainWindow），以及启动事件循环。
 */
int main(int argc, char *argv[])
{
    // 创建 QApplication 实例，管理整个Qt应用的生命周期
    QApplication app(argc, argv);
    // 实例化 MainWindow 对象
    MainWindow win;
    // 显示主窗口
    win.show();
    // 启动事件循环，处理用户输入、系统消息等，直到主窗口关闭或程序退出
    return app.exec();
}
