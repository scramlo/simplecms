<?php
$themeTitle = "";
?>
<?php include("head.inc") ?>

<div class="container-fluid">
  <div class="row">

    <div class="col-xs-4">
      Admin Panel
      <hr>
      <div id="side-panel" class="card">
        <div class="card-block">
          <h4>Welcome <?= $json->user[0]->firstName ?>!</h4>
          <hr>
          <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapseThemes" aria-expanded="false" aria-controls="collapseThemes">
            Themes
          </a>
          <div class="collapse" id="collapseThemes">
            <p>
              Current Theme:<br>
              <em>
              <?php
                foreach ($json->theme as $theme) {
                  if ($theme->active == "true") {
                    echo $theme->title;
                  }
                }
              ?>
              </em>
            </p>
            <p>
              <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">
                <div class="form-group">
                  <label for="changeTheme">Change Theme</label>
                  <?php $i = 0; ?>
                  <?php
                  $currentThemeTitle = "";
                  foreach ($json->theme as $theme) {
                    if ($theme->active == "true") {
                      $currentThemeTitle = $theme->title;
                    }
                  }
                  ?>
                  <?php foreach ($json->theme as $theme) : ?>
                    <?php $checked = ""; ?>
                    <?php if ($theme->title == $currentThemeTitle): ?>
                      <?php $checked = "checked"; ?>
                    <?php endif; ?>
                    <div class="form-check">
                      <label class="form-check-label">
                        <input class="form-check-input" type="radio" name="changeThemeRadios" id="changeThemeRadios-<?= $i ?>" value="<?= $theme->title ?>" <?= $checked ?>>
                        <?= $theme->title ?>
                      </label>
                    </div>
                    <?php $i++; ?>
                  <?php endforeach; ?>
                </div>
                <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
              </form>
            </p>
          </div>
        </div>
      </div>
    </div>

    <div class="col-xs-8">
      <div class="container">
        <div class="row">
          <div class="col-xs-12">
            Workspace
            <hr>
            <?php
              echo "<pre style='background:#eee;'>";
              //var_dump($json->theme[0]);
              echo "</pre>";

              //If Submit was sent.
              if ($_SERVER["REQUEST_METHOD"] == "POST") {

                //If Theme was changed
                if (isset($_POST["changeThemeRadios"]) && !empty($_POST["changeThemeRadios"])) {

                  //Refresh page
                  echo "<meta http-equiv='refresh' content='0'>";

                  //Create theme title variable, just for ease of readying
                  $themeTitle = $_POST["changeThemeRadios"];

                  //Iterate through each theme
                  foreach($json->theme as $theme)
                    {
                      //Change selected theme to TRUE
                      if ($theme->title == $themeTitle) {
                        $theme->active = true;
                      }
                      //Change all other themes to FALSE
                      else {
                        $theme->active = false;
                      }
                    }

                    //Convert Objects to JSON
                    $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

                    //Update JSON file
                    file_put_contents('admin.json', $updatedJSON);
                }
              }
            ?>
          </div>
        </div>
      </div>
    </div>

  </div> <!-- End primary row -->
</div> <!-- End primary container -->
<?php include("foot.inc") ?>
