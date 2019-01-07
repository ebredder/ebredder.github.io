lengthL=100;
widthL=10;

lengthT=lengthL-widthL;

pinD=3;
$fn=30;

module linkageWhole(){
    difference(){
        hull(){
            circle(d=widthL);
            translate([lengthT,0]) circle(d=widthL);
    }
    circle(d=pinD);
    translate([lengthT,0]) circle(d=pinD);
}
}
linkageWhole();