<?php
/**
 * @file
 * Displays a button which opens a modal allowing copying of node content.
 *
 * Available variables:
 *  $soc_guidelines
 *    Guidelines for republishing the content.
 *  $soc_instructions
 *    Instructions for copying and pasting the content.
 *  $soc_branding
 *    Branding information including link back to original article.
 *  $soc_tracking
 *    Whether or not to add a tracking pixel.
 *  $soc_tracking_pixel
 *    A tracking pixel if tracking is enabled, otherwise NULL, for example:
 *    <img src="http://example.com/track.gif?nid=1456">
 *  $soc_rendered_node
 *    The fully rendered node.
 *  $soc_license
 *    A themed image/link for the content license.
 *  $display_submitted
 *    TRUE if "Display author and date information" is checked for this content type.
 *  $node
 *    Node object.
 *
 * @see template_preprocess_soc_button().
 */
?>

<div id="soc_modal_wrapper">
  <p><?php print $soc_guidelines; ?></p>
  <div id="soc_license"><strong><?php print $soc_license; ?></strong></div>
  <textarea>
    <?php print $soc_rendered_node; ?>
    <?php print $soc_branding; ?>
    <?php if ($display_submitted): ?>
      <p><span class="submitted">Originally posted on <?php print date( "F j, Y", $node->created)?> by <?php print $author ?></span></p>
    <?php endif; ?>
    <?php print $soc_tracking_pixel; ?>
  </textarea>
  <p><?php print $soc_instructions; ?></p>
</div>