# StealOurContent

This module makes a "Republish" button available via the block system. 
The button will be displayed on node pages and when clicked, a modal will be 
displayed allowing users to copy the relevant content of the node along with 
additional appended information such as a link back to the originating node, 
author information, and tracking capabilities to record view counts and 
referer information.

A custom view mode called "stealourcontent_node" is added. this is used to control 
which fields are rendered for the modal. It is automtatically made available 
to all node types. Use the view mode to control what fields are available. 
You can then create custom templates for your specific fields targeting the 
view mode to control how the content for your fields are rendered.

A stats pages is providing showing the number of views for each node. 
The sortable tables are handled by:
http://tablesorter.com/docs/
NOTE: the tablesorter themes' style.css must be renamed to something else to 
work, for example, tablesorter.css, and then included.

