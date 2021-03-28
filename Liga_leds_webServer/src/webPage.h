// Display the HTML web page
char pageCode[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>LED controller</title>

    <style>
    body { 
    font-family: Helvetica; 
    display: flex; 
    flex-direction: column;
    margin: 0px auto; 
    text-align: center;
    }
    .button { 
    border: none; 
    color: white; 
    padding: 16px 40px;
    text-decoration: none; 
    border-radius: 10px;
    font-size: 30px; 
    margin: 2px; 
    }
    .azul{
      background-color: #0096c7;
      border: none; 
    }
    .verde {
      background-color: #2a9d8f;
      border: none; 
    }
    .off {
    background-color: #77878A;
    border: none; 
    }
    </style>
</head>
<body>
    <h1>ESP8266 LED Server</h1>
    <div class = "botoes">
    <p>LED AZUL</p>
     <p><button id = "btnazul", class="button off azul">OFF</button></p>
     <p>LED VERDE</p>
    <p><button id = "btnverde" class="button off verde">OFF</button></p>
  </div>
  <script>
    btn1 = document.getElementById("btnazul");
    btn2 = document.getElementById("btnverde");

    btn1.addEventListener("click", function(){
      let rqs = new XMLHttpRequest();
      let url;
      btn1.classList.toggle("off");
      if (btn1.innerText == "ON"){
        url = "/desliga1";
        btn1.innerText = "OFF";
      }
      else{
        btn1.innerText = "ON";
        url =  "\liga1";
      }    
      rqs.open("POST", url, true);
      rqs.send();
    });
          
    btn2.addEventListener("click", function(){
      let rqs = new XMLHttpRequest();
      let url;
      btn2.classList.toggle("off");
      if (btn2.innerText == "ON"){
        url = "/desliga2";
        btn2.innerText = "OFF";
      }
      else{
        btn2.innerText = "ON";
        url =  "\liga2";
      }    
      rqs.open("POST", url, true);
      rqs.send();
    });
  </script>
</body>
</html>
)=====";