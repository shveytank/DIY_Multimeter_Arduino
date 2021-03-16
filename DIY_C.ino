const int CapacitancMeter = 1; 
const int ChargePin = 13; 
const int DischargePin = 11; 
float C = 0.00; 
void calculate_capacitance() { 
  unsigned long start_time;
  unsigned long elapsed_time; 
  float microFarads; 
  float nanoFarads; 
  float r_ref = 10000.00; 
  digitalWrite(ChargePin, HIGH); 
  start_time = millis(); 
  while (analogRead(CapacitancMeter) < 648) {} 
  elapsed_time = millis() - start_time; 
  microFarads = ((float)elapsed_time / r_ref) * 1000; 
  if (microFarads > 1)  
  { 
    C = microFarads; 
  } 

  else 
  { 
    nanoFarads = microFarads * 1000.0; 
    C = nanoFarads; 
  } 
  digitalWrite(ChargePin, LOW);              
  pinMode(DischargePin, OUTPUT);             
  digitalWrite(DischargePin, LOW);          
  while (analogRead(CapacitancMeter) > 0) {} 
  pinMode(DischargePin, INPUT);             
} 

void setup() { 
  Serial.begin(9600); 
  pinMode(ChargePin, OUTPUT); 

  digitalWrite(ChargePin, LOW); 
} 
void loop() { 
  calculate_capacitance(); 
  Serial.println(C); 

  delay(2000); 
}
