int __cdecl asn1_check_eoc(int len)
{
  const unsigned __int8 **in; // ecx
  int v2; // eax

  if ( len < 2 )
    return 0;
  v2 = (int)*in;
  if ( **in || *(_BYTE *)(v2 + 1) )
    return 0;
  *in = (const unsigned __int8 *)(v2 + 2);
  return 1;
}
