#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

random_device rd;
mt19937 gen(rd());

struct instance {
    map<int, set<int>> K2LL;
    map<int, set<int>> LL;
    map<int, set<pair<int, int>>> LTS;
    map<pair<int, int>, set<pair<int, int>>> TSTS;
};

struct lecture {
    int id;
    pair<int, int> TS; // pair<tipoDia, tipoBloque>

    lecture() : id(-1) {}
    lecture(int a) : id(a) {}
};

struct solution {
    int z;
    int kpi2;
    int kpi1;
    vector<lecture> vL;

    solution() : z(-1), kpi1(-1), kpi2(-1) {}
    solution(int a) : z(a), kpi1(-1), kpi2(-1) {}
};

void newFunction() {
    cout << 'X';
}
void read_Lecture_Lecture(map<int, set<int>>& data, string path) {
    ifstream input_file(path);
    string line;

    while (getline(input_file, line)) {
        stringstream line_stream(line);
        int key, value;
        set<int> row;
        line_stream >> key;
        while (line_stream >> value) {
            row.insert(value);
        }
        data[key] = row;
    }
    input_file.close();
}
void read_Lecture_TimeSlot(map<int, set<pair<int, int>>>& data, string path) {
    ifstream infile(path);
    string line;
    int key;
    string pair_str;
    int first, second;
    char separator;

    while (getline(infile, line)) {
        stringstream ss(line);
        ss >> key;
        while (ss >> first >> separator >> second) {
            data[key].insert(make_pair(first, second));
        }
    }
    infile.close();
}
void read_TimeSlot_TimeSlot(map<pair<int, int>, set<pair<int, int>>>& data, string path) {
    ifstream infile(path);
    string line;
    string pair_str;
    int ffirst, ssecond, first, second;
    char sseparator, separator;

    while (getline(infile, line)) {
        stringstream ss(line);
        ss >> ffirst >> sseparator >> ssecond;
        while (ss >> first >> separator >> second) {
            data[make_pair(ffirst, ssecond)].insert(make_pair(first, second));
        }
    }
    infile.close();
}

void reading(instance& mConflict) {
    string pathConflictK2LL = "C:\\Users\\vidal\\OneDrive - PUJ Cali\\9 SEMESTRE\\PD II\\c++\\material\\datos_map\\K2_LECTUREvsLECTURE.txt";
    string pathConflictLL = "C:\\Users\\vidal\\OneDrive - PUJ Cali\\9 SEMESTRE\\PD II\\c++\\material\\datos_map\\LECTUREvsLECTURE.txt";
    string pathConflictLTS = "C:\\Users\\vidal\\OneDrive - PUJ Cali\\9 SEMESTRE\\PD II\\c++\\material\\datos_map\\LECTUREvsTS.txt";
    string pathConflictTSTS = "C:\\Users\\vidal\\OneDrive - PUJ Cali\\9 SEMESTRE\\PD II\\c++\\material\\datos_map\\TSvsTS.txt";

    read_Lecture_Lecture(mConflict.K2LL, pathConflictK2LL);
    read_Lecture_Lecture(mConflict.LL, pathConflictLL);
    read_Lecture_TimeSlot(mConflict.LTS, pathConflictLTS);
    read_TimeSlot_TimeSlot(mConflict.TSTS, pathConflictTSTS);
}

solution makeSolIni(instance& mConflict) {
    solution s(-88);
    s.z = -99;
    set<int> sL;

    lecture hola;

    for (size_t i = 0; i < 10; i++) {
        sL.insert(i + 1);
    }

    while (sL.size() != 0) {
        uniform_int_distribution<int> dist(0, sL.size() - 1);
        int aux = dist(gen);
        set<int>::iterator it = sL.begin();
        advance(it, aux);
        s.vL.push_back(lecture(*it));
        sL.erase(it);
    }

    return s;
}