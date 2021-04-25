char codigoWeb[] PROGMEM = R"=====(
 <!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Mensagem</title>
    <style>
        body{
            background-color: rgba(14, 165, 114, 0.966);
            display: flex;
            flex-direction: column;
            align-items: center;

        }
        h1{
            font-family: 'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif;
            color: white;
        }
        div{
            display: flex;
            flex-direction: column;
            align-items: center;
        }
        input{
            margin: 10px;
            font-size: large;
            border-radius: 10px;
            
        }
        input[type="text"]{
            width: 230%;
            font-size: large;
        }
        input[type="button"]{
            padding: 5px 15px 5px 15px;
        }
    </style>
</head>
<body>
    <h1>Mande uma mensagem para a Lelê:</h1>
    <div>
        <input type="text" id="texto">
        <input type = "button" id="btn" value="Enviar">
    </div>
    <script>
        const fazRequisicao = function(mensagem){
            //console.log(mensagem);
            let request = new XMLHttpRequest();
            let url = `/mensagem?m=${mensagem}`;       
            request.open("GET", url, true);
            request.send();
        }

        const botao = document.getElementById("btn");
        const texto = document.getElementById("texto");

        botao.addEventListener("click",function(){ 
            fazRequisicao(texto.value);
            texto.value = "";
        });
    </script>
</body>
</html>
)=====";