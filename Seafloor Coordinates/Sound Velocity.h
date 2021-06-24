#pragma once
#define _AFXDLL
#include <iostream>
#include <fstream>
#include<sstream>
#include <afx.h>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include <Eigen>

using namespace std;
using namespace Eigen;

#define rad atan(1.) * 4 / 180


void Save_Sound_Velocity(map<int, double>& Sound_Velocity);

void Coordinate(map<int, double>& Sound_Velocity);