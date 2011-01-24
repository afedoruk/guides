<?
function theme_guides_helpers_user_testimonials($testimonials)
{
	$output='';
	foreach($testimonials as $node)
	{
		$output.=node_view($node, 1);
	}
	return $output;
}