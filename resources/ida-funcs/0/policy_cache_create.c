int __usercall policy_cache_create@<eax>(stack_st_POLICYINFO *policies@<ebx>, x509_st *x, int crit)
{
  X509_POLICY_CACHE_st *policy_cache; // ebp
  int v4; // edi
  stack_st *v5; // eax
  char *v6; // eax
  asn1_object_st *v7; // eax
  X509_POLICY_DATA_st *v8; // esi
  const stack_st *v10; // [esp+0h] [ebp-14h]
  int v11; // [esp+10h] [ebp-4h]

  policy_cache = x->policy_cache;
  v4 = 0;
  v11 = 0;
  if ( sk_num(v10) )
  {
    v5 = sk_new((int (__cdecl *)(const void *, const void *))policy_data_cmp);
    policy_cache->data = (stack_st_X509_POLICY_DATA *)v5;
    if ( v5 )
    {
      if ( sk_num(&policies->stack) <= 0 )
      {
LABEL_11:
        v11 = 1;
      }
      else
      {
        while ( 1 )
        {
          v6 = sk_value(&policies->stack, v4);
          v7 = policy_data_new((POLICYINFO_st *)v6, 0, crit);
          v8 = (X509_POLICY_DATA_st *)v7;
          if ( !v7 )
            break;
          if ( OBJ_obj2nid((const asn1_object_st *)v7->ln) == (void *)746 )
          {
            if ( policy_cache->anyPolicy )
              goto LABEL_12;
            policy_cache->anyPolicy = v8;
          }
          else
          {
            if ( sk_find(v4, &policy_cache->data->stack, (char *)v8) != -1 )
            {
LABEL_12:
              x->ex_flags |= 0x800u;
              v11 = -1;
LABEL_13:
              policy_data_free(v8);
              break;
            }
            if ( !sk_push(&policy_cache->data->stack, (char *)v8) )
              goto LABEL_13;
          }
          if ( ++v4 >= sk_num(&policies->stack) )
            goto LABEL_11;
        }
      }
    }
  }
  sk_pop_free(&policies->stack, (void (__cdecl *)(void *))POLICYINFO_free);
  if ( v11 <= 0 )
  {
    sk_pop_free(&policy_cache->data->stack, (void (__cdecl *)(void *))policy_data_free);
    policy_cache->data = 0;
  }
  return v11;
}
