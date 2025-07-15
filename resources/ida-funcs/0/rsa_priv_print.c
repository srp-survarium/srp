int __cdecl rsa_priv_print(bio_st *bp, const evp_pkey_st *pkey, int indent)
{
  return do_rsa_print(pkey->pkey.rsa, bp, indent, 1);
}
