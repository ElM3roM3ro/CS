
let turn = 0;

$(document).ready(function(){
    $("#bt").click(function(){

        if(turn == 0)
        {
            $("#bt").html("[O]")
            $("#bt").parents("td").css({"color":"red","border": "2px solid red"});
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt").html("[X]")
            $("#bt").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt1").click(function(){
        
        if(turn == 0)
        {
            $("#bt1").html("[O]")
            $("#bt1").parents("td").css({"color":"red","border": "2px solid red"});
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt1").html("[X]")
            $("#bt1").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt2").click(function(){
       
        if(turn == 0)
        {
            $("#bt2").parents("td").css({"color":"red","border": "2px solid red"});
            $("#bt2").html("[O]")
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt2").html("[X]")
            $("#bt2").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt3").click(function(){
       
        if(turn == 0)
        {
            $("#bt3").parents("td").css({"color":"red","border": "2px solid red"});
            $("#bt3").html("[O]")
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt3").html("[X]")
            $("#bt3").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt4").click(function(){
        
        if(turn == 0)
        {
            $("#bt4").parents("td").css({"color":"red","border": "2px solid red"});
            $("#bt4").html("[O]")
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt4").html("[X]")
            $("#bt4").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt5").click(function(){
        
        if(turn == 0)
        {
            $("#bt5").parents("td").css({"color":"red","border": "2px solid red"});
            $("#bt5").html("[O]")
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt5").html("[X]")
            $("#bt5").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt6").click(function(){
       
        if(turn == 0)
        {
            $("#bt6").parents("td").css({"color":"red","border": "2px solid red"});
            $("#bt6").html("[O]")
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
           
            $("#bt6").html("[X]")
            $("#bt6").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt7").click(function(){
      
        if(turn == 0)
        {
           
            $("#bt7").html("[O]")
            $("#bt7").parents("td").css({"color":"red","border": "2px solid red"});
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{

            $("#bt7").html("[X]")
            $("#bt7").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#bt8").click(function(){
       
        if(turn == 0)
        {
            $("#bt8").html("[O]")
            $("#bt8").parents("td").css({"color":"red","border": "2px solid red"});
            $("#turn").html("X's Turn")
            $("#turn").css({"color": "blue"})
            turn = 1;
        }else{
            $("#bt8").html("[X]")
            $("#bt8").parents("td").css({"color":"blue","border": "2px solid blue"});
            $("#turn").html("O's Turn")
            $("#turn").css({"color": "red"})
            turn = 0; 
        }
    });
});

$(document).ready(function(){
    $("#reset").click(function(){
        $("#bt").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt1").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt2").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt3").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt4").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt5").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt6").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt7").parents("td").css({"color":"black","border": "1px solid black"});
        $("#bt8").parents("td").css({"color":"black","border": "1px solid black"});
        
        $("#bt").html("[ ]");
        $("#bt1").html("[ ]");
        $("#bt2").html("[ ]");
        $("#bt3").html("[ ]");
        $("#bt4").html("[ ]");
        $("#bt5").html("[ ]");
        $("#bt6").html("[ ]");
        $("#bt7").html("[ ]");
        $("#bt8").html("[ ]");
    });
});




$(document).ready(function(){
     $("div").find("span") });


$(document).ready(function(){ 
    $("span").find("div") });


