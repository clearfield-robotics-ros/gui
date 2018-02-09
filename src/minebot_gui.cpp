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
//    ui_.lblMap->setPixmap(QPixmap(":/cage.png"));
//    mapBGPixmap = QPixmap(":/cage.png");
    

	//Example connection of signal to a slot for ht Qt UI	
//    connect(ui_.btnNorth, SIGNAL(clicked()), this, SLOT(onBtnNorthClicked()));
    QObject::connect( this, SIGNAL(setText(const QString)),
                ui_.label, SLOT(setText(const QString))   );

    talker_sub = getNodeHandle().subscribe("/chatter", 1000, &MineBotGUI::talkerClbk, this);
//    talker_sub = ros_node_handle.subscribe("chatter", 1000, &MineBotGUI::talkerClbk, this);
    // http://doc.qt.io/qt-5/qobject.html#connect
    // http://wiki.ros.org/rqt/Tutorials/Writing%20a%20C++%20Plugin
    // https://answers.ros.org/question/226493/example-rqt-plugin-in-c-that-uses-signalsslots/
}

void MineBotGUI::shutdownPlugin()
{
    //Shutdown pubs and subs, etc
}

//All your remaining functions to go here...

void MineBotGUI::talkerClbk(const std_msgs::String &msg)
{
    ROS_INFO("here");
    QString str(QString::fromStdString(msg.data)); // converts incoming message to QString type
    emit setText(str); // emit signal
}

}

//This is a required line for Qt and ROS to work together
PLUGINLIB_EXPORT_CLASS(minebot_gui::MineBotGUI, rqt_gui_cpp::Plugin)
