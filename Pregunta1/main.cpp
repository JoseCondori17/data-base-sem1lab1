#include <iostream>
#include "FixedRecord.h"
using namespace std;

void test_fixed_record() {
    FixedRecord data("test.bin", FixedRecord::MOVE_THE_LAST);
    //data.addRecord(StudentA{"A", "Esteban","Edu", "cs",5,120});
    vector<StudentA> records = data.loadRecords();
    //data.deleteRecord(3);
    for (auto record : records) {
        cout << record.name << endl;
    }
    /*StudentA student = data.readRecord(3);
    cout << student.name << endl;*/
}

int main() {
    test_fixed_record();
    return 0;
}
