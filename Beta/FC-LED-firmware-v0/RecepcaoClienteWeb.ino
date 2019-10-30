void RecepcaoClienteWeb() {
  String red = servidorWeb.arg(0);
  String green = servidorWeb.arg(1);
  String blue = servidorWeb.arg(2);
  
  analogWrite(REDPIN, 1023 - red.toInt());
  analogWrite(GREENPIN, 1023 - green.toInt());
  analogWrite(BLUEPIN, 1023 - blue.toInt());

  ultimaTrocaCor = millis();
  
  servidorWeb.send(200, "text/html", WebPage());
}
