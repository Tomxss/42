<?php

$link = mysqli_connect('localhost:3306', 'user', 'password', 'camagru');

    if (mysqli_connect_errno()) {
        print_r(mysqli_connect_error());
        exit();
    }


