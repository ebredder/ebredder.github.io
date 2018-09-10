dia1=64.8;
dia2=94.1;
height=112.5;
res=60;
wall=5;

difference(){
    cylinder(d1=dia1, d2=dia2, h=height, $fn=res);
    translate([0,0,wall]) cylinder(d1=dia1-wall*2, d2=dia2-wall*2, h=height-wall, $fn=res);
}