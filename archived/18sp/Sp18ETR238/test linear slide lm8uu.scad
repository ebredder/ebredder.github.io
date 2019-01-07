bearingL=25;
bearingD=15;
bearinghole=9.3; //width of hole for bearing to sit while not falling through or hitting the rod

rodD=8;

nutwidth=(9/16)*(1/0.039370); //convert to mm - across flats
nutthick=(21/64)*(1/0.039370);
nuthole=9.73; //width of hole for nut to not fall through or hit threaded rod

threadedrod=(3/8)*(1/0.039370); //convert to mm

zipX=2;
zipY=4.2;

baseX=100;
baseY=100;

   
difference(){
    square([baseX,baseY], center=true);
    translate([-1/3*baseX,0]) square([nuthole, nutthick], center=true);
    translate([1/3*baseX,0]) square([bearinghole,bearingL],center=true);
    translate(
}