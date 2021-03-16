const int Ammeter = A3; 
float I = 0.00; 
void calculate_current() { 
  int sensitivity = 185; 
  int adc_value = 0; 
  float v_ref = 4.94; 
  float voltage = 0.00; 
  float pure_voltage = 0.00; 
  float offset_voltage = 2.47; 
  for (int i = 0; i < 40 ; i++) 
  { 
    adc_value = adc_value + analogRead(Ammeter); 
    delay(2); 
  } 
  adc_value = adc_value / 40; 
  voltage = ((adc_value * v_ref) / 1024); 
  pure_voltage = voltage - offset_voltage; 
 // if(pure_voltage > 0.001) pure_voltage = 0.00; 
  pure_voltage = pure_voltage * 1000; 
  I = pure_voltage / sensitivity; 
  Serial.println(String("ADC = ") + adc_value ); 
  Serial.println(String("V = ") + voltage + "v"); 
  Serial.println(String("Pure = ") + pure_voltage + "mv"); 
  Serial.println(String("I = ") + I + "A"); 
} 
void setup() { 

  Serial.begin(9600); 
} 
void loop() { 
  calculate_current(); 
  //Serial.println(String("I = ") + I + " mA");
  delay(2000); 
} 
