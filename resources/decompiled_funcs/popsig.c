int popsig()
{
  signal(22, savsig[22]);
  signal(8, savsig[8]);
  signal(4, savsig[4]);
  signal(2, savsig[2]);
  signal(11, savsig[11]);
  return signal(15, savsig[15]);
}
