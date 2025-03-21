int ledPin = 13; // Usaremos el pin 13 para el LED
char option;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  mostrarMenu(); // Mostramos el menú al iniciar
}

void loop() {
  if (Serial.available() > 0) {
    option = Serial.read();

    switch (option) {
      case '1':
        digitalWrite(ledPin, HIGH);
        Serial.println("LED encendido.");
        break;

      case '2':
        digitalWrite(ledPin, LOW);
        Serial.println("LED apagado.");
        break;

      case '3':
        Serial.println("LED en modo intermitente a 500ms.");
        for (int i = 0; i < 10; i++) { // Parpadea 10 veces a 500ms
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
        Serial.println("Modo intermitente terminado.");
        break;

      case '4':
        Serial.println("LED en modo intermitente a 1000ms.");
        for (int i = 0; i < 10; i++) { // Parpadea 10 veces a 100ms
          digitalWrite(ledPin, HIGH);
          delay(1000);
          digitalWrite(ledPin, LOW);
          delay(1000);
        }
        Serial.println("Modo intermitente terminado.");
        break;

      default:
        Serial.println("Opción inválida. Por favor elige entre 1, 2, 3 o 4.");
        break;
    }

    // Mostrar el menú nuevamente después de procesar la opción
    mostrarMenu();
  }
}

// Función para mostrar el menú
void mostrarMenu() {
  Serial.println("- Menú -");
  Serial.println("{1}. Encender LED");
  Serial.println("{2}. Apagar LED");
  Serial.println("{3}. LED en modo intermitente a 500ms");
  Serial.println("{4}. LED en modo intermitente a 100ms");
}
