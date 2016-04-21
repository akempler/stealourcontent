<?php
/**
 * @file
 * Display stats on embedded node views.
 */


function soc_stats() {

  drupal_add_js(drupal_get_path('module', 'stealourcontent') . '/js/jquery.tablesorter.min.js', 'file');
  drupal_add_js(drupal_get_path('module', 'stealourcontent') . '/js/soc_stats.js', 'file');

  soc_load_stats();
  get_referer_view_counts();


  $output = '<h1>' . t('StealOurContent Stats') . '</h1>';

  //$header = array();
  $header = array(
    'nid' => t('nid'),
    'title' => t('Title'),
    'referer' => t('Referer'),
    'count' => array("data" => t('Views'))
  );

  $records = get_referer_view_counts();
  $rows = array();

  foreach ($records as $referer => $nids) {
    foreach ($nids as $nid => $count) {
      $node = node_load((int)$nid);
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