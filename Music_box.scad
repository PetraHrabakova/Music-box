

difference() {
    // make the cube hollow
    cube([107, 75, 107]);
    translate([3, 3, 3]) {
#        cube([101, 69, 101]);
    }
    // substract the left side (will be printed separetely)
    translate([0, 3, 3]) {
#        cube([3, 69, 101]);
    }
    // speaker
    translate([53.5, 3, 53.5]) {
        rotate([90,0,0]) {
#            cylinder(h = 3, r = 23);
        }
    }
    // volume stick
    translate([104, 55, 85]) {
        rotate([0,90,0]) {
#            cylinder(h = 3, r = 5);
        }
    }
    // Atmel programmer
    translate([107, 35, 10]) {
        rotate([0,0,90]) {
#            cube([20, 3, 10]);
        }
    }
    // power supply
    translate([104, 15, 25]) {
        rotate([0,90,0]) {
#            cylinder(h = 3, r = 5);
        }
    }
        
    // Button 1
    translate([21.5, 30.5, 107]) {
        rotate([0,90,0]) {
#            cube([3, 14, 14]);
        }
    }
    // Button 2
    translate([46.5, 30.5, 107]) {
        rotate([0,90,0]) {
#            cube([3, 14, 14]);
        }
    }
   
    // Button 3
    translate([71.5, 30.5, 107]) {
        rotate([0,90,0]) {
#            cube([3, 14, 14]);
        }
    }      
}
    




