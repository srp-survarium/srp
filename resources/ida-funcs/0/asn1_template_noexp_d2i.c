int __usercall asn1_template_noexp_d2i@<eax>(
        int a1@<ebx>,
        const stack_st **val,
        unsigned __int8 **in,
        const unsigned __int8 **len,
        const ASN1_TEMPLATE_st *tt,
        int opt,
        ASN1_TLC_st *ctx)
{
  const stack_st **v7; // edi
  const ASN1_TEMPLATE_st *v9; // ebp
  unsigned int flags; // eax
  unsigned int v11; // ecx
  int v12; // eax
  ASN1_TLC_st *v13; // ebx
  int v14; // eax
  struct ASN1_VALUE_st *v15; // esi
  char *v16; // eax
  int (*item)(void); // ecx
  const ASN1_ITEM_st *v18; // eax
  const unsigned __int8 **v19; // esi
  unsigned __int8 *v20; // edi
  int (*v21)(void); // eax
  const ASN1_ITEM_st *v22; // eax
  unsigned __int8 *v23; // eax
  const ASN1_ITEM_st *v24; // eax
  int v25; // eax
  const ASN1_ITEM_st *v26; // eax
  int tag; // [esp-1Ch] [ebp-2Ch]
  int v28; // [esp-18h] [ebp-28h]
  int v29; // [esp-14h] [ebp-24h]
  int v30; // [esp-14h] [ebp-24h]
  ASN1_TLC_st *v31; // [esp-10h] [ebp-20h]
  int v32; // [esp-10h] [ebp-20h]
  ASN1_TLC_st *v33; // [esp-10h] [ebp-20h]
  char v34; // [esp+7h] [ebp-9h] BYREF
  unsigned __int8 *v35; // [esp+8h] [ebp-8h] BYREF
  struct ASN1_VALUE_st *pval; // [esp+Ch] [ebp-4h] BYREF

  v7 = val;
  if ( !val )
    return 0;
  v9 = tt;
  flags = tt->flags;
  v11 = tt->flags & 0xC0;
  v35 = *in;
  if ( (flags & 6) == 0 )
  {
    if ( (flags & 8) != 0 )
    {
      v31 = ctx;
      v29 = opt;
      v28 = v11;
      tag = tt->tag;
      v24 = tt->item();
      v25 = ASN1_item_ex_d2i((struct ASN1_VALUE_st **)val, &v35, len, v24, tag, v28, v29, v31);
      if ( !v25 )
      {
        v32 = 737;
LABEL_35:
        ERR_put_error(a1, 0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", v32);
        goto LABEL_36;
      }
    }
    else
    {
      v33 = ctx;
      v30 = opt;
      v26 = tt->item();
      v25 = ASN1_item_ex_d2i((struct ASN1_VALUE_st **)val, &v35, len, v26, -1, 0, v30, v33);
      if ( !v25 )
      {
        v32 = 751;
        goto LABEL_35;
      }
    }
    if ( v25 != -1 )
    {
LABEL_39:
      v23 = v35;
LABEL_40:
      *in = v23;
      return 1;
    }
    return -1;
  }
  if ( (flags & 8) != 0 )
  {
    v12 = tt->tag;
  }
  else
  {
    v11 = 0;
    v12 = (flags & 2 | 0x20) >> 1;
  }
  v13 = ctx;
  v14 = asn1_check_tlen((const unsigned __int8 **)&len, 0, 0, &v34, 0, (ASN1_TLC_st **)&v35, len, v12, v11, opt, ctx);
  if ( !v14 )
  {
    ERR_put_error((int)v13, 0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", 659);
    return 0;
  }
  if ( v14 == -1 )
    return -1;
  v15 = (struct ASN1_VALUE_st *)*val;
  if ( *val )
  {
    if ( sk_num(*val) > 0 )
    {
      do
      {
        v16 = sk_pop((stack_st *)v15);
        item = (int (*)(void))v9->item;
        pval = (struct ASN1_VALUE_st *)v16;
        v18 = (const ASN1_ITEM_st *)item();
        ASN1_item_ex_free((stack_st **)&pval, v18);
      }
      while ( sk_num((const stack_st *)v15) > 0 );
    }
  }
  else
  {
    *val = sk_new_null();
  }
  if ( !*val )
  {
    ERR_put_error((int)v13, 0xDu, 131, 65, ".\\crypto\\asn1\\tasn_dec.c", 683);
LABEL_36:
    ASN1_template_free(v7, v9);
    return 0;
  }
  v19 = len;
  if ( (int)len <= 0 )
  {
LABEL_24:
    if ( v34 )
    {
      ERR_put_error((int)v13, 0xDu, 131, 137, ".\\crypto\\asn1\\tasn_dec.c", 725);
      goto LABEL_36;
    }
    goto LABEL_39;
  }
  while ( 1 )
  {
    v20 = v35;
    if ( (int)v19 >= 2 && !*v35 && !v35[1] )
      break;
    v21 = (int (*)(void))v9->item;
    pval = 0;
    v22 = (const ASN1_ITEM_st *)v21();
    if ( !ASN1_item_ex_d2i(&pval, &v35, v19, v22, -1, 0, 0, v13) )
    {
      ERR_put_error((int)v13, 0xDu, 131, 58, ".\\crypto\\asn1\\tasn_dec.c", 711);
      ASN1_template_free(val, v9);
      return 0;
    }
    v19 = (const unsigned __int8 **)((char *)v19 + v20 - v35);
    if ( !sk_push((stack_st *)*val, (char *)pval) )
    {
      ERR_put_error((int)v13, 0xDu, 131, 65, ".\\crypto\\asn1\\tasn_dec.c", 719);
      ASN1_template_free(val, v9);
      return 0;
    }
    if ( (int)v19 <= 0 )
    {
      v7 = val;
      goto LABEL_24;
    }
  }
  v23 = v35 + 2;
  v35 += 2;
  if ( v34 )
    goto LABEL_40;
  ERR_put_error((int)v13, 0xDu, 131, 159, ".\\crypto\\asn1\\tasn_dec.c", 698);
  ASN1_template_free(val, v9);
  return 0;
}
