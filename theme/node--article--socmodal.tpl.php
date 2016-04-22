<?php
/**
 * @file
 * Custom template for the stealourcontent modal node.
 */
print '<h1>' . $title . '</h1>';

hide($content['comments']);
hide($content['links']);

print render($content);

?>