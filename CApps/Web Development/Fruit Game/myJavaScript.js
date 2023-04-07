var picNum;
var btnNum;

picNum = Math.floor(Math.random() * 4);
if(picNum == 0)
    {
        document.getElementById("fruit").src="apple.png";
    }else if(picNum == 1){
        document.getElementById("fruit").src="pineapple.png";
    }else if(picNum == 2){
        document.getElementById("fruit").src="orange.png";
    }else{
        document.getElementById("fruit").src="pear.png";
    }
function myCompareFunction(a,b){
    if(a == b){
        return 1;
    }else{
        return 0;
    }
}

function whichFruit(a){
    if(a == 0)
    {
        return "apple";
    }else if(a==1){
        return "pineapple";
    }else if(a==2){
        return "orange";
    }else{
        return "pear";
    }
}

function changeColor(a)
{
    if(a ==1){
        document.body.style.backgroundColor ="green";
        document.getElementById("message").innerHTML = "CORRECT!";
    }else{
        document.body.style.backgroundColor ="red";
        document.getElementById("message").innerHTML = "Incorrect";
    }
}

function apple(){
    btnNum = 0;

    var doesEqual= myCompareFunction(btnNum,picNum);
    changeColor(doesEqual);

    document.getElementById("type").innerHTML = whichFruit(picNum);
}

function pineapple(){
    btnNum = 1;

    var doesEqual= myCompareFunction(btnNum,picNum);
    changeColor(doesEqual);

    document.getElementById("type").innerHTML = whichFruit(picNum);
}

function orange(){
    btnNum = 2;

    var doesEqual= myCompareFunction(btnNum,picNum);
    changeColor(doesEqual);

    document.getElementById("type").innerHTML = whichFruit(picNum);
}

function pear(){
    btnNum = 3; 

    var doesEqual= myCompareFunction(btnNum,picNum);
    changeColor(doesEqual);

    document.getElementById("type").innerHTML = whichFruit(picNum);
}

function reset(){
    document.body.style.backgroundColor ="white";
    document.getElementById("message").innerHTML = "";
    document.getElementById("type").innerHTML = "";

    picNum = Math.floor(Math.random() * 4);

    if(picNum == 0)
    {
        document.getElementById("fruit").src="apple.png";
    }else if(picNum == 1){
        document.getElementById("fruit").src="pineapple.png";
    }else if(picNum == 2){
        document.getElementById("fruit").src="orange.png";
    }else{
        document.getElementById("fruit").src="pear.png";
    }

}





