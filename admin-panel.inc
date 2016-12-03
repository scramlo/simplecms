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

    <div class="col-xs-3">
      Admin Panel
      <hr>
      <div id="side-panel" class="card">
        <div class="card-block">
          <h4>Welcome <?= $json->user->firstName ?>!</h4>
          <hr>

          <?php //Begin Pages Options Section ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapsePages" aria-expanded="false" aria-controls="collapsePages">
              <span class="pull-xs-left"><i class="fa fa-file-o"></i></span>
              Pages
              <span class="pull-xs-right">&#9660;</span>
            </a>
            <div class="collapse" id="collapsePages">
              <form action="updateOptionsPagesNew.php" method="post">
                <div class="form-group">
                  <label for="newPageTitle">New Page</label>
                  <input type="text" class="form-control" id="newPageTitle" name="newPageTitle" value="New Page Title">
                </div>
                <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
              </form>
              <hr>
              <form action="updateOptionsPagesSwitch.php" method="post">
                <div class="form-group">
                  <label for="changePage">Change Page</label>
                  <?php $i = 0; ?>
                  <?php
                  $currentPageId = "";
                  foreach ($json->pages as $page) {
                    if ($page->active == "true") {
                      $currentPageId = $page->id;
                    }
                  }
                  ?>
                  <?php foreach ($json->pages as $page) : ?>
                    <?php $checked = ""; ?>
                    <?php if ($page->id == $currentPageId): ?>
                      <?php $checked = "checked"; ?>
                    <?php endif; ?>
                    <div class="form-check">
                      <label class="form-check-label">
                        <input class="form-check-input" type="radio" name="changePageRadios" id="changePageRadios-<?= $i ?>" value="<?= $page->id ?>" <?= $checked ?>>
                        <?= $page->title ?>
                      </label>
                    </div>
                    <?php $i++; ?>
                  <?php endforeach; ?>
                </div>
                <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
              </form>
              <hr>
              <form action="updateOptionsPagesElements.php" method="post">
                <div class="form-group">
                  <label for="addElement"><strong>Add Element</strong></label>
                  <select class="form-control" id="addElement" name="addElement">
                    <?php include("elements.inc"); ?>
                  </select>
                </div>
                <div class="form-check">
                  <label class="form-check-label">
                    <input class="form-check-input" name="hasChildren" type="checkbox" value="">
                    Has Children
                  </label>
                </div>
                <input type="hidden" name="pageId" value="<?= $currentPageId ?>">
                <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
              </form>
              <hr>
              <strong>Elements</strong>
              <hr>
                <?php foreach ($json->pages as $page): ?>
                  <?php if ($page->active == "true"): ?>
                    <?php foreach ($page->elements as $element): ?>
                      <div class="card">
                        <div class="card-header">
                          <?= $element->name ?>
                        </div>
                        <div class="card-block">
                          <?php if ($element->hasChildren == "true"): ?>
                            <form action="updateOptionsPagesElementsWithChildren.php" method="post">
                              <div class="form-group">
                                <label for="addElement">Add Element</label>
                                <select class="form-control" id="addElement" name="addElement">
                                  <?php include("elements.inc"); ?>
                                </select>
                              </div>
                              <div class="form-check">
                                <label class="form-check-label">
                                  <input class="form-check-input" name="hasChildren" type="checkbox" value="">
                                  Has Children
                                </label>
                              </div>
                              <input type="hidden" name="pageId" value="<?= $currentPageId ?>">
                              <input type="hidden" name="elementId" value="<?= $element->id ?>">
                              <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
                            </form>
                            <hr>
                            <?php foreach ($element->elements as $childElement): ?>
                              <div class="card">
                                <div class="card-header">
                                  <?= $childElement->name ?>
                                </div>
                                <?php if ($childElement->hasChildren == "true"): ?>
                                  <div class="card-block">
                                    <form action="updateOptionsPagesElementsWithChildren2.php" method="post" class="p-l-1">
                                      <div class="form-group">
                                        <label for="addElement">Add Element</label>
                                        <select class="form-control" id="addElement" name="addElement">
                                          <?php include("elements.inc"); ?>
                                        </select>
                                      </div>
                                      <div class="form-check">
                                        <label class="form-check-label">
                                          <input class="form-check-input" name="hasChildren" type="checkbox" value="">
                                          Has Children
                                        </label>
                                      </div>
                                      <input type="hidden" name="pageId" value="<?= $currentPageId ?>">
                                      <input type="hidden" name="elementId" value="<?= $element->id ?>">
                                      <input type="hidden" name="elementChildId" value="<?= $childElement->id ?>">
                                      <button type="submit" value="submit" class="btn btn-primary btn-block btn-sm">Submit</button>
                                    </form>
                                  </div>
                                <?php endif; ?>
                              </div>
                            <?php endforeach; ?>
                          <?php endif; ?>
                        </div>
                      </div>
                    <?php endforeach; ?>
                  <?php endif; ?>
                <?php endforeach; ?>
            </div>
          </p>
          <?php //End Pages Options Section ?>

          <?php //Begin Admin Theme Options Section ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapseThemes" aria-expanded="false" aria-controls="collapseThemes">
              <span class="pull-xs-left"><i class="fa fa-flag"></i></span>
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

          <?php //Begin User Settings ?>
          <p>
            <a class="btn btn-info btn-block" data-toggle="collapse" href="#collapseUserSettings" aria-expanded="false" aria-controls="collapseUserSettings">
              <span class="pull-xs-left"><i class="fa fa-gear"></i></span>
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

        </div>
      </div>
    </div>

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
