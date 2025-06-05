#include "fichierClass.hpp"


int main() {
    
    //try-catch block
    try {

        // Open file in write mode
        fichierClass file1("filename", "w", "metadata", 30);
        file1.write_file();

        // Open file in read mode
        fichierClass file2("exemple", "r", "metadata", 25);
        file2.read_line();

        // Create a combined file in write mode
        fichierClass combinedFile = file1 + file2;
        combinedFile.insert_line();
        combinedFile.set_mode("r");
        combinedFile.display_file_content();

    } 
    catch (const char* e) {
        cerr << "Exception: " << e << endl;
        return 0;
    }

    

    return 0; 
}