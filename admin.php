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
          <h4>Welcome <?= $json->user[0]->firstName ?>!</h4>
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
                  <input value="<?= $json->user[0]->firstName ?>" name="userFirstName" type="text" class="form-control" id="userFirstName" placeholder="First Name">
                </div>
                <div class="form-group">
                  <label for="userLastName">Last Name</label>
                  <input value="<?= $json->user[0]->lastName ?>" name="userLastName" type="text" class="form-control" id="userLastName" placeholder="Last Name">
                </div>
                <div class="form-group">
                  <label for="userEmail">Email address</label>
                  <input value="<?= $json->user[0]->email ?>" name="userEmail" type="email" class="form-control" id="userEmail" placeholder="Email Address">
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
              //var_dump($json->user[0]->firstName);
              echo "</pre>";
            ?>
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
    if ($_POST["userFirstName"] !== $json->user[0]->firstName) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create first name variable, just for ease of reading
      $firstName = $_POST["userFirstName"];

      //Change First Name
      $json->user[0]->firstName = $firstName;
    }
  }

  //*** User Last Name ***
  //If Last name is not empty
  if (!empty($_POST["userLastName"])) {

    //If Last name doesn't match current Last name
    if ($_POST["userLastName"] !== $json->user[0]->lastName) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create Last name variable, just for ease of reading
      $lastName = $_POST["userLastName"];

      //Change Last Name
      $json->user[0]->lastName = $lastName;
    }
  }

  //*** User Email ***
  //If Email is not empty
  if (!empty($_POST["userEmail"])) {

    //If Email doesn't match current Email
    if ($_POST["userEmail"] !== $json->user[0]->email) {

      //Refresh page
      echo "<meta http-equiv='refresh' content='0'>";

      //Create Email variable, just for ease of reading
      $email = $_POST["userEmail"];

      //Change Email
      $json->user[0]->email = $email;
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
    if ($currentPass == $json->user[0]->password) {
      //If new password matches confirmation password
      if ($newPass == $confirmPass) {
        //Change Password
        $json->user[0]->password = $newPass;
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
