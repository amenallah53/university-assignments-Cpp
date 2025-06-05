#ifndef ARTICLE_HPP
#define ARTICLE_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;


//class ARTICLE
class ARTICLE {
    private:
        //attributs
        int code;
        string designation;
        int quantiteStock;

    public:

        //constructeur
        ARTICLE();
        //destructeur
        ~ARTICLE();

        //setters
        void set_code(int c);
        void set_designation(const string &d);
        void set_quantiteStock(int q);

        //getters
        int get_code();
        string get_designation();
        int get_quantiteStock();

        //methodes d'affichage et lecture 
        void lire_article();
        void afficher_article();
};

//class PRODUIT_FINI
class PRODUIT_FINI : public ARTICLE {
    private:
        //attributs
        string marque;
        float prixRevient;
        int nombreOperations;
        string operations[10];

    public:
        
        //constructeur
        PRODUIT_FINI();
        //destructeur
        ~PRODUIT_FINI();

        //setters
        void set_marque(const string &m);
        void set_prixRevient(float prix);
        void set_nombreOperations(int n);
        void set_operations(int index, const string &op);

        //getters
        string get_marque();
        float get_prixRevient();
        int get_nombreOperations();
        string get_operation(int index);

        //methodes d'affichage et lecture 
        void lire_produit_fini();
        void afficher_produit_fini();
};

//class ELEMENT_LISTE
class ELEMENT_LISTE{
    private :
        //attribut (noeud)
        PRODUIT_FINI produit;
        ELEMENT_LISTE *suivant;
    
    public :
        //constructeur
        ELEMENT_LISTE(PRODUIT_FINI p);
        //destructeur
        ~ELEMENT_LISTE();

        //getters
        PRODUIT_FINI get_produit();
        ELEMENT_LISTE* get_suivant();

        //setters
        void set_produit(PRODUIT_FINI& p);
        void set_suivant(ELEMENT_LISTE* ptr);
};

//class LISTE_PRODUIT_FINI
class LISTE_PRODUIT_FINI {
    private:
        //attribut
        ELEMENT_LISTE *tete;

    public:
        //constructeur
        LISTE_PRODUIT_FINI();
        //destructeur
        ~LISTE_PRODUIT_FINI();
        

        //methodes d'ajout et lecture
        void ajouter(PRODUIT_FINI p);
        void afficher();

        //surdéfinition d'opérateur +
        LISTE_PRODUIT_FINI operator+(LISTE_PRODUIT_FINI &autre);
};

#endif