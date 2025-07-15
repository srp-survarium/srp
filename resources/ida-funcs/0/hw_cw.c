int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
    }
  }
  if ( ((unsigned int)&loc_30000 & abstr) != 0 )
  {
    if ( (HINSTANCE__ *)((unsigned int)&loc_30000 & abstr) == &_sbh_sizeHeaderList )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}
