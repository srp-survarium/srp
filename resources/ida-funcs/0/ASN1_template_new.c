int __usercall ASN1_template_new@<eax>(int a1@<ebx>, struct ASN1_VALUE_st **pval, const ASN1_TEMPLATE_st *tt)
{
  const ASN1_ITEM_st *v3; // eax
  unsigned int flags; // edx
  const ASN1_ITEM_st *v6; // eax
  struct ASN1_VALUE_st *v7; // eax

  v3 = tt->item();
  flags = tt->flags;
  if ( (tt->flags & 1) != 0 )
  {
    if ( (flags & 0x306) != 0 )
    {
      *pval = 0;
    }
    else
    {
      v6 = tt->item();
      asn1_item_clear(pval, v6);
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
    v7 = (struct ASN1_VALUE_st *)sk_new_null();
    if ( v7 )
    {
      *pval = v7;
      return 1;
    }
    else
    {
      ERR_put_error(a1, 0xDu, 133, 65, ".\\crypto\\asn1\\tasn_new.c", 293);
      return 0;
    }
  }
  else
  {
    return asn1_item_ex_combine_new(pval, v3, tt->flags & 0x400);
  }
}
