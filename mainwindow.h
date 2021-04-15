#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QNetworkReply>
#include <QPointer>
#include <QNetworkAccessManager>
#include <memory>

class MarianInterface;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_translateButton_clicked();

    void on_modelDownload_clicked();

    void onResult(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    std::unique_ptr<MarianInterface> translator_;
    QPointer<QNetworkAccessManager> nam_;
};
#endif // MAINWINDOW_H