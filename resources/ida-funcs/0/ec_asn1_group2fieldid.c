int __usercall ec_asn1_group2fieldid@<eax>(ssl_st *group@<ebx>, x9_62_fieldid_st *field@<ecx>)
{
  bignum_st *v2; // ebp
  const ssl_st *v4; // eax
  unsigned int v5; // esi
  asn1_object_st *v6; // eax
  char *v8; // eax
  struct ASN1_VALUE_st *v9; // esi
  unsigned int basis_type; // eax
  unsigned int v11; // edi
  asn1_object_st *v12; // eax
  asn1_string_st *v13; // eax
  struct ASN1_VALUE_st *v14; // eax
  void (__cdecl *v15)(int, int, int, const void *, unsigned int, ssl_st *, void *); // ecx
  struct ASN1_VALUE_st *v16; // eax
  int v17; // [esp-8h] [ebp-20h]
  int v18; // [esp+8h] [ebp-10h]
  int v; // [esp+Ch] [ebp-Ch] BYREF
  void (__cdecl *v20)(int, int, int, const void *, unsigned int, ssl_st *, void *); // [esp+10h] [ebp-8h] BYREF
  unsigned int v21; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  v18 = 0;
  if ( group && field )
  {
    if ( field->fieldType )
      ASN1_OBJECT_free(field->fieldType);
    if ( field->p.ptr )
      ASN1_TYPE_free(field->p.other);
    v4 = (const ssl_st *)EVP_CIPHER_CTX_cipher(group);
    v5 = EVP_CIPHER_CTX_cipher(v4);
    v6 = OBJ_nid2obj((int)group, v5);
    field->fieldType = v6;
    if ( !v6 )
    {
      v17 = 317;
LABEL_9:
      ERR_put_error((int)group, 0x10u, 154, 8, ".\\crypto\\ec\\ec_asn1.c", v17);
      return 0;
    }
    if ( v5 == 406 )
    {
      v2 = BN_new((int)group);
      if ( !v2 )
      {
        ERR_put_error((int)group, 0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 325);
        goto err_58;
      }
      if ( !EC_GROUP_get_curve_GFp((const ec_group_st *)group) )
      {
        ERR_put_error((int)group, 0x10u, 154, 16, ".\\crypto\\ec\\ec_asn1.c", 331);
        goto err_58;
      }
      v8 = (char *)BN_to_ASN1_INTEGER(v2, 0);
      field->p.ptr = v8;
      if ( !v8 )
      {
        ERR_put_error((int)group, 0x10u, 154, 13, ".\\crypto\\ec\\ec_asn1.c", 338);
        goto err_58;
      }
LABEL_35:
      v18 = 1;
err_58:
      if ( v2 )
        BN_free(v2);
      return v18;
    }
    v9 = ASN1_item_new(&local_it_60);
    field->p.ptr = (char *)v9;
    if ( !v9 )
    {
      ERR_put_error((int)group, 0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 352);
      return 0;
    }
    *(_DWORD *)v9 = EC_GROUP_get_degree((const ec_group_st *)group);
    basis_type = EC_GROUP_get_basis_type(group);
    v11 = basis_type;
    if ( !basis_type )
    {
      ERR_put_error((int)group, 0x10u, 154, 16, ".\\crypto\\ec\\ec_asn1.c", 362);
      return 0;
    }
    v12 = OBJ_nid2obj((int)group, basis_type);
    *((_DWORD *)v9 + 1) = v12;
    if ( !v12 )
    {
      v17 = 368;
      goto LABEL_9;
    }
    if ( v11 == 682 )
    {
      if ( EC_GROUP_get_trinomial_basis((int)group, group, (unsigned int *)&v) )
      {
        v13 = ASN1_INTEGER_new();
        *((_DWORD *)v9 + 2) = v13;
        if ( !v13 )
        {
          ERR_put_error((int)group, 0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 382);
          return 0;
        }
        if ( !ASN1_INTEGER_set((int)group, v13, v) )
        {
          ERR_put_error((int)group, 0x10u, 154, 13, ".\\crypto\\ec\\ec_asn1.c", 388);
          return 0;
        }
        goto LABEL_35;
      }
    }
    else
    {
      if ( v11 != 683 )
      {
        v16 = ASN1_NULL_new();
        *((_DWORD *)v9 + 2) = v16;
        if ( !v16 )
        {
          ERR_put_error((int)group, 0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 417);
          return 0;
        }
        goto LABEL_35;
      }
      if ( EC_GROUP_get_pentanomial_basis((int)group, group, (unsigned int *)&v, &v20, &v21) )
      {
        v14 = ASN1_item_new(&local_it_59);
        *((_DWORD *)v9 + 2) = v14;
        if ( !v14 )
        {
          ERR_put_error((int)group, 0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 402);
          return 0;
        }
        v15 = v20;
        *(_DWORD *)v14 = v;
        *(_DWORD *)(*((_DWORD *)v9 + 2) + 4) = v15;
        *(_DWORD *)(*((_DWORD *)v9 + 2) + 8) = v21;
        goto LABEL_35;
      }
    }
    return v18;
  }
  return 0;
}
