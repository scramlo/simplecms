<?php
/*
Use the following format to add new elements:
type|class|name

i.e. Custom Element

div|black-bg|Black Background Box

would produce

<div class="black-bg"></div>
*/
?>
<option value="div|container|Container Padded">Container Padded</option>
<option value="div|container-fluid|Container Full-Width">Container Full-Width</option>
<option value="div|row|Row">Row</option>
<?php
//To echo xs columns easier
for ($i = 1; $i <= 12; $i++) {
  echo "<option value='div|col-xs-" . $i . "|col-xs-" . $i . "'>col-xs-" . $i . "</option>";
}
?>
<option value="textarea|ckeditor|Rich Text">Rich Text</option>
<option value="img||Image">Image</option>
<option value="img|img-r|Image Full-Width">Image Full-Width</option>
<option value="h1||Heading 1">Heading 1</option>
