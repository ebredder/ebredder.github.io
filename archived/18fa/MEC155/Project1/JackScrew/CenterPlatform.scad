notch=[5,10];
module Center(){
    difference(){ 
    minkowski(){
    square(101.6,101.6);
    circle(r=2);    
        }
        
    translate([10,5]){square(notch);}
    translate([10,25]){square(notch);}
    translate([10,45]){square(notch);}translate([10,65]){square(notch);}
    translate([10,85]){square(notch);}
    
    
    translate([51.6,5]){square(notch);}
    translate([51.6,25]){square(notch);}
    translate([51.6,45]){square(notch);}translate([51.6,65]){square(notch);}
    translate([51.6,85]){square(notch);}

    
    translate([86.6,5]){square(notch);}
    translate([86.6,25]){square(notch);}
    translate([86.6,45]){square(notch);}translate([86.6,65]){square(notch);}
    translate([86.6,85]){square(notch);}
    }
}
    

module CrossBeam(){
    
   
    minkowski(){
        square([14.10,101.6]);
      circle(r=2);  
    }
       
    translate([-5,5]){square(notch);}
    translate([-5,25]){square(notch);}
    translate([-5,45]){square(notch);}translate([-5,65]){square(notch);}
    translate([-5,85]){square([5,10]);}

   translate([14.10,0]){    
   translate([0,5]){square(notch);}
    translate([0,25]){square(notch);}
    translate([0,45]){square(notch);}translate([0,65]){square(notch);}
    translate([0,85]){square(notch);}
        
   }

}

translate([110,0]){CrossBeam();}
Center();