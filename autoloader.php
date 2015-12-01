<?php
spl_autoload_register(function($Name) {
  $Chunks = explode('\\', $Name);
  if (array_key_exists(1, $Chunks) && $Chunks[0] === 'steelbrain') {
    if ($Chunks[1] === 'StringBuilder') {
      require(__DIR__.'/src-php/Builder.php');
    } else if ($Chunks[1] === 'StringTemplates') {
      require(__DIR__.'/src-php/Main.php');
    }
  }
});
