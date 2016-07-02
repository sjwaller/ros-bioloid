#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qt5/QtWidgets/QMainWindow>
#include <qt5/QtWidgets/QWidget>
#include <qt5/QtWidgets/QDockWidget>
#include <qt5/QtWidgets/QMenu>
#include <qt5/QtWidgets/QAction>
#include "robotcontroller.h"
#include "motorcommandswidget.h"
#include "motorfeedbackwidget.h"
#include "fileiocontroller.h"
#include "rosworker.h"
#include "outputlog.h"
#include "motorvalueeditor.h"
#include "motoraddresseditor.h"
#include "motordials.h"
#include "moveithandler.h"
#include "sensorgrapher.h"
#include "pidbalancerwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char* argv[], QWidget* parent = 0);
    ~MainWindow();

signals:

public slots:
    void initRosNode();
    void initMoveItHandler();

    void nodeInitialised();
    void nodeTerminated();
    void nodeConnectedToRosMaster();
    void nodeDisconnectedFromRosMaster();

    void moveItHandlerInitialised();

    void aboutQt();
    void about();
    void quit();

private:
    void setUpLayout();
    void customiseLayout();
    void connectSignalsAndSlots();

    RobotController* robotController;
    MotorCommandsWidget* motorCommandsWidget;
    MotorFeedbackWidget* motorFeedbackWidget;
    FileIoController* fileIoController;
    RosWorker* rosWorker;
    MotorValueEditor* motorValueEditor;
    MotorAddressEditor* motorAddressEditor;
    MotorDials* motorDials;
    MoveItHandler* moveItHandler;
    OutputLog* outputLog;
    SensorGrapher* sensorGrapher;
    PidBalancerWidget* pidBalancerWidget;

    QAction* exitAct;
    QAction* aboutQtAct;
    QAction* aboutAct;

    QDockWidget* motorFeedbackDockWidget;
    QDockWidget* motorCommandsDockWidget;
    QDockWidget* poseControlDockWidget;
    QDockWidget* fileIoDockWidget;
    QDockWidget* outputLogDockWidget;
    QDockWidget* motorValueEditorDockWidget;
    QDockWidget* motorAddressEditorDockWidget;
    QDockWidget* motorDialsDockWidget;    
    QDockWidget* sensorGrapherDockWidget;
    QDockWidget* pidBalancerDockWidget;
};

#endif // MAINWINDOW_H
