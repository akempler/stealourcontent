/**
 * @file
 * Contains js required for stealourcontent module.
 */

(function($) {

  Drupal.behaviors.stealourcontent = {
    attach: function(context, settings) {

      $(document).ready(function() {
        //$("#soc_stats_table").tablesorter(); 
        // Sort the 4th column and add zebra styling.
        $("#soc_stats_table").tablesorter({sortList:[[3,1]], widgets: ['zebra']});
        //$("#options").tablesorter({sortList: [[0,0]], headers: { 3:{sorter: false}, 4:{sorter: false}}});
      });
    }
  };
})(jQuery);
