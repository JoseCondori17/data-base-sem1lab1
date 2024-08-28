#ifndef FIXEDRECORD_H
#define FIXEDRECORD_H
#include <vector>
#include "Models.h"
#include "Record.h"
#include <fstream>

class FixedRecord final : public Record<StudentA> {
public:
    enum type { MOVE_THE_LAST, FREE_LIST };
    explicit FixedRecord(const string &filename, type mode = MOVE_THE_LAST);
    vector<StudentA> loadRecords() override;
    void addRecord(StudentA record) override;
    StudentA readRecord(int position) override;
    bool deleteRecord(int position) override;
    ~FixedRecord() override = default;
private:
    type mode;
    string filename;
};

inline istream &operator>>(istream &in, StudentA &record) {
    in.read(reinterpret_cast<char*>(&record), sizeof(StudentA));
    return in;
}
inline ostream &operator<<(ostream &out, const StudentA &record) {
    out.write(reinterpret_cast<const char*>(&record), sizeof(StudentA));
    return out;
}

inline FixedRecord::FixedRecord(const string &filename, const type mode) {
    this->filename = filename;
    this->mode = mode;
}

inline vector<StudentA> FixedRecord::loadRecords() {
    vector<StudentA> records = {};
    ifstream file(this->filename, ios::binary);
    if (!file.is_open()) {
        cerr << "File " << this->filename << " could not be opened" << endl;
        return records;
    }
    StudentA student{};
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    file.seekg(sizeof(int), ios::beg);
    int i = 0;
    while (file >> student && i < size) {
        records.push_back(student);
        ++i;
    }
    return records;
}

inline void FixedRecord::addRecord(StudentA record) {
    ifstream readFile(this->filename, ios::in | ios::binary);
    if (!readFile.is_open()) {
        ofstream writeFile(this->filename, ios::out | ios::binary);
        int size = 1;
        writeFile.write(reinterpret_cast<const char*>(&size), sizeof(int));
        writeFile << record;
        writeFile.close();
        cout << size << " records written" << endl;
    } else {
        int size;
        readFile.read(reinterpret_cast<char*>(&size), sizeof(int));
        size += 1;
        readFile.close();

        ofstream writeFile(this->filename, ios::out | ios::in | ios::binary);
        writeFile.seekp(0, ios::beg);
        writeFile.write(reinterpret_cast<const char*>(&size), sizeof(int));
        writeFile.seekp(0, ios::end);
        writeFile << record;
        writeFile.close();
        cout << size << " records written" << endl;
    }
}

inline StudentA FixedRecord::readRecord(const int position) {
    StudentA record{};
    ifstream file(this->filename, ios::binary);
    if (!file.is_open()) cerr << "File " << this->filename << " could not be opened" << endl;
    file.seekg(0, ios::beg);
    file.seekg((sizeof(StudentA) * position) + sizeof(int));
    file >> record;
    file.close();
    return record;
}

inline bool FixedRecord::deleteRecord(const int position) {
    ifstream readFile(this->filename, ios::binary);
    if (mode == MOVE_THE_LAST) {
        StudentA record{};
        int size;
        readFile.seekg(0, ios::end); // final
        readFile >> record; // llenamos los valores
        readFile.seekg(0, ios::beg);
        readFile.read(reinterpret_cast<char*>(&size), sizeof(int));
        size -= 1;
        readFile.close();
        ofstream writeFile(this->filename, ios::out | ios::in | ios::binary);
        writeFile.seekp(0, ios::beg);
        writeFile.write(reinterpret_cast<const char*>(&size), sizeof(int));
        writeFile.seekp((sizeof(StudentA)*position)+sizeof(int), ios::beg);
        writeFile << record;
        writeFile.close();
    }
    else if (mode == FREE_LIST) {
        // FIFO
        //LIFO
    }
    return true;
}
#endif //FIXEDRECORD_H
