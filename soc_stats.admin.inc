<?php
/**
 * @file
 * Display stats on embedded node views.
 */


function soc_stats() {

  $output = '<h1>' . t('StealOurContent Stats') . '</h1>';

  $header = array(
    'nid' => t('nid'),
    'title' => t('Title'),
    'referrer' => t('Referer'),
    'count' => t('Count')
  );

  $rows = array(
    array(
      'nid' => '<a href="#">2567</a>',
      'title' => '<a href="#">Sample node 1</a>',
      'referrer' => '<a href="#">http://example.com/page5</a>',
      'created' => 24
    ),
    array(
      'nid' => '<a href="#">2567</a>',
      'title' => '<a href="#">Sample node 1</a>',
      'referrer' => '<a href="#">http://somesite.com/page2</a>',
      'created' => 15
    ),
    array(
      'nid' => '<a href="#">2567</a>',
      'title' => '<a href="#">Sample node 1</a>',
      'referrer' => '<a href="#">http://smith.com/pages/somepage</a>',
      'created' => 6
    ),
    array(
      'nid' => '<a href="#">443</a>',
      'title' => '<a href="#">Sample node 2</a>',
      'referrer' => '<a href="#">http://acme.com/page</a>',
      'created' => 15
    ),
    array(
      'nid' => '<a href="#">443</a>',
      'title' => '<a href="#">Sample node 2</a>',
      'referrer' => '<a href="#">http://widgets.com/pages/somepage</a>',
      'created' => 6
    )
  );

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}