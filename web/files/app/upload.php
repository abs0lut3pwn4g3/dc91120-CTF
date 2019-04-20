<?php
    if(isset($_FILES['image'])) {
        $filename = $_FILES['image']['name'];
        $fileTempname = $_FILES['image']['tmp_name'];
        $fileExt = end(explode('.',$filename));
        if(preg_match("/^jpg$|^html$|^txt$|^zip$|^rar$|^png$|^jpeg$|^mp3$|^mp4$/",$fileExt)) {
            $uploadedFilename = md5(time().$filename).".".$fileExt;
            move_uploaded_file($fileTempname,"uploads/".$uploadedFilename);
            echo "<h1 style='text-align: center;'>Thanks for uploading your file to our vault, we will keep it safe.</h1>";
        } else {
            die("<h1 style='text-align: center;'>NOT THAT EASY HACKER!</h1>");
        }
    } else {
        highlight_file(__FILE__);
    }
?>