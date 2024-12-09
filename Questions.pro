QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    widget.cpp \
    questionmanagement.cpp \
    questiontemplate.cpp

HEADERS += \
    QuestionList.h \
    widget.h \
    questionmanagement.h \
    questiontemplate.h \
    ui_multiplechoiceform.h \
    ui_introwidget.h \
    ui_outrowidget.h \
    ui_rulewidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    IntroWidget.ui \
    MultipleChoiceForm.ui \
    OutroWidget.ui \
    RuleWidget.ui

RESOURCES += \
    resource.qrc
