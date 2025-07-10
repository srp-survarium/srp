int __cdecl eckey_param_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_ECParameters(pkey->pkey.ec, pder);
}
