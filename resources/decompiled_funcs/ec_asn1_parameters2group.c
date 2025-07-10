ec_group_st *__thiscall ec_asn1_parameters2group(const ec_parameters_st *params)
{
  bignum_st *v1; // ebp
  x9_62_fieldid_st *fieldID; // eax
  x9_62_curve_st *curve; // eax
  asn1_string_st *v5; // eax
  const bignum_st *v6; // edi
  const bignum_st *v7; // esi
  int v8; // eax
  char *ptr; // esi
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // edi
  bignum_st *v14; // eax
  int *v15; // edi
  int v16; // esi
  int v17; // eax
  int v18; // ecx
  ec_group_st *v19; // eax
  char *v20; // eax
  bignum_st *v21; // eax
  ec_group_st *v22; // esi
  unsigned __int8 *v23; // eax
  asn1_string_st *base; // eax
  ec_point_st *v25; // edi
  bignum_st *v26; // eax
  bignum_st *v27; // edi
  asn1_string_st *cofactor; // ebx
  int v30; // [esp-4h] [ebp-24h]
  bignum_st *b; // [esp+10h] [ebp-10h]
  bignum_st *a; // [esp+14h] [ebp-Ch]
  ec_point_st *point; // [esp+18h] [ebp-8h]
  int v34; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  fieldID = params->fieldID;
  a = 0;
  b = 0;
  point = 0;
  if ( !fieldID || !fieldID->fieldType || !fieldID->p.ptr )
  {
    ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 751);
    goto LABEL_77;
  }
  curve = params->curve;
  if ( !curve || !curve->a || !curve->a->data || (v5 = curve->b) == 0 || !v5->data )
  {
    ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 760);
    goto LABEL_77;
  }
  v6 = BN_bin2bn(params->curve->a->data, params->curve->a->length, 0);
  a = (bignum_st *)v6;
  if ( !v6 )
  {
    ERR_put_error(0x10u, 157, 3, ".\\crypto\\ec\\ec_asn1.c", 766);
    goto LABEL_77;
  }
  v7 = BN_bin2bn(params->curve->b->data, params->curve->b->length, 0);
  b = (bignum_st *)v7;
  if ( !v7 )
  {
    ERR_put_error(0x10u, 157, 3, ".\\crypto\\ec\\ec_asn1.c", 772);
    goto LABEL_77;
  }
  v8 = OBJ_obj2nid(params->fieldID->fieldType);
  if ( v8 == 407 )
  {
    ptr = params->fieldID->p.ptr;
    v34 = *(_DWORD *)ptr;
    if ( *(int *)ptr > 661 )
    {
      ERR_put_error(0x10u, 157, 143, ".\\crypto\\ec\\ec_asn1.c", 788);
      goto LABEL_77;
    }
    v1 = BN_new();
    if ( !v1 )
    {
      ERR_put_error(0x10u, 157, 65, ".\\crypto\\ec\\ec_asn1.c", 794);
      goto LABEL_77;
    }
    v10 = OBJ_obj2nid(*((const asn1_object_st **)ptr + 1));
    if ( v10 == 682 )
    {
      if ( !*((_DWORD *)ptr + 2) )
      {
        ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 807);
        goto LABEL_77;
      }
      v11 = ASN1_INTEGER_get(*((const asn1_string_st **)ptr + 2));
      v12 = *(_DWORD *)ptr;
      v13 = v11;
      if ( v12 <= v11 || v11 <= 0 )
      {
        ERR_put_error(0x10u, 157, 137, ".\\crypto\\ec\\ec_asn1.c", 815);
        goto LABEL_77;
      }
      if ( !BN_set_bit(v1, v12) )
      {
LABEL_77:
        v27 = a;
        cofactor = (asn1_string_st *)b;
        v22 = 0;
        goto LABEL_78;
      }
      v14 = BN_set_bit(v1, v13);
    }
    else
    {
      if ( v10 != 683 )
      {
        if ( v10 == 681 )
          ERR_put_error(0x10u, 157, 126, ".\\crypto\\ec\\ec_asn1.c", 853);
        else
          ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 858);
        goto LABEL_77;
      }
      v15 = (int *)*((_DWORD *)ptr + 2);
      if ( !v15 )
      {
        ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 834);
        goto LABEL_77;
      }
      v16 = *(_DWORD *)ptr;
      v17 = v15[2];
      if ( v16 <= v17 || (v18 = v15[1], v17 <= v18) || v18 <= *v15 || *v15 <= 0 )
      {
        ERR_put_error(0x10u, 157, 132, ".\\crypto\\ec\\ec_asn1.c", 840);
        goto LABEL_77;
      }
      if ( !BN_set_bit(v1, v16) || !BN_set_bit(v1, *v15) || !BN_set_bit(v1, v15[1]) )
        goto LABEL_77;
      v14 = BN_set_bit(v1, v15[2]);
    }
    if ( !v14 || !BN_set_bit(v1, 0) )
      goto LABEL_77;
    v19 = EC_GROUP_new_curve_GF2m(v1, a, b, 0);
  }
  else
  {
    if ( v8 != 406 )
    {
      ERR_put_error(0x10u, 157, 103, ".\\crypto\\ec\\ec_asn1.c", 899);
      goto LABEL_77;
    }
    v20 = params->fieldID->p.ptr;
    if ( !v20 )
    {
      ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 871);
      goto LABEL_77;
    }
    v21 = ASN1_INTEGER_to_BN((const asn1_string_st *)v20, 0);
    v1 = v21;
    if ( !v21 )
    {
      ERR_put_error(0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 877);
      goto LABEL_77;
    }
    if ( v21->neg || !v21->top )
    {
      ERR_put_error(0x10u, 157, 103, ".\\crypto\\ec\\ec_asn1.c", 883);
      goto LABEL_77;
    }
    v34 = BN_num_bits(v21);
    if ( v34 > 661 )
    {
      ERR_put_error(0x10u, 157, 143, ".\\crypto\\ec\\ec_asn1.c", 890);
      goto LABEL_77;
    }
    v19 = EC_GROUP_new_curve_GFp(v1, v6, v7, 0);
  }
  v22 = v19;
  if ( !v19 )
  {
    ERR_put_error(0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 905);
    goto LABEL_77;
  }
  if ( params->curve->seed )
  {
    if ( v19->seed )
      CRYPTO_free(v19->seed);
    v23 = (unsigned __int8 *)CRYPTO_malloc(params->curve->seed->length, ".\\crypto\\ec\\ec_asn1.c", 914);
    v22->seed = v23;
    if ( !v23 )
    {
      ERR_put_error(0x10u, 157, 65, ".\\crypto\\ec\\ec_asn1.c", 917);
      goto LABEL_76;
    }
    memcpy(v23, params->curve->seed->data, params->curve->seed->length);
    v22->seed_len = params->curve->seed->length;
  }
  if ( !params->order || (base = params->base) == 0 || !base->data )
  {
    ERR_put_error(0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 927);
    goto LABEL_76;
  }
  v25 = EC_POINT_new(v22);
  point = v25;
  if ( !v25 )
  {
LABEL_76:
    EC_GROUP_clear_free(v22);
    goto LABEL_77;
  }
  EC_GROUP_set_point_conversion_form(v22, (point_conversion_form_t)(*params->base->data & 0xFE));
  if ( !EC_POINT_oct2point(v22, v25, params->base->data, params->base->length, 0) )
  {
    ERR_put_error(0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 941);
    goto LABEL_76;
  }
  v26 = ASN1_INTEGER_to_BN(params->order, a);
  v27 = v26;
  a = v26;
  if ( !v26 )
  {
    ERR_put_error(0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 948);
    goto LABEL_76;
  }
  if ( v26->neg || !v26->top )
  {
    v30 = 953;
    goto LABEL_75;
  }
  if ( BN_num_bits(v26) > v34 + 1 )
  {
    v30 = 958;
LABEL_75:
    ERR_put_error(0x10u, 157, 122, ".\\crypto\\ec\\ec_asn1.c", v30);
    goto LABEL_76;
  }
  cofactor = params->cofactor;
  if ( cofactor )
  {
    cofactor = (asn1_string_st *)ASN1_INTEGER_to_BN(cofactor, b);
    b = (bignum_st *)cofactor;
    if ( !cofactor )
    {
      ERR_put_error(0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 974);
      goto LABEL_76;
    }
  }
  else
  {
    BN_free(b);
    b = 0;
  }
  if ( !EC_GROUP_set_generator(v22, point, v27, (const bignum_st *)cofactor) )
  {
    ERR_put_error(0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 980);
    goto LABEL_76;
  }
LABEL_78:
  if ( v1 )
    BN_free(v1);
  if ( v27 )
    BN_free(v27);
  if ( cofactor )
    BN_free((bignum_st *)cofactor);
  if ( point )
    EC_POINT_free(point);
  return v22;
}
