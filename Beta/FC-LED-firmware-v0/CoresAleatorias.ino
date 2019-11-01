void CoresAleatorias(int PosicaoNaRoda, int* RGB) {
  RodaDeCores(PosicaoNaRoda, RGB);
  analogWrite(REDPIN, map(RGB[0], 0, 255, 0, 1023));
  analogWrite(GREENPIN, map(RGB[1], 0, 255, 0, 1023));
  analogWrite(BLUEPIN, map(RGB[2], 0, 255, 0, 1023));
}


void aguardandoWiFi() {
  define_led(brightness, 0, 0);
  analogWrite(REDPIN, brightness);
  // muda o brilho para o proximo loop:
  brightness = brightness + fadeAmount;
  // inverte a direcao do fade ao final do mesmo:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
