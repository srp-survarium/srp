ec_group_st *__thiscall ec_asn1_parameters2group(const ec_parameters_st *params)
{
  bignum_st *v1; // ebp
  x9_62_fieldid_st *fieldID; // eax
  x9_62_curve_st *curve; // eax
  asn1_string_st *v5; // eax
  void *v6; // eax
  char *ptr; // esi
  void *v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // edi
  bignum_st *v12; // eax
  int *v13; // edi
  int v14; // esi
  int v15; // eax
  int v16; // ecx
  ec_group_st *v17; // eax
  char *v18; // eax
  bignum_st *v19; // eax
  ec_group_st *v20; // esi
  unsigned __int8 *v21; // eax
  asn1_string_st *base; // eax
  ec_point_st *v23; // edi
  bignum_st *v24; // eax
  bignum_st *v25; // edi
  asn1_string_st *cofactor; // ebx
  int v28; // [esp-4h] [ebp-24h]
  bignum_st *b; // [esp+10h] [ebp-10h]
  bignum_st *a; // [esp+14h] [ebp-Ch]
  ec_point_st *point; // [esp+18h] [ebp-8h]
  int v32; // [esp+1Ch] [ebp-4h]

  v1 = 0;
  fieldID = params->fieldID;
  a = 0;
  b = 0;
  point = 0;
  if ( !fieldID || !fieldID->fieldType || !fieldID->p.ptr )
  {
    ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 751);
    goto LABEL_77;
  }
  curve = params->curve;
  if ( !curve || !curve->a || !curve->a->data || (v5 = curve->b) == 0 || !v5->data )
  {
    ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 760);
    goto LABEL_77;
  }
  a = BN_bin2bn(params->curve->a->data, params->curve->a->length, 0);
  if ( !a )
  {
    ERR_put_error((int)params, 0x10u, 157, 3, ".\\crypto\\ec\\ec_asn1.c", 766);
    goto LABEL_77;
  }
  b = BN_bin2bn(params->curve->b->data, params->curve->b->length, 0);
  if ( !b )
  {
    ERR_put_error((int)params, 0x10u, 157, 3, ".\\crypto\\ec\\ec_asn1.c", 772);
    goto LABEL_77;
  }
  v6 = OBJ_obj2nid(params->fieldID->fieldType);
  if ( v6 == (void *)407 )
  {
    ptr = params->fieldID->p.ptr;
    v32 = *(_DWORD *)ptr;
    if ( *(int *)ptr > 661 )
    {
      ERR_put_error((int)params, 0x10u, 157, 143, ".\\crypto\\ec\\ec_asn1.c", 788);
      goto LABEL_77;
    }
    v1 = BN_new((int)params);
    if ( !v1 )
    {
      ERR_put_error((int)params, 0x10u, 157, 65, ".\\crypto\\ec\\ec_asn1.c", 794);
      goto LABEL_77;
    }
    v8 = OBJ_obj2nid(*((const asn1_object_st **)ptr + 1));
    if ( v8 == (void *)682 )
    {
      if ( !*((_DWORD *)ptr + 2) )
      {
        ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 807);
        goto LABEL_77;
      }
      v9 = ASN1_INTEGER_get(*((const asn1_string_st **)ptr + 2));
      v10 = *(_DWORD *)ptr;
      v11 = v9;
      if ( v10 <= v9 || v9 <= 0 )
      {
        ERR_put_error((int)params, 0x10u, 157, 137, ".\\crypto\\ec\\ec_asn1.c", 815);
        goto LABEL_77;
      }
      if ( !BN_set_bit(v1, v10) )
      {
LABEL_77:
        v25 = a;
        cofactor = (asn1_string_st *)b;
        v20 = 0;
        goto LABEL_78;
      }
      v12 = BN_set_bit(v1, v11);
    }
    else
    {
      if ( v8 != (void *)683 )
      {
        if ( v8 == (void *)681 )
          ERR_put_error((int)params, 0x10u, 157, 126, ".\\crypto\\ec\\ec_asn1.c", 853);
        else
          ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 858);
        goto LABEL_77;
      }
      v13 = (int *)*((_DWORD *)ptr + 2);
      if ( !v13 )
      {
        ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 834);
        goto LABEL_77;
      }
      v14 = *(_DWORD *)ptr;
      v15 = v13[2];
      if ( v14 <= v15 || (v16 = v13[1], v15 <= v16) || v16 <= *v13 || *v13 <= 0 )
      {
        ERR_put_error((int)params, 0x10u, 157, 132, ".\\crypto\\ec\\ec_asn1.c", 840);
        goto LABEL_77;
      }
      if ( !BN_set_bit(v1, v14) || !BN_set_bit(v1, *v13) || !BN_set_bit(v1, v13[1]) )
        goto LABEL_77;
      v12 = BN_set_bit(v1, v13[2]);
    }
    if ( !v12 || !BN_set_bit(v1, 0) )
      goto LABEL_77;
    v17 = EC_GROUP_new_curve_GF2m(v1);
  }
  else
  {
    if ( v6 != (void *)406 )
    {
      ERR_put_error((int)params, 0x10u, 157, 103, ".\\crypto\\ec\\ec_asn1.c", 899);
      goto LABEL_77;
    }
    v18 = params->fieldID->p.ptr;
    if ( !v18 )
    {
      ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 871);
      goto LABEL_77;
    }
    v19 = ASN1_INTEGER_to_BN((int)params, (const asn1_string_st *)v18, 0);
    v1 = v19;
    if ( !v19 )
    {
      ERR_put_error((int)params, 0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 877);
      goto LABEL_77;
    }
    if ( v19->neg || !v19->top )
    {
      ERR_put_error((int)params, 0x10u, 157, 103, ".\\crypto\\ec\\ec_asn1.c", 883);
      goto LABEL_77;
    }
    v32 = BN_num_bits(v19);
    if ( v32 > 661 )
    {
      ERR_put_error((int)params, 0x10u, 157, 143, ".\\crypto\\ec\\ec_asn1.c", 890);
      goto LABEL_77;
    }
    v17 = EC_GROUP_new_curve_GFp(v1);
  }
  v20 = v17;
  if ( !v17 )
  {
    ERR_put_error((int)params, 0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 905);
    goto LABEL_77;
  }
  if ( params->curve->seed )
  {
    if ( v17->seed )
      CRYPTO_free(v17->seed);
    v21 = (unsigned __int8 *)CRYPTO_malloc(params->curve->seed->length, ".\\crypto\\ec\\ec_asn1.c", 914);
    v20->seed = v21;
    if ( !v21 )
    {
      ERR_put_error((int)params, 0x10u, 157, 65, ".\\crypto\\ec\\ec_asn1.c", 917);
      goto LABEL_76;
    }
    memcpy((int)v21, (const __m128i *)params->curve->seed->data, params->curve->seed->length);
    v20->seed_len = params->curve->seed->length;
  }
  if ( !params->order || (base = params->base) == 0 || !base->data )
  {
    ERR_put_error((int)params, 0x10u, 157, 115, ".\\crypto\\ec\\ec_asn1.c", 927);
    goto LABEL_76;
  }
  v23 = EC_POINT_new(v20);
  point = v23;
  if ( !v23 )
  {
LABEL_76:
    EC_GROUP_clear_free(v20);
    goto LABEL_77;
  }
  EC_GROUP_set_point_conversion_form(v20, (point_conversion_form_t)(*params->base->data & 0xFE));
  if ( !EC_POINT_oct2point(v20, v23, params->base->data, params->base->length, 0) )
  {
    ERR_put_error((int)params, 0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 941);
    goto LABEL_76;
  }
  v24 = ASN1_INTEGER_to_BN((int)params, params->order, a);
  v25 = v24;
  a = v24;
  if ( !v24 )
  {
    ERR_put_error((int)params, 0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 948);
    goto LABEL_76;
  }
  if ( v24->neg || !v24->top )
  {
    v28 = 953;
    goto LABEL_75;
  }
  if ( BN_num_bits(v24) > v32 + 1 )
  {
    v28 = 958;
LABEL_75:
    ERR_put_error((int)params, 0x10u, 157, 122, ".\\crypto\\ec\\ec_asn1.c", v28);
    goto LABEL_76;
  }
  cofactor = params->cofactor;
  if ( cofactor )
  {
    cofactor = (asn1_string_st *)ASN1_INTEGER_to_BN((int)cofactor, cofactor, b);
    b = (bignum_st *)cofactor;
    if ( !cofactor )
    {
      ERR_put_error(0, 0x10u, 157, 13, ".\\crypto\\ec\\ec_asn1.c", 974);
      goto LABEL_76;
    }
  }
  else
  {
    BN_free(b);
    b = 0;
  }
  if ( !EC_GROUP_set_generator(v20, point, v25, (const bignum_st *)cofactor) )
  {
    ERR_put_error((int)cofactor, 0x10u, 157, 16, ".\\crypto\\ec\\ec_asn1.c", 980);
    goto LABEL_76;
  }
LABEL_78:
  if ( v1 )
    BN_free(v1);
  if ( v25 )
    BN_free(v25);
  if ( cofactor )
    BN_free((bignum_st *)cofactor);
  if ( point )
    EC_POINT_free(point);
  return v20;
}
