#include "actionhandler.h"
#include <QDebug>

ActionHandler::ActionHandler(QObject *parent) : QObject(parent)
{
    m_boldFlag = false;
    m_italicFlag = false;
}

QString ActionHandler::statusMessage() const
{
    return m_statusMessage;
}

bool ActionHandler::bold() const
{
    return m_boldFlag;
}

bool ActionHandler::italic() const
{
    return m_italicFlag;
}

void ActionHandler::setStatusMessage(QString msg)
{
    m_statusMessage = msg;
    emit statusMessageChanged();
}

void ActionHandler::setBold(bool arg)
{
    m_boldFlag = arg;
    setStatusMessage("Bold selected");
    emit boldChanged();
}

void ActionHandler::setItalic(bool arg)
{
    m_italicFlag = arg;
    setStatusMessage("Italic selected");
    emit italicChanged();
    qDebug() << "Italic selected";
}

