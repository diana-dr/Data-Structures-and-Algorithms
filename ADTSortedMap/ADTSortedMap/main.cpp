//
//  main.cpp
//  ADTSortedMap
//
//  Created by Diana Dragos on 19/05/2019.
//  Copyright © 2019 Diana Dragos. All rights reserved.
//

#include <iostream>
#include "ShortTest.hpp"
#include "ExtendedTest.hpp"
#include "SortedMap.hpp"

bool relatie(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

using namespace std;

int main(int argc, const char * argv[]) {
    
        SortedMap sm(relatie);
        sm.add(5, 2);
        sm.add(18, 3);
        sm.add(16, 4);
        sm.add(15, 3);
        sm.add(13, 3);
        sm.add(31, 3);
        sm.add(26, 3);
    
    std::vector<TKey> vector;
    vector = sm.keySet();
    for( auto i: vector)
        cout << i << endl;
    
     testAll();
     //testAllExtended();
//    SortedMap sm(relatie);
//    sm.add(5, 2);
//    sm.add(18, 3);
//    sm.add(16, 4);
//    sm.add(15, 3);
//    sm.add(13, 3);
//    sm.add(31, 3);
//    sm.add(26, 3);
//
//    SMIterator it = sm.iterator();
//    for (int i = 0; i < sm.numberOfElements; i++)
//        cout << it.sortedArray[i].first << endl;
    
//    it.first();
//    if (it.valid()) {
//        TKey cPrec = it.getCurrent().first;
//        assert(sm.search(cPrec) != NULL_TVALUE);
//        it.next();
//        while (it.valid()) {
//            TKey c = it.getCurrent().first;
//            cout << cPrec << " " << c << endl;
//            cPrec = c;
//            it.next();
//        }
    //}
}
