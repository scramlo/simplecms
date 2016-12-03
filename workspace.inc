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
            <?php $i = 1; ?>

            <?php //For each page... ?>
            <?php foreach ($json->pages as $page):

              //If the page is active (to be shown on screen)
              if ($page->active == "true"): ?>

                <?php //Workspace Meta Data ?>
                <form action="updateWorkspaceMeta.php" method="post" id="updateWorkspaceMetaForm">
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
                <?php //End workspace meta data ?>

                <hr>

                <?php //Begin components ?>
                <?php foreach ($page->elements as $element) {
                    echo "<" . $element->type . " id='element-" . $element->id . "' class='" . $element->class . "'" . ">";
                    if ($element->hasChildren == "true") {
                      foreach ($element->elements as $childElement) {
                        echo "<" . $childElement->type . " id='element-" . $element->id . $childElement->id . "' class='" . $childElement->class . "'" . ">";
                        if ($childElement->hasChildren == "true") {
                          foreach ($childElement->elements as $childChildElement) {
                            echo "<" . $childChildElement->type . " id='element-" . $element->id . $childElement->id . $childChildElement . "' class='" . $childChildElement->class . "'" . ">";
                            if ($childChildElement->hasChildren == "true") {
                              foreach ($childChildElement->elements as $childChildChildElement) {
                                echo "<" . $childChildChildElement->type . " id='element-" . $element->id . $childElement->id . $childChildElement->id . $childChildChildElement->id . "' class='" . $childChildChildElement->class . "'" . ">";
                                echo "</" . $childChildChildElement->type . "><!-- End " . $childChildChildElement->name . " -->";
                              }
                            }
                            echo "</" . $childChildElement->type . "><!-- End " . $childChildElement->name . " -->";
                          }
                        }
                        echo "</" . $childElement->type . "><!-- End " . $childElement->name . " -->";
                      }
                    }
                    echo "</" . $element->type . "><!-- End " . $element->name . " -->";
                } ?>
                <?php //End components ?>

              <?php endif; //End if page is active ?>
            <?php endforeach; // End if foreach pages ?>

        </div> <!-- End Workspace -->

        <div style="display:none;" id="preview">
        </div>

      </div> <!-- end col-xs-12 -->
    </div>

  </div> <!-- End container -->
</div> <!-- End col-xs-9 -->

<?php include("foot.inc") ?>
