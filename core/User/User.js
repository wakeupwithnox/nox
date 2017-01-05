var User = loadJson('/core/User/User.json');

function showUserData() {
for (var numberUser = 1; numberUser <= 2; numberUser++) {
    if (eval("User.user" + numberUser +".status") == 1) {
        eval( "var user" + numberUser +"Status = User.user" + numberUser +".status;" );
        eval( "var user" + numberUser +"Name = User.user" + numberUser +".name;" );
        eval( "var user" + numberUser +"Avatar = User.user" + numberUser +".avatar;" );
        eval( "var user" + numberUser +"Planner = User.user" + numberUser +".planner;" );

        var user1UrlPlanner = "../plugins/"+user1Planner+"/"+user1Planner+".json";
        var user1DataPlanner = loadJson(user1UrlPlanner);
        
        document.getElementById("user"+numberUser+"Name").innerHTML = eval("user"+numberUser+"Name") ;
        document.getElementById("user"+numberUser+"Avatar").innerHTML = "<img src=../theme/"+themePath+"avatar/"+eval("user"+numberUser+"Avatar")+">" ;
        

        
        if (eval("User.user" + numberUser +".statusNextWakeUp") == 1) {
            document.getElementById("user"+numberUser+"WakeUpStatus").innerHTML = "<img src=../theme/"+themePath+"various/alarm_clock.png onclick='changeStatusWakeUp()'>" ;
        } else {
            document.getElementById("user"+numberUser+"WakeUpStatus").innerHTML = "<img src=../theme/"+themePath+"various/alarm_clock_sleeping.png onclick='changeStatusWakeUp()'>" ;
        }
        
        var d = new Date();
        var today = d.getDay();
        var today = d.format("dddd");
        var now = d.format("HH:MM") ;
        var tomorrow = d.setDate(d.getDate() + 1);
        var tomorrow = d.format("dddd");
        var hourWakeupToday = eval("user"+numberUser+"DataPlanner.plannerUser"+numberUser+"."+today.toLowerCase()+";");
        var hourWakeupTomorrow = eval("user"+numberUser+"DataPlanner.plannerUser"+numberUser+"."+tomorrow.toLowerCase()+";");

        splitHourWakeupToday = hourWakeupToday.split(":");

        d1 = new Date(d. getFullYear(),d.getMonth(),d.getDay(),splitHourWakeupToday[0],splitHourWakeupToday[1]);
        d1 = d1.format("HH:MM");

        if (d1 < now) {
            document.getElementById("user"+numberUser+"NextWakeUp").innerHTML = hourWakeupTomorrow  ;            
            } else {
            document.getElementById("user"+numberUser+"NextWakeUp").innerHTML = hourWakeupToday ;            
            }     
        } else {
            //alert("user"+numberUser+" n est pas actif");
            
        }
    }
}