<!DOCTYPE html>
<html>
  <head>
    <link href="bootstrap/css/bootstrap.css" rel="stylesheet">
    <link rel="stylesheet" type="text/css" href="../theme/nox_blue_black/nox.css" />
    <?php require_once("js/all.inc"); ?>
    <script> 
   
    function showHourDate() { //this function use dateFormat.js
        var now = new Date();
        if ( formatTT == 12 ) {
            hour = now.format("h:MM");
            period = now.format("tt");
            } else {
            hour = now.format("HH:MM:ss");
            period = "";
            }
        date = now.format(formatDate);
        document.getElementById("idHour").innerHTML = hour + period;
        document.getElementById("idDate").innerHTML = date ;

        setTimeout("showHourDate()",1000); 
        } 

    function changeStatusWakeUp() {
        alert("changement etat reveil");    
    }
    
    var Network = loadJson('/core/ManageNetwork/ManageNetwork.json');
    function showNetworkStatus() {
        var interfaceStatus = Network.interfaceStatus;
        document.getElementById("interfaceStatus").innerHTML = "<img src=../theme/"+themePath+"wifi/wifi.png>" ;
    }
    
    </script>
    
  </head>
  <body onload="showHourDate(),showUserData(),showNetworkStatus()">

      <div class="row">
        <div class="col-xs-2" id="interfaceStatus"></div>
        <div id="idDate" class="col-xs-8"></div>
        <div class="col-xs-2">Paramètre</div>
      </div>
      <div class="row">
        <div class="col-xs-2">
            <div class="row">
                <div class="col-xs-12" id="user1Name"></div>
            </div>
            <div class="row">
                <div class="col-xs-12" id="user1Avatar"></div>
            </div>
            <div class="row">
                <div class="col-xs-12" id="user1WakeUpStatus"></div>
            </div>
            <div class="row" id="user1NextWakeUp">
                <div class="col-xs-12">p</div>
            </div>
        </div>
        <div id="idHour" class="col-xs-8" ></div>
        <div class="col-xs-2">USER2</div>
      </div>
        <div class="row">
        <div class="col-xs-3">Temp Out</div>
        <div class="col-xs-3">Condition</div>
        <div class="col-xs-3">Temp IN</div>
        <div class="col-xs-3">Santé</div>
      </div>

  </body>
</html>
