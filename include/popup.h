//
// minebot_gui.h
//
// Created: 27 Feb 2017
// Author: Adam Plowcha

#ifndef __ROS_GUI_TEMPLATE2_H__
#define __ROS_GUI_TEMPLATE2_H__

#include <fstream>
#include <ros/ros.h>
#include <ros/master.h>
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <ros/node_handle.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <rqt_gui_cpp/plugin.h>
//#include <ui_minebot_gui.h>
#include <QWidget>
#include <QPainter>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Int16.h>
#include <cmath>
#include <QString>
#include <QDebug>
#include <QMessageBox>

namespace popup_gui {
//constants can go here if needed

class PopupGUI : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    PopupGUI();
    virtual ~PopupGUI();
    virtual void initPlugin(qt_gui_cpp::PluginContext &context);
    virtual void shutdownPlugin();

Q_SIGNALS:

    void setStopGoText(const QString str);


private Q_SLOTS:
//This is where you name the
//functions that handle UI
//things like button presses, etc.

//Example - this is "connected" in the initPlugin function:
    void onCloseButtonClicked();

private:
    Ui::PopupGUIWidget ui_pop_;
    QWidget *widget_;


    // ROS Stuff
	// Add any other ROS related items here if needed
	// This is also where you can put your own function definitions
	// and variables

    //Background map for drawing on
    QPixmap mapBGPixmap;

//    ros::NodeHandle ros_node_handle;
    ros::Subscriber current_state_sub;

};
}

#endif /* __ROS_GUI_TEMPLATE2_H__ */
