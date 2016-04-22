<?php
/**
 * @file
 * Custom template for the stealourcontent modal node.
 */
?>

<?php
print '<h1>' . check_plain($title) . '</h1>';

hide($content['comments']);
hide($content['links']);
?>

<div id="soc_modal_node_content">
  <?php print render($content); ?>
  <?php print render($content['submitted']); ?>
</div>
