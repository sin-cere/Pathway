#ifndef pathway_H
#define pathway_H

#include <QtNetwork>
#include <QMainWindow>
#include <QMouseEvent>
#include <QCloseEvent>
#include <QtXml>
#include <QDomDocument>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QToolButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include "innerchat.h"
#include "friendchat.h"
#include "friendoperator.h"
#include <QObject>

namespace Ui {
class pathway;
}

class InnerChat;

class pathway : public QMainWindow
{
    Q_OBJECT

public:
    explicit pathway(QWidget *parent = 0);
    ~pathway();

    InnerChat *innerchat;                   //保存innerchat类指针
    FriendChat *friendchat;                 //保存friendchat类指针
    FriendOperator *fo;                     //保存查看好友信息类指针

    QString iport;

    void XmlOperator(QString fileName);     //读取本地好友数据
    void friendEnter();                     //判断新用户是否是好友并操作
    void friendLeft();                      //好友离开操作

protected:
    //声明移动窗体事件
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    void changeEvent(QEvent *e);

    void closeEvent(QCloseEvent *);

private:
    Ui::pathway *ui;

    QToolButton *toolBtn;
    QGroupBox *groupBox;
    QVBoxLayout *layout;

    //移动窗体参数
    QPoint mLastMousePosition;
    bool mMoving;

    QUdpSocket *udpSocket;
    qint32 port;
    qint32 bb;

    //好友信息列表
    QList<QString> friendsList;

    //添加好友列表
    QList<QString> addFriendList;

    QString newUsername;
    QString newIpaddress;
    QString newLocalhostname;

private slots:
    void on_peopleTableWidget_doubleClicked(QModelIndex index);     //双击附近的人
    void on_closePushButton_clicked();                              //关闭
    void on_minPushButton_clicked();                                //最小化

    void friendInformation();                                       //好友信息

    void newparticipant();
    void participantleft();

    void on_innerPushButton_clicked();

    void getData(QString username,QString ipaddress,QString localhostname);

    void reloadXML();

    void refuced();

    //同意添加好友
    void addFriend(QString username,QString ipaddress,QString localhostname,QString fport);

    //被同意添加
    void friendAdded(QString ipadress,QString fport);

    //好友聊天
    void fChat(QString ip);

    //新建好友udp进行聊天
    void newUdpSocket(QString ip);

    //发送同意和好友专属端口号
    void sendAgree(QString ipadress);
signals:
    void closed();

};

#endif // pathway_H
