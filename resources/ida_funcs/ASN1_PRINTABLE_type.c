int __cdecl ASN1_PRINTABLE_type(const unsigned __int8 *s, int len)
{
  int v2; // edx
  int v3; // edi
  int v4; // esi
  const unsigned __int8 *v5; // ecx
  unsigned __int8 v6; // al
  int result; // eax

  v2 = len;
  v3 = 0;
  v4 = 0;
  if ( len <= 0 )
    v2 = -1;
  v5 = s;
  if ( !s )
    return 19;
  v6 = *s;
  if ( !*s )
    return 19;
  do
  {
    if ( !v2-- )
      break;
    ++v5;
    if ( (v6 < 0x61u || v6 > 0x7Au)
      && (v6 < 0x41u || v6 > 0x5Au)
      && v6 != 32
      && (v6 < 0x30u || v6 > 0x39u)
      && v6 != 39
      && v6 != 40
      && v6 != 41
      && v6 != 43
      && v6 != 44
      && v6 != 45
      && v6 != 46
      && v6 != 47
      && v6 != 58
      && v6 != 61
      && v6 != 63 )
    {
      v3 = 1;
    }
    if ( (v6 & 0x80u) != 0 )
      v4 = 1;
    v6 = *v5;
  }
  while ( *v5 );
  if ( v4 )
    return 20;
  result = 22;
  if ( !v3 )
    return 19;
  return result;
}
