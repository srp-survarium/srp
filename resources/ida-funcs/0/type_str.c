int __cdecl type_str(unsigned int value, int *arg)
{
  int v2; // ebx

  v2 = *arg;
  if ( (*arg & 2) != 0 && !is_printable(value) )
    v2 &= ~2u;
  if ( (v2 & 0x10) != 0 && value > 0x7F )
    v2 &= ~0x10u;
  if ( (v2 & 4) != 0 && value > 0xFF )
    v2 &= ~4u;
  if ( (v2 & 0x800) != 0 && value > 0xFFFF )
    v2 &= ~0x800u;
  if ( !v2 )
    return -1;
  *arg = v2;
  return 1;
}
