<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Set variables for easy reading
  $pageId = $_POST["pageId"];
  $elementId = $_POST["elementId"];
  $elementString = $_POST["addElement"];
  $elementArr = explode('|', $elementString);
  $elementType = $elementArr[0];
  $elementClass = $elementArr[1];
  $elementName = $elementArr[2];

  foreach ($json->pages as $page) {
    if ($page->id == $pageId) {
      //Total Elements
      $totalElements = intval(count($page->elements));
      $totalChildElements = intval(count($page->elements[$elementId]->elements));

      $page->elements[$elementId]->elements[$totalChildElements]->id = $totalChildElements;
      $page->elements[$elementId]->elements[$totalChildElements]->type = $elementType;
      $page->elements[$elementId]->elements[$totalChildElements]->class = $elementClass;
      $page->elements[$elementId]->elements[$totalChildElements]->name = $elementName;

      if (isset($_POST['hasChildren'])) {
        $page->elements[$elementId]->elements[$totalChildElements]->hasChildren = "true";
      } else {
        $page->elements[$elementId]->elements[$totalChildElements]->hasChildren = "false";
      }
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);

  //Refresh Page
  header('Location: admin.php');

?>
