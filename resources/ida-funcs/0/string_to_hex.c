unsigned __int8 *__cdecl string_to_hex(const char *str, int *len)
{
  _BYTE *v3; // eax
  _BYTE *v4; // ecx
  const char *v5; // edi
  _BYTE *v6; // ebp
  unsigned __int8 v7; // bl
  unsigned __int8 v8; // al
  char v9; // al
  char v10; // bl
  char v11; // al
  void *stra; // [esp+4h] [ebp-4h]
  unsigned __int8 v13; // [esp+Ch] [ebp+4h]

  if ( !str )
  {
    ERR_put_error(0x22u, 113, 107, ".\\crypto\\x509v3\\v3_utl.c", 397);
    return 0;
  }
  v3 = CRYPTO_malloc((int)strlen(str) >> 1, ".\\crypto\\x509v3\\v3_utl.c", 400);
  v4 = v3;
  stra = v3;
  if ( !v3 )
  {
    ERR_put_error(0x22u, 113, 65, ".\\crypto\\x509v3\\v3_utl.c", 436);
    return 0;
  }
  v5 = str;
  v6 = v3;
  while ( *v5 )
  {
    v7 = *v5++;
    if ( v7 != 58 )
    {
      v8 = *v5++;
      v13 = v8;
      if ( !v8 )
      {
        ERR_put_error(0x22u, 113, 112, ".\\crypto\\x509v3\\v3_utl.c", 412);
        CRYPTO_free(stra);
        return 0;
      }
      if ( isupper(v7) )
        v7 = tolower(v7);
      if ( isupper(v13) )
        v9 = tolower(v13);
      else
        v9 = v13;
      if ( (unsigned __int8)(v7 - 48) > 9u )
      {
        if ( (unsigned __int8)(v7 - 97) > 5u )
          goto badhex;
        v10 = v7 - 87;
      }
      else
      {
        v10 = v7 - 48;
      }
      if ( (unsigned __int8)(v9 - 48) > 9u )
      {
        if ( (unsigned __int8)(v9 - 97) > 5u )
        {
badhex:
          CRYPTO_free(stra);
          ERR_put_error(0x22u, 113, 113, ".\\crypto\\x509v3\\v3_utl.c", 441);
          return 0;
        }
        v11 = v9 - 87;
      }
      else
      {
        v11 = v9 - 48;
      }
      v4 = stra;
      *v6++ = v11 | (16 * v10);
    }
  }
  if ( len )
    *len = v6 - v4;
  return v4;
}
