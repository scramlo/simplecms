<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-alpha.2/js/bootstrap.min.js" integrity="sha384-vZ2WRJMwsjRMW/8U7i6PWi6AlO1L79snBrmgiDpgIWJ82z8eA5lenwvxbMV1PAh7" crossorigin="anonymous"></script>

<script type="text/javascript">

  $("#showPreviewBtn").on("click", function() {
    $("#workspace").fadeOut(function() {
      $("#preview").fadeIn();
      $("#showPreviewBtn").hide();
      $("#showWorkspaceBtn").show();
      $("#workspace-preview").text("Preview");
    });
  });

  $("#showWorkspaceBtn").on("click", function() {
    $("#preview").fadeOut(function() {
      $("#workspace").fadeIn();
      $("#showWorkspaceBtn").hide();
      $("#showPreviewBtn").show();
      $("#workspace-preview").text("Workspace");
    });
  });

</script>

</body>
</html>
