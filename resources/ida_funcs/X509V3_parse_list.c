stack_st_CONF_VALUE *__cdecl X509V3_parse_list(char *line)
{
  char *v1; // ebx
  _BYTE *v2; // esi
  char *v3; // edi
  char v4; // al
  int v5; // ebp
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  stack_st_CONF_VALUE *extlist; // [esp+10h] [ebp-8h] BYREF
  void *v12; // [esp+14h] [ebp-4h]

  v1 = 0;
  extlist = 0;
  v12 = BUF_strdup(line);
  v2 = v12;
  v3 = (char *)v12;
  v4 = *(_BYTE *)v12;
  v5 = 1;
  if ( *(_BYTE *)v12 )
  {
    do
    {
      if ( v4 == 13 || v4 == 10 )
        break;
      if ( v5 == 1 )
      {
        if ( v4 == 58 )
        {
          v5 = 2;
          *v2 = 0;
          v1 = strip_spaces(v3);
          if ( !v1 )
          {
            ERR_put_error(0x22u, 109, 108, ".\\crypto\\x509v3\\v3_utl.c", 271);
            goto LABEL_24;
          }
          v3 = v2 + 1;
        }
        else if ( v4 == 44 )
        {
          *v2 = 0;
          v7 = strip_spaces(v3);
          v1 = v7;
          v3 = v2 + 1;
          if ( !v7 )
          {
            ERR_put_error(0x22u, 109, 108, ".\\crypto\\x509v3\\v3_utl.c", 283);
            goto LABEL_24;
          }
          X509V3_add_value(v7, 0, &extlist);
        }
      }
      else if ( v4 == 44 )
      {
        v5 = 1;
        *v2 = 0;
        v6 = strip_spaces(v3);
        if ( !v6 )
        {
          ERR_put_error(0x22u, 109, 109, ".\\crypto\\x509v3\\v3_utl.c", 299);
          goto LABEL_24;
        }
        X509V3_add_value(v1, v6, &extlist);
        v1 = 0;
        v3 = v2 + 1;
      }
      v4 = *++v2;
    }
    while ( v4 );
    if ( v5 != 2 )
      goto LABEL_22;
    v8 = strip_spaces(v3);
    if ( !v8 )
    {
      ERR_put_error(0x22u, 109, 109, ".\\crypto\\x509v3\\v3_utl.c", 316);
      goto LABEL_24;
    }
    X509V3_add_value(v1, v8, &extlist);
    goto LABEL_26;
  }
LABEL_22:
  v9 = strip_spaces(v3);
  if ( v9 )
  {
    X509V3_add_value(v9, 0, &extlist);
LABEL_26:
    CRYPTO_free(v12);
    return extlist;
  }
  ERR_put_error(0x22u, 109, 108, ".\\crypto\\x509v3\\v3_utl.c", 326);
LABEL_24:
  CRYPTO_free(v12);
  sk_pop_free(&extlist->stack, (void (__cdecl *)(void *))X509V3_conf_free);
  return 0;
}
