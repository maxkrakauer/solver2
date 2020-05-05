
#include <complex.h>
#include <iostream>
#include <vector>
#include "string.h"
using namespace std;


namespace solver{
    
    class RealVariable{
        public:
        float _value;

        
    };

    class ComplexVariable{
        public:
         complex<double>_value;

        
        
    };

    class RealUnit{
        public:
        RealUnit(){};
        RealUnit(RealVariable var, float co, int ex){
            _variable=var;
            _coeff=co;
            _exponent=ex;
        }       
        public:
        RealVariable _variable;
        double _coeff;
        int _exponent;




        
        
    };

    class ComplexUnit{
        public:
        ComplexUnit(){}
        ComplexUnit(ComplexVariable var, complex<double> co, int ex){
            _variable=var;
            _coeff=co;
            _exponent=ex;
        }
        public:
        ComplexVariable _variable;
        int _exponent;
        complex<double> _coeff;

        //friend ComplexUnit& operator^(ComplexVariable x, int y);

        //friend RealVariable& operator+(RealUnit x, RealUnit y);

        //friend RealVariable& operator-(RealUnit x, RealUnit y);

        //friend ComplexVariable& operator-(ComplexVariable x);

        //friend ComplexVariable& operator+(ComplexVariable x);
    };


    class RealVec{
        public:
        RealVec(){
    
        };
        RealVec(vector<RealUnit> units){
            _units=units;
        }
        public:
        vector<RealUnit>_units;
        
        public:
        double quadratic(); //quardratic equations
        int equation(); 
        double linear();
        /*
        case 1: if no variable: return 0
        case 2: if linear: return 1
        case 3: if quardratic: return 2
        */
        
        friend RealVec varToRVec(RealVariable x);
        friend RealVec doubleToRVec(double x);
        friend RealVec unitToRVec(RealUnit x);

    };

    class ComplexVec{
        public:

        ComplexVec(){

        }
        ComplexVec(vector<ComplexUnit>units){
            _units=units;
           
        }
        public:
        vector<ComplexUnit>_units;

        public:
        complex<double> quadratic(); //quardratic equations
        int equation(); 
        complex<double> linear();
        
        //friend ComplexVec& operator+(ComplexVec x, ComplexVec y);

        //friend ComplexVec& operator-(ComplexVec x, ComplexVec y);

        //friend ComplexVec& operator==(ComplexVec x, ComplexVec y);

        friend ComplexVec varToCVec(ComplexVariable x);
        friend ComplexVec doubleToCVec(complex<double> x);
        friend ComplexVec unitToCVec(ComplexUnit x);

    };

    class EquationR{
        public:
        EquationR(){};
        EquationR(RealVec x){
            _vec=x;
        }
        public:
        RealVec _vec;
    };

    class EquationC{
        public:
        EquationC(){};
        EquationC(ComplexVec x){
            _vec=x;
        }
        public:
        ComplexVec _vec;
    };

   

        EquationR operator==(RealVec x, RealVec y);

        EquationC operator==(ComplexVec x, ComplexVec y);

        EquationR operator==(RealUnit x, RealVec y);

        EquationC operator==(ComplexUnit x, ComplexVec y);

        EquationR operator==(RealVec x, RealUnit y);

        EquationC operator==(ComplexVec x, ComplexUnit y);

        EquationR operator==(RealUnit x, RealUnit y);

        EquationC operator==(ComplexUnit x, ComplexUnit y);

       
        EquationR operator==(RealVec x, double y);

        EquationC operator==(ComplexVec x, complex<double>y);

        EquationR operator==(double x, RealVec y);

        EquationC operator==(complex<double>x, ComplexVec y);

        
        EquationR operator==(RealUnit x, double y);

        EquationC operator==(ComplexUnit x, complex<double>y);

        EquationR operator==(double x, RealUnit y);

        EquationC operator==(complex<double>x, ComplexUnit y);


        RealVec operator+(RealVariable x);

        ComplexVec operator+(ComplexVariable x);

        RealVec operator+(RealUnit x);

        ComplexVec operator+(ComplexUnit x);

        RealVec operator-(RealVariable x);

        ComplexVec operator-(ComplexVariable x);

        RealVec operator-(RealUnit x);

        ComplexVec operator-(ComplexUnit x);



        RealUnit operator^(RealUnit x, int y);

        ComplexUnit operator^(ComplexUnit x, int y);

        RealUnit operator^(RealVariable x, int y);

        ComplexUnit operator^(ComplexVariable x, int y);


        RealVec operator+(RealVec x, RealVec y);

        ComplexVec operator+(ComplexVec x, ComplexVec y);

        RealVec operator+(RealUnit x, RealUnit y);

        ComplexVec operator+(ComplexUnit x, ComplexUnit y);

        RealVec operator+(RealUnit x, double y);

        ComplexVec operator+(ComplexUnit x, complex<double>y);

        RealVec operator+(double x, RealUnit y);

        ComplexVec operator+(complex<double>x, ComplexUnit y);
        
        RealVec operator+(double x, RealVec y);

        ComplexVec operator+(complex<double>x, ComplexVec y);

        RealVec operator+(RealVec x, double y);

        ComplexVec operator+(ComplexVec x, complex<double>y);



        RealVec operator-(RealVec x, RealVec y);

        ComplexVec operator-(ComplexVec x, ComplexVec y);

        RealVec operator-(RealUnit x, RealUnit y);

        ComplexVec operator-(ComplexUnit x, ComplexUnit y);

        RealVec operator-(RealUnit x, double y);

        ComplexVec operator-(ComplexUnit x, complex<double>y);

        RealVec operator-(double x, RealUnit y);

        ComplexVec operator-(complex<double>x, ComplexUnit y);
        
        RealVec operator-(double x, RealVec y);

        ComplexVec operator-(complex<double>x, ComplexVec y);

        RealVec operator-(RealVec x, double y);

        ComplexVec operator-(ComplexVec x, complex<double>y);


        RealVec operator+(RealVariable x, RealVariable y);

        ComplexVec operator+(ComplexVariable x, ComplexVariable y);

        RealVec operator+(RealVariable x, RealUnit y);

        ComplexVec operator+(ComplexVariable x, ComplexUnit y);

        RealVec operator+(RealUnit x, RealVariable y);

        ComplexVec operator+(ComplexUnit x, ComplexVariable y);

        RealVec operator+(RealVec x, RealVariable y);

        ComplexVec operator+(ComplexVec x, ComplexVariable y);

        RealVec operator+(RealVariable x, RealVec y);

        ComplexVec operator+(ComplexVariable x, ComplexVec y);


        RealVec operator-(RealVariable x, RealVariable y);

        ComplexVec operator-(ComplexVariable x, ComplexVariable y);

        RealVec operator-(RealVariable x, RealUnit y);

        ComplexVec operator-(ComplexVariable x, ComplexUnit y);

        RealVec operator-(RealUnit x, RealVariable y);

        ComplexVec operator-(ComplexUnit x, ComplexVariable y);

        RealVec operator-(RealVec x, RealVariable y);

        ComplexVec operator-(ComplexVec x, ComplexVariable y);

        RealVec operator-(RealVariable x, RealVec y);

        ComplexVec operator-(ComplexVariable x, ComplexVec y);



        RealVec operator+(RealVariable x, double y);

        ComplexVec operator+(ComplexVariable x, complex<double>y);

        RealVec operator+(double x, RealVariable y);

        ComplexVec operator+(complex<double>x, ComplexVariable y);


        RealVec operator+(RealUnit x, double y);

        ComplexVec operator+(ComplexUnit x, complex<double>y);

        RealVec operator+(double x, RealUnit y);

        ComplexVec operator+(complex<double>x, ComplexUnit y);


        RealVec operator+(RealVec x, double y);

        ComplexVec operator+(ComplexVec x, complex<double>y);

        RealVec operator+(double x, RealVec y);

        ComplexVec operator+(complex<double>x, ComplexVec y);



        RealVec operator-(RealVariable x, double y);

        ComplexVec operator-(ComplexVariable x, complex<double>y);

        RealVec operator-(double x, RealVariable y);

        ComplexVec operator-(complex<double>x, ComplexVariable y);


        RealVec operator-(RealUnit x, double y);

        ComplexVec operator-(ComplexUnit x, complex<double>y);

        RealVec operator-(double x, RealUnit y);

        ComplexVec operator-(complex<double>x, ComplexUnit y);


        RealVec operator-(RealVec x, double y);

        ComplexVec operator-(ComplexVec x, complex<double>y);

        RealVec operator-(double x, RealVec y);

        ComplexVec operator-(complex<double>x, ComplexVec y);




        RealUnit operator*(double x, RealUnit y);

        ComplexUnit operator*(complex<double> x, ComplexUnit y);

        RealUnit operator*(RealUnit x, double y);

        ComplexUnit operator*(ComplexUnit x, complex<double>y);


        RealUnit operator*(RealUnit x, RealUnit y);

        ComplexUnit operator*(ComplexUnit x, ComplexUnit y);

        RealUnit operator*(double x, RealVariable y);

        ComplexUnit operator*(complex<double> x, ComplexVariable y);


        RealUnit operator/(RealUnit x, double y);

        ComplexUnit operator/(ComplexUnit x, complex<double>y);


        RealUnit operator/(RealUnit x, RealUnit y);

        ComplexUnit operator/(ComplexUnit x, ComplexUnit y);



        double solve(EquationR x);

        complex<double>solve(EquationC x);


        
        
  


};
