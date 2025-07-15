int __usercall add_cert_dir@<eax>(int a1@<ebx>, lookup_dir_st *ctx, const char *dir, int type)
{
  const char *v4; // ecx
  const char *i; // edx
  unsigned __int8 *v6; // ebx
  unsigned int v7; // edi
  int v8; // esi
  const char *v9; // edx
  stack_st_BY_DIR_ENTRY *v10; // eax
  lookup_dir_entry_st *v11; // esi
  unsigned __int8 *v12; // eax
  stack_st *p_stack; // eax
  char *last; // [esp+4h] [ebp-8h]
  const char *v16; // [esp+8h] [ebp-4h]
  unsigned __int8 *source; // [esp+14h] [ebp+8h]

  if ( !dir || !*dir )
  {
    ERR_put_error(a1, 0xBu, 100, 113, ".\\crypto\\x509\\by_dir.c", 215);
    return 0;
  }
  v4 = dir;
  for ( i = dir; ; ++i )
  {
    source = (unsigned __int8 *)i;
    if ( *i == 59 || !*i )
      break;
LABEL_22:
    ;
  }
  v6 = (unsigned __int8 *)v4;
  v7 = i - v4;
  last = (char *)v4;
  v16 = i + 1;
  if ( i == v4 )
  {
LABEL_21:
    v4 = v16;
    goto LABEL_22;
  }
  v8 = 0;
  if ( sk_num(&ctx->dirs->stack) > 0 )
  {
    do
    {
      v9 = *(const char **)sk_value(&ctx->dirs->stack, v8);
      if ( strlen(v9) == v7 && !strncmp(v9, last, v7) )
        break;
      ++v8;
    }
    while ( v8 < sk_num(&ctx->dirs->stack) );
    v6 = (unsigned __int8 *)last;
  }
  if ( v8 < sk_num(&ctx->dirs->stack) )
  {
LABEL_20:
    i = (const char *)source;
    goto LABEL_21;
  }
  if ( !ctx->dirs )
  {
    v10 = (stack_st_BY_DIR_ENTRY *)sk_new_null();
    ctx->dirs = v10;
    if ( !v10 )
    {
      ERR_put_error((int)v6, 0xBu, 100, 65, ".\\crypto\\x509\\by_dir.c", 244);
      return 0;
    }
  }
  v11 = (lookup_dir_entry_st *)CRYPTO_malloc(12, ".\\crypto\\x509\\by_dir.c", 248);
  if ( !v11 )
    return 0;
  v11->dir_type = type;
  v11->hashes = (stack_st_BY_DIR_HASH *)sk_new((int (__cdecl *)(const void *, const void *))by_dir_hash_cmp);
  v12 = (unsigned __int8 *)CRYPTO_malloc(v7 + 1, ".\\crypto\\x509\\by_dir.c", 253);
  v11->dir = (char *)v12;
  if ( !v12 )
    goto LABEL_28;
  if ( v11->hashes )
  {
    strncpy(v12, v6, v7);
    v11->dir[v7] = 0;
    if ( !sk_push(&ctx->dirs->stack, (char *)v11) )
    {
      by_dir_entry_free(v11);
      return 0;
    }
    if ( !*source )
      return 1;
    goto LABEL_20;
  }
  CRYPTO_free(v12);
LABEL_28:
  p_stack = &v11->hashes->stack;
  if ( p_stack )
    sk_pop_free(p_stack, (void (__cdecl *)(void *))policy_node_free);
  CRYPTO_free(v11);
  return 0;
}
