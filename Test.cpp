#include "doctest.h"
#include "solver.hpp"
#include <string>
#include <string.h>
using namespace std;
#include <iostream>
#include <complex>
using solver::solve, solver::RealVariable, solver::ComplexVariable;

TEST_CASE(""){
   
   RealVariable x;

   CHECK(to_string(solve(2*x==2))==string("1.000000"));
   CHECK(to_string(solve((x^2)==16))==string("4.000000"));
   CHECK(to_string(solve((x^2)+2*x==3))==string("1.000000"));


   

   

}