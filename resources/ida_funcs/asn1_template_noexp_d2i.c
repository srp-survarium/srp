int __cdecl asn1_template_noexp_d2i(
        struct ASN1_VALUE_st **val,
        unsigned __int8 **in,
        unsigned __int8 *len,
        const ASN1_TEMPLATE_st *tt,
        int opt,
        ASN1_TLC_st *ctx)
{
  struct ASN1_VALUE_st **v6; // edi
  const ASN1_TEMPLATE_st *v8; // ebp
  unsigned int flags; // eax
  unsigned int v10; // ecx
  int v11; // eax
  ASN1_TLC_st *v12; // ebx
  int v13; // eax
  struct ASN1_VALUE_st *v14; // esi
  char *v15; // eax
  int (*item)(void); // ecx
  const ASN1_ITEM_st *v17; // eax
  unsigned __int8 *v18; // esi
  unsigned __int8 *v19; // edi
  int (*v20)(void); // eax
  const ASN1_ITEM_st *v21; // eax
  unsigned __int8 *v22; // eax
  const ASN1_ITEM_st *v23; // eax
  int v24; // eax
  const ASN1_ITEM_st *v25; // eax
  int tag; // [esp-1Ch] [ebp-2Ch]
  int v27; // [esp-18h] [ebp-28h]
  int v28; // [esp-14h] [ebp-24h]
  int v29; // [esp-14h] [ebp-24h]
  ASN1_TLC_st *v30; // [esp-10h] [ebp-20h]
  int v31; // [esp-10h] [ebp-20h]
  ASN1_TLC_st *v32; // [esp-10h] [ebp-20h]
  char inf; // [esp+7h] [ebp-9h] BYREF
  unsigned __int8 *ina; // [esp+8h] [ebp-8h] BYREF
  struct ASN1_VALUE_st *pval; // [esp+Ch] [ebp-4h] BYREF

  v6 = val;
  if ( !val )
    return 0;
  v8 = tt;
  flags = tt->flags;
  v10 = tt->flags & 0xC0;
  ina = *in;
  if ( (flags & 6) == 0 )
  {
    if ( (flags & 8) != 0 )
    {
      v30 = ctx;
      v28 = opt;
      v27 = v10;
      tag = tt->tag;
      v23 = tt->item();
      v24 = ASN1_item_ex_d2i(val, &ina, len, v23, tag, v27, v28, v30);
      if ( !v24 )
      {
        v31 = 737;
LABEL_35:
        ERR_put_error(0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", v31);
        goto LABEL_36;
      }
    }
    else
    {
      v32 = ctx;
      v29 = opt;
      v25 = tt->item();
      v24 = ASN1_item_ex_d2i(val, &ina, len, v25, -1, 0, v29, v32);
      if ( !v24 )
      {
        v31 = 751;
        goto LABEL_35;
      }
    }
    if ( v24 != -1 )
    {
LABEL_39:
      v22 = ina;
LABEL_40:
      *in = v22;
      return 1;
    }
    return -1;
  }
  if ( (flags & 8) != 0 )
  {
    v11 = tt->tag;
  }
  else
  {
    v10 = 0;
    v11 = (flags & 2 | 0x20) >> 1;
  }
  v12 = ctx;
  v13 = asn1_check_tlen((int *)&len, 0, 0, &inf, 0, (ASN1_TLC_st **)&ina, len, v11, v10, opt, ctx);
  if ( !v13 )
  {
    ERR_put_error(0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", 659);
    return 0;
  }
  if ( v13 == -1 )
    return -1;
  v14 = *val;
  if ( *val )
  {
    if ( sk_num((const stack_st *)*val) > 0 )
    {
      do
      {
        v15 = sk_pop((stack_st *)v14);
        item = (int (*)(void))v8->item;
        pval = (struct ASN1_VALUE_st *)v15;
        v17 = (const ASN1_ITEM_st *)item();
        ASN1_item_ex_free(&pval, v17);
      }
      while ( sk_num((const stack_st *)v14) > 0 );
    }
  }
  else
  {
    *val = (struct ASN1_VALUE_st *)sk_new_null();
  }
  if ( !*val )
  {
    ERR_put_error(0xDu, 131, 65, ".\\crypto\\asn1\\tasn_dec.c", 683);
LABEL_36:
    ASN1_template_free(v6, v8);
    return 0;
  }
  v18 = len;
  if ( (int)len <= 0 )
  {
LABEL_24:
    if ( inf )
    {
      ERR_put_error(0xDu, 131, 137, ".\\crypto\\asn1\\tasn_dec.c", 725);
      goto LABEL_36;
    }
    goto LABEL_39;
  }
  while ( 1 )
  {
    v19 = ina;
    if ( (int)v18 >= 2 && !*ina && !ina[1] )
      break;
    v20 = (int (*)(void))v8->item;
    pval = 0;
    v21 = (const ASN1_ITEM_st *)v20();
    if ( !ASN1_item_ex_d2i(&pval, &ina, v18, v21, -1, 0, 0, v12) )
    {
      ERR_put_error(0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", 711);
      ASN1_template_free(val, v8);
      return 0;
    }
    v18 += v19 - ina;
    if ( !sk_push((stack_st *)*val, (char *)pval) )
    {
      ERR_put_error(0xDu, 131, 65, ".\\crypto\\asn1\\tasn_dec.c", 719);
      ASN1_template_free(val, v8);
      return 0;
    }
    if ( (int)v18 <= 0 )
    {
      v6 = val;
      goto LABEL_24;
    }
  }
  v22 = ina + 2;
  ina += 2;
  if ( inf )
    goto LABEL_40;
  ERR_put_error(0xDu, 131, 159, ".\\crypto\\asn1\\tasn_dec.c", 698);
  ASN1_template_free(val, v8);
  return 0;
}
