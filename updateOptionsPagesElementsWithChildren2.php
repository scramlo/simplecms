<?php
  $content = file_get_contents("admin.json");
  $json = json_decode($content);

  //Set variables for easy reading
  $pageId = $_POST["pageId"];
  $elementId = $_POST["elementId"];
  $childElementId = $_POST["elementChildId"];
  $elementString = $_POST["addElement"];
  $elementArr = explode('|', $elementString);
  $elementType = $elementArr[0];
  $elementClass = $elementArr[1];
  $elementName = $elementArr[2];

  foreach ($json->pages as $page) {
    if ($page->id == $pageId) {
      //Total Elements
      $totalChildChildElements = intval(count($page->elements[$elementId]->elements[$childElementId]->elements));

      $page->elements[$elementId]->elements[$childElementId]->elements[$totalChildChildElements]->id = $totalChildChildElements;
      $page->elements[$elementId]->elements[$childElementId]->elements[$totalChildChildElements]->type = $elementType;
      $page->elements[$elementId]->elements[$childElementId]->elements[$totalChildChildElements]->class = $elementClass;
      $page->elements[$elementId]->elements[$childElementId]->elements[$totalChildChildElements]->name = $elementName;

      if (isset($_POST['hasChildren'])) {
        $page->elements[$elementId]->elements[$totalChildElements]->elements[$totalChildChildElements]->hasChildren = "true";
      } else {
        $page->elements[$elementId]->elements[$totalChildElements]->elements[$totalChildChildElements]->hasChildren = "false";
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
