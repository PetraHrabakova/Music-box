$fn=100; // kinda like resolution (makes the cylinder more smooth on the sides)


// cube to put on the button
difference () { 
#    cube([7, 7, 10]);
    
// make it hollow
    translate([1, 1, 0]) {
        cube([5, 5, 10]);
    }
}
    
// cylinder that sits on the cube  
translate([3.5, 3.5, 10]) {
#   cylinder(h = 5, r = 10);  
}