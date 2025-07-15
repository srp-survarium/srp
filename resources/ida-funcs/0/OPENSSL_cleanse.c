int __cdecl OPENSSL_cleanse(_BYTE *a1, unsigned int a2)
{
  unsigned int v3; // ecx
  int result; // eax

  v3 = a2;
  result = 0;
  if ( a2 < 7 )
  {
    if ( !a2 )
      return result;
    goto $L013little;
  }
  while ( ((unsigned __int8)a1 & 3) != 0 )
  {
    *a1 = 0;
    --v3;
    ++a1;
  }
  do
  {
    *(_DWORD *)a1 = 0;
    v3 -= 4;
    a1 += 4;
  }
  while ( (v3 & 0xFFFFFFFC) != 0 );
  for ( ; v3; ++a1 )
  {
$L013little:
    *a1 = 0;
    --v3;
  }
  return result;
}
