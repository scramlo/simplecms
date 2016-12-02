<option value="container">Container Padded</option>
<option value="container-fluid">Container Full Width</option>
<option value="row">Row</option>
<?php
//To echo xs easier
for ($i = 1; $i <= 12; $i++) {
  echo "<option value='col-xs-" . $i . "'>col-xs-" . $i . "</option>";
}
?>
<option value="ckeditor">Rich Text</option>
<option value="image">Image</option>
<option value="h1">Heading 1</option>
