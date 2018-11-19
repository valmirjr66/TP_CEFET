#include "relogio.h"
#include "cinto.h"
#include "kit.h"

const Relogio relogio_nulo = Relogio('-', "NULL", "-", '-', "-", 0, 0, 0);
const Cinto cinto_nulo = Cinto("-", "NULL", "-", '-', "-", 0);
const Kit kit_nulo = Kit("NULL", relogio_nulo, cinto_nulo, '-', "-");
enum tipos_produto {_Relogio = 1, _Cinto, _Kit, _Embalagem};

const double descontoKit = 0.17;
