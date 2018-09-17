//bottom pulley
//components must be uncommented individually

$fn=30;
wt=5;

//inside pulley
difference(){
circle(d=30);
circle(d=4.77);
}; 
/*
//outside of pulley
difference(){
circle(d=40);
circle(d=4.77);
};

//side bar
difference(){
hull(){
    translate([1.5*wt,0])circle(d=3*wt);
    translate([0,29])square(3*wt,3*wt);
};
    translate([1.5*wt,0])circle(d=4.50);
    translate([1.5*wt-wt/2,37-wt/2])square(wt);
};

//cross bar
nut=3; //thickness of BOTH nuts on axle
difference(){
polygon(points=[
    [0,wt],[wt,wt],[wt,0],
    [2*wt,0],[2*wt,wt],[3*wt,wt],
    [3*wt,nut+4*wt],[2*wt,nut+4*wt],[2*wt,nut+5*wt],
    [wt,nut+5*wt],[wt,nut+4*wt],[0,nut+4*wt]]);
translate([1.5*wt,nut/2+2.5*wt])circle(d=4.5)  
}
*/