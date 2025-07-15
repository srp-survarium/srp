X509_POLICY_DATA_st *__usercall policy_cache_find_data@<eax>(
        int a1@<edi>,
        const X509_POLICY_CACHE_st *cache,
        const asn1_object_st *id)
{
  int v3; // eax
  stack_st_X509_POLICY_DATA *data; // [esp-8h] [ebp-1Ch]
  char v6[4]; // [esp+4h] [ebp-10h] BYREF
  const asn1_object_st *v7; // [esp+8h] [ebp-Ch]

  data = cache->data;
  v7 = id;
  v3 = sk_find(a1, &data->stack, v6);
  if ( v3 == -1 )
    return 0;
  else
    return (X509_POLICY_DATA_st *)sk_value(&cache->data->stack, v3);
}
