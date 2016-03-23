#ifndef PARA_MENU_H
#define PARA_MENU_H

#include <QMenu>
#include <QDebug>

class PPMenu : public QMenu
{
  Q_OBJECT
public:
  PPMenu(QWidget *p=0):QMenu(p){}
  ~PPMenu(){qDebug()<<"~PPMenu";}
};

class PMenu : public QMenu
{
  Q_OBJECT
public:
  static PMenu* instance();
  static void destroy();
  QMenu* trayMenu();
private:
  PMenu(QWidget *parent=0);
  ~PMenu();
  static PMenu *instance_;

  //QMenu *trayMenu_;
  PPMenu *trayMenu_;
  QAction *trayQuictAction_;
};

#endif
