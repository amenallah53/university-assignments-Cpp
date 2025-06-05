#include "fichierClass.hpp"

//constructeur sans paramètre
fichierClass::fichierClass(){

    fp = nullptr;
    name = "";
    mode = "";
    size_len = 0;
}

//constructeur avec paramètre
fichierClass::fichierClass(string name, string mode, const char* fp, int size_len){
    
    this->name = name;
    this->mode = mode;
    this->size_len = size_len;
    this->fp = new char[strlen(fp) + 1];
    strcpy(this->fp,fp);

    if (mode == "w"){
        MyFile.open(this->name+".txt",ios::out);
        cout << this->name + ".txt opened in mode 'w' !!!" << endl; 
    }
    else if (mode == "r"){
        MyFile.open(this->name + ".txt", ios::in);
        if (!MyFile){
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r' !!!" << endl; 
    }
    else if (mode == "w+"){
        MyFile.open(this->name+".txt", ios::in | ios::out | ios::trunc);
        cout << this->name + ".txt opened in mode 'w+' !!!" << endl; 
    }
    else if (mode == "r+"){
        MyFile.open(this->name+".txt", ios::in | ios::out);
        if (!MyFile) {
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r+' !!!" << endl; 
    }
    else{
        throw "error !!! mode should be : r/w/w+/r+";
    }
}

//destructeur
fichierClass::~fichierClass(){

    if (MyFile.is_open()){
        MyFile.close();
    }
    delete[] fp;
}


//setters
void fichierClass:: set_name(string new_name){
    
    this->name = new_name;
    //vérifier si le fichier est ouvert
    if (MyFile.is_open()){
        //fermer
        MyFile.close();
    }

    //verifier le mode du fichier
    if (mode == "w") {
        MyFile.open(this->name + ".txt", ios::out);
        cout << this->name + ".txt opened in mode 'w' !!!" << endl;
    }
    else if (mode == "r") {
        MyFile.open(this->name + ".txt", ios::in);
        if (!MyFile) {
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r' !!!" << endl;
    }
    else if (mode == "w+") {
        MyFile.open(this->name + ".txt", ios::in | ios::out | ios::trunc);
        cout << this->name + ".txt opened in mode 'w+' !!!" << endl;
    }
    else if (mode == "r+") {
        MyFile.open(this->name + ".txt", ios::in | ios::out);
        if (!MyFile) {
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r+' !!!" << endl;
    }
    else {
        throw "error !!! mode should be : r/w/w+/r+";
    }      
}
void fichierClass:: set_mode(string new_mode){
    
    this->mode = new_mode;
    // fermer le fichier s'il est ouvert !!
    if (MyFile.is_open()) {
        MyFile.close();
    }

    //reouvrir le fichier selon le mode
    if (mode == "w") {
        MyFile.open(this->name + ".txt", ios::out);
        cout << this->name + ".txt opened in mode 'w' !!!" << endl;
    }
    else if (mode == "r") {
        MyFile.open(this->name + ".txt", ios::in);
        if (!MyFile) {
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r' !!!" << endl;
    }
    else if (mode == "w+") {
        MyFile.open(this->name + ".txt", ios::in | ios::out | ios::trunc);
        cout << this->name + ".txt opened in mode 'w+' !!!" << endl;
    }
    else if (mode == "r+") {
        MyFile.open(this->name + ".txt", ios::in | ios::out);
        if (!MyFile) {
            throw "error !!! file doesn't exist !!!";
        }
        cout << this->name + ".txt opened in mode 'r+' !!!" << endl;
    }
    else {
        throw "error !!! mode should be : r/w/w+/r+";
    }
}
void fichierClass:: set_fp(const char* new_fp){
    delete[] this->fp;
    this->fp = new char[strlen(new_fp) + 1 ];
    strcpy(this->fp,new_fp);
}
void fichierClass:: set_size_len(int new_size){
    this->size_len = new_size;
}

//getters
string fichierClass:: get_name(){

    return this->name;
}
string fichierClass:: get_mode(){
    
    return this->mode;
}
char* fichierClass:: get_fp(){
    
    return this->fp;
}
int fichierClass:: get_size_len(){
    
    return this->size_len;
}

//insertion d'une ligne
void fichierClass::insert_line() {

    if (mode == "w+" || mode == "w" || mode == "r+") {
        string input;
        cout << "Enter a line of text (exactly " << size_len << " characters): ";
        
        getline(cin, input); 

        if (input.length() > size_len) {
            throw "Error !!! The entered line must be exactly " + to_string(size_len) + " characters long.";
        }

        // ecriture dans le fichier
        MyFile << input << endl;
        cout << "Line added to the file successfully!" << endl;
    }
    else {
        throw "Error !!! we don't add a line of text to files of 'r' mode !!";
    }
}

//ecriture de multiple lignes dans le fichier
void fichierClass :: write_file(){

    if (mode == "w+" || mode == "w" || mode == "r+") {
    
        string input;
        while (true){

            cout << "Enter a line of text (exactly " << size_len << " characters): ";
            getline(cin, input);
            if (input.empty()){
                cout << "End !!" << endl;
                return; //break 
            }
            if (input.length() > size_len) {
                throw "Error !!! The entered line must be exactly " + to_string(size_len) + " characters long.";
            }
            // ecriture dans le fichier
            MyFile << input << endl;
        }
            
    }
    else {
        throw "Error !!! we don't add lines of text to files of 'r' mode !!";
    }
}

//lecture d'une ligne
void fichierClass:: read_line(){

    if (mode == "r" || mode == "r+"){
        if (MyFile.is_open()){

            if (MyFile.eof()){
                cout << "End of file !!" << endl;
                return ;
            }
            string line;
            getline(MyFile, line);
            cout << "Read line: " << line << endl;
        }
        else{
            throw "Error !! file not opened !!";
        }
    }
    else{
        throw "Error !! file must be of mode 'r'/'r+'/'w+'";
    }
}

//lecture d'une fichier
void fichierClass:: display_file_content(){

    if (mode == "r" || mode == "r+"){
        if (MyFile.is_open()){

            if (MyFile.eof()){
                cout << "End of file !!" << endl;
                return ;
            }

            MyFile.clear();
            MyFile.seekg(0, std::ios::beg);
            string line;
            while(!MyFile.eof()){
                getline(MyFile, line);
                cout << "Read line: " << line << endl;
            }

        }
        else{
            throw "Error !! file not opened !!";
        }
    }
    else{
        throw "Error !! file must be of mode 'r'/'r+'/'w+'";
    }
}

//constructeur par recopie
fichierClass :: fichierClass(const fichierClass &file){

    this->name = file.name;
    this->mode = file.mode;
    this->fp = new char[strlen(file.fp) + 1];
    strcpy(fp,file.fp);
    this->size_len = file.size_len;
}

//surdéfinition d'opérateur + 
fichierClass fichierClass ::  operator + (fichierClass &file){

    cout << "Combining files with + operator ... " << endl;
    //nouveu nom du fichier
    string new_name;
    cout << "Enter the name of the new file: ";
    cin >> new_name;
    //clean buffer
    cin.ignore();
    
    int max_size = max(this->size_len, file.size_len);
    
    //appel au constructeur
    fichierClass plusFile(new_name, "w", this->fp, max_size);
    
    //ajout des lignes des fichiers reliées aux objets (*this et file)
    ifstream in1(this->name+".txt");
    ifstream in2(file.name+".txt");
    if (!in1.is_open() || !in2.is_open()) {
        throw "Error: One or both files could not be opened!";
    }
    string line;
    while(!in1.eof()){
        getline(in1, line);
        // ecriture dans le fichier
        plusFile.MyFile << line << endl;
    }
    while(!in2.eof()){
        getline(in2, line);
        // ecriture dans le fichier
        plusFile.MyFile << line << endl;
    }
    in1.close();
    in2.close();

    //retourner l'objet concatainé
    return plusFile;
}