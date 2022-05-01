#ifndef INPUT_H
#define INPUT_H
#include <fstream>

using namespace std;

namespace global_files {
    // Declaration des fichiers d'entree et sortie
    extern ifstream ifs;
    extern ofstream ofs;
}

namespace global_func {
    // Declaration de la fonction de recuperation de l'entree
    string ask4UInput(const string & invite="", const bool & putInOutput=true);
}
#endif // INPUT_H
