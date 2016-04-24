<?php
/**
 * @file
 * Displays a button which opens a modal allowing copying of node content.
 *
 * Available variables:
 *  $soc_guidelines
 *    Guidelines for republishing the content.
 *  $soc_guidelines_link
 *    Optional link to a page with additional guidelines.
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
 *  $soc_private_files
 *    TRUE if there are any private files, otherwise FALSE (only public files).
 *  $node
 *    Node object.
 *
 * @see template_preprocess_soc_button().
 */
?>

<div id="soc_modal_wrapper">
  <p><?php print $soc_guidelines; ?></p>
  <?php
  if ($soc_guidelines_link):
    print '<p>' . $soc_guidelines_link . '</p>';
  endif;
  ?>
  <div id="soc_license"><strong><?php print $soc_license; ?></strong></div>
  <textarea>
    <?php print $soc_rendered_node; ?>
    <p><?php print $soc_branding; ?></p>
    <?php if ($display_submitted): ?>
      <p><span class="submitted">Originally posted on <?php print date( "F j, Y", $node->created)?> by <?php print $author ?></span></p>
    <?php endif; ?>
    <?php print $soc_tracking_pixel; ?>
  </textarea>
  <p><?php print $soc_instructions; ?></p>
  <?php
  if ($soc_private_files):
    print '<strong>' . t('Some files may not display correctly. These can be removed manually from the html') . '</strong>';
  endif;
  ?>
</div>