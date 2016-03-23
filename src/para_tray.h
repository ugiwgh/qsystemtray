#ifndef PARA_TRAY_H
#define PARA_TRAY_H

#include <QSystemTrayIcon>
#include <QString>
#include <QDebug>

class PTray : public QSystemTrayIcon
{
  Q_OBJECT
public:
  static PTray* instance();
  static void destroy();
  void setTipMessage(QString &tip);
signals:
  void showPConsole();
public slots:
  void showRealTimeMessage(const QString &title,const QString &msg);
private slots:
  void trayHandle(QSystemTrayIcon::ActivationReason reason);
  void showMessageTotal();
private:
  PTray(QObject *parent=0);
  ~PTray();
  static PTray *instance_;
  QString tipMessage_;
};

#endif
