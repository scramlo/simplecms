<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Create Element 1 variables, just for ease of reading
  $element1Tag = $_POST["element1Tag"];
  $element1Class = $_POST["element1Class"];
  $element1Content = $_POST["element1Content"];

  //Create Page ID variable, just for ease of reading
  $pageId = $_POST["pageId"];

  //Change Element 1
  foreach ($json->pages[0] as $page) {
    if ($page->id == $pageId) {
      foreach($page->elements[0] as $element) {
        $element->type = $element1Tag;
        $element->class = $element1Class;
        $element->content = $element1Content;
      }
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  header('Location: admin.php');

?>
