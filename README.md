String-Templates
==========

Super lightweight string templating in PHP/Hack.

#### API
```js
class StringTemplates {
  public static (string, string) $Wrappers = tuple('{', '}')
  public static function Render(string $Content, array $Parameters, ?(string, string) $Wrappers = null): string
}
class StringBuilder implements Stringish {
  public function __construct(public string $Contents = '')
  public function render(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this
  public function renderLine(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this
  public function addLine(mixed $Line): this
  public function add(mixed $Line): this
  public static function create(string $Contents = ''): StringBuilder
}
```


#### Examples

```hack
<?hh
$Contents = (string) StringBuilder::create()
  ->addLine('apt-get update')
  ->addLine('apt-get upgrade')
  ->renderLine('echo "{Hostname}" > /etc/hostname', ['Hostname' => 'example.com']);
echo $Contents;
echo StringTemplates::Render('Hello {{Name}}', ['Name' => 'Dolly'], tuple('{{', '}}'));
```

#### License

This project is licensed under the terms of MIT license. See the license file for more info.
