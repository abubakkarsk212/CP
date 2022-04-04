class Fraction{

private:
    int numerator;
    int dinominator;
public:
    Fraction(int numerator,int dinominator){
        this->numerator = numerator;
        this->dinominator=dinominator;
       
        }


}
void print(){
cout<<numerator<<" "<<dinominator;

}
void simplify(){
int gcd = 1;
int j = (numerator>dinominator)?numerator:dinominator; 
for(int i = 1; i<=j;i++){
 if(numerator%i == 0 && dinominator%i == 0){
gcd = i;
}
}
dinominator = dinominator/gcd;
numerator = numerator/gcd;

}



void add(Fraction f2){
int lcm = dinominator * f2.dinominator;
int x = lcm/dinominator;
int y = lcm/f2.dinominator;
numerator = x * numerator + y*f2.numerator;
dinominator =lcm; 
simplify();
}
};
