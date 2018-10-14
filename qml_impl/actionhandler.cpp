#include "actionhandler.h"

ActionHandler::ActionHandler(QObject *parent) : QObject(parent)
{
    m_boldFlag = false;
    m_italicFlag = false;
}

bool ActionHandler::bold() const
{
    return m_boldFlag;
}

bool ActionHandler::italic() const
{
    return m_italicFlag;
}

void ActionHandler::setBold(bool arg)
{
    m_boldFlag = arg;
    emit boldChanged();
}

void ActionHandler::setItalic(bool arg)
{
    m_italicFlag = arg;
    emit italicChanged();
}

