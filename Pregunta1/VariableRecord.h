#ifndef VARIABLERECORD_H
#define VARIABLERECORD_H
#include "Models.h"
#include "Record.h"
class VariableRecord final : public Record<StudentB> {
    enum type { MOVE_THE_LAST, FREE_LIST };
public:
    explicit VariableRecord(string filename, type mode = MOVE_THE_LAST);
    vector<StudentB> loadRecords() override;
    void addRecord(StudentB record) override;
    StudentB readRecord(int position) override;
    bool deleteRecord(int position) override;
private:
    type mode;
    string filename;
};
#endif //VARIABLERECORD_H
