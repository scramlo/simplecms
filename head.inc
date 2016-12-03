<?php //If this is the admin page, load admin JSON ?>
<?php if (basename($_SERVER["SCRIPT_FILENAME"]) == "admin.php"): ?>
  <?php
    $content = file_get_contents("admin.json");
    $json = json_decode($content);
  ?>
<?php endif; ?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <title></title>

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/2.1.4/jquery.min.js"></script>
    <script src="ckeditor/ckeditor.js"></script>

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.2/css/bootstrap.min.css" integrity="sha384-y3tfxAZXuh4HwSYylfB+J125MxIs6mR5FOHamPBG064zB+AFeWH94NdvaCBm8qnd" crossorigin="anonymous">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css">

    <style>
      body {
        padding-top:2rem;
        padding-bottom:2rem;
      }

      .uppercase {
          text-transform: uppercase;
      }

      #workspace .container, #workspace .container-fluid, #workspace .row, #workspace .col-xs-12 {
        border: 1px dotted red;
      }

      <?php //If this is the admin page, load admin theme body css ?>
      <?php if (basename($_SERVER["SCRIPT_FILENAME"]) == "admin.php"){
      foreach ($json->theme as $theme) {
        if ($theme->active == "true") {
          foreach ($theme->css[0] as $selector => $properties) {
            echo $selector . " {";
              foreach ($properties[0] as $property => $value) {
                echo $property . ": " . $value . ";";
              }
            echo "}";
          }
        }
      }
    }
    ?>

    </style>
  </head>
  <body>
