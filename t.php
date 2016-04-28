<?php

$name = $argv[1];

@mkdir($name);
@mkdir($name . "/items/");

$dir_entry = opendir(".");

while($f = readdir($dir_entry)){
	if(!in_array($f,array(".","..","t.php",$name,"items"))){
		do_cg_file($f,"./$name/$f");
	}
}
closedir($dir_entry);

rename("./$name/php_scraw.h","./$name/php_${name}.h");
rename("./$name/scraw.c","./$name/${name}.c");
rename("./$name/scraw.php","./$name/${name}.php");

do_cg_file("./items/func.h","./$name/items/func.h");
do_cg_file("./items/func.c","./$name/items/func.c");

function do_cg_file($src,$aim){
		global $name;
		$content = file_get_contents($src);
		$content = str_replace("scraw",$name,$content);
		$content = str_replace("SCRAW",strtoupper($name),$content);
		file_put_contents($aim,$content);
}
