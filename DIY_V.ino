/* 
  Voltmeter with Arduino 
   modified on 21 Jul 2019 
  by Saeed Hosseini @ Electropeak 
  https://electropeak.com/learn 
*/ 
const int VoltMeter = 2; 
float V = 0.00; 
void calculate_voltage() { 
  float R1 = 10000.00; 
  float R2 = 4700.00; 
  float v_ref = 5.00; 
  float resistor_ratio = 0.00;
  float adc_value = 0.00; 
  float voltage = 0.00; 
  resistor_ratio = (R2 / (R1 + R2)); 
  for (int i = 0; i < 20 ; i++) 
  { 
    adc_value = adc_value + analogRead(VoltMeter);
    delay(3); 
  } 
  adc_value = adc_value / 20; 
  voltage = ((adc_value * v_ref) / 1024); 
  V = voltage / resistor_ratio; 
} 
void setup() { 
  Serial.begin(9600); 
} 
void loop() { 
  calculate_voltage(); 
  Serial.print(V); 
  Serial.println(" v"); 
  delay(2000); 
} 
