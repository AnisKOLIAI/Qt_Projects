#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QCalendarWidget>
class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget * central;
    QVBoxLayout * layoutPrencipale;

    QCalendarWidget * dateDeNess;
    QCalendarWidget * dateDuJour;

    QLabel * resultat;
    float nombreDeJours = 0;
    QString  resultatText;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createLayout();
    void miseAjourText();
public slots:
    void calculeJours(const QDate &date);
};
#endif // MAINWINDOW_H
