void define_led(int R, int G, int B) {
  analogWrite(REDPIN, R);
  analogWrite(GREENPIN, G);
  analogWrite(BLUEPIN, B);
}
