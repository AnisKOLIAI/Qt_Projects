#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{ 
    setCentralWidget(central = new QWidget);
    setWindowTitle("Calcule de jours");
    setWindowIcon(QIcon("img/icon.png"));
    setFixedSize(400,600);



    createLayout();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createLayout()
{
    layoutPrencipale = new QVBoxLayout(central);

    // label (votre date de nésséance )
    QLabel * text1 = new QLabel(nullptr);
    text1->setText("Entrez votre date de naissance : ");
    text1->setStyleSheet("font-size: 18px;font-weight: bold;");
    // create date widget pour entrer la date de nessance
     dateDeNess = new QCalendarWidget();
    dateDeNess->setGridVisible(true);

     // label (votre date du jour ou autre )
     QLabel * text2 = new QLabel(nullptr);
     text2->setText("Entrez une date : ");
     text2->setStyleSheet("font-size: 18px;font-weight: bold;");

     // create date widget pour entrer la date
     dateDuJour= new QCalendarWidget();
    dateDuJour->setGridVisible(true);

     // label (Resultat )
     QLabel * text3 = new QLabel(nullptr);
     text3->setText("Résultat : ");
     text3->setStyleSheet("font-size: 18px;font-weight: bold;");

     resultat = new QLabel(nullptr);

     miseAjourText();
     resultat->setStyleSheet("font-size: 18px;font-weight: bold; color:green");

     layoutPrencipale-> addWidget(text1);
     layoutPrencipale->addWidget(dateDeNess);
     layoutPrencipale->addWidget(text2);
     layoutPrencipale->addWidget(dateDuJour);
     layoutPrencipale->addWidget(text3);
     layoutPrencipale->addWidget(resultat);



     connect(dateDeNess,&QCalendarWidget::clicked,this,&MainWindow::calculeJours);
     connect(dateDuJour,&QCalendarWidget::clicked,this,&MainWindow::calculeJours);
}

void MainWindow::miseAjourText()
{
    resultatText = QString("vous avez vecu %1 jours sur la Terre").arg( QString::number(nombreDeJours));
    resultat->setText(resultatText);
}

void MainWindow::calculeJours(const QDate &date)
{


    QDate dateN = dateDeNess->selectedDate();
    QDate dateJ = dateDuJour->selectedDate();


    int f = dateJ.day();
    int h = dateJ.month();
    int g = dateJ.year();

//    cout<<"Enter the day of today : " ;
//    cin>> f;
//    cout<<"Enter the month of today : " ;
//    cin>> h;
//    cout<<"Enter the year of today : " ;
//    cin>> g;

    int a = dateN.day();
    int b = dateN.month();
    int c = dateN.year();

//    cout<<"Enter your day of birth : " ;
//    cin>> a;
//    cout<<"Enter your month of birth : " ;
//    cin>> b;
//    cout<<"Enter your year of birth : " ;
//    cin>> c;


    int r1= f-a;
    int r2= h*30+5;
    int r3= b*30+5;
    int r4= r2-r3;
    int r5= g*365;
    int r6= c*365;
    int r7= r5-r6;
    int fr= r1 + r4 + r7;


    nombreDeJours = fr;
    miseAjourText();

//    cout<<"Your age with days is : "<< fr<< " days.";

}

