<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Set variables for easy reading
  $pageId = $_POST["pageId"];
  $elementId = $_POST["elementId"];
  $childElementId = $_POST["childElementId"];
  $childChildElementId = $_POST["childChildElementId"];
  $elementString = $_POST["addElement"];
  $elementArr = explode('|', $elementString);
  $elementType = $elementArr[0];
  $elementClass = $elementArr[1];
  $elementName = $elementArr[2];

  foreach ($json->pages as $page) {
    if ($page->id == $pageId) {
      //Total Elements
      $totalChildChildChildElements = intval(count($page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements));

      $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->id = $totalChildChildChildElements;
      $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->type = $elementType;
      $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->class = $elementClass;
      $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->name = $elementName;

      if (isset($_POST['hasChildren'])) {
        $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->hasChildren = "true";
      } else {
        $page->elements[$elementId]->elements[$childElementId]->elements[$childChildElementId]->elements[$totalChildChildChildElements]->hasChildren = "false";
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
