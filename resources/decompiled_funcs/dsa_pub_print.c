int __cdecl dsa_pub_print(bio_st *bp, const evp_pkey_st *pkey, int indent)
{
  return do_dsa_print(bp, pkey->pkey.dsa, indent, 1);
}
