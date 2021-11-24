#ifndef COMMANDLINEIFACE_H
#define COMMANDLINEIFACE_H

#include <QObject>
#include <QPointer>
#include <QTextStream>
#include <QCommandLineParser>
#include <QEventLoop>
#include "ModelManager.h"
#include "Settings.h"
#include "MarianInterface.h"
#include "Translation.h"

class CommandLineIface : public QObject {
    Q_OBJECT
private:
    ModelManager models_;
    
    // Settings and translator:
    Settings settings_;
    QPointer<MarianInterface> translator_;

    // Event loop that would wait until translation completes
    QEventLoop eventLoop_;

    // do_once file in and file out
    QFile infile_;
    QFile outfile_;
    QTextStream instream_;
    QTextStream outstream_;

    static const int constexpr prefetchLines = 320;

    // Functions
    void printLocalModels();
    void doTranslation();
    inline QString &fetchData(QString &);

public:
    explicit CommandLineIface(QObject * parent = nullptr);
    int run(QCommandLineParser const &);

private slots:
    void outputError(QString error);
    void outputTranslation(Translation output);
};

#endif // COMMANDLINEIFACE_H