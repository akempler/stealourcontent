<?php
/**
 * @file
 * Display stats on embedded node views.
 */

/**
 * Display a page with stats in table format.
 *
 * @return string
 *   The html for the page.
 */
function soc_stats() {

  drupal_add_js(drupal_get_path('module', 'stealourcontent') . '/js/tablesorter/jquery.tablesorter.min.js', 'file');
  drupal_add_js(drupal_get_path('module', 'stealourcontent') . '/js/soc_stats.js', 'file');

  drupal_add_css(drupal_get_path('module', 'stealourcontent') . '/js/tablesorter/themes/blue/tablesorter.css');

  soc_load_stats();
  get_referer_view_counts();

  $output = '<h1>' . t('StealOurContent Stats') . '</h1>';

  $header = array(
    'nid' => t('nid'),
    'title' => t('Title'),
    'referer' => t('Referer'),
    'count' => t('Views'),
  );

  $records = get_referer_view_counts();
  $rows = array();

  foreach ($records as $referer => $nids) {
    foreach ($nids as $nid => $count) {
      $node = node_load((int) $nid);
      $rows[] = array(
        'nid' => l($nid, 'node/' . $nid),
        'title' => l(check_plain($node->title), 'node/' . $nid),
        'referer' => l(check_plain($referer), check_plain($referer)),
        'count' => $count,
      );
    }
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'soc_stats_table', 'class' => array('tablesorter'))));

  return $output;
}
