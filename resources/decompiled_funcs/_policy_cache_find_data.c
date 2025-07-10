X509_POLICY_DATA_st *__cdecl policy_cache_find_data(const X509_POLICY_CACHE_st *cache, const asn1_object_st *id)
{
  int v2; // eax
  stack_st_X509_POLICY_DATA *v4; // [esp-8h] [ebp-1Ch]
  char data[4]; // [esp+4h] [ebp-10h] BYREF
  const asn1_object_st *v6; // [esp+8h] [ebp-Ch]

  v4 = cache->data;
  v6 = id;
  v2 = sk_find(&v4->stack, data);
  if ( v2 == -1 )
    return 0;
  else
    return (X509_POLICY_DATA_st *)sk_value(&cache->data->stack, v2);
}
