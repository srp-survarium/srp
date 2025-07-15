int __cdecl asn1_template_ex_i2d(
        struct ASN1_VALUE_st **pval,
        unsigned __int8 **out,
        const ASN1_TEMPLATE_st *tt,
        int tag,
        int iclass)
{
  unsigned int flags; // ecx
  int v7; // esi
  unsigned int v8; // eax
  int v9; // edi
  unsigned int v10; // edi
  int v11; // ebp
  struct ASN1_VALUE_st *v12; // ebx
  int v13; // edi
  int i; // esi
  const ASN1_ITEM_st *v15; // eax
  int v16; // eax
  bool v17; // zf
  const ASN1_ITEM_st *v18; // eax
  const ASN1_ITEM_st *v19; // eax
  int v20; // eax
  int v21; // esi
  const ASN1_ITEM_st *v22; // eax
  const ASN1_ITEM_st *v23; // eax
  int v24; // [esp-Ch] [ebp-38h]
  int v25; // [esp+8h] [ebp-24h]
  char xclass; // [esp+Ch] [ebp-20h]
  int v27; // [esp+10h] [ebp-1Ch]
  int do_sort; // [esp+14h] [ebp-18h]
  int taga; // [esp+18h] [ebp-14h]
  char v30; // [esp+1Ch] [ebp-10h]
  unsigned int v31; // [esp+20h] [ebp-Ch]
  int v32; // [esp+20h] [ebp-Ch]
  struct ASN1_VALUE_st *pvala; // [esp+24h] [ebp-8h] BYREF
  int length; // [esp+28h] [ebp-4h]
  int aclass; // [esp+40h] [ebp+14h]

  flags = tt->flags;
  v31 = tt->flags;
  if ( (tt->flags & 0x18) != 0 )
  {
    if ( tag != -1 )
      return -1;
    v7 = tt->tag;
    v8 = tt->flags & 0xC0;
    v25 = v7;
    xclass = flags & 0xC0;
    goto LABEL_8;
  }
  if ( tag == -1 )
  {
    v25 = -1;
    v7 = -1;
    xclass = 0;
    v8 = 0;
LABEL_8:
    v9 = iclass;
    goto LABEL_9;
  }
  v9 = iclass;
  v25 = tag;
  v7 = tag;
  v8 = iclass & 0xC0;
  xclass = iclass & 0xC0;
LABEL_9:
  v10 = v9 & 0xFFFFFF3F;
  aclass = v10;
  if ( (flags & 0x800) == 0 || (v11 = 2, (v10 & 0x800) == 0) )
    v11 = 1;
  if ( (flags & 6) != 0 )
  {
    v12 = *pval;
    v13 = 0;
    if ( *pval )
    {
      if ( (flags & 2) != 0 )
      {
        do_sort = 1;
        if ( (flags & 4) != 0 )
          do_sort = 2;
      }
      else
      {
        do_sort = 0;
      }
      if ( v7 == -1 || (flags & 0x10) != 0 )
      {
        v30 = 0;
        taga = (do_sort != 0) + 16;
      }
      else
      {
        taga = v7;
        v30 = v8;
      }
      for ( i = 0; i < sk_num((const stack_st *)v12); ++i )
      {
        pvala = (struct ASN1_VALUE_st *)sk_value((const stack_st *)v12, i);
        v15 = tt->item();
        v13 += ASN1_item_ex_i2d(&pvala, 0, v15, -1, aclass);
      }
      v16 = ASN1_object_size(v11, v13, taga);
      v17 = (v31 & 0x10) == 0;
      length = v16;
      v32 = v31 & 0x10;
      if ( !v17 )
        v16 = ASN1_object_size(v11, v16, v25);
      v27 = v16;
      if ( out )
      {
        if ( v32 )
          ASN1_put_object(out, v11, length, v25, xclass);
        ASN1_put_object(out, v11, v13, taga, v30);
        v18 = tt->item();
        asn1_set_seq_out((stack_st_ASN1_VALUE *)v12, out, v13, v18, do_sort, aclass);
        if ( v11 == 2 )
        {
          ASN1_put_eoc(out);
          if ( v32 )
          {
            ASN1_put_eoc(out);
            return v27;
          }
        }
      }
      return v27;
    }
    return 0;
  }
  if ( (flags & 0x10) != 0 )
  {
    v19 = tt->item();
    v20 = ASN1_item_ex_i2d(pval, 0, v19, -1, v10);
    v21 = v20;
    if ( v20 )
    {
      v27 = ASN1_object_size(v11, v20, v25);
      if ( out )
      {
        ASN1_put_object(out, v11, v21, v25, xclass);
        v22 = tt->item();
        ASN1_item_ex_i2d(pval, out, v22, -1, v10);
        if ( v11 == 2 )
          ASN1_put_eoc(out);
      }
      return v27;
    }
    return 0;
  }
  v24 = v10 | v8;
  v23 = tt->item();
  return ASN1_item_ex_i2d(pval, out, v23, v7, v24);
}
