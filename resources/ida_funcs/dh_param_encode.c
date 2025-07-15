int __cdecl dh_param_encode(const evp_pkey_st *pkey, unsigned __int8 **pder)
{
  return i2d_DHparams(pkey->pkey.dh, pder);
}
