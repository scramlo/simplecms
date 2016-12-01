<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Page ID variable, just for ease of reading
  $pageId = $_POST["changePageRadios"];

  //make all pages non-active
  foreach ($json->pages as $page) {
    $page->active = "false";
  }

  //Set page to current active
  $json->pages[$pageId]->active = "true";

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  //Refresh Page
  header('Location: admin.php');

?>
