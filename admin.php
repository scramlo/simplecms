<?php
$themeTitle = "";
?>
<?php include("head.inc") ?>

<div class="container-fluid">
  <div class="row">

    <div id="errorMsg" style="display:none;" class="col-xs-12">
      <div id="errorMsgText" class="alert alert-danger alert-dismissible" role="alert">
        <button type="button" class="close" data-dismiss="alert" aria-label="Close">
          <span aria-hidden="true">&times;</span>
        </button>
        <strong>Oh snap!</strong>
      </div>
    </div>

    <div class="col-xs-4">
      Admin Panel
      <hr>
      <div id="side-panel" class="card">
        <div class="card-block">
          <h4>Welcome <?= $json->user->firstName ?>!</h4>
          <hr>

          <?php //Begin User Settings ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapseUserSettings" aria-expanded="false" aria-controls="collapseUserSettings">
              User Settings
              <span class="pull-xs-right">&#9660;</span>
            </a>
            <div class="collapse" id="collapseUserSettings">
              <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>" method="post">
                <div class="form-group">
                  <label for="userFirstName">First Name</label>
                  <input value="<?= $json->user->firstName ?>" name="userFirstName" type="text" class="form-control" id="userFirstName" placeholder="First Name">
                </div>
                <div class="form-group">
                  <label for="userLastName">Last Name</label>
                  <input value="<?= $json->user->lastName ?>" name="userLastName" type="text" class="form-control" id="userLastName" placeholder="Last Name">
                </div>
                <div class="form-group">
                  <label for="userEmail">Email address</label>
                  <input value="<?= $json->user->email ?>" name="userEmail" type="email" class="form-control" id="userEmail" placeholder="Email Address">
                </div>
                <div class="form-group">
                  <label for="userCurrentPassword">Current Password</label>
                  <input name="userCurrentPassword" type="password" class="form-control" id="userCurrentPassword" placeholder="Password">
                </div>
                <div class="form-group">
                  <label for="userNewPassword">New Password</label>
                  <input name="userNewPassword" type="password" class="form-control" id="userNewPassword" placeholder="New Password">
                </div>
                <div class="form-group">
                  <label for="userConfirmPassword">Confirm New Password</label>
                  <input name="userConfirmPassword" type="password" class="form-control" id="userConfirmPassword" placeholder="Confirm New Password">
                </div>
                <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
              </form>
            </div>
          </p>
          <?php //End User Settings Section ?>

          <?php //Begin Admin Theme Options Section ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapseThemes" aria-expanded="false" aria-controls="collapseThemes">
              Admin Themes
              <span class="pull-xs-right">&#9660;</span>
            </a>
            <div class="collapse" id="collapseThemes">
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
            </div>
          </p>
          <?php //End Admin Themes Section ?>
          <?php //Begin Pages Options Section ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapsePages" aria-expanded="false" aria-controls="collapsePages">
              Pages
              <span class="pull-xs-right">&#9660;</span>
            </a>
            <div class="collapse" id="collapsePages">

            </div>
          </p>
          <?php //End Pages Section ?>
        </div>
      </div>
    </div>

    <div class="col-xs-8">
      <div class="container">
        <div class="row">
          <div class="col-xs-12">

            <span id="workspace-preview">Workspace</span>
            <span class="pull-xs-right">
              <a class="btn btn-primary btn-sm" href="#">Save</a>
              <a id="showPreviewBtn" class="btn btn-info btn-sm" href="#">Preview</a>
              <a style="display:none;" id="showWorkspaceBtn" class="btn btn-info btn-sm" href="#">Workspace</a>
              <a class="btn btn-success btn-sm" href="#">Publish</a>
            </span>
            <hr>

            <div id="workspace">
              <?php if (2==3): ?>
                <pre style="background:#eee;">
                  <?php print_r($json->pages[0]->page->elements[0]->element->elements[0]->element->elements[0]->element->elements[0]->element) ?>
                </pre>
              <?php endif; ?>
            </div>

            <div style="display:none;" id="preview">
              <?php //For each page... ?>
              <?php foreach ($json->pages[0] as $page) {

                //If the page is active (to be shown on screen)
                if ($page->active == "true") {

                  //Iterate through page elements
                  foreach ($page->elements[0] as $element1) {

                    //Open Tag and Class
                    echo "<" . $element1->type . " class='" . $element1->class . "'>";

                    //Element Content
                    echo $element1->content;

                    //For each element within element 1
                    foreach ($element1->elements[0] as $element2) {

                      //Open Tag and Class
                      echo "<" . $element2->type . " class='" . $element2->class . "'>";
                      //Element Content
                      echo $element2->content;

                      //For each element within element 2
                      foreach ($element2->elements[0] as $element3) {

                        //Open Tag and Class
                        echo "<" . $element3->type . " class='" . $element3->class . "'>";
                        //Element Content
                        echo $element3->content;

                        foreach ($element3->elements[0] as $element4) {
                          //Open Tag and Class
                          echo "<" . $element4->type . " class='" . $element4->class . "'>";
                          //Element Content
                          echo $element4->content;
                          //Close Element Tag
                          echo "</" . $element4->type . ">";
                        }
                        //Close Element Tag
                        echo "</" . $element3->type . ">";
                      }
                      //Close Element Tag
                      echo "</" . $element2->type . ">";
                    }
                    // Close Tag
                    echo "</" . $element1->type . ">";
                  }
                } //End if page is active
              } // End if foreach pages?>
            </div>
            <?php // End Preview Window ?>
          </div>
        </div>
      </div>
    </div>

  </div> <!-- End primary row -->
</div> <!-- End primary container -->
<?php include("foot.inc") ?>

<?php //BEGIN FORM SUBMISSION STUFF ?>
<?php
//If Submit was sent.
if ($_SERVER["REQUEST_METHOD"] == "POST") {

  //*** If Theme was changed ***
  if (isset($_POST["changeThemeRadios"]) && !empty($_POST["changeThemeRadios"])) {

    //Refresh page
    echo "<meta http-equiv='refresh' content='0'>";

    //Create theme title variable, just for ease of readying
    $themeTitle = $_POST["changeThemeRadios"];

    //Iterate through each theme
    foreach($json->theme as $theme) {
      //Change selected theme to TRUE
      if ($theme->title == $themeTitle) {
        $theme->active = true;
      }
      //Change all other themes to FALSE
      else {
        $theme->active = false;
      }
    }
  }

  //*** User First Name ***
  //If first name is not empty
  if (!empty($_POST["userFirstName"])) {

    //If First name matches match current first name
    if ($_POST["userFirstName"] !== $json->user->firstName) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create first name variable, just for ease of reading
      $firstName = $_POST["userFirstName"];

      //Change First Name
      $json->user->firstName = $firstName;
    }
  }

  //*** User Last Name ***
  //If Last name is not empty
  if (!empty($_POST["userLastName"])) {

    //If Last name doesn't match current Last name
    if ($_POST["userLastName"] !== $json->user->lastName) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create Last name variable, just for ease of reading
      $lastName = $_POST["userLastName"];

      //Change Last Name
      $json->user->lastName = $lastName;
    }
  }

  //*** User Email ***
  //If Email is not empty
  if (!empty($_POST["userEmail"])) {

    //If Email doesn't match current Email
    if ($_POST["userEmail"] !== $json->user->email) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create Email variable, just for ease of reading
      $email = $_POST["userEmail"];

      //Change Email
      $json->user->email = $email;
    }
  }

  //*** If Password was changed ***
  if ((!empty($_POST["userNewPassword"])) && (!empty($_POST["userConfirmPassword"]))) {

    //Refresh page
    //echo "<meta http-equiv='refresh' content='0'>";

    //Create first name variable, just for ease of readying
    $currentPass = $_POST["userCurrentPassword"];
    $newPass = $_POST["userNewPassword"];
    $confirmPass = $_POST["userConfirmPassword"];

    //Password Validation
    //If current password is equal to correct current password
    if ($currentPass == $json->user->password) {
      //If new password matches confirmation password
      if ($newPass == $confirmPass) {
        //Change Password
        $json->user->password = $newPass;
      } else {
        echo "<script>";
        echo "$('#errorMsgText').append('Password do not match.');";
        echo "$('#errorMsg').fadeIn();</script>";
        echo "</script>";
      }
    } else {
      echo "<script>";
      echo "$('#errorMsgText').append('That is not your password.');";
      echo "$('#errorMsg').fadeIn();</script>";
      echo "</script>";
    }
  }

  //Convert Objects to JSON
  $updatedJSON = json_encode($json, JSON_PRETTY_PRINT);

  //Update JSON file
  file_put_contents('admin.json', $updatedJSON);
}
?>
