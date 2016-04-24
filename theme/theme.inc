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

  $guidelines_link = variable_get('soc_guidelines_link', '');
  if (!empty($guidelines_link)) {
    $absolute = FALSE;
    if ((substr($link, 0, 7) == 'http://') || (substr($link, 0, 8) == 'https://')) {
      $absolute = TRUE;
      //$guidelines_link = url($guidelines_link, array('absolute' => $absolute));
    }
    $vars['soc_guidelines_link'] = l(t('View additional guideline details.'), $guidelines_link, array('absolute' => $absolute));
  } else {
    $vars['soc_guidelines_link'] = '';
  }

  $vars['soc_instructions'] = variable_get('soc_instructions', stealourcontent_text('soc_instructions'));
  $vars['soc_tracking'] = variable_get('soc_tracking', 1);

  $branding = variable_get('soc_branding', stealourcontent_text('soc_branding'));
  $vars['soc_branding'] = token_replace($branding, array('node' => $vars['node']));

  $vars['soc_rendered_node'] = render(node_view($vars['node'], 'stealourcontent_node', NULL));

  $vars['soc_tracking_pixel'] = NULL;
  if ($vars['soc_tracking']) {
    global $base_url;
    $vars['soc_tracking_pixel'] = theme('image', array('path' => $base_url . '/track.gif?nid=' . $vars['node']->nid, 'attributes' => array('height' => '1', 'width' => '1')));
  }

  $licenses = soc_licenses();
  $license = variable_get('soc_license', 'cc-by-nd-4');
  $image = theme('image', array('path' => $licenses[$license]['image'], 'alt' => 'License'));
  $vars['soc_license'] = l($image, $licenses[$license]['link'], array('html' => TRUE));

  $vars['display_submitted'] = variable_get('node_submitted_' . $vars['node']->type, TRUE);

  $account = user_load($vars['node']->uid);
  $author_url = url('user/' . $vars['node']->uid, array('absolute' => TRUE));
  $vars['author'] = theme('username', array('account' => $account, 'link_path' => $author_url, 'link_options' => array('absolute' => TRUE)));

  // If there are any private files, display an appropriate message.
  $vars['soc_private_files'] = FALSE;
  $files = soc_get_file_fields($vars['node']);
  $private = soc_private_files($files);
  if ($private) {
    $vars['soc_private_files'] = TRUE;
  }

}
