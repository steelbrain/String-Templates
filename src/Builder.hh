<?hh

class StringBuilder implements Stringish {
  public function __construct(public string $Contents = '') {

  }
  public function __toString(): string {
    return $this->Contents;
  }
  public function render(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this {
    if ($Parameters === null) {
      return $this->addLine($Line);
    } else {
      $this->__validate($Line);
      $this->Contents .= StringTemplates::Render((string) $Line, $Parameters, $Wrappers);
      return $this;
    }
  }
  public function renderLine(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this {
    if ($Parameters === null) {
      return $this->addLine($Line);
    } else {
      $this->__validate($Line);
      $this->Contents .= StringTemplates::Render((string) $Line, $Parameters, $Wrappers) . "\n";
      return $this;
    }
  }
  public function addLine(mixed $Line): this {
    $this->add($Line);
    $this->Contents .= "\n";
    return $this;
  }
  public function add(mixed $Line): this {
    $this->__validate($Line);
    $this->Contents .= (string) $Line;
    return $this;
  }
  public function __validate(mixed $Line): void {
    if (!is_string($Line) && !is_int($Line) && !is_float($Line) && !($Line instanceof Stringish)) {
      throw new Exception('Invalid line provided, expected Stringish');
    }
  }
  public static function create(string $Contents = ''): StringBuilder {
    return new StringBuilder($Contents);
  }
}
