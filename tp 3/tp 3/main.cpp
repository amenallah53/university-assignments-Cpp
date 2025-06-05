#include "arbre.hpp"

int main() {
    // Création d'arbre
    Arbre<int> arbre(10);
    //racine de l'arbre
    Noeud<int>* racine = arbre.get_racine();

    // Création des autres noeuds
    Noeud<int>* enfant1 = new Noeud<int>(20);
    Noeud<int>* enfant2 = new Noeud<int>(30);
    Noeud<int>* enfant3 = new Noeud<int>(40);
    Noeud<int>* enfant4 = new Noeud<int>(50);
    Noeud<int>* enfant5 = new Noeud<int>(60);
    Noeud<int>* enfant6 = new Noeud<int>(70);

    // Insertion dans l'arbre
    arbre.inserer(&racine, enfant1, racine);
    arbre.inserer(&racine, enfant2, racine);   
    arbre.inserer(&racine, enfant3, enfant1); 
    arbre.inserer(&racine, enfant4, enfant2); 
    arbre.inserer(&racine, enfant5, enfant3); 
    arbre.inserer(&racine, enfant6, enfant2); 

    
    // Affichage
    cout << "Structure de l'arbre avant suppression :" << endl;
    arbre.display_arbre(racine);
    
    
    // Affichage après suppression 
    cout << "Structure de l'arbre après suppression :" << endl;
    arbre.supprimer_noeud(enfant5);
    arbre.display_arbre(arbre.get_racine());
    cout << "------" << endl;
    
    

    // Recherche
    int valeurRecherchee = 20;
    Noeud<int>* noeudTrouve = arbre.rechercher(arbre.get_racine(), valeurRecherchee);
    if (noeudTrouve != nullptr) {
        cout << "Noeud trouvé avec la valeur : " << noeudTrouve->get_data() << endl;
    } else {
        cout << "Noeud avec la valeur " << valeurRecherchee << " non trouvé." << endl;
    }

    return 0;
}
