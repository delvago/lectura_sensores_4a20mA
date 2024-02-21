String pyranometro;

String lectura_radiacion_solar(){
  float lectura;
  int promedio;
  String lectura_envio;
  
// Codigo si se tiene en cuenta un voltaje de referencia de 5V
  int lectura_min = 0;// Valor minimo del adc
  int lectura_max = 4095;// Depende del numero de bits del arduino
  float variable_min = 500;// Valor minimo del rango de lectura del sensor W/m2
  float variable_max = 2500;// Valor máximo del rango de lectura del sensor W/m2
  
  promedio = 0;
  for (int i=0; i<10; i++) {
    promedio = promedio + analogRead(32);//Numero del pin ADC
  }
  promedio = promedio/10;
  
  // Asegurando unos valores dentro del rango de la lectura.
  lectura = constrain(promedio, lectura_min, lectura_max);

  // Convertir la lectura en variable con interpolación lineal.
  float variable = map(lectura, lectura_min, lectura_max, variable_min, variable_max);
   
 //lectura = (promedio * 5.0)/1023.0;// 5.0 equivale al voltaje de referencia
  lectura_envio = String(variable);
  return lectura_envio;
}

String lectura_simple(){
  int promedio = 0;
  for (int i=0; i<10; i++) {
    promedio = promedio + analogRead(33);//Numero del pin ADC
  }
  promedio = promedio/10;
  int lect = analogRead(33);

  //float lectura = (promedio * 4.0)/4095.0;
  //float lectura = map(promedio, 0, 4095, 500, 2500);
  //String envio = String(lectura);
  String lectu = String(lect);

  return lectu;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {
   //pyranometro = lectura_radiacion_solar();
   pyranometro = lectura_simple();
   Serial.print("Lectura prueba: ");
   Serial.println(pyranometro);
   Serial.println("--------------");

   delay(500);
}
