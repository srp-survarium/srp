void __cdecl policy_data_free(X509_POLICY_DATA_st *data)
{
  ASN1_OBJECT_free(data->valid_policy);
  if ( (data->flags & 4) == 0 )
    sk_pop_free(&data->qualifier_set->stack, (void (__cdecl *)(void *))POLICYQUALINFO_free);
  sk_pop_free(&data->expected_policy_set->stack, (void (__cdecl *)(void *))ASN1_OBJECT_free);
  CRYPTO_free(data);
}
