boltD = 4.8;
boltheadD= 9;
boltarea=3;
width=17;

difference(){
    union(){
        cylinder(d=width, h=boltarea, $fn=60);
        translate([0,0,boltarea]) cylinder(d1=width,d2=width-5,h=boltarea,$fn=60);
    }
    cylinder(d=boltD, h=boltarea, $fn=60);
    translate([0,0,boltarea-1]) cylinder(d=boltheadD,h=boltarea+1,$fn=60); 
}