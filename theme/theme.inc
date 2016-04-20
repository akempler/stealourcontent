<?php
/**
 * @file
 * Theme preprocessors for the StealOurContent module.
 *
 */

/**
 * Theme preprocessor for the soc_button.tpl.php.
 */
function template_preprocess_soc_button(&$vars) {

  if ($vars['node']) {

    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();

    // block config variables.
    $vars['soc_link_text'] = variable_get('soc_link_text', stealourcontent_text('soc_link_text'));
  }

}

/**
 * Theme preprocessor for soc_modal_window.tpl.php.
 */
function template_preprocess_soc_modal_window(&$vars) {

  $vars['soc_title'] = variable_get('soc_title', stealourcontent_text('soc_title'));
  $vars['soc_guidelines'] = variable_get('soc_guidelines', stealourcontent_text('soc_guidelines'));
  $vars['soc_instructions'] = variable_get('soc_instructions', stealourcontent_text('soc_instructions'));
  $vars['soc_branding'] = variable_get('soc_branding', stealourcontent_text('soc_branding', NULL, TRUE, $vars['node']));
  $vars['soc_tracking'] = variable_get('soc_tracking', 1);

  $vars['soc_rendered_node'] = render(node_view($vars['node'], 'stealourcontent_node', NULL));

  $vars['soc_tracking_pixel'] = NULL;
  if ($vars['soc_tracking']) {
    global $base_url;
    $vars['soc_tracking_pixel'] = theme('image', array('path' => $base_url . '/track.gif?nid=' . $vars['node']->nid));
  }
}