<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Set variables for easy reading
  $pageId = $_POST["pageId"];
  $elementClass = $_POST["addElement"];

  foreach ($json->pages as $page) {
    if ($page->id == $pageId) {
      //Total Elements
      $totalElements = intval(count($page->elements));

      $page->elements[$totalElements]->id = $totalElements;
      $page->elements[$totalElements]->type = "The Type";
      $page->elements[$totalElements]->class = $elementClass;
      $page->elements[$totalElements]->name = "The Name";
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  //Refresh Page
  header('Location: admin.php');

?>
