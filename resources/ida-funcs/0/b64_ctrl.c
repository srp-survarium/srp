int __cdecl b64_ctrl(bio_st *b, int cmd, int num, void *ptr)
{
  char *v4; // esi
  int v5; // edi
  int result; // eax
  int v7; // edi

  v4 = (char *)b->ptr;
  v5 = 1;
  switch ( cmd )
  {
    case 1:
      *((_DWORD *)v4 + 6) = 1;
      *((_DWORD *)v4 + 5) = 1;
      *((_DWORD *)v4 + 4) = 0;
      return BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
    case 2:
      if ( *((int *)v4 + 6) > 0 )
        return BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
      return v5;
    case 10:
      if ( *(_DWORD *)v4 < *((_DWORD *)v4 + 1) )
        OpenSSLDie(1, (int)v4, (int)b, ".\\crypto\\evp\\bio_b64.c", 523, "ctx->buf_len >= ctx->buf_off");
      v5 = *(_DWORD *)v4 - *((_DWORD *)v4 + 1);
      goto LABEL_17;
    case 11:
again_2:
      if ( *(_DWORD *)v4 == *((_DWORD *)v4 + 1) )
        goto LABEL_22;
      break;
    case 12:
      return v5;
    case 13:
      if ( *(_DWORD *)v4 < *((_DWORD *)v4 + 1) )
        OpenSSLDie(1, (int)v4, (int)b, ".\\crypto\\evp\\bio_b64.c", 514, "ctx->buf_len >= ctx->buf_off");
      v5 = *(_DWORD *)v4 - *((_DWORD *)v4 + 1);
      if ( *(_DWORD *)v4 == *((_DWORD *)v4 + 1) )
      {
        if ( *((_DWORD *)v4 + 4) != v5 && *((_DWORD *)v4 + 7) != v5 )
          return 1;
      }
      else
      {
LABEL_17:
        if ( v5 > 0 )
          return v5;
      }
      return BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
    case 101:
      BIO_clear_flags(b, 15);
      v7 = BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
      BIO_copy_next_retry(b);
      return v7;
    default:
      return BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
  }
  while ( 1 )
  {
    result = b64_write(0, b, 0, 0);
    if ( result < 0 )
      return result;
    if ( *(_DWORD *)v4 == *((_DWORD *)v4 + 1) )
    {
LABEL_22:
      if ( (BIO_test_flags(b, -1) & 0x100) != 0 )
      {
        if ( *((_DWORD *)v4 + 2) )
        {
          *(_DWORD *)v4 = EVP_EncodeBlock(
                            (unsigned __int8 *)v4 + 124,
                            (const unsigned __int8 *)v4 + 1626,
                            *((_DWORD *)v4 + 2));
          *((_DWORD *)v4 + 1) = 0;
          *((_DWORD *)v4 + 2) = 0;
          goto again_2;
        }
      }
      else if ( *((_DWORD *)v4 + 4) && *((_DWORD *)v4 + 7) )
      {
        *((_DWORD *)v4 + 1) = 0;
        EVP_EncodeFinal((evp_Encode_Ctx_st *)(v4 + 28), (unsigned __int8 *)v4 + 124, (int *)v4);
        goto again_2;
      }
      return BIO_ctrl((int)b, b->next_bio, cmd, num, ptr);
    }
  }
}
