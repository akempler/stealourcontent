/**
 * @file
 * Contains js required for stealourcontent module.
 */

(function($) {

  Drupal.behaviors.stealourcontent = {
    attach: function(context, settings) {

      $(document).ready(function() {
        $("#soc_stats_table").tablesorter(); 
      });
    }
  };
})(jQuery);
