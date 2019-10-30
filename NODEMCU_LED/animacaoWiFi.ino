void aguardandoWiFi() {
  define_led(brightness, brightness, brightness);
  analogWrite(VERMELHO, brightness);
  // muda o brilho para o proximo loop:
  brightness = brightness + fadeAmount;
  // inverte a direcao do fade ao final do mesmo:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
