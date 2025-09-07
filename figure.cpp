#include <iostream> 
#define _USE_MATH_DEFINES 
#include <math.h> 
using namespace std; 
void SolveCircle(double &S,double &p ,double R) 
{ 
S = M_PI * (R *R); 
p= 2*M_PI*fabs(R); 
} 
void SolveEllipse(double&S, double&p, double a, double b) 
{ 
S = M_PI * fabs(a * b); 
p= (4*(M_PI*fabs(a)*fabs(b)+(fabs(a)-fabs(b))*(fabs(a)
fabs(b))))/(fabs(a)+fabs(b)); 
} 
void SolveRectangle(double&S, double&p, double a, double b) 
{ 
S =fabs(a*b); 
p=2*(fabs(a)+fabs(b)); 
} 
void SolveSquare(double&S, double&p, double a) 
{ 
S = a*a; 
p = S; 
} 
void SolvePentagon(double&S,double&p, double a) 
{ 
S = ((a*a)/4)*sqrt(25+10*sqrt(5)); 
p= 5*fabs(a); 
} 
void SolveTetrahedron4(double&S, double&V,double&p, double a,double b, 
double h) 
{ 
} 
S = a*a + 2*fabs(a)* sqrt(b*b - (a*a/4)); 
if(h!=0) V = (S * fabs(h))/3; 
SolveSquare(S,p,a); 
void SolveCone(double&S, double&V,double&p, double R ,double h) 
{ 
S = (M_PI*fabs(R)) *(fabs(R) + sqrt(R*R + h*h)); 
if(h!=0)V = (M_PI * R*R*fabs(h))/3; 
SolveCircle(S,p,R); 
} 
void SolveCube(double&S, double&V, double a) 
{ 
S = 6*a*a; 
V = fabs(a)*a*a; 
} 
 
void SolvePrism(double&S, double&V,double&p, double a, double h) 
{ 
   S = 5*fabs(a)*(sqrt(pow(fabs(a)/(2*sin(M_PI/5)),2)-(a*a)/4)+fabs(h)); 
   if(h!=0)V = ((5*fabs(a*a*h))/4)*sqrt((1/(sin(M_PI/5)*sin(M_PI/5)))-1); 
   SolvePentagon(S,p,a); 
} 
 
void SolveCylinder(double&S, double&V,double&p, double R, double h) 
{ 
     S = 2*M_PI*fabs(R*h); 
     if(h!=0)V = M_PI*fabs(R*R*h); 
     SolveCircle(S,p,R); 
} 
 
void SolveEllipsoid(double&S, double&V,double&p, double a, double b, 
double &h) 
{ 
      const double P = 1.6075; 
      double temp=fabs(h); 
      S = 4*M_PI 
*pow(((pow(fabs(a),P)*pow(fabs(b),P)+pow(fabs(b),P)*pow(fabs(h),P)+pow(fa
 bs(a),P)*pow(fabs(h),P))/3),1/P); 
      if(a==0) 
      { 
         h=a; 
         a=temp; 
      } 
      if(b==0) 
      { 
         h=b; 
         b=temp; 
      } 
      if(h!=0) V = (4*M_PI *fabs(a*b*h))/3; 
      SolveEllipse(S,p,a,b); 
} 
 
string twoDimensional(string tSol, double S, double p) 
{ 
   double a,b,R; 
   if(tSol== "Круг") 
    { 
      cout<<"Введите длину радиуса круга"<<endl; 
      cin>>R; 
      SolveCircle(S,p,R); 
    } 
    if(tSol=="Эллипс") 
    { 
       cout<<"Введите длину большой и малой полуоси эллипса"<<endl; 
       cin>>a>>b; 
       SolveEllipse(S,p,a,b); 
    } 
    if(tSol=="Прямоугольник") 
    { 
      cout<<"Введите длину большой и малой стороны прямоугольника"<<endl; 
      cin>>a>>b; 
 
      SolveRectangle(S, p,a, b); 
    } 
    return to_string(S)+"\nПериметр = "+to_string(p);     
} 
 
string threeDimensional(string tSol,double S,double V,double p) 
{ 
   double h,a,b,R; 
    
   if (tSol =="Тетраэдр4") 
   { 
      cout<<"Введите длину стороны основания, бокового ребра, высоты 
тетраэдра"<<endl; 
      cin>>a>>b>>h; 
      SolveTetrahedron4( S,V,p,a,b,h); 
   } 
    
    if(tSol == "Конус") 
    { 
      cout<<"Введите длину радиуса и высоты конуса"<<endl; 
      cin>>R>>h; 
      SolveCone(S,V,p,R,h); 
    } 
     
    if(tSol == "Куб") 
    { 
      cout<<"Введите длину грани куба"<<endl; 
      cin>>a; 
      SolveCube(S,V,a); 
    } 
     
    if(tSol=="Призма5") 
    { 
      cout<<"Введите длину стороны основания, высоты призмы"<<endl; 
      cin>>a>>h; 
      SolvePrism(S,V,p,a,h); 
    } 
     
    if(tSol== "Цилиндр") 
    { 
      cout<<"Введите длину радиуса и высоты цилиндра"<<endl; 
      cin>>R>>h; 
      SolveCylinder(S,V,p,R,h); 
    } 
     
     if(tSol=="Эллипсоид") 
    { 
      cout<<"Введите длину трёх полуосей эллипсоида"<<endl; 
      cin>>a>>b>>h; 
      SolveEllipsoid(S,V,p,a,b,h); 
    } 
     
    if(h!=0)return to_string(S)+"\nОбъем = "+to_string(V);  
     
    return to_string(S)+"\nПериметр = "+to_string(p);  
} 
 
string figure_pr() 
{ 
double S,V,p; 
string typeSol,output; 
cin>>typeSol; 
if(typeSol == "Круг" || typeSol =="Эллипс" || typeSol == 
"Прямоугольник") return output = "Площадь ="+twoDimensional(typeSol,S,p); 
if(typeSol == "Куб" || typeSol =="Цилиндр" || typeSol == "Призма5"  
|| typeSol == "Тетраэдр4"|| typeSol == "Эллипсоид" || typeSol == 
"Конус")return output = "Площадь = "+threeDimensional(typeSol,S,V,p); 
return "Неправильный выбор фигуры"; 
} 
int main () 
{ 
string Output=figure_pr(); 
cout<<Output; 
return 0; 
} 
