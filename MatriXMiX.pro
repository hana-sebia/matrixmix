######################################################################
# Automatically generated by qmake (3.1) Wed Mar 6 22:16:58 2019
######################################################################

TEMPLATE = app
CONFIG += release

DESTDIR = ./bin
OBJECTS_DIR = ./obj/
MOC_DIR = ./moc
TARGET = MatriXMiX
ICON = MatriXMiX.icns

include(ext/latex/jkqtmathtext.pri);
INCLUDEPATH += ext/Eigen/

DEFINES += QT_DEPRECATED_WARNINGS

# Input

HEADERS += src/Matrix.h \
	src/VectorX.h \
	src/Polynomial.h \
	src/Fraction.h \
	src/MatriXMiXTXT.h \
	src/MatrixLibrary.h \
	src/MainWindow.h \
    src/LibraryWindow.h \
    src/ShowMatrixWidget.h \
    src/Error.h \
    src/MatrixViewWidget.h \
    src/MenuBar.h \
    src/Gauss.h \
    src/AbstractOperationWidget.h \
    src/BinaryOpMatrixMatrixWidget.h \
    src/BinaryOpMatrixNumberWidget.h \
    src/UnaryOpWidget.h \
    src/DiagonalisationWidget.h \
    src/ExprEvalWidget.h \
    src/SetMatrixWidget.h \
    src/HelpWindow.h \
    src/HelpWindowQt.h


SOURCES += src/main.cpp \
	src/Matrix.cpp \
	src/VectorX.cpp \ 
	src/Polynomial.cpp \
	src/Fraction.cpp \
	src/MatriXMiXTXT.cpp \
	src/MatrixLibrary.cpp \
	src/MainWindow.cpp \
    src/LibraryWindow.cpp \
    src/MatrixViewWidget.cpp \
    src/Error.cpp \
    src/MenuBar.cpp \
    src/Gauss.cpp \
    src/AbstractOperationWidget.cpp \
    src/BinaryOpMatrixMatrixWidget.cpp \
    src/BinaryOpMatrixNumberWidget.cpp \
    src/UnaryOpWidget.cpp \
    src/DiagonalisationWidget.cpp \
    src/ExprEvalWidget.cpp \
    src/SetMatrixWidget.cpp \
	src/ShowMatrixWidget.cpp \
    src/HelpWindow.cpp \
    src/HelpWindowQt.cpp

RESOURCES += \
    data/data.qrc



