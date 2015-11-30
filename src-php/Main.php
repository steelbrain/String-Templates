<?php
namespace steelbrain;
use Exception;

class StringTemplates {

  public static $Wrappers = ['{', '}'];

  public static function Render($Content, array $Parameters, $Wrappers = null, $isHTML = false) {
    if ($Wrappers === null) {
      $Wrappers = static::$Wrappers;
    }

    return preg_replace_callback('/\\'. $Wrappers[0] . '([\w\.]+)\\' . $Wrappers[1] .'/', function($matches) use ($Parameters, $isHTML) {
      if (strpos($matches[1], '.') === false) {
        return array_key_exists($matches[1], $Parameters) ? $Parameters[$matches[1]] : $matches[0];
      } else {
        $Subject = $Parameters;
        foreach(explode('.', $matches[1]) as $Chunk) {
          if (array_key_exists($Chunk, $Subject)) {
            $Subject = $Subject[$Chunk];
          } else return '';
        }
        if (!is_string($Subject) && !is_numeric($Subject) && !(is_object($Subject) && is_callable([$Subject, '__toString']))) {
          throw new Exception('Can not use non-stringish value into template: ' . $matches[1]);
        }
        return $isHTML ? htmlentities($Subject) : (string) $Subject;
      }
    }, $Content);
  }
}
