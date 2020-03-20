float mereniVzduchu() {
  teplomer.requestTemperaturesByIndex(1); // zmer teplotu venkovniho vzduchu a vypis ji
  return teplomer.getTempCByIndex(1);
}
float mereniVody() {
  teplomer.requestTemperaturesByIndex(0); // zmer teplotu vody v kotli a vypis ji
  return teplomer.getTempCByIndex(0);
}
