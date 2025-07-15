int __thiscall vostok::round_up_to_the_next_power_of_two(void *v)
{
  unsigned int v1; // ecx
  unsigned int v2; // ecx

  v1 = (((((unsigned int)v - 1) >> 1) | ((unsigned int)v - 1)) >> 2)
     | (((unsigned int)v - 1) >> 1)
     | ((unsigned int)v - 1);
  v2 = (((v1 >> 4) | v1) >> 8) | (v1 >> 4) | v1;
  return (v2 | HIWORD(v2)) + 1;
}
