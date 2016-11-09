#include "qdeepintheme.h"
#include "qdeepinfiledialoghelper.h"
#include "qdeepinplatformmenu.h"
#include "qdeepinplatformmenuitem.h"
#include "diconproxyengine.h"

#include <dfmglobal.h>

#include <QVariant>
#include <QDebug>

#include <XdgIcon>

QT_BEGIN_NAMESPACE

const char *QDeepinTheme::name = "deepin";
bool QDeepinTheme::m_usePlatformNativeDialog = true;
bool QDeepinTheme::m_usePlatformNativeMenu = true;

QDeepinTheme::QDeepinTheme()
{
    DFMGlobal::installTranslator();
}

//QPlatformMenuItem *QDeepinTheme::createPlatformMenuItem() const
//{
//    if (!m_usePlatformNativeMenu)
//        return 0;

//    return new QDeepinPlatformMenuItem;
//}

//QPlatformMenu *QDeepinTheme::createPlatformMenu() const
//{
//    if (!m_usePlatformNativeMenu)
//        return 0;

//    return new QDeepinPlatformMenu;
//}

bool QDeepinTheme::usePlatformNativeDialog(DialogType type) const
{
    if (type == FileDialog)
        return m_usePlatformNativeDialog;

    return QGenericUnixTheme::usePlatformNativeDialog(type);
}

QPlatformDialogHelper *QDeepinTheme::createPlatformDialogHelper(DialogType type) const
{
    if (type == FileDialog)
        return m_usePlatformNativeDialog ? new QDeepinFileDialogHelper() : Q_NULLPTR;

    return QGenericUnixTheme::createPlatformDialogHelper(type);
}

QIconEngine *QDeepinTheme::createIconEngine(const QString &iconName) const
{
    XdgIcon::setThemeName(QIcon::themeName());

    const QIcon &icon = XdgIcon::fromTheme(iconName);

    if (icon.availableSizes().isEmpty())
        return 0;

    return new DIconProxyEngine(icon);
}

QPixmap QDeepinTheme::standardPixmap(QPlatformTheme::StandardPixmap sp, const QSizeF &size) const
{
    switch (sp) {
    case ArrowRight:
        return QPixmap(":/images/arrow-light.png");
    default: break;
    }

    return QGenericUnixTheme::standardPixmap(sp, size);
}

//QVariant QDeepinTheme::themeHint(QPlatformTheme::ThemeHint hint) const
//{
//    switch (hint) {
//    case QPlatformTheme::StyleNames: {
//        QStringList styleNames;
//        // TODO(hualet): Make ddark&dlight styles ready!
//        // styleNames << QStringLiteral("dlight");
//        styleNames << QStringLiteral("GTK+") << QStringLiteral("fusion");
//        return QVariant(styleNames);
//    }
//    default:
//        break;
//    }

//    return QPlatformTheme::themeHint(hint);
//}

QT_END_NAMESPACE
