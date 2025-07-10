int __cdecl x509_name_ex_print(
        bio_st *out,
        struct ASN1_VALUE_st **pval,
        int indent,
        const char *fname,
        const asn1_pctx_st *pctx)
{
  return X509_NAME_print_ex(out, (X509_name_st *)*pval, indent, pctx->nm_flags) <= 0 ? 0 : 2;
}
