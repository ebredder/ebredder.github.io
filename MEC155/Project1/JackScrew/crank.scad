crankd=25;
handled=15;
screw=9.14;
bolt=6.23;
length=120;

module Crank(){
    
    difference(){
    hull(){
    circle(r=crankd);
        
        translate([length,0])circle(r=handled); 
        
    
}
    circle(r=screw);
     translate([length,0])circle(r=bolt);
    
   
    
}
}
Crank();