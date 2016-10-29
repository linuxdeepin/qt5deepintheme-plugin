#include "qdeepintheme.h"
#include "qdeepinfiledialoghelper.h"
#include "qdeepinplatformmenu.h"
#include "qdeepinplatformmenuitem.h"

#include <dfmglobal.h>

#include <QVariant>
#include <QDebug>

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

QPixmap QDeepinTheme::standardPixmap(QPlatformTheme::StandardPixmap sp, const QSizeF &size) const
{
    switch (sp) {
    case ArrowRight:
        return QPixmap(":/images/arrow-light.png");
    default: break;
    }

    return QGenericUnixTheme::standardPixmap(sp, size);
}

QT_END_NAMESPACE
