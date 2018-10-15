#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#include <QObject>
#include <qqmlfile.h>

class ActionHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool bold READ bold WRITE setBold NOTIFY boldChanged)
    Q_PROPERTY(bool italic READ italic WRITE setItalic NOTIFY italicChanged)
    Q_PROPERTY(QString statusMessage READ statusMessage NOTIFY statusMessageChanged)
public:
    explicit ActionHandler(QObject *parent = nullptr);
    bool bold() const;
    bool italic() const;
    QString statusMessage() const;

signals:
    void boldChanged();
    void italicChanged();
    void statusMessageChanged();

public slots:
    void setBold(bool arg);
    void setItalic(bool arg);

private:

    void setStatusMessage(QString msg);
    bool m_boldFlag;
    bool m_italicFlag;
    QString m_statusMessage;
};

#endif // ACTIONHANDLER_H
