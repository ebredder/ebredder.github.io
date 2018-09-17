lengthL=100;
widthL=10;

lengthT=lengthL-widthL;

pinD=3;
$fn=30;

//linkage parts
module linkageWhole(){
    hull(){
        circle(d=widthL);
        translate([lengthT,0]) circle(d=widthL);
    }
}
    
module holes2(){
    circle(d=pinD);
    translate([lengthT, 0]) circle(d=pinD);
}

//actual linkage
module linkage(){
    difference(){
        linkageWhole();
        holes2();
    }
}

linkage();