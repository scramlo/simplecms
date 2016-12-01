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

                <?php //Begin Workspace Form ?>
                <form action="updateWorkspace.php" method="post">
                  <?php //Iterate through page elements ?>
                  <?php if ($page->elements): ?>
                    <?php foreach ($page->elements[0] as $element1): ?>
                      <div class="card">
                        <div class="card-header" role="tab" id="elementHeading<?= $i ?>">
                          <a class="collapsed" data-toggle="collapse" data-parent="#workspace-accordion" href="#elementCollapse<?= $i ?>" aria-expanded="false" aria-controls="elementCollapse<?= $i ?>">
                            Element <?= $i ?>
                            <span class="text-muted pull-xs-right uppercase"><?= $element1->type ?> <?= $element1->class ?></span>
                          </a>
                        </div>

                        <div id="elementCollapse<?= $i ?>" class="collapse" role="tabpanel" aria-labelledby="elementHeading<?= $i ?>">
                          <div class="card-block">
                            <div class="form-group">
                              <label for="element<?= $i ?>Tag">Tag Name</label>
                              <input class="form-control" type="text" name="element<?= $i ?>Tag" value="<?= $element1->type ?>">
                            </div>
                            <div class="form-group">
                              <label for="element<?= $i ?>Class">Class Name</label>
                              <input class="form-control" type="text" name="element<?= $i ?>Class" value="<?= $element1->class ?>">
                            </div>
                            <div class="form-group">
                              <label for="element<?= $i ?>Content">Content</label>
                              <textarea class="form-control ckeditor" type="text" name="element<?= $i ?>Content"><?= $element1->content ?></textarea>
                            </div>
                            <input type="hidden" name="pageId" value="<?= $page->id ?>">

                            <?php foreach ($element1->elements[0] as $element2): ?>
                              <div class="card m-t-1">
                                <div class="card-header" role="tab" id="elementHeading<?= $i+1 ?>">
                                  <a class="collapsed" data-toggle="collapse" data-parent="#workspace-accordion" href="#elementCollapse<?= $i+1 ?>" aria-expanded="false" aria-controls="elementCollapse<?= $i+1 ?>">
                                    Element <?= $i+1 ?>
                                  </a>
                                  <span class="text-muted pull-xs-right uppercase"><?= $element2->type ?> <?= $element2->class ?></span>
                                </div>
                                <div id="elementCollapse<?= $i+1 ?>" class="collapse" role="tabpanel" aria-labelledby="elementHeading<?= $i+1 ?>">
                                  <div class="card-block">
                                    <div class="form-group">
                                      <label for="element<?= $i+1 ?>Tag">Tag Name</label>
                                      <input class="form-control" type="text" name="element<?= $i+1 ?>Tag" value="<?= $element2->type ?>">
                                    </div>
                                    <div class="form-group">
                                      <label for="element<?= $i+1 ?>Class">Class Name</label>
                                      <input class="form-control" type="text" name="element<?= $i+1 ?>Class" value="<?= $element2->class ?>">
                                    </div>
                                    <div class="form-group">
                                      <label for="element<?= $i+1 ?>Tag">Content</label>
                                      <textarea class="form-control ckeditor" type="text" name="element<?= $i+1 ?>Content"><?= $element2->content ?></textarea>
                                    </div>

                                    <?php foreach ($element2->elements[0] as $element3): ?>
                                      <div class="card m-t-1">
                                        <div class="card-header" role="tab" id="elementHeading<?= $i+2 ?>">
                                          <a class="collapsed" data-toggle="collapse" data-parent="#workspace-accordion" href="#elementCollapse<?= $i+2 ?>" aria-expanded="false" aria-controls="elementCollapse<?= $i+2 ?>">
                                            Element <?= $i+2 ?>
                                          </a>
                                          <span class="text-muted pull-xs-right uppercase"><?= $element3->type ?> <?= $element3->class ?></span>
                                        </div>
                                        <div id="elementCollapse<?= $i+2 ?>" class="collapse" role="tabpanel" aria-labelledby="elementHeading<?= $i+2 ?>">
                                          <div class="card-block">
                                            <div class="form-group">
                                              <label for="element<?= $i+2 ?>Tag">Tag Name</label>
                                              <input class="form-control" type="text" name="element<?= $i+2 ?>Tag" value="<?= $element3->type ?>">
                                            </div>
                                            <div class="form-group">
                                              <label for="element<?= $i+2 ?>Class">Class Name</label>
                                              <input class="form-control" type="text" name="element<?= $i+2 ?>Class" value="<?= $element3->class ?>">
                                            </div>
                                            <div class="form-group">
                                              <label for="element<?= $i+2 ?>Tag">Content</label>
                                              <textarea class="form-control ckeditor" type="text" name="element<?= $i+2 ?>Content"><?= $element3->content ?></textarea>
                                            </div>

                                            <?php foreach ($element3->elements[0] as $element4): ?>
                                              <div class="card m-t-1">
                                                <div class="card-header" role="tab" id="elementHeading<?= $i+3 ?>">
                                                  <a class="collapsed" data-toggle="collapse" data-parent="#workspace-accordion" href="#elementCollapse<?= $i+3 ?>" aria-expanded="false" aria-controls="elementCollapse<?= $i+3 ?>">
                                                    Element <?= $i+3 ?>
                                                  </a>
                                                  <span class="text-muted pull-xs-right uppercase"><?= $element4->type ?> <?= $element4->class ?></span>
                                                </div>
                                                <div id="elementCollapse<?= $i+3 ?>" class="collapse" role="tabpanel" aria-labelledby="elementHeading<?= $i+3 ?>">
                                                  <div class="card-block">
                                                    <div class="form-group">
                                                      <label for="element<?= $i+3 ?>Tag">Tag Name</label>
                                                      <input class="form-control" type="text" name="element<?= $i+3 ?>Tag" value="<?= $element4->type ?>">
                                                    </div>
                                                    <div class="form-group">
                                                      <label for="element<?= $i+3 ?>Class">Class Name</label>
                                                      <input class="form-control" type="text" name="element<?= $i+3 ?>Class" value="<?= $element4->class ?>">
                                                    </div>
                                                    <div class="form-group">
                                                      <label for="element<?= $i+3 ?>Tag">Content</label>
                                                      <textarea class="form-control ckeditor" type="text" name="element<?= $i+3 ?>Content"><?= $element4->content ?></textarea>
                                                    </div>
                                                  </div>
                                                </div>
                                              </div>
                                            <?php endforeach; ?>

                                          </div>
                                        </div>
                                      </div>
                                    <?php endforeach; //End Element 3 Card?>

                                  </div>
                                </div>
                              </div>
                            <?php endforeach; //End Element 2 Card ?>

                          </div> <!-- End Element 1 Card Block -->
                        </div> <!-- End Element 1 Collapse -->
                      </div> <!-- End Element 1 Card -->
                    <?php endforeach; //End for each element 1 on page ?>
                    <button type="submit" class="btn btn-success btn-sm btn-block">Save</button>
                  <?php endif; //End if there are any elements ?>
                </form>
              <?php endif; //End if page is active ?>
            <?php endforeach; // End if foreach pages ?>

          </div> <!-- End Accordions -->
        </div> <!-- End Workspace -->

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
