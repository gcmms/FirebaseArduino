void InicializaMDNS() {
  if (!MDNS.begin(host)) {
    while (1) {
      delay(1000);
    }
  }
  MDNS.addService("http", "tcp", 80);
}
