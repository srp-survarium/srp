asn1_object_st *__cdecl policy_data_new(POLICYINFO_st *policy, X509_POLICY_DATA_st *cid, int crit)
{
  asn1_object_st *result; // eax
  asn1_object_st *v4; // edi
  X509_POLICY_DATA_st *v5; // esi
  stack_st *v6; // eax

  result = (asn1_object_st *)cid;
  if ( policy )
  {
    if ( !cid )
    {
      v4 = 0;
      goto LABEL_8;
    }
  }
  else if ( !cid )
  {
    return result;
  }
  result = OBJ_dup((const asn1_object_st *)cid);
  v4 = result;
  if ( !result )
    return result;
LABEL_8:
  v5 = (X509_POLICY_DATA_st *)CRYPTO_malloc(16, ".\\crypto\\x509v3\\pcy_data.c", 100);
  if ( !v5 )
    return 0;
  v6 = sk_new_null();
  v5->expected_policy_set = (stack_st_ASN1_OBJECT *)v6;
  if ( !v6 )
  {
    CRYPTO_free(v5);
    if ( v4 )
      ASN1_OBJECT_free(v4);
    return 0;
  }
  v5->flags = crit != 0 ? 0x10 : 0;
  if ( v4 )
  {
    v5->valid_policy = v4;
  }
  else
  {
    v5->valid_policy = policy->policyid;
    policy->policyid = 0;
  }
  if ( policy )
  {
    v5->qualifier_set = policy->qualifiers;
    result = (asn1_object_st *)v5;
    policy->qualifiers = 0;
  }
  else
  {
    v5->qualifier_set = 0;
    return (asn1_object_st *)v5;
  }
  return result;
}
