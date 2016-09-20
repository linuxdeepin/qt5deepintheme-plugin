#include "qdeepinplatformmenuitem.h"
#include "qdeepinplatformmenu.h"

#include <QAction>
#include <QMenu>
#include <QDebug>

QDeepinPlatformMenuItem::QDeepinPlatformMenuItem()
    : QPlatformMenuItem()
{

}

void QDeepinPlatformMenuItem::setTag(quintptr tag)
{
    if (action)
        action->deleteLater();

    action = reinterpret_cast<QAction*>(tag);
}

quintptr QDeepinPlatformMenuItem::tag() const
{
    return quintptr(action);
}

void QDeepinPlatformMenuItem::setText(const QString &text)
{
    action->setText(text);
}

void QDeepinPlatformMenuItem::setIcon(const QIcon &icon)
{
    action->setIcon(icon);
}

void QDeepinPlatformMenuItem::setMenu(QPlatformMenu *menu)
{
    QDeepinPlatformMenu *dmenu = qobject_cast<QDeepinPlatformMenu*>(menu);

    if (dmenu)
        action->setMenu(dmenu->menu);
}

void QDeepinPlatformMenuItem::setVisible(bool isVisible)
{
    action->setVisible(isVisible);
}

void QDeepinPlatformMenuItem::setIsSeparator(bool isSeparator)
{
    action->setSeparator(isSeparator);
}

void QDeepinPlatformMenuItem::setFont(const QFont &font)
{
    action->setFont(font);
}

void QDeepinPlatformMenuItem::setRole(QPlatformMenuItem::MenuRole role)
{
    QAction::MenuRole menu_role = QAction::NoRole;

    switch (role) {
    case QPlatformMenuItem::TextHeuristicRole:
        menu_role = QAction::TextHeuristicRole;
        break;
    case QPlatformMenuItem::ApplicationSpecificRole:
        menu_role = QAction::ApplicationSpecificRole;
        break;
    case QPlatformMenuItem::AboutQtRole:
        menu_role = QAction::AboutQtRole;
        break;
    case QPlatformMenuItem::AboutRole:
        menu_role = QAction::AboutRole;
        break;
    case QPlatformMenuItem::PreferencesRole:
        menu_role = QAction::PreferencesRole;
        break;
    case QPlatformMenuItem::QuitRole:
        menu_role = QAction::QuitRole;
        break;
    default:
        break;
    }

    action->setMenuRole(menu_role);
}

void QDeepinPlatformMenuItem::setCheckable(bool checkable)
{
    action->setCheckable(checkable);
}

void QDeepinPlatformMenuItem::setChecked(bool isChecked)
{
    action->setChecked(isChecked);
}

void QDeepinPlatformMenuItem::setShortcut(const QKeySequence &shortcut)
{
    action->setShortcut(shortcut);
}

void QDeepinPlatformMenuItem::setEnabled(bool enabled)
{
    action->setEnabled(enabled);
}

void QDeepinPlatformMenuItem::setIconSize(int size)
{
    Q_UNUSED(size)
}
