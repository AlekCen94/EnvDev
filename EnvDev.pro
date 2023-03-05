QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EnvFramework/tinyxml/tinystr.cpp \
    EnvFramework/tinyxml/tinyxml.cpp \
    EnvFramework/tinyxml/tinyxmlerror.cpp \
    EnvFramework/tinyxml/tinyxmlparser.cpp \
    abstractenvobject.cpp \
    dockercommand.cpp \
    dockercomposebuilder.cpp \
    dockerimagebuilder.cpp \
    envbuilder.cpp \
    envcommand.cpp \
    envconnect.cpp \
    envcontainer.cpp \
    envcontainerparametarswig.cpp \
    envcontainerprop.cpp \
    envcontainersearch.cpp \
    envfactory.cpp \
    envitem.cpp \
    envpropertiesterminalwig.cpp \
    envscene.cpp \
    envsearchitem.cpp \
    envtoolwg.cpp \
    gitcommand.cpp \
    main.cpp \
    envdev.cpp \
    maptable.cpp \
    shellbuilder.cpp \
    vagrantcommand.cpp \
    vagrantfilebuilder.cpp

HEADERS += \
    EnvFramework/tinyxml/tinystr.h \
    EnvFramework/tinyxml/tinyxml.h \
    Types.h \
    abstractenvobject.h \
    dockercommand.h \
    dockercomposebuilder.h \
    dockerimagebuilder.h \
    envbuilder.h \
    envcommand.h \
    envconnect.h \
    envcontainer.h \
    envcontainerparametarswig.h \
    envcontainerprop.h \
    envcontainersearch.h \
    envdev.h \
    envfactory.h \
    envitem.h \
    envpropertiesterminalwig.h \
    envscene.h \
    envsearchitem.h \
    envtoolwg.h \
    gitcommand.h \
    maptable.h \
    shellbuilder.h \
    vagrantcommand.h \
    vagrantfilebuilder.h

FORMS += \
    envcontainerparametarswig.ui \
    envcontainerprop.ui \
    envcontainersearch.ui \
    envdev.ui \
    envpropertiesterminalwig.ui \
    envtoolwg.ui \
    maptable.ui

TRANSLATIONS += \
    EnvDev_en_AS.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
