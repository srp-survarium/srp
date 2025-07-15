int __cdecl pkey_rsa_ctrl(evp_pkey_ctx_st *ctx, int type, int p1, const ssl_st *p2)
{
  void *data; // esi
  int result; // eax
  bool v6; // zf

  data = ctx->data;
  if ( type > 4097 )
  {
    if ( type == 4098 )
    {
      if ( p1 >= -2 )
      {
        if ( *((_DWORD *)data + 4) == 6 )
        {
          *((_DWORD *)data + 6) = p1;
          return 1;
        }
        else
        {
          ERR_put_error((int)ctx, 4u, 143, 146, ".\\crypto\\rsa\\rsa_pmeth.c", 411);
          return -2;
        }
      }
    }
    else
    {
      if ( type == 4099 )
      {
        if ( p1 >= 256 )
        {
          *(_DWORD *)data = p1;
          return 1;
        }
        else
        {
          ERR_put_error((int)ctx, 4u, 143, 145, ".\\crypto\\rsa\\rsa_pmeth.c", 420);
          return -2;
        }
      }
      if ( type == 4100 && p2 )
      {
        *((_DWORD *)data + 1) = p2;
        return 1;
      }
    }
    return -2;
  }
  if ( type == 4097 )
  {
    if ( (unsigned int)(p1 - 1) <= 5 )
    {
      if ( !check_padding_md(*((const ssl_st **)data + 5), (int)ctx, p1) )
        return 0;
      if ( p1 == 6 )
      {
        v6 = (ctx->operation & 0x18) == 0;
      }
      else
      {
        if ( p1 != 4 )
        {
LABEL_17:
          *((_DWORD *)data + 4) = p1;
          return 1;
        }
        v6 = (ctx->operation & 0x300) == 0;
      }
      if ( !v6 )
      {
        if ( !*((_DWORD *)data + 5) )
          *((_DWORD *)data + 5) = EVP_sha1();
        goto LABEL_17;
      }
    }
    ERR_put_error((int)ctx, 4u, 143, 144, ".\\crypto\\rsa\\rsa_pmeth.c", 403);
    return -2;
  }
  switch ( type )
  {
    case 1:
      if ( !check_padding_md(p2, (int)ctx, *((_DWORD *)data + 4)) )
        return 0;
      *((_DWORD *)data + 5) = p2;
      result = 1;
      break;
    case 2:
      ERR_put_error((int)ctx, 4u, 143, 148, ".\\crypto\\rsa\\rsa_pmeth.c", 450);
      result = -2;
      break;
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
    case 10:
    case 11:
      return 1;
    default:
      return -2;
  }
  return result;
}
