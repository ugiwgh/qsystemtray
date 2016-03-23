#include <para_tray.h>

#include <qtsingleapplication.h>

#include <QObject>
#include <QString>
#include <QDebug>

int main(int argc,char **argv)
{
  QtSingleApplication app("MYProgram", argc, argv);
  QString message=QString("PID=")+QString::number(QCoreApplication::applicationPid());
  if(app.sendMessage(message))return 0;

  PTray *tray=PTray::instance();
  tray->show();
	
  app.exec();
  qDebug()<<"QApplication END";
  
  return 0;
}
