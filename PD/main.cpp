#include "header.h"

int main() {
    instance mConflict;
    reading(mConflict);

    //heuristic construtive sol inicial

    solution sonIni = makeSolIni(mConflict);


    cout << "fin...\n";
    cin.get();
    return 1;
}