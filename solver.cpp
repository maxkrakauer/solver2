#include "solver.hpp"

using solver::RealVariable, solver::ComplexVariable,
solver::solve, solver::RealUnit, solver::ComplexUnit, 
solver::RealVec, solver::ComplexVec, solver::EquationC, solver::EquationR;
//using namespace std;

double _a,_b,_c;
complex<double>_coma, _comb, _comc;



        struct oops : std::exception {
            string what()  noexcept 
            {
                printf("throwing oops\n");
                return "no solution";}
            };



        RealVec solver::doubleToRVec(double x){
            RealVariable y;
            RealUnit unit (y,x,0);
            vector<RealUnit>units;
            units.push_back(unit);
            RealVec r(units);
            return r;
        }

        RealVec solver::varToRVec(RealVariable x){
            RealUnit unit(x,1,1);
            vector<RealUnit>units;
            units.push_back(unit);
            RealVec r(units);
            return r;
        }



         ComplexVec solver::varToCVec(ComplexVariable y){
            ComplexUnit unit (y,1,1);
            vector<ComplexUnit>units;
            units.push_back(unit);
            ComplexVec c(units);
            return c;
         }

         ComplexVec solver::doubleToCVec(complex<double> x){
            ComplexVariable y;
            ComplexUnit unit(y,x,0);
            vector<ComplexUnit>units;
            units.push_back(unit);
            ComplexVec c(units);
            return c;
         }

         RealVec solver::unitToRVec(RealUnit x){
             vector<RealUnit>units;
             units.push_back(x);
             RealVec r(units);
             return r;
         }

         ComplexVec solver::unitToCVec(ComplexUnit x){
             vector<ComplexUnit>units;
             units.push_back(x);
             ComplexVec c(units);
             return c;
         }


        RealVec solver::operator+(RealVec x, RealVec y){
            vector<RealUnit>units;
            for(int i=0; i<3; i++){
                RealUnit unit;
                unit._exponent=-1;
                unit._coeff=0;
                for(RealUnit r:x._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                for(RealUnit r:y._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                if(unit._exponent>-1){
                    units.push_back(unit);
                }
            }
            RealVec r(units);
            return r;
        }

        RealVec solver::operator-(RealVec x, RealVec y){
            vector<RealUnit>units;
            for(int i=0; i<3; i++){
                RealUnit unit;
                unit._exponent=-1;
                unit._coeff=0;
                for(RealUnit r:x._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                for(RealUnit r:y._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff-=r._coeff;
                    }
                }
                if(unit._exponent>-1){
                    units.push_back(unit);
                }
            }
            RealVec r(units);
            return r;
        }


        ComplexVec solver::operator+(ComplexVec x, ComplexVec y){
            vector<ComplexUnit>units;
            for(int i=0; i<3; i++){
                ComplexUnit unit;
                unit._exponent=-1;
                unit._coeff=0;
                for(ComplexUnit r:x._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                for(ComplexUnit r:y._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                if(unit._exponent>-1){
                    units.push_back(unit);
                }
            }
            ComplexVec c(units);
            return c;
        }

        ComplexVec solver::operator-(ComplexVec x, ComplexVec y){
            vector<ComplexUnit>units;
            for(int i=0; i<3; i++){
                ComplexUnit unit;
                unit._exponent=-1;
                unit._coeff=0;
                for(ComplexUnit r:x._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff+=r._coeff;
                    }
                }
                for(ComplexUnit r:y._units){
                    if(r._exponent==i){
                        unit._exponent=i;
                        unit._coeff-=r._coeff;
                    }
                }
                if(unit._exponent>-1){
                    units.push_back(unit);
                }
            }
            ComplexVec c(units);
            return c;
        }









        EquationR solver::operator==(RealVec x, RealVec y){
            RealVec r = x-y;
            EquationR e(r);
            return e;
        }

        EquationC solver::operator==(ComplexVec x, ComplexVec y){
            ComplexVec c = x-y;
            EquationC e(c);
            return e;
        }

        EquationR solver::operator==(RealUnit x, RealVec y){
            RealVec rx=unitToRVec(x);
            EquationR e(rx-y);
            return e;
        }

        EquationC solver::operator==(ComplexUnit x, ComplexVec y){
            ComplexVec cx=unitToCVec(x);
            EquationC e(cx-y);
            return e;
        }

        EquationR solver::operator==(RealVec x, RealUnit y){
            RealVec r = unitToRVec(y);
            EquationR e(x-r);
            return e;
        }

        EquationC solver::operator==(ComplexVec x, ComplexUnit y){
            ComplexVec c = unitToCVec(y);
            EquationC e(x-c);
            return e;
        }

        EquationR solver::operator==(RealUnit x, RealUnit y){
            RealVec rx=unitToRVec(x);
            RealVec ry=unitToRVec(y);
            EquationR e(rx-ry);
            return e;
        }

        EquationC solver::operator==(ComplexUnit x, ComplexUnit y){
            ComplexVec cx=unitToCVec(x);
            ComplexVec cy=unitToCVec(y);
            EquationC e(cx-cy);
            return e;
        }

       
        EquationR solver::operator==(RealVec x, double y){
            printf("start of EquationR solver::operator==(RealVec x, double y)");
            RealVec ry=doubleToRVec(y);
            EquationR e(x-ry);
            return e;
        }



        EquationC solver::operator==(ComplexVec x, complex<double>y){
            ComplexVec c=doubleToCVec(y);
            EquationC e(x-c);
            return e;
        }

        EquationR solver::operator==(double x, RealVec y){
            RealVec r=doubleToRVec(x);
            EquationR e(r-y);
            return e;
        }

        EquationC solver::operator==(complex<double>x, ComplexVec y){
            ComplexVec c=doubleToCVec(x);
            EquationC e(c-y);
            return e;
        }

        
        EquationR solver::operator==(RealUnit x, double y){
            RealVec rx=unitToRVec(x);
            RealVec ry=doubleToRVec(y);
            EquationR e(rx-ry);
            return e;        
        }

        EquationC solver::operator==(ComplexUnit x, complex<double>y){
            ComplexVec cx=unitToCVec(x);
            ComplexVec cy=doubleToCVec(y);
            EquationC e(cx-cy);
            return e;
        }

        EquationR solver::operator==(double x, RealUnit y){
            RealVec rx=doubleToRVec(x);
            RealVec ry=unitToRVec(y);
            EquationR e(rx-ry);
            return e;
        }

        EquationC solver::operator==(complex<double>x, ComplexUnit y){
            ComplexVec cx=doubleToCVec(x);
            ComplexVec cy=unitToCVec(y);
            EquationC e(cx-cy);
            return e;
        }


        RealVec solver::operator+(RealVariable x){
            RealVec r=varToRVec(x);
            return r;
        }

        ComplexVec solver::operator+(ComplexVariable x){
            ComplexVec c=varToCVec(x);
            return c;
        }

        RealVec solver::operator-(RealVariable x){
            RealVec r=varToRVec(x);
            return r;
        }

        ComplexVec solver::operator-(ComplexVariable x){
            ComplexVec c=varToCVec(x);
            return c;
        }

        RealVec solver::operator-(RealUnit x){
            x._coeff=-x._coeff;
            RealVec r=unitToRVec(x);
            return r;
        }

        ComplexVec solver::operator-(ComplexUnit x){
            x._coeff=-x._coeff;
            ComplexVec c=unitToCVec(x);
            return c;
        }

        RealUnit solver::operator^(RealUnit x, int y){
            x._exponent=x._exponent*y;
            x._coeff=pow(x._coeff,y);
            return x;
        }

        ComplexUnit solver::operator^(ComplexUnit x, int y){
             x._exponent=x._exponent*y;
            x._coeff=pow(x._coeff,y);
            return x;
        }

        
        RealUnit solver::operator^(RealVariable x, int y){
            RealUnit r(x,1,y);
            return r;
        }

        ComplexUnit solver::operator^(ComplexVariable x, int y){
            ComplexUnit c(x,1,y);
            return c;
        }

      
        RealVec solver::operator+(RealUnit x, RealUnit y){
            vector<RealUnit>units;
            units.push_back(x);
            units.push_back(y);
            RealVec r(units);
            return r;
        }

        ComplexVec solver::operator+(ComplexUnit x, ComplexUnit y){
            vector<ComplexUnit>units;
            units.push_back(x);
            units.push_back(y);
            ComplexVec c(units);
            return c;
        }

        RealVec solver::operator+(RealUnit x, double y){
            RealUnit ry(x._variable,y,0);
            return x+ry;
        }

        ComplexVec solver::operator+(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,y,0);
            return x+c;
        }

        RealVec solver::operator+(double x, RealUnit y){
            RealUnit r(y._variable,x,0);
            return r+y;
        }

        ComplexVec solver::operator+(complex<double>x, ComplexUnit y){
            ComplexUnit c(y._variable,x,0);
            return c+y;
        }
        
        RealVec solver::operator+(double x, RealVec y){
            RealVec r=doubleToRVec(x);
            return r+y;
        }

        ComplexVec solver::operator+(complex<double>x, ComplexVec y){
            ComplexVec c=doubleToCVec(x);
            return c+y;
        }

        RealVec solver::operator+(RealVec x, double y){
            RealVec r=doubleToRVec(y);
            return x+r;
        }

        ComplexVec solver::operator+(ComplexVec x, complex<double>y){
            ComplexVec c=doubleToCVec(y);
            return x+c;
        }


        RealVec solver::operator-(RealUnit x, RealUnit y){
            RealVec rx=unitToRVec(x);
            RealVec ry=unitToRVec(y);
            return rx-ry;
        }

        ComplexVec solver::operator-(ComplexUnit x, ComplexUnit y){
            ComplexVec cx=unitToCVec(x);
            ComplexVec cy=unitToCVec(y);
            return cx-cy;
        }

        RealVec solver::operator-(RealUnit x, double y){
            printf("start of RealVec solver::operator-(RealUnit x, double y)\n");
            RealUnit r(x._variable,y,0);
            return x-r;
        }

        ComplexVec solver::operator-(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,y,0);
            return x-c;
        }

        RealVec solver::operator-(double x, RealUnit y){
            RealUnit r(y._variable,x,0);
            return r-y;
        }

        ComplexVec solver::operator-(complex<double>x, ComplexUnit y){
            ComplexUnit c(y._variable,x,0);
            return c-y;
        }
        
        RealVec solver::operator-(double x, RealVec y){
            RealVec r=doubleToRVec(x);
            return r-y;
        }

        ComplexVec solver::operator-(complex<double>x, ComplexVec y){
            ComplexVec c=doubleToCVec(x);
            return c-y;
        }

        RealVec solver::operator-(RealVec x, double y){
            RealVec r=doubleToRVec(y);
            return x-r;
        }

        ComplexVec solver::operator-(ComplexVec x, complex<double>y){
            ComplexVec c=doubleToCVec(y);
            return x-c;
        }

        RealUnit solver::operator*(double x, RealUnit y){
            RealUnit r(y._variable,x*y._coeff,y._exponent);
            return r;
        }

        ComplexUnit solver::operator*(complex<double> x, ComplexUnit y){
            ComplexUnit c(y._variable,x*y._coeff,y._exponent);
            return c;
        }

        RealUnit solver::operator*(RealUnit x, double y){
            RealUnit r(x._variable,y*x._coeff,x._exponent);
            return r;
        }

        ComplexUnit solver::operator*(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,y*x._coeff,x._exponent);
            return c;
        }


        RealUnit solver::operator*(RealUnit x, RealUnit y){
            RealUnit r(x._variable,x._coeff*y._coeff,y._exponent+x._exponent);
            return r;
        }

        ComplexUnit solver::operator*(ComplexUnit x, ComplexUnit y){
            ComplexUnit c(x._variable,x._coeff*y._coeff,y._exponent+x._exponent);
            return c;
        }

        RealUnit solver::operator*(double x, RealVariable y){
            RealUnit r(y,x,1);
            return r;
        }

        ComplexUnit solver::operator*(complex<double> x, ComplexVariable y){
            ComplexUnit c(y,x,1);
            return c;
        }

        
        RealUnit solver::operator/(RealUnit x, double y){
            RealUnit r(x._variable,x._coeff/y,x._exponent);
            return r;
        }

        ComplexUnit solver::operator/(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,x._coeff/y,x._exponent);
            return c;
        }

        RealUnit solver::operator/(RealUnit x, RealUnit y){
            RealUnit r(x._variable,x._coeff/y._coeff,x._exponent-y._exponent);
            return r;
        }

        ComplexUnit solver::operator/(ComplexUnit x, ComplexUnit y){
            ComplexUnit c(x._variable,x._coeff/y._coeff,x._exponent-y._exponent);
            return c;
        }


        RealVec solver::operator+(RealVariable x, RealVariable y){
            RealVec rx=varToRVec(x);
            RealVec ry=varToRVec(y);
            return rx+ry;
        }

        ComplexVec solver::operator+(ComplexVariable x, ComplexVariable y){
            ComplexVec com1=varToCVec(x);
            ComplexVec com2=varToCVec(y);
            return com1+com2;
        }

        RealVec solver::operator+(RealVariable x, RealUnit y){
            RealVec real1=varToRVec(x);
            RealVec real2=unitToRVec(y);
            return real1+real2;
        }

        ComplexVec solver::operator+(ComplexVariable x, ComplexUnit y){
            ComplexVec cx = varToCVec(x);
            ComplexVec cy = unitToCVec(y);
            return cx+cy;
        }

        RealVec solver::operator+(RealUnit x, RealVariable y){
            RealVec rx=unitToRVec(x);
            RealVec ry=varToRVec(y);
            return rx+ry;
        }

        ComplexVec solver::operator+(ComplexUnit x, ComplexVariable y){
            ComplexVec cx=unitToCVec(x);
            ComplexVec cy=varToCVec(y);
            return cx+cy;
        }

        RealVec solver::operator+(RealVec x, RealVariable y){
            RealVec cy=varToRVec(y);
            return x+cy;
        }

        ComplexVec solver::operator+(ComplexVec x, ComplexVariable y){
            ComplexVec c=varToCVec(y);
            return x+c;
        }

        RealVec solver::operator+(RealVariable x, RealVec y){
            RealVec r=varToRVec(x);
            return r+y;
        }

        ComplexVec solver::operator+(ComplexVariable x, ComplexVec y){
            ComplexVec c=varToCVec(x);
            return c+y;
        }

        RealVec solver::operator-(RealVariable x, RealVariable y){
            RealVec rx=varToRVec(x);
            RealVec ry=varToRVec(y);
            return rx-ry;
        }

        ComplexVec solver::operator-(ComplexVariable x, ComplexVariable y){
            ComplexVec cx=varToCVec(x);
            ComplexVec cy=varToCVec(y);
            return cx-cy;
        }

        RealVec solver::operator-(RealVariable x, RealUnit y){
            RealVec rx=varToRVec(x);
            RealVec ry=unitToRVec(y);
            return rx-ry;
        }

        ComplexVec solver::operator-(ComplexVariable x, ComplexUnit y){
            ComplexVec cx=varToCVec(x);
            ComplexVec cy=unitToCVec(y);
            return cx-cy;
        }

        RealVec solver::operator-(RealUnit x, RealVariable y){
            RealVec rx=unitToRVec(x);
            RealVec ry=varToRVec(y);
            return rx-ry;
        }

        ComplexVec solver::operator-(ComplexUnit x, ComplexVariable y){
            ComplexVec cx=unitToCVec(x);
            ComplexVec cy=varToCVec(y);
            return cx-cy;
        }

        RealVec solver::operator-(RealVec x, RealVariable y){
            RealVec c=varToRVec(y);
            return x-c;
        }

        ComplexVec solver::operator-(ComplexVec x, ComplexVariable y){
            ComplexVec c=varToCVec(y);
            return x-c;
        }

        RealVec solver::operator-(RealVariable x, RealVec y){
            RealVec c=varToRVec(x);
            return x-y;
        }

        ComplexVec solver::operator-(ComplexVariable x, ComplexVec y){
            ComplexVec c=varToCVec(x);
            return c-y;
        }








        RealVec solver::operator+(RealVariable x, double y){
            RealUnit rx(x,1,1);
            RealUnit ry(x,y,0);
            return rx+ry;
        }

        ComplexVec solver::operator+(ComplexVariable x, complex<double>y){
            ComplexUnit cx(x,1,1);
            ComplexUnit cy(x,y,0);
            return cx+cy;
        }

        RealVec solver::operator+(double x, RealVariable y){
            RealUnit rx(y,x,0);
            RealUnit ry(y,1,1);
            return rx+ry;
        }

        ComplexVec solver::operator+(complex<double>x, ComplexVariable y){
            ComplexUnit cx(y,x,0);
            ComplexUnit cy(y,1,1);
            return cx+cy;
        }

/*
        RealVec solver::operator+(RealUnit x, double y){
            RealUnit r(x._variable,y,0);
            return x+r;
        }

        ComplexVec solver::operator+(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,y,0);
            return x+c;
        }

        RealVec solver::operator+(double x, RealUnit y){
            RealUnit r(y._variable,x,0);
            return r+y;
        }

        ComplexVec solver::operator+(complex<double>x, ComplexUnit y){
            ComplexUnit c(y._variable,x,0);
            return x+y;
        }


        RealVec solver::operator+(RealVec x, double y){
            RealVec r=doubleToRVec(y);
            return x+r;
        }

        ComplexVec solver::operator+(ComplexVec x, complex<double>y){
            ComplexVec c=doubleToCVec(y);
            return x+c;
        }

        RealVec solver::operator+(double x, RealVec y){
            RealVec r=doubleToRVec(x);
            return r+y;
        }

        ComplexVec solver::operator+(complex<double>x, ComplexVec y){
            ComplexVec c=doubleToCVec(x);
            return x+c;
        }
*/


        RealVec solver::operator-(RealVariable x, double y){
            RealUnit rx(x,1,1);
            RealUnit ry(x,y,0);
            return rx-ry;
        }

        ComplexVec solver::operator-(ComplexVariable x, complex<double>y){
            ComplexUnit cx(x,1,1);
            ComplexUnit cy(x,y,0);
            return cx-cy;
        }

        RealVec solver::operator-(double x, RealVariable y){
            RealUnit rx(y,x,0);
            RealUnit ry(y,1,1);
            return rx-ry;
        }

        ComplexVec solver::operator-(complex<double>x, ComplexVariable y){
            ComplexUnit cx(y,x,0);
            ComplexUnit cy(y,1,1);
            return cx-cy;
        }

/*
        RealVec solver::operator-(RealUnit x, double y){
            RealUnit r(x._variable,y,0);
            return x-r;
        }

        ComplexVec solver::operator-(ComplexUnit x, complex<double>y){
            ComplexUnit c(x._variable,y,0);
            return x-c;
        }

        RealVec solver::operator-(double x, RealUnit y){
            RealUnit r(y._variable,x,0);
            return r-y;
        }

        ComplexVec solver::operator-(complex<double>x, ComplexUnit y){
            ComplexUnit c(y._variable,x,0);
            return c-y;
        }


        RealVec solver::operator-(RealVec x, double y){
            RealVec r=doubleToCVec(y);
            return x-r;
        }

        ComplexVec solver::operator-(ComplexVec x, complex<double>y){
            ComplexVec c=doubleToCVec(y);
            return x-c;
        }

        RealVec solver::operator-(double x, RealVec y){
            RealVec r=doubleToRVec(x);
            return r-y;
        }

        ComplexVec solver::operator-(complex<double>x, ComplexVec y){
            ComplexVec c=doubleToCVec(x);
            return c-y;
        }


*/










        

      


        double RealVec::quadratic(){
            vector<RealUnit>units=_units;
            int len=units.size();
            _a=0;
            _b=0;
            _c=0;
            for(int i=0;i<len;i++){
                if(units[i]._exponent==0){
                    _c=units[i]._coeff;
                }
                else if(units[i]._exponent==1){
                    _b=units[i]._coeff;
                }
               else if(units[i]._exponent==2){
                    _a=units[i]._coeff;
                }
            }
            if(pow(_b,2)-4*(_a*_c)<0){
                throw oops();
            }
            return (-_b+pow(pow(_b,2)-4*(_a*_c),.5))/2*_a;
        }


         complex<double> ComplexVec::quadratic(){
            vector<ComplexUnit>units=_units;
            int len=units.size();
            _coma=0;
            _comb=0;
            _comc=0;
            for(int i=0;i<len;i++){
                if(units[i]._exponent==0){
                    _comc+=units[i]._coeff;
                }
                else if(units[i]._exponent==1){
                    _comb+=units[i]._coeff;
                }
               else if(units[i]._exponent==2){
                    _coma+=units[i]._coeff;
                }
            }
            printf("comb is %lf\n",_comb);
            printf("coma is %lf\n",_coma);
            printf("comc is %lf\n",_comc);
            printf("pow(pow(_comb,2)-4.0*(_coma*_comc),.5) is: %lf\n",pow(pow(_comb,2)-4.0*(_coma*_comc),.5));
            return (-_comb+sqrt(pow(_comb,2)-4.0*(_coma*_comc)))/2.0*_coma;
         }

        double RealVec::linear(){
            vector<RealUnit>units=_units;
            int len=units.size();
            _b=0;
            _c=0;
            for(int i=0;i<len;i++){
                if(units[i]._exponent==0){
                    _c=units[i]._coeff;
                }
                else if(units[i]._exponent==1){
                    _b=units[i]._coeff;
                }
            }
            return -_c/_b;
        }


         complex<double> ComplexVec::linear(){
            vector<ComplexUnit>units=_units;
            int len=units.size();
            _comb=0;
            _comc=0;
            for(int i=0;i<len;i++){
                if(units[i]._exponent==0){
                    _comc=units[i]._coeff;
                }
                else if(units[i]._exponent==1){
                    _comb=units[i]._coeff;
                }
            }
             printf("comb's real is is %lf\n",real(_comb));
             printf("comb's imag is is %lf\n",imag(_comb));
             printf("comc's real is %lf\n",real(_comc));
             printf("comc's imag is %lf\n",imag(_comc));
            complex<double>result=_comc/_comb;
            
            /*
            if(imag(result)==-0 && real(result)==-0){
                complex<double>c=(-real(result),-imag(result));
                return c;
            }
            else if(imag(result)==-0){
                complex<double>c=(real(result),-imag(result));
                return c;
            }
            else if(real(result)==-0){
                complex<double>c=(-real(result),imag(result));
                return c;
            }
           */ 
            return -result;
         }


        int RealVec::equation(){
            int expo=0;
            vector<RealUnit>units=_units;
            int len=units.size();
            for(int i=0;i<len;i++){
                if(units[i]._exponent==2)
                return 2;
                else if(units[i]._exponent==1)
                expo=1;
            }
            return expo;
        }

        int ComplexVec::equation(){
            printf("starting complex equation\n");
            int expo=0;
            vector<ComplexUnit>units=_units;
            int len=units.size();
            for(int i=0;i<len;i++){
                if(units[i]._exponent==2)
                return 2;
                else if(units[i]._exponent==1)
                expo=1;
            }
            return expo;
        }


/*

        ComplexUnit& solver::operator+(double x){
            Complex<double>com=x+5i;
        }

        ComplexUnit& operator+(int x){

        }

        ComplexUnit& operator-(double x);

        RealUnit& operator+(int x);

        RealUnit& operator+(double x);

        RealUnit& operator-(int x);

        RealUnit& operator-(double x);

*/



        complex<double> solver::solve(EquationC x){
            printf("start of complex solve\n");
            ComplexVec c=x._vec;
            printf("before start of complex equation function\n");
            int e = c.equation();
            if(e==0){
                throw "no answer";
            }
            else if(e==1){
                return c.linear();
            }
            else
            {
                return c.quadratic();
            }
        }

        double solver::solve(EquationR x){
            printf("start of real solve\n");
            RealVec r=x._vec;
            int e = r.equation();
            if(e==0){
                throw "no answer";
            }
            else if(e==1){
                return r.linear();
            }
            else
            {
                return r.quadratic();
            }
        }



