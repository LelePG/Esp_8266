char pageCode[] PROGMEM = R"=====(
    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tiara LED RGB</title>
    <style>
    h1{
        display: block;
        text-align: center;
    }
    div.cores{
        display: flex;
        justify-content: center;
    }
    button {
    width: 150px;
    height: 100px;
    font-size: 20px;
    }
    #azul{
        background-color: #0000FF ;
    }
    #aqua{
        background-color:#00FFFF ;
    }
    #VP{
        background-color:#00FF7F;
    }
    #Verde{
        background-color:#008000 ;
    }
    #lilas{
        background-color:#7B68EE ;
    }
    #blue-violet{
        background-color:#8A2BE2 ;
    }
    #magenta{
        background-color: #FF00FF ;
    }
    #Rosa{
        background-color: #FF1493;
    }
    #red{
        background-color: #FF0000;
    }
    #branco{
        background-color: #FFFFFF;
    }
    </style>
</head>
<body>
    <h1>Escolha a cor dos LEDs</h1>
    <div class = "cores">      
        <button id = "azul">Azul</button>   
        <button id = "aqua">Aqua</button>   
        <button id = "VP">Verde Primavera</button>   
        <button id = "Verde">Verde</button>  
        <button id = "lilas">Lilás</button>
        <button id = "blue-violet">Azul Violeta</button>   
        <button id = "magenta">Magenta</button>       
        <button id = "Rosa">Rosa Profundo</button>   
        <button id = "red">Vermelho</button> 
        <button id = "branco">Branco</button>     
    </div>

    <script>
        function requisita(botao){
            let request = new XMLHttpRequest();
            url = `\\${botao.id}`
            //console.log(url);
            request.open("POST", url, true);
            request.send();
        }

        const btnAzul = document.getElementById("azul");
        btnAzul.addEventListener("click", function(){requisita(btnAzul)});
        let btnAqua = document.getElementById("aqua");
        btnAqua.addEventListener("click", function(){requisita(btnAqua)});
        let btnVP = document.getElementById("VP");
        btnVP.addEventListener("click", function(){requisita(btnVP)});
        let btnVerde = document.getElementById("Verde");
        btnVerde.addEventListener("click", function(){requisita(btnVerde)});
        let btnLilas = document.getElementById("lilas");
        btnLilas.addEventListener("click", function(){requisita(btnLilas)});
        let btnBV = document.getElementById("blue-violet");
        btnBV.addEventListener("click", function(){requisita(btnBV)});
        let btnMagenta = document.getElementById("magenta");
        btnMagenta.addEventListener("click", function(){requisita(btnMagenta)});
        let btnRosa = document.getElementById("Rosa");
        btnRosa.addEventListener("click", function(){requisita(btnRosa)});
        let btnRed = document.getElementById("red");
        btnRed.addEventListener("click", function(){requisita(btnRed)});
        let btnBranco = document.getElementById("branco");
        btnBranco.addEventListener("click", function(){requisita(btnBranco)});
        
       
    </script>
</body>
</html>
)=====";

