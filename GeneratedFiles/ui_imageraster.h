/********************************************************************************
** Form generated from reading UI file 'imageraster.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGERASTER_H
#define UI_IMAGERASTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageRasterClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageRasterClass)
    {
        if (ImageRasterClass->objectName().isEmpty())
            ImageRasterClass->setObjectName(QStringLiteral("ImageRasterClass"));
        ImageRasterClass->resize(600, 400);
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/SmartRaster.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImageRasterClass->setWindowIcon(icon);
        centralWidget = new QWidget(ImageRasterClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        ImageRasterClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageRasterClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        ImageRasterClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageRasterClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageRasterClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageRasterClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageRasterClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());

        retranslateUi(ImageRasterClass);

        QMetaObject::connectSlotsByName(ImageRasterClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageRasterClass)
    {
        ImageRasterClass->setWindowTitle(QApplication::translate("ImageRasterClass", "Image Raster", 0));
        menuFile->setTitle(QApplication::translate("ImageRasterClass", "File", 0));
        menuView->setTitle(QApplication::translate("ImageRasterClass", "View", 0));
        menuEdit->setTitle(QApplication::translate("ImageRasterClass", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageRasterClass: public Ui_ImageRasterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGERASTER_H