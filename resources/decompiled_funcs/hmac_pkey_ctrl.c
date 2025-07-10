int __cdecl hmac_pkey_ctrl(evp_pkey_st *pkey, int op, int arg1, _DWORD *arg2)
{
  if ( op != 3 )
    return -2;
  *arg2 = 64;
  return 1;
}
