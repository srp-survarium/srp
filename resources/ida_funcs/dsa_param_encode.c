int __cdecl dsa_param_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_DSAparams(pkey->pkey.dsa, pder);
}
