int __usercall X509V3_add_value@<eax>(
        stack_st_CONF_VALUE **a1@<ebx>,
        char *name,
        char *value,
        stack_st_CONF_VALUE **extlist)
{
  char *v4; // esi
  char *v5; // edi
  char *v6; // ebp
  stack_st_CONF_VALUE *v7; // eax

  v4 = 0;
  v5 = 0;
  v6 = 0;
  if ( (!name || (v5 = BUF_strdup(name)) != 0) && (!value || (v6 = BUF_strdup(value)) != 0) )
  {
    v4 = (char *)CRYPTO_malloc(12, ".\\crypto\\x509v3\\v3_utl.c", 88);
    if ( v4 )
    {
      a1 = extlist;
      if ( *extlist || (v7 = (stack_st_CONF_VALUE *)sk_new_null(), (*extlist = v7) != 0) )
      {
        *(_DWORD *)v4 = 0;
        *((_DWORD *)v4 + 1) = v5;
        *((_DWORD *)v4 + 2) = v6;
        if ( sk_push(&(*extlist)->stack, v4) )
          return 1;
      }
    }
  }
  ERR_put_error((int)a1, 0x22u, 105, 65, ".\\crypto\\x509v3\\v3_utl.c", 96);
  if ( v4 )
    CRYPTO_free(v4);
  if ( v5 )
    CRYPTO_free(v5);
  if ( v6 )
    CRYPTO_free(v6);
  return 0;
}
