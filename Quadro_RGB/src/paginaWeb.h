char codigoRGB[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Escolha a cor do quadro</title>
    <style>
         body{
             background-color: bisque;
             display: flex;
             flex-direction: column;
             text-align: center;
         }   

         input{
             width: 150px;
             height: 100px;
         }

         button{
             font-size: 16px;
             width: 50px;
         }

    </style>
</head>
<body>
    <div>
    <h1>Ligue e desligue</h1>
    <button id = "liga">ON</button>
    <button id = "desliga">OFF</button>
    <h1>Escolha uma cor</h1>   
    <input type = "color" id = "cor">
    </div>


    <script>
        const fazRequisicao = function(url){
            console.log(url);
            let request = new XMLHttpRequest();
            request.open("POST", url, true);
            request.send();
        }

        document.getElementById("liga").addEventListener("click", function(){fazRequisicao("/liga");});
        document.getElementById("desliga").addEventListener("click", function(){fazRequisicao("/desliga");});
        document.getElementById("cor").addEventListener("mouseleave", function(){fazRequisicao(`/cor/${cor.value}`);} )

    </script>
</body>
</html>
)=====";

