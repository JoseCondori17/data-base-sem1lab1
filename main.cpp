#include <iostream>
#include "FixedRecord.h"
using namespace std;

void test_fixed_record() {
    FixedRecord data("student.bin", FixedRecord::MOVE_THE_LAST);
    const vector<StudentA> records =  data.loadRecords();
    //cout << (records.size() == 5) << endl;
    data.deleteRecord(0);
}

int main() {
    test_fixed_record();
    return 0;
}
