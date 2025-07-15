lhash_node_st *__cdecl _CONF_new_section(conf_st *conf, const __m128i *section)
{
  stack_st *v2; // ebx
  lhash_node_st *v3; // esi
  unsigned int v4; // edi
  void *v5; // eax

  v2 = sk_new_null();
  if ( !v2 )
    return 0;
  v3 = (lhash_node_st *)CRYPTO_malloc(12, ".\\crypto\\conf\\conf_api.c", 278);
  if ( !v3
    || (v4 = strlen(section->m128i_i8) + 1,
        v5 = CRYPTO_malloc(v4, ".\\crypto\\conf\\conf_api.c", 281),
        (v3->data = v5) == 0) )
  {
    sk_free(v2);
    if ( v3 )
      CRYPTO_free(v3);
    return 0;
  }
  memcpy((int)v5, section, v4);
  v3->next = 0;
  v3->hash = (unsigned int)v2;
  if ( lh_insert((lhash_st *)conf->data, v3) )
    OpenSSLDie(v4, (int)v3, (int)v2, ".\\crypto\\conf\\conf_api.c", 289, "vv == NULL");
  return v3;
}
