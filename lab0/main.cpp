#include <iostream>
#include <QCoreApplication>
#include <QFile>
#include <QVector>
#include <QtAlgorithms>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(argc != 2)
    {
        cout << "File not found.";
        return 1;
    }
    cout << "INPUT FILE: " << argv[argc-1];
    QFile in(argv[argc-1]);
    if(!in.open(QIODevice::ReadOnly)){
        cout << "Can not open: " << argv[argc-1];
        return 1;
    }
    QVector<int> packs;
    while(!in.atEnd()){
        packs.append(QString(in.readLine()).toInt());
    }
    qSort(packs);
//    for(int i = 0; i < packs.size(); i++)
//        cout << "\n[" << i << "] " << packs.at(i);
    QVector<bool> variables;
    for(int i = packs.at(0); i <= packs.at(packs.size()-1); i++){
        variables.append(false);
    }   // Заполняем вектор булов, отметив, что ни один элемент не отмечен.

    for(int i = 0; i < packs.size(); i++){
        variables[(packs.at(i)-packs[0])] = true;
    }
    cout << endl << endl;
    bool nonEpsent = true;
    for(int i = 0; i < variables.size(); i++){
        if(variables[i] == false)
        {
            nonEpsent = false;
            cout << packs.at(0) + i << " ";
        }
    }
    if(nonEpsent)
        cout << "No items missing.\nCount: " << variables.count();


    return a.exec();
}
