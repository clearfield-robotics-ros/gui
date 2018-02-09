//
// minebot_gui.cpp
//
// Created: 27 Feb 2017
// Author: Adam Plowcha
//


#include <minebot_gui.h>


namespace minebot_gui
{

MineBotGUI::MineBotGUI() :
    rqt_gui_cpp::Plugin(), widget_(0)
{
    setObjectName("MineBotGUI");
}

MineBotGUI::~MineBotGUI()
{

}

void MineBotGUI::initPlugin(qt_gui_cpp::PluginContext &context)
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

    //Expanded GUI initializations...
    //Add some pics to our labels
    ui_.lblMap->setPixmap(QPixmap(":/cage.png"));
    mapBGPixmap = QPixmap(":/cage.png");
    

	//Example connection of signal to a slot for ht Qt UI	
    //connect(ui_.btnNorth, SIGNAL(clicked()), this, SLOT(onBtnNorthClicked()));

    talker_sub = getNodeHandle().subscribe("talker", 1, &MineBotGUI::talkerClbk, this);
}

void MineBotGUI::shutdownPlugin()
{
    //Shutdown pubs and subs, etc
}

//All your remaining functions to go here...

void MineBotGUI::talkerClbk(const std_msgs::String &msg)
{
    // msg->data.c_str();
}

}

//This is a required line for Qt and ROS to work together
PLUGINLIB_EXPORT_CLASS(minebot_gui::MineBotGUI, rqt_gui_cpp::Plugin)
