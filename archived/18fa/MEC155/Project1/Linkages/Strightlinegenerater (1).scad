$fn=30;
width = 20;
length1 = 150;
length2 = 60;
module Square1(){
    difference(){
square(size= [width,length1],
center = true);
        translate ([0,60,0])
        circle(d=5);
        translate ([0,-60,0])
        circle(d=5);
        translate([0,-22,0])
        circle(d=5);
    }  
}
module Square2(){
  difference(){
    square(size= [width,length2],
    center = true);
      translate ([0,20,0])
      circle(d=5);
      translate ([0,-20,0])
      circle(d=5);
  }
}

scale([10,10])
Square1();
scale([10,10])
translate ([60,0,0])
Square2();
