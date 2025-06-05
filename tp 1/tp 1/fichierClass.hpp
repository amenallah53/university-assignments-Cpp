//class fichier hpp
#ifndef FICHIER_HPP
#define FICHIER_HPP
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std; 

//class fichierClass
class fichierClass{

    private:
        /* attributs */
        string name;
        string mode;
        char* fp;
        int size_len;
        fstream MyFile;

    public:

        //constructeur sans paramètre 
        fichierClass();
        //constructeur avec paramètre 
        fichierClass(string name, string mode, const char* fp, int size_len);
        //destructeur
        ~fichierClass();

        //setters
        void set_name(string new_name);
        void set_mode(string new_mode);
        void set_fp(const char* new_fp);
        void set_size_len(int new_size);

        //getters
        string get_name();
        string get_mode();
        char* get_fp();
        int get_size_len();

        // write-read methods
        void insert_line();
        void write_file();
        void read_line();
        void display_file_content();

        //constructeur par recopie 
        fichierClass(const fichierClass &file);
        // +operation
        fichierClass operator + (fichierClass &file);

};
#endif