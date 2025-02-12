#ifndef MAINWINDOW_HPP_
#define MAINWINDOW_HPP_

#include <QApplication>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QMenuBar>
#include <QStatusBar>
#include <QLabel>
#include <QToolBar>

#include <QAction>
#include <QMenu>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
#include <QPushButton>

class MainWindow : public QMainWindow
{
#ifdef USE_QOBJECT_MACRO
    Q_OBJECT
#endif
    // prinvate member functions
    void initMenuBar();
    void initStatusBar();
    void initToolBar();
    void open();
    void newFile();
    void saveAs();
    void save();
#ifdef ADD_PAGE_SETUP
    void openCustomPageSetupDialog();
#endif
    void setCurrentFile(QString fileName);
    void documantModified();
    bool wantToSave();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPlainTextEdit *textArea;
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QMenu *formatMenu;
    int font_size;
    QToolBar *toolBar;

    // actions
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *copyAction;
    QAction *cutAction;
    QAction *pasteAction;
    QAction *printAction;
    QAction *undoAction;
    QAction *redoAction;

    QAction *pageSetupAction;
    QAction *exitAction;

    QAction *aboutAction;

    QString currentFileName;
};

#endif
