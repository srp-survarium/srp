int __cdecl rc2_ctrl(evp_cipher_ctx_st *c, int type, int arg, _DWORD *ptr)
{
  if ( type )
  {
    if ( type == 2 )
    {
      *ptr = *(_DWORD *)c->cipher_data;
      return 1;
    }
    else if ( type == 3 )
    {
      if ( arg <= 0 )
      {
        return 0;
      }
      else
      {
        *(_DWORD *)c->cipher_data = arg;
        return 1;
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    *(_DWORD *)c->cipher_data = 8 * EVP_CIPHER_CTX_key_length(c);
    return 1;
  }
}
