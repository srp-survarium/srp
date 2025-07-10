int __cdecl dh_param_print(bio_st *bp, const evp_pkey_st *pkey, int indent)
{
  return do_dh_print(bp, pkey->pkey.dh, indent, 0);
}
