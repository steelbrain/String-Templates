<?php
namespace steelbrain;

class StringBuilder {
  public function __construct($Contents = '') {
    $this->Contents = $Contents;
  }
  public function __toString() {
    return $this->Contents;
  }
  public function render($Line, $Parameters = null, $Wrappers = null) {
    if ($Parameters === null) {
      return $this->add($Line);
    } else {
      return $this->add(StringTemplates::Render((string) $Line, $Parameters, $Wrappers));
    }
  }
  public function renderLine($Line, $Parameters = null, $Wrappers = null) {
    return $this->render("$Line\n", $Parameters, $Wrappers);
  }
  public function addLine($Line) {
    $this->Contents .= "$Line\n";
    return $this;
  }
  public function add($Line) {
    $this->Contents .= (string) $Line;
    return $this;
  }
  public static function create($Contents = '') {
    return new StringBuilder($Contents);
  }
}
