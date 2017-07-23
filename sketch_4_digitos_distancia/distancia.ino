/* distancia en mm */

long measure()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement();
  }
  return measureSum / MEASURE_SAMPLES;
}


long singleMeasurement()
{
  long duration = 0;
  // Measure: Lanzamos el trigger
  digitalWrite(TRIGGER, HIGH);
  // esperamos
  delayMicroseconds(11);
  // cerramos el trigger
  digitalWrite(TRIGGER, LOW);
  // esperamos el echo
  duration = pulseIn(ECHO, HIGH);
  return (long) (((float) duration / USONIC_DIV) * 10.0);
}

