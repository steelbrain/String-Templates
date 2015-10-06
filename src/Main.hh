<?hh

class StringTemplates {
  public static (string, string) $Wrappers = tuple('{', '}');
  public static function Render(string $Content, array $Parameters): string {
    return preg_replace_callback('/'. static::$Wrappers[0] . '([\w\.]+)' . static::$Wrappers[1] .'/', function($matches) use ($Parameters) {
      if (strpos($matches[1], '.') === false) {
        return array_key_exists($matches[1], $Parameters) ? $Parameters[$matches[1]] : $matches[0];
      } else {
        $Subject = $Parameters;
        foreach(explode('.', $matches[1]) as $Chunk) {
          if (array_key_exists($Chunk, $Subject)) {
            $Subject = $Subject[$Chunk];
          } else return '';
        }
        if (!is_string($Subject) && !is_numeric($Subject) && !($Subject instanceof Stringish)) {
          throw new Exception('Can not use non-stringish value into template: ' . $matches[1]);
        }
        return (string) $Subject;
      }
    }, $Content);
  }
}

echo StringTemplates::Render('Hello {name}, I am {greet.message} to meet you', [
  'name' => 'steel',
  'greet' => [
    'message' => 'honored'
  ]
]), "\n";
