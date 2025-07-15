asn1_object_st *__cdecl policy_data_new(POLICYINFO_st *policy, asn1_object_st *cid, int crit)
{
  asn1_object_st *result; // eax
  asn1_object_st *v4; // edi
  asn1_object_st *v5; // esi
  stack_st *v6; // eax

  result = cid;
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
  result = OBJ_dup((int)policy, cid);
  v4 = result;
  if ( !result )
    return result;
LABEL_8:
  v5 = (asn1_object_st *)CRYPTO_malloc(16, ".\\crypto\\x509v3\\pcy_data.c", 100);
  if ( !v5 )
    return 0;
  v6 = sk_new_null();
  v5->length = (int)v6;
  if ( !v6 )
  {
    CRYPTO_free(v5);
    if ( v4 )
      ASN1_OBJECT_free(v4);
    return 0;
  }
  v5->sn = crit != 0 ? (const char *)0x10 : 0;
  if ( v4 )
  {
    v5->ln = (const char *)v4;
  }
  else
  {
    v5->ln = (const char *)policy->policyid;
    policy->policyid = 0;
  }
  if ( policy )
  {
    v5->nid = (int)policy->qualifiers;
    result = v5;
    policy->qualifiers = 0;
  }
  else
  {
    v5->nid = 0;
    return v5;
  }
  return result;
}
