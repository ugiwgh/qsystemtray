#include <para_tray.h>
#include <para_menu.h>

#include <QCoreApplication>
#include <QDateTime>
#include <QMessageBox>

/*
 * The class does not permite used in thread.
 * Needn't used in thread. So not thread-safe.
 */

PTray *PTray::instance_=NULL;

PTray::PTray(QObject *parent)
  :QSystemTrayIcon(parent)
  ,tipMessage_("ParamonYun")
{
  setIcon(QIcon(":/paramon-logo.png"));
  setToolTip(tipMessage_);
}

PTray::~PTray()
{
  qDebug()<<"~PTray";
}

PTray* PTray::instance()
{
  if(NULL==instance_)
  {
    QCoreApplication *app=QCoreApplication::instance();
    if(NULL==app)return NULL;
    instance_=new PTray(app);
    if(NULL==instance_)return NULL;
    connect(instance_,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),instance_,SLOT(trayHandle(QSystemTrayIcon::ActivationReason)));
    connect(instance_,SIGNAL(messageClicked()),instance_,SLOT(showMessageTotal()));

    PMenu *menu=PMenu::instance();
    if(menu)
    {
      instance_->setContextMenu(menu->trayMenu());
    }
  }
  return instance_;
}

void PTray::destroy()
{
  if(instance_) delete instance_;
  instance_=NULL;
}

void PTray::setTipMessage(QString &tip)
{
  tipMessage_=tip;
  setToolTip(tipMessage_);
}

void PTray::showRealTimeMessage(const QString &title,const QString &msg)
{
  showMessage(title,msg,QSystemTrayIcon::NoIcon,10000);
}

void PTray::trayHandle(QSystemTrayIcon::ActivationReason reason)
{
  switch(reason)
  {
    case QSystemTrayIcon::Context:
      break;
    case QSystemTrayIcon::Trigger:
      emit showPConsole();
      break;
    case QSystemTrayIcon::DoubleClick:
    case QSystemTrayIcon::MiddleClick:
    default:
      break;
  }
}

void PTray::showMessageTotal()
{
}
