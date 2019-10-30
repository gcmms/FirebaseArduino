void InicializaPinos(){
  //Iniciando os pinos como saida e com o valor alto (ligado)
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  
  analogWrite(REDPIN, HIGH);
  analogWrite(GREENPIN, HIGH);
  analogWrite(BLUEPIN, HIGH);
  
  delay(1000);
}
