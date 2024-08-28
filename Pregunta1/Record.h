#ifndef RECORD_H
#define RECORD_H
#include <vector>
using namespace std;

template <typename T>
class Record {
public:
    virtual ~Record() = default;
    virtual vector<T> loadRecords() = 0;
    virtual void addRecord(T record) = 0;
    virtual T readRecord(int position) = 0;
    virtual bool deleteRecord(int position) = 0;
    /*virtual istream& operator>>(istream& in, T& record) = 0;
    virtual ostream& operator<<(ostream& out, T& record) = 0;*/
};
#endif //RECORD_H
