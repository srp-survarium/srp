int __cdecl X509_NAME_print(bio_st *bp, X509_name_st *name)
{
  char *v2; // eax
  _BYTE *v4; // esi
  const char *v5; // ebp
  char v6; // al
  char v7; // al
  int v8; // esi
  char *str; // [esp+4h] [ebp-4h]

  v2 = X509_NAME_oneline(name, 0, 0);
  str = v2;
  if ( *v2 )
  {
    v4 = v2 + 1;
    v5 = v2 + 1;
    while ( 1 )
    {
      if ( *v4 == 47
        && (v6 = v4[1], v6 >= 65)
        && v6 <= 90
        && ((v7 = v4[2], v7 == 61) || v7 >= 65 && v7 <= 90 && v4[3] == 61)
        || !*v4 )
      {
        if ( BIO_write(bp, v5, v4 - v5) != v4 - v5 )
          goto err_152;
        v5 = v4 + 1;
        if ( !*v4 )
          break;
        if ( BIO_write(bp, (const char *)&stru_95AF78.m_key_bindings[32], 2) != 2 )
        {
err_152:
          ERR_put_error(0xBu, 117, 7, ".\\crypto\\asn1\\t_x509.c", 489);
          v8 = 0;
          goto LABEL_19;
        }
        if ( !*v4 )
          break;
      }
      ++v4;
    }
    v8 = 1;
LABEL_19:
    CRYPTO_free(str);
    return v8;
  }
  else
  {
    CRYPTO_free(v2);
    return 1;
  }
}
