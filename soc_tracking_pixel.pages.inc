<?php
/**
 * @file
 * Provide tracking pixels.
 */


function soc_tracking_pixel_gif() {
  ignore_user_abort(true);

  // Ensure the tracking pixel is always served by Drupal so the cookie is set.
  drupal_page_is_cacheable(FALSE);

  if (function_exists('apache_setenv')) {
    apache_setenv('no-gzip', 1);
  }
  ini_set('zlib.output_compression', 0);
  if (ob_get_level() == 0) {
    ob_start();
  }
  drupal_add_http_header('Content-encoding', 'none');
  drupal_add_http_header('Content-type', 'image/gif');
  drupal_add_http_header('Content-Length', '42');
  drupal_add_http_header('Cache-Control', 'private, no-cache, no-cache=Set-Cookie, proxy-revalidate');
  drupal_add_http_header('Expires', 'Wed, 11 Jan 2000 12:59:00 GMT');
  drupal_add_http_header('Last-Modified', 'Wed, 11 Jan 2006 12:59:00 GMT');
  drupal_add_http_header('Pragma', 'no-cache');
  // This is the actual image, no GD library required!
  echo sprintf('%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%',71,73,70,56,57,97,1,0,1,0,128,255,0,192,192,192,0,0,0,33,249,4,1,0,0,0,0,44,0,0,0,0,1,0,1,0,0,2,2,68,1,0,59);
  ob_flush();
  flush();
  ob_end_flush();

  // Save the view to the db.
  soc_save_node_views();

  drupal_exit();
}