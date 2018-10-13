#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#include <QObject>

class ActionHandler : public QObject
{
    Q_OBJECT
public:
    explicit ActionHandler(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ACTIONHANDLER_H