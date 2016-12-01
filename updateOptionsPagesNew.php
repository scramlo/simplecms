<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Create Page ID variable, just for ease of reading
  $newPageTitle = $_POST["newPageTitle"];

  //Total Pages is also equal to index of new page
  $totalPages = intval(count($json->pages));

  //Set new page title and ID
  $json->pages[$totalPages]->title = $newPageTitle;
  $json->pages[$totalPages]->id = $totalPages;

  //make all pages non-active
  foreach ($json->pages as $page) {
    $page->active = "false";
  }

  //Set page to current active
  $json->pages[$totalPages]->active = "true";

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  //Refresh Page
  header('Location: admin.php');

?>
