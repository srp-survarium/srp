char *__cdecl hex_to_string(const unsigned __int8 *buffer, int len)
{
  int v2; // esi
  char *result; // eax
  char *v4; // ecx
  const unsigned __int8 *v5; // edx
  _BYTE *v6; // ecx

  if ( !buffer )
    return 0;
  v2 = len;
  if ( !len )
    return 0;
  result = (char *)CRYPTO_malloc(3 * len + 1, ".\\crypto\\x509v3\\v3_utl.c", 370);
  if ( result )
  {
    v4 = result;
    v5 = buffer;
    if ( len > 0 )
    {
      do
      {
        *v4 = hexdig[*v5 >> 4];
        v6 = v4 + 1;
        *v6++ = hexdig[*v5 & 0xF];
        *v6 = 58;
        v4 = v6 + 1;
        ++v5;
        --v2;
      }
      while ( v2 );
    }
    *(v4 - 1) = 0;
  }
  else
  {
    ERR_put_error((int)buffer, 0x22u, 111, 65, ".\\crypto\\x509v3\\v3_utl.c", 371);
    return 0;
  }
  return result;
}
