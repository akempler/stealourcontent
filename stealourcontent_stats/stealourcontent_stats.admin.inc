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
function stealourcontent_stats() {

  $output = '<h1>' . t('StealOurContent Stats') . '</h1>';

  $header = array(
    array('data' => 'nid', 'field' => 'nid', 'sort' => 'ASC'),
    array('data' => t('Title'), 'field' => 'title', 'sort' => 'ASC'),
    array('data' => t('Referer'), 'field' => 'referer', 'sort' => 'ASC'),
    array('data' => t('Views'), 'field' => 'views', 'sort' => 'DESC'),
  );


  $records = stealourcontent_load_stats($header);
  $rows = array();

  foreach ($records as $key => $value) {
    $rows[] = array(
      'nid' => l($value->nid, 'node/' . $value->nid),
      'title' => l(check_plain($value->title), 'node/' . $value->nid),
      'referer' => l(check_plain($value->referer), check_plain($value->referer)),
      array('field' => 'stats.views', 'data' => $value->views),
    );
  }

  $output .= theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'empty' => t('No data has been recorded yet.'),
    'attributes' => array(
      'id' => 'soc_stats_table',
      'class' => array('tablesorter'),
    ))).theme('pager');

  return $output;
}
