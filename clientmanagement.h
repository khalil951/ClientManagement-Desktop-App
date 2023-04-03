#ifndef CLIENTMANAGEMENT_H
#define CLIENTMANAGEMENT_H

#include <QMainWindow>
#include "client.h"
QT_BEGIN_NAMESPACE
namespace Ui { class clientmanagement; }
QT_END_NAMESPACE

class clientmanagement : public QMainWindow
{
    Q_OBJECT

public:
    clientmanagement(QWidget *parent = nullptr);
    ~clientmanagement();

private slots:
    void on_AddButton_clicked();

    void on_UpdateButton_clicked();

    void on_deleteButton_clicked();

    void on_SearchButton_clicked();

    void on_Sort_clicked();

    void on_pdf_clicked();
    
    void on_stats_clicked();
    
    void on_lineEdit_Search_editingFinished();

    void on_refresh_clicked();

private:
    Ui::clientmanagement *ui;
    CLIENT Etmp;
protected:
     CLIENT c;
};
#endif // CLIENTMANAGEMENT_H
