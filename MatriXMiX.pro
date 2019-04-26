######################################################################
# Automatically generated by qmake (3.1) Wed Mar 6 22:16:58 2019
######################################################################

TEMPLATE = app
CONFIG += link_prl qt debug_and_release
CONFIG += qt
QT += widgets

include(ext/latex/jkqtmathtext.pri);

DESTDIR = ./bin
OBJECTS_DIR = ./obj/
MOC_DIR = ./moc
TARGET = MatriXMiX

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
    src/AddMatrixWidget.h \
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
    src/ExprEvalWidget.h

SOURCES += src/main.cpp \ 
	src/Matrix.cpp \
	src/VectorX.cpp \ 
	src/Polynomial.cpp \
	src/Fraction.cpp \
	src/MatriXMiXTXT.cpp \
	src/MatrixLibrary.cpp \
	src/MainWindow.cpp \
    src/LibraryWindow.cpp \
    src/AddMatrixWidget.cpp \
    src/ShowMatrixWidget.cpp \
    src/MatrixViewWidget.cpp \
    src/Error.cpp \
    src/MenuBar.cpp \
    src/Gauss.cpp \
    src/AbstractOperationWidget.cpp \
    src/BinaryOpMatrixMatrixWidget.cpp \
    src/BinaryOpMatrixNumberWidget.cpp \
    src/UnaryOpWidget.cpp \
    src/DiagonalisationWidget.cpp \
    src/ExprEvalWidget.cpp

RESOURCES += \
    data/data.qrc


