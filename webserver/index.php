<?php
$data = file_get_contents("drivers.json");

$character = json_decode($data);

$mode = "N/A";
if(empty($GET["mode"])){
    $mode = strtolower($_GET["mode"]);
}else{
    echo("Mode Not Specified");
}

$driver = "N/A";
if(empty($GET["driver"])){
    $driver = strtolower($_GET["driver"]);
}else{
    echo("Driver Not Specified");
}

$req = "N/A";
if(empty($GET["req"])){
    $req = strtolower($_GET["req"]);
}else{
    echo("Request Not Specified");
}

function change($req, $nb){
    print($character);
    print($nb);
    //$drivers = json_encode($data);
    //file_put_contents('driverss.json', $drivers);
}

if(($mode == 0)){
    print( $character->Drivers->$driver->$req->button);
}else if($mode == 1){
    print($character->Drivers->$driver->$req->controller);
}else if($mode == 2){
    $nb = $_GET["nb"];
    $character->Drivers->$driver->$req->button = $nb;
    print($character->Drivers->$driver->$req->button);
    $newFile = json_encode($character);
    file_put_contents('drivers.json', $newFile);
}

    
?>