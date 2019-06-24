#ifndef LIB_H
#define LIB_H
#include <string>
#include <vector>

class lib
{
    struct book;
    struct reader{
    int id;
    char name[30];
    //std::vector<book> tbooks;
    };
    struct book{
    int id;
    char name[30];
    int who=NULL;
    bool isread=false;

    };

    std::vector<reader> readers;
    std::vector<book> books;

public:
    lib();
    ~lib();
    void showbook(int i);
    void showreader(int i);
    void newbook(char name_[30]); //1
    void newreader(char name_[30]); //2
    void viewreadrs(); //3
    void viewbooks(); //4
    void takebook(int idbook,int idreader); //5
    void returnbook(int idbook); //6
    void savelib();  //7
    void loadlib(); //8
};

#endif // LIB_H
