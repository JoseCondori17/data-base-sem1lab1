#include "headers.h"
#include "VariableRecord.h"

int main() {
    VariableRecord file("archivo.txt");

    file.add(Alumno("Howard", "Paredes Zegarra", "Computacion", 1500.0));
    file.add(Alumno("Penny", "Vargas Cordero", "Industrial", 1800.0));
    file.add(Alumno("Sheldon", "Cooper Quizpe", "Mecatronica", 1300.0));

    cout << "Carga de datos del archivo: " << endl;
    vector<Alumno> records_loaded = file.load();

    for (const auto &record : records_loaded) {
        record.showDataLine();
    }

    cout << endl;
    cout << "Buscar por posicion en el archivo: " << endl;
    int pos = 0;
    cout << "Record a leer pos " << pos << ":" << endl;
    Alumno alumno = file.readRecord(pos);
    alumno.showDataLine();

    cout << endl;
    cout << "Limpiar el archivo de todos los registros..." << endl;
    file.clearAll();

    cout << "Carga de datos después de limpiar el archivo: " << endl;
    records_loaded = file.load();

    if (records_loaded.empty()) {
        cout << "Archivo vacio" << endl;
    } else {
        for (const auto &record : records_loaded) {
            record.showDataLine();
        }
    }

    return 99;
}
