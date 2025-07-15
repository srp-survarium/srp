int __cdecl crl_cb(int operation, struct ASN1_VALUE_st **pval)
{
  X509_crl_st *v2; // ebx
  const env_md_st *v3; // eax
  ISSUING_DIST_POINT_st *ext_d2i; // eax
  asn1_string_st *v5; // eax
  const stack_st *p_stack; // ebp
  int v7; // edi
  char *v8; // esi
  int v9; // eax
  int (__cdecl *crl_init)(X509_crl_st *); // eax
  int (__cdecl *crl_free)(X509_crl_st *); // eax
  const x509_crl_method_st *v13; // ecx

  v2 = (X509_crl_st *)*pval;
  if ( operation == 1 )
  {
    v13 = default_crl_method;
    v2->idp = 0;
    v2->akid = 0;
    v2->flags = 0;
    v2->idp_flags = 0;
    v2->idp_reasons = 32895;
    v2->meth = v13;
    v2->meth_data = 0;
    v2->issuers = 0;
    v2->crl_number = 0;
    v2->base_crl_number = 0;
    return 1;
  }
  if ( operation != 3 )
  {
    if ( operation == 5 )
    {
      v3 = EVP_sha1();
      X509_CRL_digest(v2, v3, v2->sha1_hash, 0);
      ext_d2i = (ISSUING_DIST_POINT_st *)X509_CRL_get_ext_d2i(v2, 770, 0, 0);
      v2->idp = ext_d2i;
      if ( ext_d2i )
        setup_idp(ext_d2i, v2);
      v2->akid = (AUTHORITY_KEYID_st *)X509_CRL_get_ext_d2i(v2, 90, 0, 0);
      v2->crl_number = (asn1_string_st *)X509_CRL_get_ext_d2i(v2, 88, 0, 0);
      v5 = (asn1_string_st *)X509_CRL_get_ext_d2i(v2, 140, 0, 0);
      v2->base_crl_number = v5;
      if ( v5 && !v2->crl_number )
        v2->flags |= 0x80u;
      p_stack = &v2->crl->extensions->stack;
      v7 = 0;
      if ( sk_num(p_stack) > 0 )
      {
        while ( 1 )
        {
          v8 = sk_value(p_stack, v7);
          v9 = OBJ_obj2nid(*(const asn1_object_st **)v8);
          if ( v9 == 857 )
            v2->flags |= 0x1000u;
          if ( *((int *)v8 + 1) > 0 )
            break;
          if ( ++v7 >= sk_num(p_stack) )
            goto LABEL_18;
        }
        if ( v9 != 770 && v9 != 140 )
          v2->flags |= 0x200u;
      }
LABEL_18:
      if ( !crl_set_issuers(v2) )
        return 0;
      crl_init = v2->meth->crl_init;
      if ( crl_init )
      {
        if ( !crl_init(v2) )
          return 0;
      }
    }
    return 1;
  }
  crl_free = v2->meth->crl_free;
  if ( crl_free && !crl_free((X509_crl_st *)*pval) )
    return 0;
  if ( v2->akid )
    AUTHORITY_KEYID_free(v2->akid);
  if ( v2->idp )
    ISSUING_DIST_POINT_free(v2->idp);
  ASN1_INTEGER_free(v2->crl_number);
  ASN1_INTEGER_free(v2->base_crl_number);
  sk_pop_free(&v2->issuers->stack, (void (__cdecl *)(void *))GENERAL_NAMES_free);
  return 1;
}
