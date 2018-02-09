//
// minebot_gui.h
//
// Created: 27 Feb 2017
// Author: Adam Plowcha

#ifndef __ROS_GUI_TEMPLATE_H__
#define __ROS_GUI_TEMPLATE_H__

#include <fstream>
#include <ros/ros.h>
#include <ros/master.h>
#include <pluginlib/class_list_macros.h>
#include <QStringList>
#include <ros/node_handle.h>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/join.hpp>
#include <rqt_gui_cpp/plugin.h>
#include <ui_minebot_gui.h>
#include <QWidget>
#include <QPainter>
#include <std_msgs/String.h>
#include <cmath>

namespace minebot_gui {
//constants can go here if needed

class MineBotGUI : public rqt_gui_cpp::Plugin
{
    Q_OBJECT
public:
    MineBotGUI();
    virtual ~MineBotGUI();
    virtual void initPlugin(qt_gui_cpp::PluginContext &context);
    virtual void shutdownPlugin();

Q_SIGNALS:

private Q_SLOTS:
//This is where you name the
//functions that handle UI
//things like button presses, etc.

//Example - this is "connected" in the initPlugin function:
//void onBtnNorthClicked();


private:
    Ui::MineBotGUIWidget ui_;
    QWidget *widget_;


    // ROS Stuff
	// Add any other ROS related items here if needed
	// This is also where you can put your own function definitions
	// and variables

    //Background map for drawing on
    QPixmap mapBGPixmap;
   
   
};
}

#endif /* __ROS_GUI_TEMPLATE_H__ */
