int __cdecl long_print(bio_st *out, struct ASN1_VALUE_st **pval)
{
  return BIO_printf(out, "%ld\n", *pval);
}
