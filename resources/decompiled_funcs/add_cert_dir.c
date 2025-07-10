int __cdecl add_cert_dir(lookup_dir_st *ctx, const char *dir, int type)
{
  const char *v3; // ecx
  const char *i; // edx
  unsigned __int8 *v5; // ebx
  unsigned int v6; // edi
  int v7; // esi
  const char *v8; // edx
  stack_st_BY_DIR_ENTRY *v9; // eax
  lookup_dir_entry_st *v10; // esi
  unsigned __int8 *v11; // eax
  stack_st *p_stack; // eax
  char *last; // [esp+4h] [ebp-8h]
  const char *v15; // [esp+8h] [ebp-4h]
  unsigned __int8 *source; // [esp+14h] [ebp+8h]

  if ( !dir || !*dir )
  {
    ERR_put_error(0xBu, 100, 113, ".\\crypto\\x509\\by_dir.c", 215);
    return 0;
  }
  v3 = dir;
  for ( i = dir; ; ++i )
  {
    source = (unsigned __int8 *)i;
    if ( *i == 59 || !*i )
      break;
LABEL_22:
    ;
  }
  v5 = (unsigned __int8 *)v3;
  v6 = i - v3;
  last = (char *)v3;
  v15 = i + 1;
  if ( i == v3 )
  {
LABEL_21:
    v3 = v15;
    goto LABEL_22;
  }
  v7 = 0;
  if ( sk_num(&ctx->dirs->stack) > 0 )
  {
    do
    {
      v8 = *(const char **)sk_value(&ctx->dirs->stack, v7);
      if ( strlen(v8) == v6 && !strncmp(v8, last, v6) )
        break;
      ++v7;
    }
    while ( v7 < sk_num(&ctx->dirs->stack) );
    v5 = (unsigned __int8 *)last;
  }
  if ( v7 < sk_num(&ctx->dirs->stack) )
  {
LABEL_20:
    i = (const char *)source;
    goto LABEL_21;
  }
  if ( !ctx->dirs )
  {
    v9 = (stack_st_BY_DIR_ENTRY *)sk_new_null();
    ctx->dirs = v9;
    if ( !v9 )
    {
      ERR_put_error(0xBu, 100, 65, ".\\crypto\\x509\\by_dir.c", 244);
      return 0;
    }
  }
  v10 = (lookup_dir_entry_st *)CRYPTO_malloc(12, ".\\crypto\\x509\\by_dir.c", 248);
  if ( !v10 )
    return 0;
  v10->dir_type = type;
  v10->hashes = (stack_st_BY_DIR_HASH *)sk_new((int (__cdecl *)(const void *, const void *))by_dir_hash_cmp);
  v11 = (unsigned __int8 *)CRYPTO_malloc(v6 + 1, ".\\crypto\\x509\\by_dir.c", 253);
  v10->dir = (char *)v11;
  if ( !v11 )
    goto LABEL_28;
  if ( v10->hashes )
  {
    strncpy(v11, v5, v6);
    v10->dir[v6] = 0;
    if ( !sk_push(&ctx->dirs->stack, (char *)v10) )
    {
      by_dir_entry_free(v10);
      return 0;
    }
    if ( !*source )
      return 1;
    goto LABEL_20;
  }
  CRYPTO_free(v11);
LABEL_28:
  p_stack = &v10->hashes->stack;
  if ( p_stack )
    sk_pop_free(p_stack, (void (__cdecl *)(void *))policy_node_free);
  CRYPTO_free(v10);
  return 0;
}
