int __cdecl dh_private_print(bio_st *bp, const evp_pkey_st *pkey, int indent)
{
  return do_dh_print(bp, pkey->pkey.dh, indent, (asn1_pctx_st *)2);
}
