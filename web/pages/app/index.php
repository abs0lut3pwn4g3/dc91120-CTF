<?php
if (isset($_GET['page'])) { 
    $page = $_GET['page'];
    include($page);
} else {
    include("./home.html");
}
 