int __cdecl ASN1_const_check_infinite_end(const unsigned __int8 **p, int len)
{
  int v2; // eax

  if ( len <= 0 )
    return 1;
  if ( len >= 2 )
  {
    v2 = (int)*p;
    if ( !**p && !*(_BYTE *)(v2 + 1) )
    {
      *p = (const unsigned __int8 *)(v2 + 2);
      return 1;
    }
  }
  return 0;
}
