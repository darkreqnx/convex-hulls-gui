//!  Class for the GUI
/*!
  Class that holds all the GUI elements and slots/signals.
*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basic.h"
#include "graph.h"
#include "graham.h"
#include "jarvis.h"
#include <QPainter>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //! Listener function for setting Mode and running the corresponding algorithm
    /*!
    */
    void on_pushButton_2_clicked();

    //! Listener function for getting graph of the next iteration
    /*!
    */
    void on_pushButton_clicked();

    //! Util Function that provides current mouse click coordinates.
    /*!
    */
    void mouse_pos();

    //! Listener function for getting graph of the previous iteration
    /*!
    */
    void on_pushButton_3_clicked();

    //! Listener function for resetting the GUI and corresponding variables for fresh iteration.
    /*!
    */
    void on_pushButton_4_clicked();

    void reset();

private:
    Ui::MainWindow *ui;

    //! Util Functionf or painting current graph onto the QLabel in the GUI.
    /*!
    */
    void Paint();
};

#endif // MAINWINDOW_H
