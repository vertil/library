#include <QCoreApplication>
#include <iostream>
#include "lib.h"
#include <string>

class lib;
int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    lib lib;
    int d;
    std::cout<<"what you want?"<<std::endl;
    std::cout<<"0-info, 1-newbook, 2-newreader, 3-viewallreaders, 4-viewallbooks, 5-takebook, 6-returnbook, 7-savelibrary, 8-loadlibrary"<<std::endl;
    for (;;) {
        std::cin>>d;
        switch (d) {
        case 0:
        {std::cout<<"0-info, 1-newbook, 2-newreader, 3-viewallreaders, 4-viewallbooks, 5-takebook, 6-returnbook,  7-savelibrary, 8-loadlibrary"<<std::endl;break;}
        case 1:
            {std::cout<<"write name book's name"<<std::endl;
            char str[30];
            std::cin>>str;
            lib.newbook(str);
            break;}
        case 2:
            {std::cout<<"write new reader's name"<<std::endl;
            char str[30];
            std::cin>>str;
            lib.newreader(str);
            break;}
        case 3:
        {lib.viewreadrs();break;}
        case 4:
        {lib.viewbooks();break;}
        case 5:
            {std::cout<<"enter books id and reader id"<<std::endl;
            int a,b;
            std::cin>>a>>b;
            lib.takebook(a,b);
            break;
            }
        case 6:
            {std::cout<<"enter enter book's id"<<std::endl;
            int a;
            std::cin>>a;
            lib.returnbook(a);
            break;
            }
        case 7:
            {lib.savelib();
            break;
            }
        case 8:
            {lib.loadlib();
            break;
            }
        default:
            {std::cout<<"i don't understand you ))"<<std::endl;}
    }




    }


    return a.exec();
}
