CONF_VALUE *__cdecl _CONF_new_section(conf_st *conf, char *section)
{
  stack_st *v2; // ebx
  unsigned __int8 **v3; // esi
  unsigned int v4; // edi
  unsigned __int8 *v5; // eax

  v2 = sk_new_null();
  if ( !v2 )
    return 0;
  v3 = (unsigned __int8 **)CRYPTO_malloc(12, ".\\crypto\\conf\\conf_api.c", 278);
  if ( !v3
    || (v4 = strlen(section) + 1,
        v5 = (unsigned __int8 *)CRYPTO_malloc(v4, ".\\crypto\\conf\\conf_api.c", 281),
        (*v3 = v5) == 0) )
  {
    sk_free(v2);
    if ( v3 )
      CRYPTO_free(v3);
    return 0;
  }
  memcpy(v5, (unsigned __int8 *)section, v4);
  v3[1] = 0;
  v3[2] = (unsigned __int8 *)v2;
  if ( lh_insert((lhash_st *)conf->data, v3) )
    OpenSSLDie(v4, (unsigned int)v3, ".\\crypto\\conf\\conf_api.c", 289, "vv == NULL");
  return (CONF_VALUE *)v3;
}
