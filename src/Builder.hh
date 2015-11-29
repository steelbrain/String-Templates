<?hh
namespace steelbrain;
use Stringish;

class StringBuilder implements Stringish {
  public function __construct(public string $Contents = '') { }
  public function __toString(): string {
    return $this->Contents;
  }
  public function render(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this {
    if ($Parameters === null) {
      return $this->add($Line);
    } else {
      return $this->add(StringTemplates::Render((string) $Line, $Parameters, $Wrappers));
    }
  }
  public function renderLine(mixed $Line, ?array $Parameters = null, ?(string, string) $Wrappers = null): this {
    return $this->render("$Line\n", $Parameters, $Wrappers);
  }
  public function addLine(mixed $Line): this {
    $this->Contents .= "$Line\n";
    return $this;
  }
  public function add(mixed $Line): this {
    $this->Contents .= (string) $Line;
    return $this;
  }
  public static function create(string $Contents = ''): StringBuilder {
    return new StringBuilder($Contents);
  }
}
