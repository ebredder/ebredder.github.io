x=25;
y=25;
diameter=10;
res=60;

difference(){
    square([x,y], center=true);
    circle(d=diameter, $fn=res);
}