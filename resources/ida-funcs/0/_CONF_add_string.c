int __cdecl _CONF_add_string(conf_st *conf, CONF_VALUE *section, CONF_VALUE *value)
{
  char *v3; // edi
  int result; // eax
  char *v5; // eax
  void **v6; // esi

  v3 = section->value;
  value->section = section->section;
  result = sk_push((stack_st *)v3, (char *)value);
  if ( result )
  {
    v5 = (char *)lh_insert((lhash_st *)conf->data, (lhash_node_st *)value);
    v6 = (void **)v5;
    if ( v5 )
    {
      sk_delete_ptr((stack_st *)v3, v5);
      CRYPTO_free(v6[1]);
      CRYPTO_free(v6[2]);
      CRYPTO_free(v6);
    }
    return 1;
  }
  return result;
}
