#ifndef INCLUDED_DISTANCES_H_
#define INCLUDED_DISTANCES_H_

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

double computeCoordinatePart(size_t deg, size_t min, size_t sec);
double computeDifference(double coordPart1, double coordPart2);
void correct(double &coordPart, char hem);
void correct(double &difference, double coordPart);
double getCoordinatePart();
string getDistance(double difference);
void usage(string const &programName);

#endif