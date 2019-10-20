<?php

    include("functions.php");

    if ($_GET['action'] == "loginSignup") {
        
        $error ="";
        
        if (!$_POST['email']) {
            echo "an email address is required.";
        } else if (!$_POST['password']){
            
            $error = "A password is required";
            
        } else if (filter_var($_POST['email'], FILTER_VALIDATE_EMAIL) === false) {
            
            $error = "Please enter a valid email address!";
}
        
        if ($error != "") echo $error;
        
        
        if ($_POST['loginActive'] == '0') {

        }
        
    }