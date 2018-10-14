#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#include <QObject>
#include <qqmlfile.h>

class ActionHandler : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool bold READ bold WRITE setBold NOTIFY boldChanged)
    Q_PROPERTY(bool italic READ italic WRITE setItalic NOTIFY italicChanged)
public:
    explicit ActionHandler(QObject *parent = nullptr);
    bool bold() const;
    bool italic() const;

signals:
    void boldChanged();
    void italicChanged();

public slots:
    void setBold(bool arg);
    void setItalic(bool arg);

private:
    bool m_boldFlag;
    bool m_italicFlag;
};

#endif // ACTIONHANDLER_H
