//
//  main.cpp
//  algrithem
//
//  Created by Apple on 2018/10/12.
//  Copyright © 2018年 Apple. All rights reserved.
//

#include <iostream>
#include "BinarySearch.h"
#include "ChessBoard.h"
#include "MatrixMutiply.h"
#include "MaxSubString.h"
#include "MaxSum.h"
#include "PolygonGame.h"
#include "MergeSort.h"
#include"QuickSort.h"
#include "Knapsack.h"
#include"Agenda.h"
using namespace std;

int main(int argc, const char * argv[]) {

    int n=7;
    Agenda a=*new Agenda(n);
    a.Output();
    
    return 0;
}
