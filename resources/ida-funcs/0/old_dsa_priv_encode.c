int __cdecl old_dsa_priv_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_DSAPrivateKey(pkey->pkey.dsa, pder);
}
