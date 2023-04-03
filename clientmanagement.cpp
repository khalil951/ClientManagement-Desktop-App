#include "clientmanagement.h"
#include "ui_clientmanagement.h"
#include "client.h"
#include<QMessageBox>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QMessageBox>
#include <QValidator>
#include <QtPrintSupport/QPrintDialog>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QTextDocument>
#include<QSystemTrayIcon>
#include<QPrinter>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QMessageBox>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QtCharts>
#include <QSqlQuery>

clientmanagement::clientmanagement(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::clientmanagement)
{
     ui->setupUi(this);
     ui->tableView->setModel(CLIENT().displayClient());

     //input control
     ui->lineEdit->setValidator(new QIntValidator(0, 999999, this));
     ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
     ui->lineEdit_3->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
     ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"), this));
     ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("\\d+"), this));
     ui->lineEdit_7->setValidator(new QIntValidator(0, 999999, this));
     ui->lineEdit_8->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
     ui->lineEdit_9->setValidator(new QRegExpValidator(QRegExp("[A-Za-z]+"), this));
     ui->lineEdit_11->setValidator(new QRegExpValidator(QRegExp("[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}"), this));
     ui->lineEdit_12->setValidator(new QRegExpValidator(QRegExp("\\d+"), this));

}

clientmanagement::~clientmanagement()
{
    delete ui;
}


void clientmanagement::on_AddButton_clicked()
{
    int ID=ui->lineEdit->text().toInt();
    QString First_name=ui->lineEdit_2->text();
    QString last_name=ui->lineEdit_3->text();
    QString Address=ui->lineEdit_4->text();
    QString Email=ui->lineEdit_5->text();
    QString Phone=ui->lineEdit_6->text();
    CLIENT Cl(ID,First_name,last_name,Address,Email,Phone);

    bool test=Cl.addClient();
    if(test)
    {
           ui->tableView->setModel(Cl.displayClient());
           (*ui->lineEdit).clear();
           (*ui->lineEdit_2).clear();
           (*ui->lineEdit_3).clear();
           (*ui->lineEdit_4).clear();
           (*ui->lineEdit_5).clear();
           (*ui->lineEdit_6).clear();
     }
    else

        QMessageBox::critical(nullptr, QObject::tr("Error"),
        QObject::tr("Addition not made.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}

void clientmanagement::on_UpdateButton_clicked()
{
    int ID=ui->lineEdit_7->text().toInt();
    QString First_name=ui->lineEdit_8->text();
    QString last_name=ui->lineEdit_9->text();
    QString Address=ui->lineEdit_10->text();
    QString Email=ui->lineEdit_11->text();
    QString Phone=ui->lineEdit_12->text();


    CLIENT Cl1 ( ID, First_name, last_name,Address,Email,Phone);


    bool test=  Cl1.modifyClient();

    if(test)
    {
      ui->tableView->setModel(Cl1.displayClient());
      (*ui->lineEdit_7).clear();
      (*ui->lineEdit_8).clear();
      (*ui->lineEdit_9).clear();
      (*ui->lineEdit_10).clear();
      (*ui->lineEdit_11).clear();
      (*ui->lineEdit_12).clear();

    }

    else
        QMessageBox::critical(nullptr, QObject::tr("Error"),
        QObject::tr("no update made.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void clientmanagement::on_deleteButton_clicked()
{
    int ID=ui->lineEdit_13->text().toInt();
    bool test=Etmp.deleteClient(ID);
    if(test)
    {
         ui->tableView->setModel(Etmp.displayClient());
        QMessageBox::information(nullptr, QObject::tr("Success !"),
        QObject::tr("Deletion made. \n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
         (*ui->lineEdit_13).clear();
     }
    else

        QMessageBox::critical(nullptr, QObject::tr("Error"),
        QObject::tr("Deletion not made.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}

void clientmanagement::on_SearchButton_clicked()
{
    ui->tableView->setModel(CLIENT().SearchClient(ui->lineEdit_Search->text()));
}

void clientmanagement::on_Sort_clicked()
{
    ui->tableView->setModel(CLIENT().SortByName());
}




void clientmanagement::on_pdf_clicked()
{
    QString strStream;
                                              QTextStream out(&strStream);

                                              const int rowCount = ui->tableView->model()->rowCount();
                                              const int columnCount = ui->tableView->model()->columnCount();

                                              out <<  "<html>\n"
                                                  "<head>\n"
                                                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                                  <<  QString("<title>%1</title>\n").arg("strTitle")
                                                  <<  "</head>\n"
                                                  "<body bgcolor=#ffffff link=#5000A0>\n"

                                                 //     "<align='right'> " << datefich << "</align>"
                                                  "<center> <H1>list of Clients </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                              // headers
                                              out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                              for (int column = 0; column < columnCount; column++)
                                                  if (!ui->tableView->isColumnHidden(column))
                                                      out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                              out << "</tr></thead>\n";

                                              // data table
                                              for (int row = 0; row < rowCount; row++) {
                                                  out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                                  for (int column = 0; column < columnCount; column++) {
                                                      if (!ui->tableView->isColumnHidden(column)) {
                                                          QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                      }
                                                  }
                                                  out << "</tr>\n";
                                                                                      }
                                                                                      out <<  "</table> </center>\n"
                                                                                          "</body>\n"
                                                                                          "</html>\n";

                                                                                QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "register in PDF", QString(), "*.pdf");
                                                                                  if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                                                                 QPrinter printer (QPrinter::PrinterResolution);
                                                                                  printer.setOutputFormat(QPrinter::PdfFormat);
                                                                                 printer.setPaperSize(QPrinter::A4);
                                                                                printer.setOutputFileName(fileName);

                                                                                 QTextDocument doc;
                                                                                  doc.setHtml(strStream);
                                                                                  doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                                                                  doc.print(&printer);
}

void clientmanagement::on_stats_clicked()
{
                   QPieSeries *series = new QPieSeries();


                   QStringList list=Etmp.list_Sum("ADDRESSC");
                   if(list.size() != 0) {
                       for (int i =0; i< list.size();i++)
                       {
                           series->append(list[i],Etmp.calcul_Sum(list[i],"ADDRESSC"));

                       }
                       QPieSlice *slice = series->slices().at(1);
                       slice->setLabelVisible();
                       slice->setExploded();


                       QtCharts::QChart *chart =new QtCharts::QChart();
                       chart->addSeries(series);
                       chart->setTitle("Most Common locations");
                       chart->setAnimationOptions(QChart::AllAnimations);
                       QChartView *chartview=new QChartView(chart);
                       QGridLayout *mainLayout=new QGridLayout();
                       mainLayout->addWidget(chartview,0,0);
                       ui->statistics->setLayout(mainLayout);
                   }
                   else{
                       QMessageBox::information(nullptr, QObject::tr("Error !"),
                       QObject::tr("Empty database. \n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
                   }

}

void clientmanagement::on_refresh_triggered(QAction *arg1)
{
    Etmp.displayClient();
}
