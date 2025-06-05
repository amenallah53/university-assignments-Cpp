#include "liste_chainne.hpp"

//class ARTICLE
//constructeur
/*sans parametre*/
ARTICLE::ARTICLE() : code(0), quantiteStock(0), designation("") {}
/*avec parametre*/
ARTICLE::ARTICLE(int code, string desig, int qte) :
    code(code > 0 ? code : throw invalid_argument("Le code doit être un entier positif.")),
    quantiteStock(qte > 0 ? qte : throw invalid_argument("La quantité en stock ne peut pas être négative.")),
    designation(!desig.empty() ? desig : throw invalid_argument("La designation ne peut pas être vide.")){}
//destructeur
ARTICLE::~ARTICLE(){}

//setters
void ARTICLE::set_code(int c) {

    if (c <= 0) throw invalid_argument("Le code doit être un entier positif.");
    code = c;
}

void ARTICLE::set_designation(const string &d) {

    if (d.empty()) throw invalid_argument("La designation ne peut pas être vide.");
    designation = d;
}

void ARTICLE::set_quantiteStock(int q) {

    if (q < 0) throw invalid_argument("La quantité en stock ne peut pas être négative.");
    quantiteStock = q;
}

//getters
int ARTICLE::get_code() {
    return code; 
}

string ARTICLE::get_designation(){
    return designation; 
}

int ARTICLE::get_quantiteStock() {
    return quantiteStock;
}



//afficher les données d'une instance d'ARTICLE
void ARTICLE::afficher_article(){

    cout << "Code: " << code << ", Designation: " << designation
        << ", Quantité en stock: " << quantiteStock << endl;
}


//class PRODUIT_FINI
//constructeur
/*sans parametre*/
PRODUIT_FINI::PRODUIT_FINI() : prixRevient(0.0), nombreOperations(0), marque("") {}
/*avec parametre*/
PRODUIT_FINI::PRODUIT_FINI(int code, string desig, int qte, string marque, float prix, int nb_op) :
    ARTICLE(code, desig, qte),
    prixRevient((prix >= 0.0) ? prix : throw invalid_argument("Le prix de revient ne peut pas être négatif.")),
    nombreOperations((nb_op >= 0 && nb_op <= 10) ? nb_op : throw out_of_range("Le nombre d'opérations doit être entre 0 et 10.")),
    marque(!marque.empty() ? marque : throw invalid_argument("La marque ne peut pas être vide."))
          
{
    cout << "Creation de produit de code N° " << code << endl;
    for (int i = 0; i < nombreOperations; ++i) {
        cout << "Opération " << i + 1 << ": ";
        getline(cin, operations[i]);
        if (operations[i].empty()) throw invalid_argument("Une opération ne peut pas être vide.");
    }
}
//destructeur
PRODUIT_FINI::~PRODUIT_FINI(){}

//setters
void PRODUIT_FINI::set_marque(const string &m) {
    if (m.empty()) throw invalid_argument("La marque ne peut pas être vide.");
    marque = m;
}

void PRODUIT_FINI::set_prixRevient(float prix) {
    if (prix < 0.0) throw invalid_argument("Le prix de revient ne peut pas être négatif.");
    prixRevient = prix;
}

void PRODUIT_FINI::set_nombreOperations(int n) {
    if (n < 0 || n > 10) throw out_of_range("Le nombre d'opérations doit être entre 0 et 10.");
    nombreOperations = n;
}

void PRODUIT_FINI::set_operations(int index, const string &op) {
    if (index < 0 || index >= 10) throw out_of_range("Index d'opération invalide.");
    if (op.empty()) throw invalid_argument("Une opération ne peut pas être vide.");
    operations[index] = op;
}

//getters
string PRODUIT_FINI::get_marque() {
    return marque; 
}

float PRODUIT_FINI::get_prixRevient() {
    return prixRevient; 
}

int PRODUIT_FINI::get_nombreOperations() {
    return nombreOperations; 
}

string PRODUIT_FINI::get_operation(int index) {
    if (index < 0 || index >= 10) throw out_of_range("Index d'opération invalide.");
    return operations[index];
}

//afficher les données d'une instance d'PRODUIT_FINI
void PRODUIT_FINI::afficher_produit_fini() {
    afficher_article();
    cout << "Marque: " << marque << ", Prix de revient: " << prixRevient
        << ", Nombre d'opérations: " << nombreOperations << endl;
    for (int i = 0; i < nombreOperations; ++i) {
        cout << "  Opération " << i + 1 << ": " << operations[i] << endl;
    }
}


//class ELEMENT_LISTE
//constructeur
ELEMENT_LISTE::ELEMENT_LISTE(PRODUIT_FINI p) : produit(p), suivant(NULL) {}
//destructeur
ELEMENT_LISTE::~ELEMENT_LISTE(){}

//getters
PRODUIT_FINI ELEMENT_LISTE:: get_produit(){
    return produit;
}
ELEMENT_LISTE* ELEMENT_LISTE:: get_suivant(){
    return suivant;
}   

//setters
void ELEMENT_LISTE:: set_produit(PRODUIT_FINI& p){
    produit = p;
}
void ELEMENT_LISTE:: set_suivant(ELEMENT_LISTE* ptr){
    suivant = ptr;
}


//class LISTE_PRODUIT_FINI
//constructeur
LISTE_PRODUIT_FINI::LISTE_PRODUIT_FINI() : tete(NULL) {}
//destructeur
LISTE_PRODUIT_FINI::~LISTE_PRODUIT_FINI() {

    while (tete) {
        ELEMENT_LISTE *temp = tete;
        tete = tete->get_suivant();
        delete temp;
    }
}

//méthode d'ajoute d'un noeud dans la liste chainné
void LISTE_PRODUIT_FINI::ajouter(PRODUIT_FINI p) {

    ELEMENT_LISTE *nouveau = new ELEMENT_LISTE(p);
    nouveau->set_suivant(tete);
    tete = nouveau;
}

//méthode d'afficher la liste chainné
void LISTE_PRODUIT_FINI::afficher() {

    ELEMENT_LISTE *courant = tete;
    while (courant) {
        courant->get_produit().afficher_produit_fini();
        courant = courant->get_suivant();
    }
}

//surdéfinition d'opération + 
LISTE_PRODUIT_FINI LISTE_PRODUIT_FINI::operator+(LISTE_PRODUIT_FINI& autre) {
    
    LISTE_PRODUIT_FINI resultat;
    // Ajouter tous les noeuds de la liste de cette instance dans la liste de concataination "resultat"
    ELEMENT_LISTE* current = tete;
    while (current) {
        resultat.ajouter(current->get_produit());
        current = current->get_suivant();
    }

    // Ajouter tous les noeuds de la liste de l'instance "autre" dans la liste de concataination "resultat"
    ELEMENT_LISTE* autreCurrent = autre.tete;
    while (autreCurrent) {
        resultat.ajouter(autreCurrent->get_produit());
        autreCurrent = autreCurrent->get_suivant();
    }

    //retourner liste
    return resultat;
}

/*fin ...*/