#ifndef QDEEPINTHEME_H
#define QDEEPINTHEME_H

#include <private/qgenericunixthemes_p.h>
#include <qpa/qplatformwindow.h>
#include <qpa/qplatformnativeinterface.h>

class QDeepinTheme : public QGenericUnixTheme
{
public:
    QDeepinTheme();

    bool usePlatformNativeDialog(DialogType type) const Q_DECL_OVERRIDE;
    QPlatformDialogHelper *createPlatformDialogHelper(DialogType type) const Q_DECL_OVERRIDE;

    static const char *name;

private:
    static bool m_usePlatformNativeDialog;

    friend class QDeepinFileDialogHelper;
};

#endif // QDEEPINTHEME_H
