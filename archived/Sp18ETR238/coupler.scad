outerD=20;
rodD=9;
stepD=5;
height=30;

difference(){
    cylinder(d=outerD, h=height, $fn=60, center=false);
    cylinder(d=stepD, h=height/2, $fn=60, center=false);
    translate([0,0,height/2]) cylinder(d=rodD, h=height/2, $fn=60, center=false);
}