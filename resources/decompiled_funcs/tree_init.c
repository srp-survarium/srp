int __cdecl tree_init(X509_POLICY_TREE_st **ptree, stack_st_X509 *certs)
{
  unsigned int flags; // ecx
  __int16 v3; // si
  int v4; // eax
  int v5; // ebp
  int v6; // ebx
  int result; // eax
  unsigned int v8; // edi
  x509_st *v9; // esi
  const X509_POLICY_CACHE_st *v10; // eax
  unsigned int ex_flags; // ecx
  int explicit_skip; // eax
  X509_POLICY_TREE_st *v13; // eax
  X509_POLICY_TREE_st *v14; // ebx
  X509_POLICY_LEVEL_st *v15; // eax
  X509_POLICY_LEVEL_st *levels; // edi
  asn1_object_st *v17; // eax
  const X509_POLICY_DATA_st *v18; // eax
  int v19; // eax
  char *v20; // esi
  const X509_POLICY_CACHE_st *v21; // ebp
  int v22; // ecx
  int any_skip; // eax
  int v24; // eax
  int map_skip; // ebp
  int v26; // [esp+10h] [ebp-14h]
  int v27; // [esp+14h] [ebp-10h]
  int v28; // [esp+14h] [ebp-10h]
  int v29; // [esp+18h] [ebp-Ch]
  int v30; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v3 = flags;
  v27 = 1;
  *ptree = 0;
  v4 = sk_num(&certs->stack);
  v5 = v4;
  if ( (v3 & 0x100) != 0 )
  {
    v6 = 0;
    v26 = 0;
  }
  else
  {
    v26 = v4 + 1;
    v6 = v4 + 1;
  }
  if ( (v3 & 0x200) != 0 )
    v29 = 0;
  else
    v29 = v4 + 1;
  if ( (v3 & 0x400) != 0 )
    v30 = 0;
  else
    v30 = v4 + 1;
  if ( v4 == 1 )
    return 1;
  v8 = v4 - 2;
  i = v4 - 2;
  if ( v4 - 2 >= 0 )
  {
    while ( 1 )
    {
      v9 = (x509_st *)sk_value(&certs->stack, v8);
      X509_check_purpose(v8, v9, -1, -1);
      v10 = policy_cache_set(v9);
      if ( !v10 )
        return 0;
      ex_flags = v9->ex_flags;
      if ( (ex_flags & 0x800) != 0 )
      {
        v27 = -1;
      }
      else if ( v27 == 1 && !v10->data )
      {
        v27 = 2;
      }
      if ( v6 > 0 )
      {
        if ( (ex_flags & 0x20) == 0 )
          v26 = --v6;
        explicit_skip = v10->explicit_skip;
        if ( explicit_skip != -1 && explicit_skip < v6 )
        {
          v26 = explicit_skip;
          v6 = explicit_skip;
        }
      }
      if ( (--v8 & 0x80000000) != 0 )
      {
        result = v27;
        if ( v27 == 1 )
          break;
        if ( v27 == 2 && !v6 )
          return 6;
        return result;
      }
    }
  }
  v13 = (X509_POLICY_TREE_st *)CRYPTO_malloc(24, ".\\crypto\\x509v3\\pcy_tree.c", 222);
  v14 = v13;
  if ( !v13 )
    return 0;
  v13->flags = 0;
  v15 = (X509_POLICY_LEVEL_st *)CRYPTO_malloc(16 * v5, ".\\crypto\\x509v3\\pcy_tree.c", 228);
  v14->levels = v15;
  v14->nlevel = 0;
  v14->extra_data = 0;
  v14->auth_policies = 0;
  v14->user_policies = 0;
  if ( !v15 )
  {
    CRYPTO_free(v14);
    return 0;
  }
  memset((int)v15, 0, 16 * v5);
  levels = v14->levels;
  v14->nlevel = v5;
  v17 = OBJ_nid2obj(0x2EAu);
  v18 = policy_data_new(0, v17, 0);
  if ( !v18 || !level_add_node(levels, v18, 0, v14) )
  {
    X509_policy_tree_free(v14);
    return 0;
  }
  v19 = i;
  v28 = i;
  if ( i >= 0 )
  {
    while ( 1 )
    {
      ++levels;
      v20 = sk_value(&certs->stack, v19);
      v21 = policy_cache_set((x509_st *)v20);
      CRYPTO_add_lock((int *)v20 + 4, 1, 3, ".\\crypto\\x509v3\\pcy_tree.c", 258);
      levels->cert = (x509_st *)v20;
      if ( !v21->anyPolicy )
        levels->flags |= 0x200u;
      v22 = v29;
      if ( v29 )
      {
        if ( (v20[40] & 0x20) == 0 )
          v22 = --v29;
        any_skip = v21->any_skip;
        if ( any_skip >= 0 && any_skip < v22 )
          v29 = v21->any_skip;
      }
      else if ( (v20[40] & 0x20) == 0 || !v28 )
      {
        levels->flags |= 0x200u;
      }
      v24 = v30;
      if ( v30 )
      {
        if ( (v20[40] & 0x20) == 0 )
          v24 = --v30;
        map_skip = v21->map_skip;
        if ( map_skip >= 0 && map_skip < v24 )
          v30 = map_skip;
      }
      else
      {
        levels->flags |= 0x400u;
      }
      if ( --v28 < 0 )
        break;
      v19 = v28;
    }
  }
  *ptree = v14;
  return 4 * (v26 == 0) + 1;
}
