void InicializaMDNS() {
  int port = 80;
  String protocolo = "tcp";
  if (!MDNS.begin(host)) {
    while (1) {
      aguardandoWiFi();
      delay(1000);
    }
  }
  MDNS.addService("http", protocolo, port);
}
