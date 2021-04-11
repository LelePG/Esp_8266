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
        div#horizontal{
            width: 500px;
            margin: auto;
            margin-left: 48%;
            font-size: large;
        }
        input#baixo{
            width: 170px;
        }
    </style>
</head>
<body>
    <div id = "vertical">
        <input type="range" id="lateral" min="0" max="180" orient = "vertical">
        <img src = "../imagens/braco_site.png" width = 200px>
    </div>

    <div id = "horizontal">
        <input type="range" id="baixo" min="0" max="180">
        <p id = "texto">Vertical 0 | Horizontal 0</p>
    </div>

    <script>
        const sliderhorizontal = document.getElementById("baixo");
        const slidervertical = document.getElementById("lateral");
        const texto = document.getElementById("texto");

        const fazRequisicao = function(){
            let request = new XMLHttpRequest();
            let url = `/movimento?h=${sliderhorizontal.value}&v=${slidervertical.value}`; 
            console.log(url);
            /*request.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {//readyState 4 indica que a operação terminou e status 200 indica que foi com sucesso
                texto.innerText = `Vertical ${slidervertical.value} | Horizontal ${sliderhorizontal.value}`;
             }
            };  */          
            request.open("GET", url, true);
            request.send();
        }

        sliderhorizontal.value =  slidervertical.value =  0;
        sliderhorizontal.addEventListener("click", fazRequisicao);
        slidervertical.addEventListener("click", fazRequisicao);

    </script>
</body>
</html>
)=====";

