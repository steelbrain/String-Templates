<?php
namespace steelbrain;

class StringBuilder {
  public function __construct($Contents = '') {
    $this->Contents = $Contents;
  }
  public function __toString() {
    return $this->Contents;
  }
  public function render($Line, $Parameters = null, $Wrappers = null, $isHTML = false) {
    if ($Parameters === null) {
      return $this->add($Line);
    } else {
      return $this->add(StringTemplates::Render((string) $Line, $Parameters, $Wrappers, $isHTML));
    }
  }
  public function renderLine($Line, $Parameters = null, $Wrappers = null, $isHTML = false) {
    return $this->render("$Line\n", $Parameters, $Wrappers, $isHTML);
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
