int __usercall policy_cache_new@<eax>(stack_st_X509_EXTENSION *x@<edi>)
{
  _DWORD *v1; // eax
  _DWORD *v2; // esi
  int result; // eax
  POLICY_CONSTRAINTS_st *ext_d2i; // eax
  POLICY_CONSTRAINTS_st *v5; // ebp
  asn1_string_st *v6; // ebx
  asn1_string_st *requireExplicitPolicy; // eax
  stack_st_POLICYINFO *v8; // eax
  stack_st_POLICY_MAPPING *v9; // eax
  asn1_string_st *v10; // eax
  int v11; // [esp+8h] [ebp-Ch] BYREF
  asn1_string_st *a; // [esp+Ch] [ebp-8h]
  int *out; // [esp+10h] [ebp-4h]

  a = 0;
  v1 = CRYPTO_malloc(20, ".\\crypto\\x509v3\\pcy_cache.c", 137);
  v2 = v1;
  if ( !v1 )
    return 0;
  v1[2] = -1;
  out = v1 + 2;
  *v1 = 0;
  v1[1] = 0;
  v1[3] = -1;
  v1[4] = -1;
  x[3].stack.data = (char **)v1;
  ext_d2i = (POLICY_CONSTRAINTS_st *)X509_get_ext_d2i(x, 401, &v11, 0);
  v5 = ext_d2i;
  if ( ext_d2i )
  {
    requireExplicitPolicy = ext_d2i->requireExplicitPolicy;
    if ( v5->requireExplicitPolicy )
    {
      if ( requireExplicitPolicy->type == 258 )
        goto LABEL_5;
      v2[3] = ASN1_INTEGER_get(v5->requireExplicitPolicy);
    }
    else if ( !v5->inhibitPolicyMapping )
    {
      goto LABEL_5;
    }
    if ( !policy_cache_set_int(v2 + 4, v5->inhibitPolicyMapping) )
      goto LABEL_5;
  }
  else if ( v11 != -1 )
  {
LABEL_5:
    v6 = a;
    goto bad_cache;
  }
  v8 = (stack_st_POLICYINFO *)X509_get_ext_d2i(x, 89, &v11, 0);
  if ( !v8 )
  {
    if ( v11 == -1 )
      return 1;
    goto LABEL_5;
  }
  result = policy_cache_create(v8, (x509_st *)x, v11);
  v11 = result;
  if ( result <= 0 )
    return result;
  v9 = (stack_st_POLICY_MAPPING *)X509_get_ext_d2i(x, 747, &v11, 0);
  if ( v9 )
  {
    v11 = policy_cache_set_mapping((x509_st *)x, v9);
    if ( v11 <= 0 )
      goto LABEL_5;
  }
  else if ( v11 != -1 )
  {
    goto LABEL_5;
  }
  v10 = (asn1_string_st *)X509_get_ext_d2i(x, 748, &v11, 0);
  v6 = v10;
  if ( v10 )
  {
    if ( policy_cache_set_int(out, v10) )
      goto LABEL_7;
  }
  else if ( v11 == -1 )
  {
    goto LABEL_7;
  }
bad_cache:
  x[2].stack.num |= 0x800u;
LABEL_7:
  if ( v5 )
    POLICY_CONSTRAINTS_free(v5);
  if ( v6 )
    ASN1_INTEGER_free(v6);
  return 1;
}
