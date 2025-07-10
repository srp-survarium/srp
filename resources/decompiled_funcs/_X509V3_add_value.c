int __cdecl X509V3_add_value(const char *name, const char *value, stack_st_CONF_VALUE **extlist)
{
  char *v3; // esi
  char *v4; // edi
  char *v5; // ebp
  stack_st_CONF_VALUE *v6; // eax

  v3 = 0;
  v4 = 0;
  v5 = 0;
  if ( (!name || (v4 = BUF_strdup(name)) != 0) && (!value || (v5 = BUF_strdup(value)) != 0) )
  {
    v3 = (char *)CRYPTO_malloc(12, ".\\crypto\\x509v3\\v3_utl.c", 88);
    if ( v3 )
    {
      if ( *extlist || (v6 = (stack_st_CONF_VALUE *)sk_new_null(), (*extlist = v6) != 0) )
      {
        *(_DWORD *)v3 = 0;
        *((_DWORD *)v3 + 1) = v4;
        *((_DWORD *)v3 + 2) = v5;
        if ( sk_push(&(*extlist)->stack, v3) )
          return 1;
      }
    }
  }
  ERR_put_error(0x22u, 105, 65, ".\\crypto\\x509v3\\v3_utl.c", 96);
  if ( v3 )
    CRYPTO_free(v3);
  if ( v4 )
    CRYPTO_free(v4);
  if ( v5 )
    CRYPTO_free(v5);
  return 0;
}
