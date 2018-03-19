//
// minebot_gui.cpp
//
// Created: 27 Feb 2017
// Author: Adam Plowcha
//


#include <popup.h>


namespace popup
{

PopupGUI::PopupGUI() :
    rqt_gui_cpp::Plugin(), widget_(0)
{
    setObjectName("PopupGUI");
}

PopupGUI::~PopupGUI()
{

}

void PopupGUI::initPlugin(qt_gui_cpp::PluginContext &context)
{
    std::string full_name_space = getNodeHandle().getNamespace();
    std::vector<std::string> components;
    boost::split(components, full_name_space, boost::is_any_of("/"));
    components.pop_back();
    std::string name_space = boost::algorithm::join(components, "/");

    /* Setup the widget */
    widget_ = new QWidget();
    ui_.setupUi(widget_);
    context.addWidget(widget_);



    // Status Reporting Boxes
    QObject::connect( this, SIGNAL(setStopGoText(const QString)),
                ui_.stop_go, SLOT(setText(const QString)));

    current_state_sub = getNodeHandle().subscribe("/current_state", 1000, &MineBotGUI::currentStateClbk, this);

}

void PopupGUI::shutdownPlugin()
{
    //Shutdown pubs and subs, etc
}

//All your remaining functions to go here...

void PopupGUI::onCloseButtonClicked()
{

}
}

//This is a required line for Qt and ROS to work together
PLUGINLIB_EXPORT_CLASS(popup_gui::PopupGUI, rqt_gui_cpp::Plugin)
