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
    /*istream& operator>>(istream& in, StudentA& record) override;
    ostream& operator<<(ostream& out, StudentA& record) override;*/
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
    out << endl << flush;
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
    while (file >> student) {
        records.push_back(student);
    }
    return records;
}

inline void FixedRecord::addRecord(StudentA record) {
    ifstream file(this->filename, ios::app | ios::binary);
    if (!file.is_open()) {
        cerr << "File " << this->filename << " could not be opened" << endl;
    }
    file.seekg(0, ios::end);
    file >> record;
    file.close();
    cout << "Record successfully added" << endl;
}

inline StudentA FixedRecord::readRecord(const int position) {
    StudentA record{};
    ifstream file(this->filename, ios::binary);
    if (!file.is_open()) {
        cerr << "File " << this->filename << " could not be opened" << endl;
    }
    file.seekg(position, ios::beg);
    file >> record;
    file.close();
    return record;
}

inline bool FixedRecord::deleteRecord(const int position) {
    // MOVE_THE_LAST
    StudentA record{};
    ofstream file(this->filename, ios::ate | ios::binary);
    file.seekg(-sizeof(StudentA),ios::end);
    file.put
    file >> record;
    file.seekg(position, ios::beg);
    file << record;
    file.close();
    return true;
}
#endif //FIXEDRECORD_H
