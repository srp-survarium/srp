int __cdecl BN_GENCB_call(bn_gencb_st *cb, int a, int b)
{
  void (__cdecl *cb_1)(int, int, void *); // ecx

  if ( !cb )
    return 1;
  if ( cb->ver == 1 )
  {
    cb_1 = cb->cb.cb_1;
    if ( cb_1 )
      cb_1(a, b, cb->arg);
    return 1;
  }
  if ( cb->ver == 2 )
    return ((int (__cdecl *)(int, int, bn_gencb_st *))cb->cb.cb_1)(a, b, cb);
  else
    return 0;
}
