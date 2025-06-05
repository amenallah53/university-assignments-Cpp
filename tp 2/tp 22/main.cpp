#include "liste_chainne.hpp"

int main() {

    //try-catch block
    try {

        //déclaration deux listes 1 et 2
        LISTE_PRODUIT_FINI liste1, liste2;

        //initialisation des instances des produits finis
        PRODUIT_FINI p1(1,"aaa",25,"ford",150.5,1);
        PRODUIT_FINI p2(2,"bbb",5,"kia",90.0,3);
        PRODUIT_FINI p3(3,"ccc",15,"cheverolet",130.5,1);
        PRODUIT_FINI p4(4,"ddd",9,"toyota",80.0,1);
        PRODUIT_FINI p5(5,"eee",20,"subaru",100.5,2);
        
        //liste 1 (ajout)
        liste1.ajouter(p1);
        liste1.ajouter(p2);
        liste1.ajouter(p3);

        //liste 2 (ajout)
        liste2.ajouter(p4);
        liste2.ajouter(p5);
        

        //affichage liste1
        cout << "Liste 1:" << endl;
        liste1.afficher();
        cout << endl;

        //affichage liste2
        cout << "Liste 2:" << endl;
        liste2.afficher();
        cout << endl;


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