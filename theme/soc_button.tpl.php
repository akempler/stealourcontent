<?php
/**
 * @file
 * Displays a button which opens a modal allowing copying of node content.
 *
 * Available variables:
 *  $soc_link_text
 *    The text to display on the button.
 *  $node
 *    Node object.
 *
 * @see template_preprocess_soc_button().
 */
?>

<div id="soc_button_wrapper">
<?php
print l(check_plain($soc_link_text), "stealourcontent/nojs/" . $node->nid, array(
  "attributes" => array(
    "class" => array(
      "ctools-use-modal",
      "soc_button"
      ),
    ),
  )
);
?>
</div>