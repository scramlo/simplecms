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

  $element3Tag = $_POST["element3Tag"];
  $element3Class = $_POST["element3Class"];
  $element3Content = $_POST["element3Content"];

  $element4Tag = $_POST["element4Tag"];
  $element4Class = $_POST["element4Class"];
  $element4Content = $_POST["element4Content"];

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

          foreach($element2->elements[0] as $element3) {
            $element3->type = $element3Tag;
            $element3->class = $element3Class;
            $element3->content = $element3Content;

            foreach($element3->elements[0] as $element4) {
              $element4->type = $element4Tag;
              $element4->class = $element4Class;
              $element4->content = $element4Content;
            }
          }
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
