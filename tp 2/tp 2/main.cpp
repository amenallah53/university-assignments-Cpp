#include "liste_chainne.hpp"

int main() {

    //try-catch block
    try {

        //déclaration deux listes 1 et 2
        LISTE_PRODUIT_FINI liste1, liste2;

        //remplissage de liste1
        cout << "Saisir la première liste de produits finis:" << endl;
        for (int i = 0; i < 2; ++i) {
            PRODUIT_FINI p;
            p.lire_produit_fini();
            liste1.ajouter(p);
        }

        //remplissage de liste2
        cout << "Saisir la deuxième liste de produits finis:" << endl;
        for (int i = 0; i < 2; ++i) {
            PRODUIT_FINI p;
            p.lire_produit_fini();
            liste2.ajouter(p);
        }

        //affichage liste1
        cout << "Liste 1:" << endl;
        liste1.afficher();

        //affichage liste2
        cout << "Liste 2:" << endl;
        liste2.afficher();

        //opération + : "liste1 + liste2"
        LISTE_PRODUIT_FINI listeAddition = liste1 + liste2;

        //affichage de listeAddition
        cout << "Liste résultant de l'addition des deux listes:" << endl;
        listeAddition.afficher();

    } catch (const exception &e) {
        cerr << "Erreur: " << e.what() << endl;
    }

    return 0;
}
//fin ..