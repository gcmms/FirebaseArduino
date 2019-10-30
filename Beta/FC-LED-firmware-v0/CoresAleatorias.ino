void CoresAleatorias(int PosicaoNaRoda, int* RGB) {
  RodaDeCores(PosicaoNaRoda, RGB);
  analogWrite(REDPIN, map(RGB[0], 0, 255, 0, 1023));
  analogWrite(GREENPIN, map(RGB[1], 0, 255, 0, 1023));
  analogWrite(BLUEPIN, map(RGB[2], 0, 255, 0, 1023));
}
