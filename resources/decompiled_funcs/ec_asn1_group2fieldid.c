int __usercall ec_asn1_group2fieldid@<eax>(const ssl_st *group@<ebx>, x9_62_fieldid_st *field@<ecx>)
{
  bignum_st *v2; // ebp
  const ssl_st *v4; // eax
  unsigned int v5; // esi
  asn1_object_st *v6; // eax
  bignum_st *v8; // eax
  char *v9; // eax
  struct ASN1_VALUE_st *v10; // esi
  unsigned int basis_type; // eax
  unsigned int v12; // edi
  asn1_object_st *v13; // eax
  asn1_string_st *v14; // eax
  struct ASN1_VALUE_st *v15; // eax
  unsigned int v16; // ecx
  struct ASN1_VALUE_st *v17; // eax
  int v18; // [esp-8h] [ebp-20h]
  int v19; // [esp+8h] [ebp-10h]
  unsigned int k; // [esp+Ch] [ebp-Ch] BYREF
  unsigned int v21; // [esp+10h] [ebp-8h] BYREF
  unsigned int v22; // [esp+14h] [ebp-4h] BYREF

  v2 = 0;
  v19 = 0;
  if ( group && field )
  {
    if ( field->fieldType )
      ASN1_OBJECT_free(field->fieldType);
    if ( field->p.ptr )
      ASN1_TYPE_free(field->p.other);
    v4 = (const ssl_st *)EVP_CIPHER_CTX_cipher(group);
    v5 = EVP_CIPHER_CTX_cipher(v4);
    v6 = OBJ_nid2obj(v5);
    field->fieldType = v6;
    if ( !v6 )
    {
      v18 = 317;
LABEL_9:
      ERR_put_error(0x10u, 154, 8, ".\\crypto\\ec\\ec_asn1.c", v18);
      return 0;
    }
    if ( v5 == 406 )
    {
      v8 = BN_new();
      v2 = v8;
      if ( !v8 )
      {
        ERR_put_error(0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 325);
        goto err_56;
      }
      if ( !EC_GROUP_get_curve_GFp((const ec_group_st *)group, v8, 0, 0, 0) )
      {
        ERR_put_error(0x10u, 154, 16, ".\\crypto\\ec\\ec_asn1.c", 331);
        goto err_56;
      }
      v9 = (char *)BN_to_ASN1_INTEGER(v2, 0);
      field->p.ptr = v9;
      if ( !v9 )
      {
        ERR_put_error(0x10u, 154, 13, ".\\crypto\\ec\\ec_asn1.c", 338);
        goto err_56;
      }
LABEL_35:
      v19 = 1;
err_56:
      if ( v2 )
        BN_free(v2);
      return v19;
    }
    v10 = ASN1_item_new(&local_it_60);
    field->p.ptr = (char *)v10;
    if ( !v10 )
    {
      ERR_put_error(0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 352);
      return 0;
    }
    *(_DWORD *)v10 = EC_GROUP_get_degree((const ec_group_st *)group);
    basis_type = EC_GROUP_get_basis_type(group);
    v12 = basis_type;
    if ( !basis_type )
    {
      ERR_put_error(0x10u, 154, 16, ".\\crypto\\ec\\ec_asn1.c", 362);
      return 0;
    }
    v13 = OBJ_nid2obj(basis_type);
    *((_DWORD *)v10 + 1) = v13;
    if ( !v13 )
    {
      v18 = 368;
      goto LABEL_9;
    }
    if ( v12 == 682 )
    {
      if ( EC_GROUP_get_trinomial_basis(group, &k) )
      {
        v14 = ASN1_INTEGER_new();
        *((_DWORD *)v10 + 2) = v14;
        if ( !v14 )
        {
          ERR_put_error(0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 382);
          return 0;
        }
        if ( !ASN1_INTEGER_set(v14, k) )
        {
          ERR_put_error(0x10u, 154, 13, ".\\crypto\\ec\\ec_asn1.c", 388);
          return 0;
        }
        goto LABEL_35;
      }
    }
    else
    {
      if ( v12 != 683 )
      {
        v17 = ASN1_NULL_new();
        *((_DWORD *)v10 + 2) = v17;
        if ( !v17 )
        {
          ERR_put_error(0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 417);
          return 0;
        }
        goto LABEL_35;
      }
      if ( EC_GROUP_get_pentanomial_basis(group, &k, &v21, &v22) )
      {
        v15 = ASN1_item_new(&local_it_59);
        *((_DWORD *)v10 + 2) = v15;
        if ( !v15 )
        {
          ERR_put_error(0x10u, 154, 65, ".\\crypto\\ec\\ec_asn1.c", 402);
          return 0;
        }
        v16 = v21;
        *(_DWORD *)v15 = k;
        *(_DWORD *)(*((_DWORD *)v10 + 2) + 4) = v16;
        *(_DWORD *)(*((_DWORD *)v10 + 2) + 8) = v22;
        goto LABEL_35;
      }
    }
    return v19;
  }
  return 0;
}
