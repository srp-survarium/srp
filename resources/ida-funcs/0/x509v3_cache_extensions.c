void __thiscall x509v3_cache_extensions(x509_st *x)
{
  const env_md_st *v2; // eax
  const X509_name_st *subject_name; // eax
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
  int ext_count; // eax
  int v19; // ecx
  ui_string_st *ext; // esi
  const asn1_object_st *object; // eax
  const asn1_object_st *v22; // eax
  int v23; // eax
  unsigned __int8 *sha1_hash; // [esp-14h] [ebp-20h]
  const X509_name_st *issuer_name; // [esp-10h] [ebp-1Ch]
  int i; // [esp+4h] [ebp-8h] BYREF
  int key; // [esp+8h] [ebp-4h] BYREF

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
    ext_d2i = (BASIC_CONSTRAINTS_st *)X509_get_ext_d2i(x, 87, 0, 0);
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
    v7 = (PROXY_CERT_INFO_EXTENSION_st *)X509_get_ext_d2i(x, 663, 0, 0);
    if ( v7 )
    {
      if ( (x->ex_flags & 0x10) != 0 || X509_get_ext_by_NID(x, 85, 0) >= 0 || X509_get_ext_by_NID(x, 86, 0) >= 0 )
        x->ex_flags |= 0x80u;
      if ( v7->pcPathLengthConstraint )
        x->ex_pcpathlen = ASN1_INTEGER_get(v7->pcPathLengthConstraint);
      else
        x->ex_pcpathlen = -1;
      PROXY_CERT_INFO_EXTENSION_free(v7);
      x->ex_flags |= 0x400u;
    }
    v8 = (asn1_string_st *)X509_get_ext_d2i(x, 83, 0, 0);
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
    v10 = (const stack_st *)X509_get_ext_d2i(x, 126, 0, 0);
    v11 = (stack_st *)v10;
    if ( v10 )
    {
      x->ex_flags |= 4u;
      i = 0;
      v12 = sk_num(v10);
      v13 = 0;
      if ( v12 > 0 )
      {
        do
        {
          v14 = sk_value(v11, v13);
          switch ( OBJ_obj2nid((const asn1_object_st *)v14) )
          {
            case 129:
              x->ex_xkusage |= 1u;
              break;
            case 130:
              x->ex_xkusage |= 2u;
              break;
            case 131:
              x->ex_xkusage |= 8u;
              break;
            case 132:
              x->ex_xkusage |= 4u;
              break;
            case 133:
              x->ex_xkusage |= 0x40u;
              break;
            case 137:
            case 139:
              x->ex_xkusage |= 0x10u;
              break;
            case 180:
              x->ex_xkusage |= 0x20u;
              break;
            case 297:
              x->ex_xkusage |= 0x80u;
              break;
            default:
              break;
          }
          ++i;
          v15 = sk_num(v11);
          v13 = i;
        }
        while ( i < v15 );
      }
      sk_pop_free(v11, (void (__cdecl *)(void *))ASN1_OBJECT_free);
    }
    v16 = (asn1_string_st *)X509_get_ext_d2i(x, 71, 0, 0);
    if ( v16 )
    {
      if ( v16->length <= 0 )
        x->ex_nscert = 0;
      else
        x->ex_nscert = *v16->data;
      x->ex_flags |= 8u;
      ASN1_BIT_STRING_free(v16);
    }
    x->skid = (asn1_string_st *)X509_get_ext_d2i(x, 82, 0, 0);
    x->akid = (AUTHORITY_KEYID_st *)X509_get_ext_d2i(x, 90, 0, 0);
    x->altname = (stack_st_GENERAL_NAME *)X509_get_ext_d2i(x, 85, 0, 0);
    v17 = (NAME_CONSTRAINTS_st *)X509_get_ext_d2i(x, 666, &i, 0);
    x->nc = v17;
    if ( !v17 && i != -1 )
      x->ex_flags |= 0x80u;
    setup_crldp(x);
    i = 0;
    ext_count = X509_get_ext_count(x);
    v19 = i;
    if ( i < ext_count )
    {
      while ( 1 )
      {
        ext = (ui_string_st *)X509_get_ext(x, v19);
        if ( X509_EXTENSION_get_critical((X509_extension_st *)ext) )
        {
          object = (const asn1_object_st *)X509_EXTENSION_get_object(ext);
          if ( OBJ_obj2nid(object) == 857 )
            x->ex_flags |= 0x1000u;
          v22 = (const asn1_object_st *)X509_EXTENSION_get_object(ext);
          key = OBJ_obj2nid(v22);
          if ( !key || !OBJ_bsearch_(&key, "G", 11, 4, nid_cmp_BSEARCH_CMP_FN) )
            break;
        }
        ++i;
        v23 = X509_get_ext_count(x);
        v19 = i;
        if ( i >= v23 )
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
