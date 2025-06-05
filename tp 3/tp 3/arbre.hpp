#ifndef ARBRE_HPP
#define ARBRE_HPP

#include <iostream>
using namespace std;

//class template 
template <typename T>
//class Noeud
class Noeud{
    private:
        //attributs
        T data; /*valeur*/
        Noeud<T>* fils; /*branche fils*/
        Noeud<T>* frere; /*branche frère*/

    public:
        //constructeur
        Noeud(T data){
            this->data = data;
            this->frere = nullptr;
            this->fils = nullptr;
        }

        //getters
        T get_data() const {
            return data;
        }
        Noeud<T>* get_fils() const {
            return fils;
        }
        Noeud<T>* get_frere() const {
            return frere;
        }
        Noeud<T>** get_fils_ptr() {
            return &fils;
        }
        Noeud<T>** get_frere_ptr() {
            return &frere;
        }

        //setters
        void set_fils(Noeud<T>* newFils) {
            fils = newFils;
        }
        void set_frere(Noeud<T>* newFrere) {
            frere = newFrere;
        }

        //affichage de donnée d'un noeud
        void display() const {
            cout << data << endl;
        }

};


//class template 
template <typename T>
//class Arbre
class Arbre{
    private:
        //racine
        Noeud<T>* racine;

        //méthode privé : 
        void arbre_destructeur(Noeud<T>* ptr) {
            if (ptr != nullptr) {
                arbre_destructeur(ptr->get_fils());
                arbre_destructeur(ptr->get_frere());
                delete ptr;
            }
        }
        int supprimer(Noeud<T>** racine, Noeud<T>* target_noeud) {

            if (*racine == nullptr) {
                return 0;
            }
            if(*racine == target_noeud){
                Noeud<T>* toDelete = *racine;
                Noeud<T>* fils = toDelete->get_fils();
                Noeud<T>* frere = toDelete->get_frere();
                if(fils != nullptr){
                    // Rechercher le dernier frère dans la liste des fils
                    while(fils->get_frere() != nullptr){
                        fils = fils->get_frere();
                    }
                    // Faire le lien entre lady frere dans les films et les films de toDelete
                    fils->set_frere(frere);
                    // Faire prendre la place de racine au fils
                    *racine = toDelete->get_fils();
                }
                else{
                    // Sinon faire en sorte que frere remplace toDelete
                    *racine = frere;
                }
                // Supprimer le noeud
                delete toDelete;
                return 1;
            }
            else{
                Noeud<T>* fils = (*racine)->get_fils();
                Noeud<T>* frere = (*racine)->get_frere();
                
                if(supprimer(&fils, target_noeud)){
                    (*racine)->set_fils(fils);
                }
                else if(supprimer(&frere, target_noeud)){
                    (*racine)->set_frere(frere);
                }
            }
            return 0;
        }

    public:

        //constructeur
        Arbre(T val) {
            this->racine = new Noeud<T>(val);
        }
        //destructeur
        ~Arbre() {
            arbre_destructeur(racine);
        }

        //getter
        Noeud<T>* get_racine(){
            return racine;
        }

        //insertion
        void inserer(Noeud<T>** racine, Noeud<T>* nouveu_noued, Noeud<T>* parent_noeud) {
            if (*racine != nullptr) {
                if (*racine == parent_noeud){
                    nouveu_noued->set_frere((*racine)->get_fils());
                    (*racine)->set_fils(nouveu_noued);
                }
                else{
                    inserer((*racine)->get_fils_ptr(), nouveu_noued, parent_noeud);
                    inserer((*racine)->get_frere_ptr(), nouveu_noued, parent_noeud);
                }
            }
        }
        
        //suppression
        void supprimer_noeud(Noeud<T>* ptr){
            
            supprimer(&(this->racine),ptr);
            
        }
        
        //affichage
        void display_arbre(Noeud<T>* racine) const {
            if (racine != nullptr) {
                racine->display();
                display_arbre(racine->get_fils());
                display_arbre(racine->get_frere());
            }
        }

        //recherche
        Noeud<T>* rechercher(Noeud<T>* racine, const T& val) const {
            if (racine != nullptr) {
                if (racine->get_data() == val) {
                    return racine;
                }
                Noeud<T>* foundInFils = rechercher(racine->get_fils(), val);
                if (foundInFils != nullptr) {
                    return foundInFils;
                }
                return rechercher(racine->get_frere(), val);
            }
            return nullptr;
        }
};


#endif