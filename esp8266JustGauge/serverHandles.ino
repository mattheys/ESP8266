void handleRoot() {
  server.send(200, "text/html", "<html>\n  <head>\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  </head>\n  <body>\n    <div id=\"gauge\"></div>\n    <script src=\"raphael-2.1.4.min.js\"></script>\n    <script src=\"justgage.js\"></script>\n    <script>\n      var g = new JustGage({\n        id: \"gauge\",\n        value: 67,\n        min: 0,\n        max: 100,\n        title: \"Visitors\"\n      });\n    </script>\n  </body>\n</html>");
}

void handlejQuery() {
  server.send(200, "application/javascript", jq());
}

void handleRaphael() {
  server.send(200, "application/javascript", raph());
}

void handleJustGauge() {
  server.send(200, "application/javascript", jg());
}

void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += ( server.method() == HTTP_GET ) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for ( uint8_t i = 0; i < server.args(); i++ ) {
    message += " " + server.argName ( i ) + ": " + server.arg ( i ) + "\n";
  }

  server.send ( 404, "text/plain", message );
}
