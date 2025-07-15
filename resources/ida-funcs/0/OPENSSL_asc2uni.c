unsigned __int8 *__cdecl OPENSSL_asc2uni(const char *asc, unsigned int asclen, unsigned __int8 **uni, int *unilen)
{
  unsigned int v4; // eax
  int v5; // edi
  unsigned __int8 *result; // eax
  int i; // ecx

  v4 = asclen;
  if ( asclen == -1 )
    v4 = strlen(asc);
  v5 = 2 * v4 + 2;
  result = (unsigned __int8 *)CRYPTO_malloc(v5, ".\\crypto\\pkcs12\\p12_utl.c", 71);
  if ( result )
  {
    for ( i = 0; i < v5 - 2; i += 2 )
    {
      result[i] = 0;
      result[i + 1] = asc[i >> 1];
    }
    result[v5 - 2] = 0;
    result[v5 - 1] = 0;
    if ( unilen )
      *unilen = v5;
    if ( uni )
      *uni = result;
  }
  return result;
}
