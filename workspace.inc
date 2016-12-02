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
                <a data-toggle="collapse" class="btn btn-primary" id="toggleUpdateWorkspaceMetaForm" href="#updateWorkspaceMetaForm">Page Meta Data</a>
                <form action="updateWorkspaceMeta.php" method="post" class="collapse" id="updateWorkspaceMetaForm">
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
                <?php foreach ($page->elements as $element): ?>
                  <?php
                    echo "<" . $element->type . " class='" . $element->class . "'" . ">";
                  ?>
                <?php endforeach; ?>
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
