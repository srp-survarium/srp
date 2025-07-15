void __cdecl ASN1_template_free(struct ASN1_VALUE_st **pval, const ASN1_TEMPLATE_st *tt)
{
  const ASN1_TEMPLATE_st *v2; // esi
  stack_st *v3; // ebp
  int v4; // ebx
  char *v5; // eax
  int (*item)(void); // ecx
  const ASN1_ITEM_st *v7; // eax
  const ASN1_ITEM_st *v8; // eax
  unsigned int v9; // [esp-4h] [ebp-10h]
  struct ASN1_VALUE_st *pvala; // [esp+8h] [ebp-4h] BYREF

  v2 = tt;
  if ( (tt->flags & 6) != 0 )
  {
    v3 = (stack_st *)*pval;
    v4 = 0;
    if ( sk_num((const stack_st *)*pval) > 0 )
    {
      while ( 1 )
      {
        v5 = sk_value(v3, v4);
        item = (int (*)(void))v2->item;
        pvala = (struct ASN1_VALUE_st *)v5;
        v7 = (const ASN1_ITEM_st *)item();
        asn1_item_combine_free(&pvala, v7, 0);
        if ( ++v4 >= sk_num(v3) )
          break;
        v2 = tt;
      }
    }
    sk_free(v3);
    *pval = 0;
  }
  else
  {
    v9 = tt->flags & 0x400;
    v8 = tt->item();
    asn1_item_combine_free(pval, v8, v9);
  }
}
