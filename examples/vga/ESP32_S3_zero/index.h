/* 
 * Written by 3tawi
 * Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/
 
const char Main_Page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html><meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<meta charset="utf-8" />
<head>
    <title>Great Projects</title>
    <script>
    var temp_val = "-";
    var humi_val = "-";
    var MesgeDate = "-";
    var tmz_str = "-";
    var tz_val = "-";
    var tdz_val = "-";
    var h24val = "-";
    var cival = "-";
    var ciaval = "-";
    var cisval = "-";
    var amclmuval = "-";
    var amclval = "-";
    var ammcval = "-";
    var smvval = "-";
    var dotval = "-";
    var spee0 = "1";
    var spee1 = "1";
    var spee2 = "10";
    var spee3 = "10";
    var spee4 = "10";
    var spee5 = "10";
    var spee6 = "10";
    var spee7 = "10";
    const modedot = ["&laquo; Dot Off &raquo", "&laquo; Dot On &raquo"];
    const modesmv = ["&laquo; SMV On &raquo", "&laquo; SMV Off &raquo"];
    const mode24h = ["&laquo; 12h &raquo", "&laquo; 24h &raquo"];
    const amvalarr = ["&laquo; Manual &raquo", "&laquo; Auto &raquo"];
    const clmcvalarr = ["&laquo; Music &raquo", "&laquo; Clock &raquo"];
    const weekday = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];

function DisplayCurrentTime() {
  var dt = new Date();
  var dow = weekday[dt.getDay()];
  var da = dt.toLocaleDateString();
  var ti = dt.toLocaleTimeString(true);
  document.getElementById("datemesg").innerHTML = (dow + " " + da + " " + ti);
  setTimeout('DisplayCurrentTime()', 1000);
}
function myFunction24h() {
  var strLine = "mode24h";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionClMc() {
  var strLine = "modeclmc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionMACl() {
  var strLine = "modeautocl";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionMAMc() {
  var strLine = "modeautomc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionPreCl() {
  var strLine = "modeprecl";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionNexCl() {
  var strLine = "modenexcl";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionPreMc() {
  var strLine = "modepremc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionNexSc() {
  var strLine = "modenexsc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionPreSc() {
  var strLine = "modepresc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionNexMc() {
  var strLine = "modenexmc";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionMg() {
  var n = document.getElementById("mymesg");
  var request = new XMLHttpRequest();
  var strLine = "mymessg?Message=" + n.value;
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionS0() {
  var n = document.getElementById("mySpeed0");
  var strLine = "mySpeed0?Speed0=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS1() {
  var n = document.getElementById("mySpeed1");
  var strLine = "mySpeed1?Speed1=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS2() {
  var n = document.getElementById("mySpeed2");
  var strLine = "mySpeed2?Speed2=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS3() {
  var n = document.getElementById("mySpeed3");
  var strLine = "mySpeed3?Speed3=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS4() {
  var n = document.getElementById("mySpeed4");
  var strLine = "mySpeed4?Speed4=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS5() {
  var n = document.getElementById("mySpeed5");
  var strLine = "mySpeed5?Speed5=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS6() {
  var n = document.getElementById("mySpeed6");
  var strLine = "mySpeed6?Speed6=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionS7() {
  var n = document.getElementById("mySpeed7");
  var strLine = "mySpeed7?Speed7=" + n.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt0()', 1000);
}
function myFunctionntp() {
  var strLine = "ntptime";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionlo() {
  var d = new Date();
  var n = d.getTime()/1000;
  var request = new XMLHttpRequest();
  var strLine = "localdatime?locadt=" + n;
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionTma() {
  var nt = document.getElementById("mytmie");
  var nd = document.getElementById("myddate");
  let timeString = nt.value;
  let dateString = nd.value;
  let [hh, mm, ss] = timeString.split(':');
  let [yr, mo, dd] = dateString.split('-');
  var strLine = "mydtime?htmie=" + hh;
      strLine += "&mtmie=" + mm;
      strLine += "&stmie=" + ss;
      strLine += "&ddate=" + dd;
      strLine += "&mdate=" + mo;
      strLine += "&ydate=" + yr;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionTz() {
  var ntz = document.getElementById("mylocatz");
  var dtz = document.getElementById("mylocadtz");
  var strLine = "mytimezon?locatz=" + ntz.value;
      strLine += "&locadz=" + dtz.value;
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionsenddate() {
  var request = new XMLHttpRequest();
  var dateString = document.getElementById("mysenddate");
  var strLine = "sendate?daydate=";
      strLine += dateString.value;
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt3()', 500);
}
function myFunctionRt() {
  var strLine = "rotation";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctionRest() {
  var strLine = "restesp";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
}
function myFunctiondot() {
  var strLine = "modedot";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}
function myFunctionsmv() {
  var strLine = "modesmv";
  var request = new XMLHttpRequest();
  request.open("GET", strLine, false);
  request.send(null);
  setTimeout('GetMesgestt2()', 1000);
}

function GetMesgestt0()  {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      tmz_str   = this.responseXML.getElementsByTagName('analog')[0].childNodes[0].nodeValue;
      tz_val    = this.responseXML.getElementsByTagName('analog')[1].childNodes[0].nodeValue;
      tdz_val   = this.responseXML.getElementsByTagName('analog')[2].childNodes[0].nodeValue;
      spee0     = this.responseXML.getElementsByTagName('analog')[3].childNodes[0].nodeValue;
      spee1     = this.responseXML.getElementsByTagName('analog')[4].childNodes[0].nodeValue;
      spee2     = this.responseXML.getElementsByTagName('analog')[5].childNodes[0].nodeValue;
      spee3     = this.responseXML.getElementsByTagName('analog')[6].childNodes[0].nodeValue;
      spee4     = this.responseXML.getElementsByTagName('analog')[7].childNodes[0].nodeValue;
      spee5     = this.responseXML.getElementsByTagName('analog')[8].childNodes[0].nodeValue;
      spee6     = this.responseXML.getElementsByTagName('analog')[9].childNodes[0].nodeValue;
      spee7     = this.responseXML.getElementsByTagName('analog')[10].childNodes[0].nodeValue;
    }
    document.getElementById("Sped0").innerHTML = spee0;
    document.getElementById("Sped1").innerHTML = spee1;
    document.getElementById("Sped2").innerHTML = spee2;
    document.getElementById("Sped3").innerHTML = spee3;
    document.getElementById("Sped4").innerHTML = spee4;
    document.getElementById("Sped5").innerHTML = spee5;
    
    var codeBlock  = '<input type="number" value="' + tz_val + '" name="locatz" id="mylocatz" min="-12" max="+12" style="width:16%" class="button-blue">';
        codeBlock += '<input type="number" value="' + tdz_val + '" name="locadtz" id="mylocadtz" min="-60" max="+60" step="5" style="width:16%" class="button-blue">';
        codeBlock += '<b class="button-blue" style="width:16%">' + tmz_str + '</b>';
    document.getElementById("TZmesg").innerHTML = codeBlock;


    var speedBlock0 = '<input style="width:68%" type="range" name="Speed0" min="1" max="40" value="' + spee0 + '" class="slider" id="mySpeed0">';
    document.getElementById("Sppeed0").innerHTML = speedBlock0;
    var slider0 = document.getElementById("mySpeed0");
    var output0 = document.getElementById("speed0");
    output0.innerHTML = slider0.value;
    slider0.oninput = function() {
      output0.innerHTML = this.value;
    }
    var speedBlock1 = '<input style="width:68%" type="range" name="Speed1" min="1" max="40" value="' + spee1 + '" class="slider" id="mySpeed1">';
    document.getElementById("Sppeed1").innerHTML = speedBlock1;
    var slider1 = document.getElementById("mySpeed1");
    var output1 = document.getElementById("speed1");
    output1.innerHTML = slider1.value;
    slider1.oninput = function() {
      output1.innerHTML = this.value;
    }
    var speedBlock2 = '<input style="width:68%" type="range" name="Speed2" min="1" max="20" value="' + spee2 + '" class="slider" id="mySpeed2">';
    document.getElementById("Sppeed2").innerHTML = speedBlock2;
    var slider2 = document.getElementById("mySpeed2");
    var output2 = document.getElementById("speed2");
    output2.innerHTML = slider2.value;
    slider2.oninput = function() {
      output2.innerHTML = this.value;
    }
    var speedBlock3 = '<input style="width:68%" type="range" name="Speed3" step="5" min="0" max="1000" value="' + spee3 + '" class="slider" id="mySpeed3">';
    document.getElementById("Sppeed3").innerHTML = speedBlock3;
    var slider3 = document.getElementById("mySpeed3");
    var output3 = document.getElementById("speed3");
    output3.innerHTML = slider3.value;
    slider3.oninput = function() {
      output3.innerHTML = this.value;
    }
    var speedBlock4 = '<input style="width:68%" type="range" name="Speed4" step="10" min="0" max="2000" value="' + spee4 + '" class="slider" id="mySpeed4">';
    document.getElementById("Sppeed4").innerHTML = speedBlock4;
    var slider4 = document.getElementById("mySpeed4");
    var output4 = document.getElementById("speed4");
    output4.innerHTML = slider4.value;
    slider4.oninput = function() {
      output4.innerHTML = this.value;
    }
    var speedBlock5 = '<input style="width:68%" type="range" name="Speed5" step="5" min="0" max="360" value="' + spee5 + '" class="slider" id="mySpeed5">';
    document.getElementById("Sppeed5").innerHTML = speedBlock5;
    var slider5 = document.getElementById("mySpeed5");
    var output5 = document.getElementById("speed5");
    output5.innerHTML = slider5.value;
    slider5.oninput = function() {
      output5.innerHTML = this.value;
    }

    var speedBlock6 = '<input style="width:18%" type="number" name="Speed6" min="2" max="360" value="' + spee6 + '" class="button-blue" id="mySpeed6">';
    document.getElementById("Sppeed6").innerHTML = speedBlock6;

    var speedBlock7 = '<input style="width:18%" type="number" name="Speed7" min="2" max="360" value="' + spee7 + '" class="button-blue" id="mySpeed7">';
    document.getElementById("Sppeed7").innerHTML = speedBlock7;

  }
  xhttp.open("GET", "readstt0", true);
  xhttp.send();
}

function GetMesgestt1()  {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      temp_val  = this.responseXML.getElementsByTagName('analog')[0].childNodes[0].nodeValue;
      humi_val  = this.responseXML.getElementsByTagName('analog')[1].childNodes[0].nodeValue;
    }
     
     var codeBlock1 = "<h1>" + temp_val + " &degC</h1>";
     var codeBlock2 = "<h1>" + humi_val + " %RH</h1>";
    document.getElementById("Temp").innerHTML = codeBlock1;
    document.getElementById("Humi").innerHTML = codeBlock2;
    var elem = document.getElementById("Humi");
    elem.style.color = "#0000ff";
    elem.style.fontSize = "30px";
    var elem = document.getElementById("Temp");
    elem.style.color = "#ff0000";
    elem.style.fontSize = "30px";
  }
  xhttp.open("GET", "readstt1", true);
  xhttp.send();
  setTimeout('GetMesgestt1()', 30000);
}

function GetMesgestt2() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
            amclmuval = this.responseXML.getElementsByTagName('analog')[0].childNodes[0].nodeValue;
            amclval   = this.responseXML.getElementsByTagName('analog')[1].childNodes[0].nodeValue;
            ammcval   = this.responseXML.getElementsByTagName('analog')[2].childNodes[0].nodeValue;
            cival     = this.responseXML.getElementsByTagName('analog')[3].childNodes[0].nodeValue;
            ciaval    = this.responseXML.getElementsByTagName('analog')[4].childNodes[0].nodeValue;
            cisval    = this.responseXML.getElementsByTagName('analog')[5].childNodes[0].nodeValue;
            h24val    = this.responseXML.getElementsByTagName('analog')[6].childNodes[0].nodeValue;
            dotval    = this.responseXML.getElementsByTagName('analog')[7].childNodes[0].nodeValue;
            smvval    = this.responseXML.getElementsByTagName('analog')[8].childNodes[0].nodeValue;
    }
    document.getElementById("cimesg").innerHTML = "Mode " + cival;
    document.getElementById("ciamesg").innerHTML = "Mode " + ciaval;
    document.getElementById("cismesg").innerHTML = "Mode " + cisval;
    document.getElementById("amclmesg").innerHTML = amvalarr[amclval];
    document.getElementById("ammcmesg").innerHTML = amvalarr[ammcval];
    document.getElementById("modeclmcmesg").innerHTML = clmcvalarr[amclmuval];
    document.getElementById("m24h").innerHTML = "Mode " + mode24h[h24val];
    document.getElementById("dotmesg").innerHTML = modedot[dotval];
    document.getElementById("smvmesg").innerHTML = modesmv[smvval];
  }
  xhttp.open("GET", "readstt2", true);
  xhttp.send();
}
function GetMesgestt3()  {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      MesgeDate = this.responseXML.getElementsByTagName("analog")[0].childNodes[0].nodeValue;
    }
    document.getElementById("datmsg").innerHTML = "Date : " + MesgeDate;
    var codetxt = '<embed type="text/html" src="readtext" class="embed-g" width="98%" height="380px">';
    document.getElementById("txtthmesg").innerHTML = codetxt;
  }
  xhttp.open("GET", "readstt3", true);
  xhttp.send();
}

      document.addEventListener('DOMContentLoaded', function() {
        DisplayCurrentTime(),GetMesgestt0(),GetMesgestt1(),GetMesgestt2(),GetMesgestt3();
      }, false);
    </script>
    <style>
   body {
   text-align: center;
   background-color: #222222;
   }
.slider {
  -webkit-appearance: none;
  width: 100%;
  height: 15px;
  background: #ffff00;
  outline: none;
  opacity: 0.7;
  -webkit-transition: .2s;
  transition: opacity .2s;
}
.slider:hover {
  opacity: 1;
}
.slider::-moz-range-thumb {
  width: 15px;
  height: 25px;
  background: #FF0F50;
  cursor: pointer;
}
  .data-box {
  width: 99%;
  height: 40px;
  float: center;
  text-align: center;
  background-color: #000000;
  font-size:26px;
  color:red;
  border: 5px solid #666666;
  -moz-border-radius: 10px;
  -webkit-border-radius: 10px;
  }
  .data-input {
  width: 100%;
  text-align: center;
  float: center;
  background-color: #111111;
  font-size:26px;
  color:red;
  border: 5px solid #888888;
  -moz-border-radius: 10px;
  -webkit-border-radius: 10px;
  }
  .button-blue {
  text-shadow: 1px 1px #ff0000;
  padding: 2px 2px 2px 2px;
  width: 100%;
  border: #5555ff solid 0.5px;
  background-color: #0000ff;
  color:white;
  font-size:20px;
  padding-bottom:2px;
  font-weight:700;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
  }
  table {
  text-align: center;
  width:100%;
  color: #0000ff;
  }
.Date{
  padding-top: 0px;
  color: #ff00ff;
  text-shadow: 1px 1px #ff8800;
  text-align: center;
  font-style: blod;
  font-size:26px;
}
.embed-g {
  width: 98%;
  background-color: #ffffff;
  font-size:26px;
  text-align: center;
  font-style: blod;
  color:red;
  border: 5px solid #444444;
  -moz-border-radius: 7px;
  -webkit-border-radius: 7px;
}

/* Full-width input fields */
input[type=text], input[type=password] {
  width: 100%;
  padding: 12px 20px;
  margin: 8px 0;
  display: inline-block;
  border: 1px solid #ccc;
  box-sizing: border-box;
}
.container {
  padding: 16px;
}

span.psw {
  float: right;
  padding-top: 16px;
}

/* The Modal (background) */
.modal {
  display: none; /* Hidden by default */
  position: fixed; /* Stay in place */
  z-index: 1; /* Sit on top */
  left: 0;
  top: 0;
  width: 100%; /* Full width */
  height: 100%; /* Full height */
  overflow: auto; /* Enable scroll if needed */
  background-color: rgb(0,0,255); /* Fallback color */
  background-color: rgba(0,0,255,0.4); /* Black w/ opacity */
  padding-top: 60px;
}
.modal0 {
  display: none; /* Hidden by default */
  position: fixed; /* Stay in place */
  z-index: 1; /* Sit on top */
  left: 0;
  top: 0;
  width: 100%; /* Full width */
  height: 600px; /* Full height */
  overflow: auto; /* Enable scroll if needed */
  background-color: rgb(0,0,255); /* Fallback color */
  background-color: rgba(0,0,255,0.4); /* Black w/ opacity */
  padding-top: 60px;
}

/* Set a style for all buttons */
button {
  background-color: #4CAF50;
  color: white;
  padding: 14px 20px;
  margin: 8px 0;
  border: none;
  cursor: pointer;
  width: 100%;
}

button:hover {
  opacity: 0.8;
}

/* Modal Content/Box */
.modal-content {
  background-color: #fefefe;
  margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
  border: 1px solid #888;
  width: 50%; /* Could be more or less, depending on screen size */
}
.modal0-content {
  background-color: #fefefe;
  margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
  border: 1px solid #888;
  width: 60%; /* Could be more or less, depending on screen size */
}
/* Add Zoom Animation */
.animate {
  -webkit-animation: animatezoom 0.5s;
  animation: animatezoom 0.5s
}

@-webkit-keyframes animatezoom {
  from {-webkit-transform: scale(0)} 
  to {-webkit-transform: scale(1)}
}
  
@keyframes animatezoom {
  from {transform: scale(0)} 
  to {transform: scale(1)}
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
  span.psw {
     display: block;
     float: none;
  }
  .cancelbtn {
     width: 100%;
  }
}
   </style>
</head>
<body>
<tr>
     <div class="data-input">
       <table>
         <form action="/" method="POST">
            <td style="width:16%">
                <button onclick="myFunctionClMc()" class="button-blue" style="width:98%"><span id="modeclmcmesg"></button>
            </td>
            <td style="width:40%">
                <span id="TZmesg"></span>
                <button onclick="myFunctionTz()" class="button-blue" style="width:16%">Set</button>
            </td>
            <td style="width:16%">
                <button class="button-blue" onclick="myFunction24h()"><span id="m24h"></span></button></td>
         </form>
        <td style='width:24%'>
    <button onclick="document.getElementById('id01').style.display='block'" class="button-blue" style="width:96%">Connect to Wi-Fi</button>
    <div id="id01" class="modal">
  <form class="modal-content animate" action="/Mywifi" method="POST">
    <div  class="data-input">
    <div class="slidecontainer">
      <label for="usname"><b>Wifi Ssid</b></label>
      <input type="text" placeholder="Enter Ssid" name="usname" required>
      <label for="pssw"><b>Password</b></label>
      <input type="password" placeholder="Enter Password" name="pssw">
      <button type="submit" class="button-blue"><b>Connect</b></button>
    </div>
    </div>
  </form>
</div>

<script>
// Get the modal
var modal = document.getElementById('id01');

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}
</script></td>
       </table>
     </div>
</tr>
<tr>
     <div class="data-input">
       <table>
         <form action="/" method="POST">
            <td style="width:16%">
                <button class="button-blue" style="width:98%" onclick="myFunctionntp()">Set NTP Time</button></td>
            <td style="width:40%">
                <input type="date" value="0" name="date" id="myddate" class="button-blue" style="width:32%">
                <input type="time" value="00:00:00" name="tmie" id="mytmie" class="button-blue" step="2" style="width:32%">
                <button onclick="myFunctionTma()" class="button-blue" style="width:22%">Set</button>
            </td>
            <td style="width:20%">
                <button onclick="myFunctionlo()" class="button-blue">Set local Time</button>
            </td>
         </form>
       </table>
     </div>
</tr>
    <tr>
     <div class="data-input">
        <table>
         <form action="/" method="POST">
            <td style="width:59%">
                <button class="button-blue" onclick="myFunctionsmv()" style="width:18%"><span id="smvmesg"></span></button>
                <button class="button-blue" onclick="myFunctionPreCl()" style="width:30%">&laquo; Previous</span></button>
                <b class="button-blue" style="width:18%"><span id="cimesg"></span></b>
                <button class="button-blue" onclick="myFunctionNexCl()" style="width:30%">Next &raquo;</span></button>
            </td>
            <td style="width:40%">
                <button class="button-blue" style="width:50%" onclick="myFunctionMACl()"><span id="amclmesg"></span></button>
                <span id="Sppeed6"></span>
                <button onclick="myFunctionS6()" class="button-blue" style="width:18%">Set</button>
            </td>
         </form>
        </table>
    </div>
</tr>
    <tr>
     <div class="data-input">
        <table>
         <form action="/" method="POST">
            <td style="width:59%">
                <button class="button-blue" onclick="myFunctiondot()" style="width:18%"><span id="dotmesg"></span></button>
                <button class="button-blue" onclick="myFunctionPreMc()" style="width:30%">&laquo; Previous</span></button>
                <b class="button-blue" style="width:18%"><span id="ciamesg"></span></b>
                <button class="button-blue" onclick="myFunctionNexMc()" style="width:30%">Next &raquo;</span></button>
            </td>
            <td style="width:40%">
                <button class="button-blue" style="width:50%" onclick="myFunctionMAMc()"><span id="ammcmesg"></span></button>
                <span id="Sppeed7"></span>
                <button onclick="myFunctionS7()" class="button-blue" style="width:18%">Set</button>
            </td>
         </form>
        </table>
    </div>
</tr>
    <tr>
     <div class="data-input">
        <table>
            <form action="/" method="POST">
            <td style="width:80%">
            <input type="text" placeholder="Enter your message here..." maxlength="655" class="button-white" style="width:90%;height:35px;font-size:30px" id="mymesg">
            </td>
            <td style="width:18%">
            <button style="width:90%" class="button-blue" onclick="myFunctionMg()">Send</button>
            </td>
         </form>
        </table>
    </div>
</tr>
<tr>
    <table>
      <td style="width:30%">
        <div class="data-box">
          <span class="Date" id="datemesg"></span>
        </div>
        <div class="data-input">
          <button onclick="document.getElementById('id02').style.display='block'" class="button-blue" style="width:26%">Show</button>
          <div id="id02" class="modal0">
          <div class="modal0-content animate">
          <div class="slidecontainer">
          <input type="date" id="mysenddate" name="mysenddate" class="button-blue" style="width:30%">
          <span id="datmsg" class="button-blue" style="width:22%"></span>
          <button onclick="myFunctionsenddate()" class="button-blue" style="width:16%">Set</button>
          <span id="txtthmesg"></span>
          </div>
          </div>
          </div>

<script>
// Get the modal
var modal0 = document.getElementById('id02');

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal0) {
        modal0.style.display = "none";
    }
}
</script>
        <b><span id="Temp"></span></b>
        <p><span id="Humi"></span></p>
        </div>
      </td>
      <td style="width:70%">
        <div class="data-input">
        <div class="data-box">
        <form action="/" method="POST">
        <b class="button-blue" style="width:12%"><span id="Sped0"></span></b>
        <span id="Sppeed0"></span>
        <span class="button-blue" id="speed0" style="width:12%"></span>
        <button onclick="myFunctionS0()" class="button-blue" style="width:18%">Message</button>
         </form>
        </div>
        <div class="data-box">
         <form action="/" method="POST">
        <b class="button-blue" style="width:12%"><span id="Sped1"></span></b>
        <span id="Sppeed1"></span>
        <span class="button-blue" id="speed1" style="width:12%"></span>
        <button onclick="myFunctionS1()" class="button-blue" style="width:18%">Band</button>
         </form>
        </div>
        <div class="data-box">
         <form action="/" method="POST">
        <b class="button-blue" style="width:12%"><span id="Sped2"></span></b>
        <span id="Sppeed2"></span>
        <span class="button-blue" id="speed2" style="width:12%"></span>
        <button onclick="myFunctionS2()" class="button-blue" style="width:18%">Dot</button>
         </form>
        </div>
        <div class="data-box">
        <form action="/" method="POST">
        <b class="button-blue" style="width:20%"><span id="Sped3"></span></b>
        <span id="Sppeed3"></span>
        <span class="button-blue" id="speed3" style="width:20%"></span>
        <button onclick="myFunctionS3()" class="button-blue" style="width:18%">Noise Mic</button>
         </form>
        </div>
        <div class="data-box">
        <form action="/" method="POST">
        <b class="button-blue" style="width:20%"><span id="Sped4"></span></b>
        <span id="Sppeed4"></span>
        <span class="button-blue" id="speed4" style="width:20%"></span>
        <button onclick="myFunctionS4()" class="button-blue" style="width:18%">Noise</button>
         </form>
        </div>
        <div class="data-box">
        <form action="/" method="POST">
        <b class="button-blue" style="width:20%"><span id="Sped5"></span></b>
        <span id="Sppeed5"></span>
        <span class="button-blue" id="speed5" style="width:20%"></span>
        <button onclick="myFunctionS5()" class="button-blue" style="width:18%">Volume</button>
         </form>

        </div>
        <div class="data-box">
          <button class="button-blue" onclick="myFunctionPreSc()" style="width:30%">&laquo; Previous</span></button>
          <b class="button-blue" style="width:18%"><span id="cismesg"></span></b>
          <button class="button-blue" onclick="myFunctionNexSc()" style="width:30%">Next &raquo;</span></button>
        </div>

        </div>
       </td>
    </table>
</tr>
<tr>
    <table>
         <form action="/" method="POST">
        <div class="data-input">
            <button onclick="myFunctionRt()" class="button-blue" style="width:30%">Flip</button>
            <input type="submit" value="Refresh" class="button-blue" style="width:34%">
            <button onclick="myFunctionRest()" class="button-blue" style="width:34%">Rest Esp32</button>
        </div>
         </form>
    </table>
</tr>
</body>
</html>
)=====";
