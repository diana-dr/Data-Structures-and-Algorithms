#include "TestP2.h"
#include "P2.h"
#include <vector>
#include <algorithm>
#include <assert.h>
#include <iostream>

using namespace std;

bool lessThanRelation(TElem e1, TElem e2) {
    return e1 <= e2;
}

bool greaterThanRelation(TElem e1, TElem e2) {
    return e1 >= e2;
}

bool lessThanLastDigit(TElem e1, TElem e2) {
    return e1 % 10 <= e2 % 10;
}

bool lessThanRelationS(TElem e1, TElem e2) {
    return e1 < e2;
}

bool greaterThanRelationS(TElem e1, TElem e2) {
    return e1 > e2;
}

bool lessThanLastDigitS(TElem e1, TElem e2) {
    return e1 % 10 < e2 % 10;
}

void testRelShort(Relation rel, Relation relS) {
    vector<vector<TElem>> input;
    for (int i = 0; i < 5; i++) {
        vector<TElem> v1;
        for (int j = 0; j < 20; j++) {
            v1.push_back(rand() % 100);
        }
        sort(v1.begin(), v1.end(), relS);
        input.push_back(v1);
    }
    vector<TElem> empty;;
    input.push_back(empty);

    vector<TElem> res = mergeVectors(input, rel);
    assert(res.size() == 100);
    for (int i = 0; i < res.size() - 1; i++) {
        assert(rel(res[i], res[i + 1]));
    }
}

void testRelLong(Relation rel, Relation relS) {
    vector<vector<TElem>> input;
    for (int i = 0; i < 50; i++) {
        vector<TElem> v1;
        for (int j = 0; j < 2000; j++) {
            v1.push_back(rand() % 10000);
        }
        sort(v1.begin(), v1.end(), relS);
        input.push_back(v1);
    }
    vector<TElem> empty;;
    input.push_back(empty);

    vector<TElem> res = mergeVectors(input, rel);
    assert(res.size() == 100000);
    for (int i = 0; i < res.size() - 1; i++) {
        assert(rel(res[i], res[i + 1]));
    }
}

void testP1() {

    testRelShort(lessThanRelation, lessThanRelationS);
    cout << "Short test, rel 1" << endl;
    //testRelShort(greaterThanRelation, greaterThanRelationS);
    cout << "Short test, rel 2" << endl;
    //testRelShort(lessThanLastDigit, lessThanLastDigitS);
    cout << "Short test, rel 3" << endl;
    //testRelLong(lessThanRelation, lessThanRelationS);
    cout << "Long test, rel 1" << endl;
    testRelLong(greaterThanRelation, greaterThanRelationS);
    cout << "Long test, rel 2" << endl;
    //testRelLong(lessThanLastDigit, lessThanLastDigitS);
    cout << "Long test, rel 3" << endl;

}
