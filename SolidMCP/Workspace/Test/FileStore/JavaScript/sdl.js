// ----------------------------------------------------------------------------
// It's used to demostrate how to embed JavaScript to C/C++ Application
// ----------------------------------------------------------------------------


function OnClick(x, y) {
    draw_bmp(x, y, 4) ; 
    commit() ; 
}


// clear screen 
set_draw_color(0, 0, 0) ; 
clear() ; 
commit(); 


// draw some bitmap images
var i = 0; 
var j = 0;
for(i = 0; i < 5; i++) {
    draw_bmp(j, j, i); 
    j += 80; 
}


// Draw some lines with defined color
set_draw_color(255, 0, 0); 
for(i = 0; i < 800; i +=40) {
      draw_line(600, 600, i, 200); 
}

commit(); 
