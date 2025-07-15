unsigned __int8 *__usercall string_to_hex@<eax>(char a1@<bl>, const char *str, int *len)
{
  _BYTE *v4; // eax
  _BYTE *v5; // ecx
  const char *v6; // edi
  _BYTE *v7; // ebp
  unsigned __int8 v8; // bl
  unsigned __int8 v9; // al
  char v10; // al
  char v11; // al
  void *stra; // [esp+4h] [ebp-4h]
  unsigned __int8 v13; // [esp+Ch] [ebp+4h]

  if ( !str )
  {
    ERR_put_error(a1, 0x22u, 113, 107, ".\\crypto\\x509v3\\v3_utl.c", 397);
    return 0;
  }
  v4 = CRYPTO_malloc((int)strlen(str) >> 1, ".\\crypto\\x509v3\\v3_utl.c", 400);
  v5 = v4;
  stra = v4;
  if ( !v4 )
  {
    ERR_put_error(a1, 0x22u, 113, 65, ".\\crypto\\x509v3\\v3_utl.c", 436);
    return 0;
  }
  v6 = str;
  v7 = v4;
  while ( *v6 )
  {
    v8 = *v6++;
    if ( v8 != 58 )
    {
      v9 = *v6++;
      v13 = v9;
      if ( !v9 )
      {
        ERR_put_error(v8, 0x22u, 113, 112, ".\\crypto\\x509v3\\v3_utl.c", 412);
        CRYPTO_free(stra);
        return 0;
      }
      if ( isupper(v8) )
        v8 = tolower(v8);
      if ( isupper(v13) )
        v10 = tolower(v13);
      else
        v10 = v13;
      if ( (unsigned __int8)(v8 - 48) > 9u )
      {
        if ( (unsigned __int8)(v8 - 97) > 5u )
          goto badhex;
        v8 -= 87;
      }
      else
      {
        v8 -= 48;
      }
      if ( (unsigned __int8)(v10 - 48) > 9u )
      {
        if ( (unsigned __int8)(v10 - 97) > 5u )
        {
badhex:
          CRYPTO_free(stra);
          ERR_put_error(v8, 0x22u, 113, 113, ".\\crypto\\x509v3\\v3_utl.c", 441);
          return 0;
        }
        v11 = v10 - 87;
      }
      else
      {
        v11 = v10 - 48;
      }
      v5 = stra;
      *v7++ = v11 | (16 * v8);
    }
  }
  if ( len )
    *len = v7 - v5;
  return v5;
}
