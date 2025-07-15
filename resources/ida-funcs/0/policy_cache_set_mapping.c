int __cdecl policy_cache_set_mapping(x509_st *x, stack_st_POLICY_MAPPING *maps)
{
  x509_st *v2; // edi
  X509_POLICY_CACHE_st *policy_cache; // ebx
  int v4; // ebp
  const asn1_object_st **v6; // edi
  X509_POLICY_DATA_st *data; // eax
  X509_POLICY_DATA_st *v8; // esi
  stack_st_POLICYQUALINFO *qualifier_set; // ecx
  int v10; // [esp+10h] [ebp-4h]

  v2 = x;
  policy_cache = x->policy_cache;
  v4 = 0;
  v10 = 0;
  if ( !sk_num(&maps->stack) )
  {
    v10 = -1;
    goto LABEL_3;
  }
  if ( sk_num(&maps->stack) <= 0 )
  {
LABEL_17:
    v10 = 1;
    goto LABEL_4;
  }
  while ( 1 )
  {
    v6 = (const asn1_object_st **)sk_value(&maps->stack, v4);
    if ( OBJ_obj2nid(v6[1]) == (void *)746 || OBJ_obj2nid(*v6) == (void *)746 )
      break;
    data = policy_cache_find_data((int)v6, policy_cache, *v6);
    v8 = data;
    if ( data )
    {
      data->flags |= 1u;
LABEL_14:
      if ( !sk_push(&v8->expected_policy_set->stack, (char *)v6[1]) )
        goto LABEL_4;
      v6[1] = 0;
      goto LABEL_16;
    }
    if ( policy_cache->anyPolicy )
    {
      v8 = (X509_POLICY_DATA_st *)policy_data_new(0, (asn1_object_st *)*v6, policy_cache->anyPolicy->flags & 0x10);
      if ( !v8 )
        goto LABEL_4;
      qualifier_set = policy_cache->anyPolicy->qualifier_set;
      v8->flags |= 6u;
      v8->qualifier_set = qualifier_set;
      if ( !sk_push(&policy_cache->data->stack, (char *)v8) )
      {
        policy_data_free(v8);
        goto LABEL_4;
      }
      goto LABEL_14;
    }
LABEL_16:
    if ( ++v4 >= sk_num(&maps->stack) )
      goto LABEL_17;
  }
  v2 = x;
  v10 = -1;
LABEL_3:
  v2->ex_flags |= 0x800u;
LABEL_4:
  sk_pop_free(&maps->stack, (void (__cdecl *)(void *))POLICY_MAPPING_free);
  return v10;
}
