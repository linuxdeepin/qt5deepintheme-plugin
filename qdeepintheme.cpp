#include "qdeepintheme.h"
#include "qdeepinfiledialoghelper.h"

#include <QVariant>

QT_BEGIN_NAMESPACE

const char *QDeepinTheme::name = "deepin";
bool QDeepinTheme::m_usePlatformNativeDialog = true;

QDeepinTheme::QDeepinTheme()
{

}

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

QT_END_NAMESPACE
