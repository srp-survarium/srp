struct ASN1_VALUE_st **__cdecl asn1_get_field_ptr(struct ASN1_VALUE_st **pval, const ASN1_TEMPLATE_st *tt)
{
  if ( (tt->flags & 0x400) != 0 )
    return pval;
  else
    return (struct ASN1_VALUE_st **)((char *)*pval + tt->offset);
}
