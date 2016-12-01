<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Create Page ID variable, just for ease of reading
  $pageId = $_POST["pageId"];

  //Create page variables, just for ease of reading
  $pageTitle = $_POST["pageTitle"];
  $pageSlug = $_POST["pageSlug"];
  $pageDescription = $_POST["pageDescription"];

  //Change Elements
  foreach ($json->pages as $page) {
    if ($page->id == $pageId) {
      $page->title = $pageTitle;
      $page->slug = $pageSlug;
      $page->description = $pageDescription;
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  //Refresh Page
  header('Location: admin.php');

?>
