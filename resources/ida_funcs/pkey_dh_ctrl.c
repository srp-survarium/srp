int __cdecl pkey_dh_ctrl(evp_pkey_ctx_st *ctx, int type, int p1)
{
  _DWORD *data; // ecx

  data = ctx->data;
  if ( type != 2 )
  {
    if ( type != 4097 )
    {
      if ( type == 4098 )
      {
        data[1] = p1;
        return 1;
      }
      return -2;
    }
    if ( p1 < 256 )
      return -2;
    *data = p1;
  }
  return 1;
}
