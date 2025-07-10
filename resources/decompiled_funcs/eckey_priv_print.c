int __cdecl eckey_priv_print(bio_st *bp, const evp_pkey_st *pkey, int indent)
{
  return do_EC_KEY_print(bp, indent, 2);
}
