int __cdecl old_rsa_priv_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_RSAPrivateKey(pkey->pkey.rsa, pder);
}
