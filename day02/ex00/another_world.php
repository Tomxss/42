#!/usr/bin/php
<?php
	if ($argc > 1)
	{
        /*removes whitespaces at the left and right*/
		$str = trim($argv[1]);
        /*finds all whitespaces, tabs*/ /*replaces it with a space*/ /*the string that will be searched through*/
		$str = preg_replace('/\s+/', ' ', $str);
		if ($str)
			echo "$str"."\n";
	}
?>
