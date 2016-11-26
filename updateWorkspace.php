<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Create Page ID variable, just for ease of reading
  $pageId = $_POST["pageId"];

  //Create Element variables, just for ease of reading
  $element1Tag = $_POST["element1Tag"];
  $element1Class = $_POST["element1Class"];
  $element1Content = $_POST["element1Content"];

  $element2Tag = $_POST["element2Tag"];
  $element2Class = $_POST["element2Class"];
  $element2Content = $_POST["element2Content"];

  //Change Elements
  foreach ($json->pages[0] as $page) {
    if ($page->id == $pageId) {

      foreach($page->elements[0] as $element1) {
        $element1->type = $element1Tag;
        $element1->class = $element1Class;
        $element1->content = $element1Content;

        foreach($element1->elements[0] as $element2) {
          $element2->type = $element2Tag;
          $element2->class = $element2Class;
          $element2->content = $element2Content;
        }
      }
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  header('Location: admin.php');

?>
