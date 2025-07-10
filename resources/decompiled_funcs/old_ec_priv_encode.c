int __cdecl old_ec_priv_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_ECPrivateKey(pkey->pkey.ec, pder);
}
