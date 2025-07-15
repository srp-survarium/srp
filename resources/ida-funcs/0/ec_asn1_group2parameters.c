ec_parameters_st *__cdecl ec_asn1_group2parameters(ec_parameters_st *param)
{
  int v1; // ecx
  ssl_st *v2; // ebx
  struct ASN1_VALUE_st *v3; // esi
  x9_62_fieldid_st *v4; // ecx
  const ec_point_st *v5; // ebp
  int v6; // eax
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  asn1_string_st *v9; // eax
  asn1_string_st *v10; // eax
  asn1_string_st *v11; // eax
  int v13; // [esp-4h] [ebp-20h]
  bignum_st *order; // [esp+10h] [ebp-Ch]
  unsigned __int8 *d; // [esp+14h] [ebp-8h]
  point_conversion_form_t form; // [esp+18h] [ebp-4h]

  v2 = (ssl_st *)v1;
  d = 0;
  order = BN_new(v1);
  if ( !order )
  {
    ERR_put_error((int)v2, 0x10u, 155, 65, ".\\crypto\\ec\\ec_asn1.c", 576);
LABEL_34:
    v3 = 0;
    goto LABEL_35;
  }
  v3 = (struct ASN1_VALUE_st *)param;
  if ( !param )
  {
    v3 = ASN1_item_new(&local_it_63);
    if ( !v3 )
    {
      ERR_put_error((int)v2, 0x10u, 155, 65, ".\\crypto\\ec\\ec_asn1.c", 585);
LABEL_31:
      if ( v3 && !param )
        ASN1_item_free(v3, &local_it_63);
      goto LABEL_34;
    }
  }
  v4 = (x9_62_fieldid_st *)*((_DWORD *)v3 + 1);
  *(_DWORD *)v3 = 1;
  if ( !ec_asn1_group2fieldid(v2, v4) )
  {
    ERR_put_error((int)v2, 0x10u, 155, 16, ".\\crypto\\ec\\ec_asn1.c", 598);
    goto LABEL_31;
  }
  if ( !ec_asn1_group2curve((int)v2, v2, *((x9_62_curve_st **)v3 + 2)) )
  {
    ERR_put_error((int)v2, 0x10u, 155, 16, ".\\crypto\\ec\\ec_asn1.c", 605);
    goto LABEL_31;
  }
  v5 = (const ec_point_st *)EVP_CIPHER_block_size((const env_md_st *)v2);
  if ( !v5 )
  {
    ERR_put_error((int)v2, 0x10u, 155, 113, ".\\crypto\\ec\\ec_asn1.c", 612);
    goto LABEL_31;
  }
  form = EC_GROUP_get_point_conversion_form((const ec_group_st *)v2);
  v6 = EC_POINT_point2oct((const ec_group_st *)v2, v5, form, 0, 0, 0);
  v7 = v6;
  if ( !v6 )
  {
    ERR_put_error((int)v2, 0x10u, 155, 16, ".\\crypto\\ec\\ec_asn1.c", 621);
    goto LABEL_31;
  }
  v8 = (unsigned __int8 *)CRYPTO_malloc(v6, ".\\crypto\\ec\\ec_asn1.c", 624);
  d = v8;
  if ( !v8 )
  {
    ERR_put_error((int)v2, 0x10u, 155, 65, ".\\crypto\\ec\\ec_asn1.c", 626);
    goto LABEL_31;
  }
  if ( !EC_POINT_point2oct((const ec_group_st *)v2, v5, form, v8, v7, 0) )
  {
    ERR_put_error((int)v2, 0x10u, 155, 16, ".\\crypto\\ec\\ec_asn1.c", 631);
    goto LABEL_31;
  }
  if ( !*((_DWORD *)v3 + 3) )
  {
    v9 = ASN1_OCTET_STRING_new();
    *((_DWORD *)v3 + 3) = v9;
    if ( !v9 )
    {
      ERR_put_error((int)v2, 0x10u, 155, 65, ".\\crypto\\ec\\ec_asn1.c", 636);
      goto LABEL_31;
    }
  }
  if ( !ASN1_OCTET_STRING_set(*((asn1_string_st **)v3 + 3), d, v7) )
  {
    v13 = 641;
LABEL_30:
    ERR_put_error((int)v2, 0x10u, 155, 13, ".\\crypto\\ec\\ec_asn1.c", v13);
    goto LABEL_31;
  }
  if ( !EC_GROUP_get_order((const ec_group_st *)v2, order) )
  {
    ERR_put_error((int)v2, 0x10u, 155, 16, ".\\crypto\\ec\\ec_asn1.c", 648);
    goto LABEL_31;
  }
  v10 = BN_to_ASN1_INTEGER(order, *((asn1_string_st **)v3 + 4));
  *((_DWORD *)v3 + 4) = v10;
  if ( !v10 )
  {
    v13 = 654;
    goto LABEL_30;
  }
  if ( EC_GROUP_get_cofactor((const ec_group_st *)v2, order) )
  {
    v11 = BN_to_ASN1_INTEGER(order, *((asn1_string_st **)v3 + 5));
    *((_DWORD *)v3 + 5) = v11;
    if ( !v11 )
    {
      v13 = 664;
      goto LABEL_30;
    }
  }
LABEL_35:
  if ( order )
    BN_free(order);
  if ( d )
    CRYPTO_free(d);
  return (ec_parameters_st *)v3;
}
