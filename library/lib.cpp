#include "lib.h"
#include <cstring>
#include <QTextStream>
#include <iostream>
#include <fstream>


lib::lib()
{};
lib::~lib()
{}

void lib::showbook(int i)
{
    std::cout<<books[i].id<<" "<<books[i].name<<" ";
    if(books[i].isread==false){
        std::cout<<"free"<<std::endl;;
    }else {
        std::cout<<"taken by "<<readers[books[i].who].id<<" "<<readers[books[i].who].name<<std::endl;
    }
    std::cout<<"**********************"<<std::endl;
};
void lib::showreader(int i)
{
    std::cout<<readers[i].id<<" "<<readers[i].name<<" "<<std::endl;
    std::cout<<"list of taking books:"<<std::endl;
    int counter=0;
    for (auto j : books) {
        if((j.isread==true)&&(j.who==readers[i].id)){
            std::cout<<j.id<<" "<<j.name<<std::endl;
            counter++;
        }
    }
    if(counter==0){
        std::cout<<"nothing"<<std::endl;
    }
    std::cout<<"**********************"<<std::endl;
};
void lib::newbook(char name_[30]){
    book newbook_;
    strncpy(newbook_.name,name_,30);
    (newbook_.id)=books.size();
    books.push_back(newbook_);
};
void lib::newreader(char name_[30]){
    reader newreader_;
    strncpy(newreader_.name,name_,30);
    (newreader_.id)=readers.size();
    readers.push_back(newreader_);
};
void lib::viewreadrs(){
    if(readers.size()==0){
        std::cout<<"no readers"<<std::endl;
    }
    for (int i=0;i<readers.size();i++) {
        showreader(i);
    }
};
void lib::viewbooks(){
    if(books.size()==0){
        std::cout<<"no books"<<std::endl;
    }
    for (int i=0;i<books.size();i++) {
        showbook(i);
    }
};
void lib::takebook(int idbook,int idreader){
    books[idbook].who=idreader;
    books[idbook].isread=true;
    std::cout<<readers[idreader].id<<" "<<readers[idreader].name<<" take "<<books[idbook].id<<" "<<books[idbook].name<<std::endl;
};
void lib::returnbook(int idbook){
    for (auto i : books) {
        if(i.id==idbook){
            i.who=NULL;
            i.isread=false;
        }
    }
};
void lib::savelib(){
    std::ofstream savebooks("books.dat",std::ios::binary);
    if(savebooks.is_open()){
        for (auto i : books) {
            savebooks.write(reinterpret_cast<char *>(&i),sizeof(book));
        }
    }else{std::cout<<"can't open file"<<std::endl;}

    savebooks.flush();
    savebooks.close();

    std::ofstream savereaders("readers.dat",std::ios::binary);
    if(savereaders.is_open()){
        for (auto i : readers) {
            savereaders.write(reinterpret_cast<char *>(&i),sizeof (reader));
        }
    }
    savereaders.flush();
    savereaders.close();

};
void lib::loadlib(){
    std::ifstream loadbook("books.dat", std::ios::in | std::ios::binary);
    if(loadbook.is_open())
        {
            book t_book;
            while(loadbook.read(reinterpret_cast<char*>(&t_book), sizeof(book)))
            {
                books.push_back(t_book);
            }
    }else
        {
            std::cout << "I could not open file to load books" << std::endl;
        }
        loadbook.close();
    ////////////////////////////////
    std::ifstream loaduser("readers.dat", std::ios::in | std::ios::binary);
    if(loaduser.is_open())
        {
            reader t_reader;
            while (loaduser.read(reinterpret_cast<char*>(&t_reader), sizeof(reader)))
            {
                readers.push_back(t_reader);
            }
    }else
        {
            std::cout << "I could not open file to load users" << std::endl;
        }
        loaduser.close();
    ///////////////////////////////////

}






