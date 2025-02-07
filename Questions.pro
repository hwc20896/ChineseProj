QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/cpp/main.cpp \
    src/cpp/questionmanagement.cpp \
    src/cpp/questiontemplate.cpp \
    src/cpp/widget.cpp

HEADERS += \
    src/headers/questionmanagement.h \
    src/headers/questiontemplate.h \
    src/headers/widget.h \
    src/ui_files/ui_introwidget.h \
    src/ui_files/ui_multiplechoiceform.h \
    src/ui_files/ui_outrowidget.h \
    src/ui_files/ui_rulewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    src/ui_files/RuleWidget.ui \
    src/ui_files/MultipleChoiceForm.ui \
    src/ui_files/OutroWidget.ui \
    src/ui_files/IntroWidget.ui

RESOURCES += \
    resource.qrc
