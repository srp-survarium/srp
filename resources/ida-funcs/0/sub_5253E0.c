unsigned int sub_5253E0()
{
  unsigned int seed; // [esp+0h] [ebp-4h]

  seed = _time64(0) % 0xFFFFFFFFLL;
  srand(seed);
  return rand();
}
