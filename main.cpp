#include <iostream>
#include "FixedRecord.h"
using namespace std;

void test_fixed_record() {
    FixedRecord data("test.bin", FixedRecord::MOVE_THE_LAST);
    //data.addRecord(StudentA{"A", "Estebas","Edu", "cs",5,120});
    /*vector<StudentA> records = data.loadRecords();
    for (auto record : records) {
        cout << record.name << endl;
    }*/
}

int main() {
    test_fixed_record();
    return 0;
}
