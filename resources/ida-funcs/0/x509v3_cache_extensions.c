void __thiscall x509v3_cache_extensions(x509_st *x)
{
  const env_md_st *v2; // eax
  X509_name_st *subject_name; // eax
  BASIC_CONSTRAINTS_st *ext_d2i; // eax
  BASIC_CONSTRAINTS_st *v5; // esi
  asn1_string_st *pathlen; // eax
  PROXY_CERT_INFO_EXTENSION_st *v7; // esi
  asn1_string_st *v8; // eax
  unsigned int v9; // ecx
  const stack_st *v10; // eax
  stack_st *v11; // esi
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  int v15; // eax
  asn1_string_st *v16; // eax
  NAME_CONSTRAINTS_st *v17; // eax
  const stack_st_X509_EXTENSION *ext_count; // eax
  int v19; // ecx
  ui_string_st *ext; // esi
  ui_string_st *object; // eax
  ui_string_st *v22; // eax
  const stack_st_X509_EXTENSION *v23; // eax
  unsigned __int8 *sha1_hash; // [esp-14h] [ebp-20h]
  X509_name_st *issuer_name; // [esp-10h] [ebp-1Ch]
  int crit; // [esp+4h] [ebp-8h] BYREF
  void *v27; // [esp+8h] [ebp-4h] BYREF

  if ( (x->ex_flags & 0x100) == 0 )
  {
    sha1_hash = x->sha1_hash;
    v2 = EVP_sha1();
    X509_digest(x, v2, sha1_hash, 0);
    issuer_name = X509_get_issuer_name(x);
    subject_name = X509_get_subject_name(x);
    if ( !X509_NAME_cmp(subject_name, issuer_name) )
      x->ex_flags |= 0x20u;
    if ( !ASN1_INTEGER_get(x->cert_info->version) )
      x->ex_flags |= 0x40u;
    ext_d2i = (BASIC_CONSTRAINTS_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 87, 0, 0);
    v5 = ext_d2i;
    if ( ext_d2i )
    {
      if ( ext_d2i->ca )
        x->ex_flags |= 0x10u;
      pathlen = ext_d2i->pathlen;
      if ( pathlen )
      {
        if ( pathlen->type == 258 || !v5->ca )
        {
          x->ex_flags |= 0x80u;
          x->ex_pathlen = 0;
        }
        else
        {
          x->ex_pathlen = ASN1_INTEGER_get(v5->pathlen);
        }
      }
      else
      {
        x->ex_pathlen = -1;
      }
      BASIC_CONSTRAINTS_free(v5);
      x->ex_flags |= 1u;
    }
    v7 = (PROXY_CERT_INFO_EXTENSION_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 663, 0, 0);
    if ( v7 )
    {
      if ( (x->ex_flags & 0x10) != 0
        || X509_get_ext_by_NID((stack_st_X509_ATTRIBUTE *)x, 85, 0) >= 0
        || X509_get_ext_by_NID((stack_st_X509_ATTRIBUTE *)x, 86, 0) >= 0 )
      {
        x->ex_flags |= 0x80u;
      }
      if ( v7->pcPathLengthConstraint )
        x->ex_pcpathlen = ASN1_INTEGER_get(v7->pcPathLengthConstraint);
      else
        x->ex_pcpathlen = -1;
      PROXY_CERT_INFO_EXTENSION_free(v7);
      x->ex_flags |= 0x400u;
    }
    v8 = (asn1_string_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 83, 0, 0);
    if ( v8 )
    {
      if ( v8->length <= 0 )
      {
        x->ex_kusage = 0;
      }
      else
      {
        v9 = *v8->data;
        x->ex_kusage = v9;
        if ( v8->length > 1 )
          x->ex_kusage = v9 | (v8->data[1] << 8);
      }
      x->ex_flags |= 2u;
      ASN1_BIT_STRING_free(v8);
    }
    x->ex_xkusage = 0;
    v10 = (const stack_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 126, 0, 0);
    v11 = (stack_st *)v10;
    if ( v10 )
    {
      x->ex_flags |= 4u;
      crit = 0;
      v12 = sk_num(v10);
      v13 = 0;
      if ( v12 > 0 )
      {
        do
        {
          v14 = sk_value(v11, v13);
          switch ( (unsigned int)OBJ_obj2nid((const asn1_object_st *)v14) )
          {
            case 0x81u:
              x->ex_xkusage |= 1u;
              break;
            case 0x82u:
              x->ex_xkusage |= 2u;
              break;
            case 0x83u:
              x->ex_xkusage |= 8u;
              break;
            case 0x84u:
              x->ex_xkusage |= 4u;
              break;
            case 0x85u:
              x->ex_xkusage |= 0x40u;
              break;
            case 0x89u:
            case 0x8Bu:
              x->ex_xkusage |= 0x10u;
              break;
            case 0xB4u:
              x->ex_xkusage |= 0x20u;
              break;
            case 0x129u:
              x->ex_xkusage |= 0x80u;
              break;
            default:
              break;
          }
          ++crit;
          v15 = sk_num(v11);
          v13 = crit;
        }
        while ( crit < v15 );
      }
      sk_pop_free(v11, (void (__cdecl *)(void *))ASN1_OBJECT_free);
    }
    v16 = (asn1_string_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 71, 0, 0);
    if ( v16 )
    {
      if ( v16->length <= 0 )
        x->ex_nscert = 0;
      else
        x->ex_nscert = *v16->data;
      x->ex_flags |= 8u;
      ASN1_BIT_STRING_free(v16);
    }
    x->skid = (asn1_string_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 82, 0, 0);
    x->akid = (AUTHORITY_KEYID_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 90, 0, 0);
    x->altname = (stack_st_GENERAL_NAME *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 85, 0, 0);
    v17 = (NAME_CONSTRAINTS_st *)X509_get_ext_d2i((stack_st_X509_EXTENSION *)x, 666, &crit, 0);
    x->nc = v17;
    if ( !v17 && crit != -1 )
      x->ex_flags |= 0x80u;
    setup_crldp((stack_st_X509_EXTENSION *)x);
    crit = 0;
    ext_count = X509_get_ext_count(x);
    v19 = crit;
    if ( crit < (int)ext_count )
    {
      while ( 1 )
      {
        ext = (ui_string_st *)X509_get_ext(x, v19);
        if ( X509_EXTENSION_get_critical((X509_extension_st *)ext) )
        {
          object = X509_EXTENSION_get_object(ext);
          if ( OBJ_obj2nid((const asn1_object_st *)object) == (void *)857 )
            x->ex_flags |= 0x1000u;
          v22 = X509_EXTENSION_get_object(ext);
          v27 = OBJ_obj2nid((const asn1_object_st *)v22);
          if ( !v27
            || !OBJ_bsearch_(&v27, "G", 11, 4, (int (__cdecl *)(const void *, const void *))nid_cmp_BSEARCH_CMP_FN) )
          {
            break;
          }
        }
        ++crit;
        v23 = X509_get_ext_count(x);
        v19 = crit;
        if ( crit >= (int)v23 )
        {
          x->ex_flags |= 0x100u;
          return;
        }
      }
      x->ex_flags |= 0x200u;
    }
    x->ex_flags |= 0x100u;
  }
}
