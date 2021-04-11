char paginaWeb[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mova o braço</title>
    <style>
        body{
           display: flex; 
           flex-direction: column;
           background-color: beige;
        }
        div#vertical{
           display: flex;
           flex-direction: row;
           justify-content: center;
        }
        input#lateral
        {
            -webkit-appearance: slider-vertical; /*Para aparecer vertical no google-chrome*/
            height: 150px;
        }
        input#baixo{
            width: 220px;
            margin: auto;
            
        }
    </style>
</head>
<body>
    <div id = "vertical">
        <input type="range" id="lateral" min="0" max="180" orient = "vertical">
        <img src = "../imagens/braco_site.png" width = 200px>
    </div>
    <input type="range" id="baixo" min="0" max="180">
    
    <script>
        const fazRequisicao = function(url){
            let request = new XMLHttpRequest();
            console.log(url);
            request.open("POST", url, true);
            request.send();
        }

        const sliderhorizontal = document.getElementById("baixo");
        const slidervertical = document.getElementById("lateral");
        sliderhorizontal.value =  slidervertical.value =  0;
        sliderhorizontal.addEventListener("click", function(){
            fazRequisicao(`horizontal?/h = ${sliderhorizontal.value}`);
        });

        slidervertical.addEventListener("click", function(){
            fazRequisicao(`vetical?/v = ${slidervertical.value}`);
        });

    </script>
</body>
</html>
)=====";

