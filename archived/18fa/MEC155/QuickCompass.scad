/*Quick Compass 
modeled after John Heisz's Compact Compass: 
https://www.youtube.com/watch?v=5owEwcrbe2w 
https://ibuildit.ca/tips/making-a-compact-compass/
*/

dist=3.5; //distance center-center of dia1 and dia2 circles

bolt=.19; //#10-24 bolt x 1"
pin=.095; //6d nail
pencil=.1; //pencil tip

dia1=.5; //smaller diameter of the compass shape
dia2=2; //larger diameter of the compass shape


//compass shapes - 2 layers of 5mm plywood:

module shape(){
    difference(){
        hull(){
            circle(d=dia1, $fn=60, center = true);
            translate([dist, 0]) circle(d=dia2, $fn=60, center = true);
        }
        translate([dist, 0]) circle(d=bolt, $fn=60, center = true);
    }
}

module hole(pin){
    circle(d=pin, $fn=60, center = true);
}

module compass(holesize){
    scale([25.4,25.4])
    difference(){
        shape();
        hole(holesize); 
    }
}

compass(pin); //comment or uncomment - enter pin or pencil for the parameter

//knob - built in 3 layers of 3mm plywood:

nut=.413; //#10-24 nut

module knob1(){
    difference(){
        for(i=[0:3]){
            rotate([0,0, (360/4)*i])
            translate([dia2/8, 0]) circle(d=dia2/4, $fn=60, center = true);}
        circle(d=bolt, $fn=60, center = true);
    }
}

module knob2(){
    difference(){
        circle(d=2*nut, $fn=60, center = true);
        circle(d=nut, $fn=6, center = true);
    }
}

module knob3(){
    difference(){
        circle(d=2*nut, $fn=60, center = true);
        circle(d=bolt, $fn=60, center = true);
    }
}

//uncomment each knob individually to build each layer
//scale([25.4,25.4])
//knob1();
//knob2();
//knob3();
