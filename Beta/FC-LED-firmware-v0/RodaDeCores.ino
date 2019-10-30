void RodaDeCores(int PosicaoNaRoda, int* RGB) {
  PosicaoNaRoda = PosicaoNaRoda % 256;

  if (PosicaoNaRoda < 85) {
    RGB[0] = PosicaoNaRoda * 3;
    RGB[1] = 255 - PosicaoNaRoda * 3;
    RGB[2] = 0;
  }
  else if (PosicaoNaRoda < 170) {
    PosicaoNaRoda -= 85;
    RGB[2] = PosicaoNaRoda * 3;
    RGB[0] = 255 - PosicaoNaRoda * 3;
    RGB[1] = 0;
  }
  else if (PosicaoNaRoda < 255) {
    PosicaoNaRoda -= 170;
    RGB[1] = PosicaoNaRoda * 3;
    RGB[2] = 255 - PosicaoNaRoda * 3;
    RGB[0] = 0;
  }
  else
  {
    PosicaoNaRoda -= 255;
    RGB[0] = PosicaoNaRoda * 3;
    RGB[1] = 255 - PosicaoNaRoda * 3;
    RGB[2] = 0;
  }
}
