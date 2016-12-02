<div class="col-xs-9">
  <div class="container">
    <div class="row">
      <div class="col-xs-12">

        <span id="workspace-preview">Workspace</span>
        <span class="pull-xs-right">
          <a id="showPreviewBtn" class="btn btn-info btn-sm" href="#">Preview</a>
          <a style="display:none;" id="showWorkspaceBtn" class="btn btn-info btn-sm" href="#">Workspace</a>
          <a class="btn btn-success btn-sm" href="#">Publish</a>
        </span>
        <hr>

        <div id="workspace">
          <?php if (2==3): ?>
            <pre style="background:#eee;">
              <?php

              ?>
            </pre>
          <?php endif; ?>

          <div id="workspace-accordion" role="tablist">
            <?php $i = 1; ?>

            <?php //For each page... ?>
            <?php foreach ($json->pages as $page):

              //If the page is active (to be shown on screen)
              if ($page->active == "true"): ?>

                <p>
                  <form action="updateWorkspaceMeta.php" method="post">
                    <div class="form-group">
                      <label for="pageId">Page ID</label>: <?= $page->id ?>
                    </div>
                    <div class="form-group">
                      <label for="pageTitle">Page Title</label>
                      <input type="text" class="form-control" id="pageTitle" name="pageTitle" value="<?= $page->title?>">
                    </div>
                    <div class="form-group">
                      <label for="pageSlug">Page Slug</label>
                      <input type="text" class="form-control" id="pageSlug" name="pageSlug" value="<?= $page->slug ?>">
                    </div>
                    <div class="form-group">
                      <label for="pageDescription">SEO Description</label>
                      <textarea type="text" class="form-control" id="pageDescription" name="pageDescription"><?= $page->description ?></textarea>
                    </div>
                    <input type="hidden" name="pageId" value="<?= $page->id ?>">
                    <button type="submit" class="btn btn-primary">Save</button>
                  </form>
                </p>
                <hr>

              <?php endif; //End if page is active ?>
            <?php endforeach; // End if foreach pages ?>

          </div> <!-- End Accordions -->
        </div> <!-- End Workspace -->

        <div style="display:none;" id="preview">
          <?php //For each page... ?>
          <?php foreach ($json->pages as $page) {

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
