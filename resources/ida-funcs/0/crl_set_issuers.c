int __usercall crl_set_issuers@<eax>(X509_crl_st *crl@<ebx>)
{
  stack_st *v1; // esi
  int v2; // ebp
  stack_st_X509_EXTENSION *v3; // esi
  char *ext_d2i; // eax
  char *v5; // edi
  bool v7; // zf
  stack_st_GENERAL_NAMES *v8; // eax
  asn1_string_st *v9; // eax
  asn1_string_st *v10; // edi
  const stack_st *sorted; // esi
  int v12; // eax
  int v13; // ecx
  char *v14; // eax
  int v15; // eax
  int v16; // [esp+Ch] [ebp-Ch] BYREF
  char *v17; // [esp+10h] [ebp-8h]
  stack_st *st; // [esp+14h] [ebp-4h]

  v2 = 0;
  st = &crl->crl->revoked->stack;
  v1 = st;
  v17 = 0;
  if ( sk_num(st) <= 0 )
    return 1;
  while ( 1 )
  {
    v3 = (stack_st_X509_EXTENSION *)sk_value(v1, v2);
    ext_d2i = (char *)X509_REVOKED_get_ext_d2i(v3, 771, &v16, 0);
    v5 = ext_d2i;
    if ( ext_d2i )
      break;
    if ( v16 != -1 )
      goto LABEL_6;
LABEL_11:
    v3->stack.num_alloc = (int)v17;
    v9 = (asn1_string_st *)X509_REVOKED_get_ext_d2i(v3, 141, &v16, 0);
    v10 = v9;
    if ( v9 )
    {
      v3->stack.comp = (int (__cdecl *)(const void *, const void *))ASN1_ENUMERATED_get(v9);
      ASN1_ENUMERATED_free(v10);
    }
    else
    {
      if ( v16 != -1 )
      {
LABEL_6:
        crl->flags |= 0x80u;
        return 1;
      }
      v3->stack.comp = (int (__cdecl *)(const void *, const void *))-1;
    }
    sorted = (const stack_st *)v3->stack.sorted;
    v16 = 0;
    v12 = sk_num(sorted);
    v13 = v16;
    if ( v16 < v12 )
    {
      while ( 1 )
      {
        v14 = sk_value(sorted, v13);
        if ( *((int *)v14 + 1) > 0 && OBJ_obj2nid(*(const asn1_object_st **)v14) != (void *)771 )
          break;
        ++v16;
        v15 = sk_num(sorted);
        v13 = v16;
        if ( v16 >= v15 )
          goto LABEL_21;
      }
      crl->flags |= 0x200u;
    }
LABEL_21:
    if ( ++v2 >= sk_num(st) )
      return 1;
    v1 = st;
  }
  v7 = crl->issuers == 0;
  v17 = ext_d2i;
  if ( !v7 || (v8 = (stack_st_GENERAL_NAMES *)sk_new_null(), (crl->issuers = v8) != 0) )
  {
    if ( sk_push(&crl->issuers->stack, v5) )
      goto LABEL_11;
  }
  return 0;
}
