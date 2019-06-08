#include "main.h"


static int Mode;
void setMode(int n){
    Mode = n;
    return;
}

int getMode(){
    return Mode;
}

Graph& getGraph(){
    static Graph g;
    return g;
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
