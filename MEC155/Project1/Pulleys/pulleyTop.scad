$fn=30;

rope_diameter = 5;
bolt_diameter = 4.7;
pulley_diameter = 30;
pulley_case_diameter = 40;
washer_width = 1.5;
wood_width= 5;

arm_width =20;
arm_height = 80;
leg_length = 3*wood_width + 2*washer_width;
tooth= 5;






module innerPulley() {
    difference(){
        circle(d=pulley_diameter);
        circle(d=bolt_diameter);
    }
}

module outerPulley(){
    
    difference(){
        circle(d=pulley_case_diameter);
        circle(d=bolt_diameter);
    }
}

module squareArm(){
        
    difference(){
        square([arm_width, arm_height]);
        translate([arm_width/2, arm_height/2, 0]) circle(d=bolt_diameter);
        translate([arm_width/2-wood_width,wood_width,0]) square([wood_width*2, wood_width]);
        translate([arm_width/2-wood_width,arm_height-wood_width*2,0]) square([wood_width*2, wood_width]);
    }
}



module squareBottomLeg(){
    difference(){
        square([arm_width, leg_length]);
        translate([arm_width/2,leg_length/2,0])circle(d=rope_diameter+2);
    }
    translate([arm_width/2-wood_width,-wood_width,0]) square([wood_width*2,wood_width]);
    translate([arm_width/2-wood_width, leg_length,0]) square([wood_width*2,wood_width]);
      
}
innerPulley();
//outerPulley();
//squareArm();
//squareBottomLeg();