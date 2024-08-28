

#ifndef UNTITLED5_VARIABLERECORD_H
#define UNTITLED5_VARIABLERECORD_H

#include "headers.h"
#include "Modelos.h"

using namespace std;
class VariableRecord {
private:
    string fileName;
    const char fieldDelim = '|';
    const char recordDelim = '\n';

    bool fileExists() const {
        ifstream dataFile(fileName);
        return dataFile.good();
    }

    void initializeFile() const {
        ofstream dataFile(fileName);
        dataFile << "Nombre" << fieldDelim
                 << "Apellidos" << fieldDelim
                 << "Carrera" << fieldDelim
                 << "Mensualidad" << recordDelim;
    }

    void skipFirstLine(ifstream &file) const {
        file.ignore(numeric_limits<streamsize>::max(), recordDelim);
    }

public:
    explicit VariableRecord(string fileName) : fileName(move(fileName)) {
        if (!fileExists()) {
            initializeFile();
        }
    }

    vector<Alumno> load() const {
        vector<Alumno> records;
        ifstream dataFile(fileName);

        if (!dataFile.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + fileName);
        }

        skipFirstLine(dataFile);

        string line;
        while (getline(dataFile, line)) {
            Alumno record;
            size_t pos = 0;
            size_t nextPos;

            nextPos = line.find(fieldDelim, pos);
            record.Nombre = line.substr(pos, nextPos - pos);

            pos = nextPos + 1;
            nextPos = line.find(fieldDelim, pos);
            record.Apellidos = line.substr(pos, nextPos - pos);

            pos = nextPos + 1;
            nextPos = line.find(fieldDelim, pos);
            record.Carrera = line.substr(pos, nextPos - pos);

            pos = nextPos + 1;
            record.mensualidad = stof(line.substr(pos));

            records.push_back(record);
        }

        return records;
    }

    void add(const Alumno &record) const {
        ofstream dataFile(fileName, ios::app);

        if (!dataFile.is_open()) {
            throw runtime_error("No se pudo abrir el archivo");
        }

        dataFile << record.Nombre << fieldDelim
                 << record.Apellidos << fieldDelim
                 << record.Carrera << fieldDelim
                 << record.mensualidad << recordDelim;
    }

    Alumno readRecord(int pos) const {
        ifstream dataFile(fileName);

        if (!dataFile.is_open()) {
            throw runtime_error("No se pudo abrir el archivo");
        }

        skipFirstLine(dataFile);

        string line;
        int currentPos = 0;

        while (getline(dataFile, line)) {
            if (currentPos == pos) {
                Alumno record;
                size_t pos = 0;
                size_t nextPos;

                nextPos = line.find(fieldDelim, pos);
                record.Nombre = line.substr(pos, nextPos - pos);

                pos = nextPos + 1;
                nextPos = line.find(fieldDelim, pos);
                record.Apellidos = line.substr(pos, nextPos - pos);

                pos = nextPos + 1;
                nextPos = line.find(fieldDelim, pos);
                record.Carrera = line.substr(pos, nextPos - pos);

                pos = nextPos + 1;
                record.mensualidad = stof(line.substr(pos));

                return record;
            }
            ++currentPos;
        }

        throw out_of_range("Posición fuera de rango");
    }

    void clearAll() const {
        ofstream dataFile(fileName, ios::trunc);

        if (!dataFile.is_open()) {
            throw runtime_error("No se pudo abrir el archivo: " + fileName);
        }

        initializeFile();
    }
};


#endif //UNTITLED5_VARIABLERECORD_H
