int __cdecl ASN1_template_new(struct ASN1_VALUE_st **pval, const ASN1_TEMPLATE_st *tt)
{
  const ASN1_ITEM_st *v2; // eax
  unsigned int flags; // edx
  const ASN1_ITEM_st *v5; // eax
  struct ASN1_VALUE_st *v6; // eax

  v2 = tt->item();
  flags = tt->flags;
  if ( (tt->flags & 1) != 0 )
  {
    if ( (flags & 0x306) != 0 )
    {
      *pval = 0;
    }
    else
    {
      v5 = tt->item();
      asn1_item_clear(pval, v5);
    }
    return 1;
  }
  else if ( (flags & 0x300) != 0 )
  {
    *pval = 0;
    return 1;
  }
  else if ( (flags & 6) != 0 )
  {
    v6 = (struct ASN1_VALUE_st *)sk_new_null();
    if ( v6 )
    {
      *pval = v6;
      return 1;
    }
    else
    {
      ERR_put_error(0xDu, 133, 65, ".\\crypto\\asn1\\tasn_new.c", 293);
      return 0;
    }
  }
  else
  {
    return asn1_item_ex_combine_new(pval, v2, tt->flags & 0x400);
  }
}
