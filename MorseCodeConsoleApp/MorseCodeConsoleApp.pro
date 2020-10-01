TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../MorseCodeTranslatorEngine/release/ -lMorseCodeTranslatorEngine
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../MorseCodeTranslatorEngine/debug/ -lMorseCodeTranslatorEngine
else:unix: LIBS += -L$$OUT_PWD/../MorseCodeTranslatorEngine/ -lMorseCodeTranslatorEngine

INCLUDEPATH += $$PWD/../MorseCodeTranslatorEngine
DEPENDPATH += $$PWD/../MorseCodeTranslatorEngine
