#include <para_menu.h>

#include <QApplication>
#include <QDebug>

/*
 * The class does not permite used in thread.
 * So not thread-safe.
 */

PMenu *PMenu::instance_=NULL;

PMenu::PMenu(QWidget *parent)
  :QMenu(parent)
  ,trayMenu_(NULL),trayQuictAction_(NULL)
{
}
PMenu::~PMenu()
{
  instance_=NULL;
  qDebug()<<"~PMenu";
}

PMenu* PMenu::instance()
{
  if(NULL==instance_)
  {
    instance_=new PMenu();
  }
  return instance_;
}

void PMenu::destroy()
{
  if(instance_)delete instance_;
  instance_=NULL;
}

QMenu* PMenu::trayMenu()
{
  if(NULL==trayMenu_)
  {
    trayMenu_=new PPMenu(this);
    //trayMenu_=new QMenu(this);
    trayQuictAction_=new QAction("Quit",trayMenu_);
    connect(trayQuictAction_,SIGNAL(triggered()),qApp,SLOT(quit()));
    trayMenu_->addAction(trayQuictAction_);
  }
  return trayMenu_;
}

