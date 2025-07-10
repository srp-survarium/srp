int __cdecl enc_ctrl(bio_st *b, int cmd, int num, _DWORD *ptr)
{
  char *v4; // esi
  int v5; // edi
  int result; // eax
  int v7; // edi
  evp_cipher_ctx_st *v8; // edi
  int v9; // [esp-4h] [ebp-14h]

  v4 = (char *)b->ptr;
  v5 = 1;
  switch ( cmd )
  {
    case 1:
      v9 = *((_DWORD *)v4 + 7);
      *((_DWORD *)v4 + 4) = 1;
      *((_DWORD *)v4 + 3) = 0;
      EVP_CipherInit_ex((evp_cipher_ctx_st *)(v4 + 20), 0, 0, 0, 0, v9);
      return BIO_ctrl(b->next_bio, cmd, num, ptr);
    case 2:
      if ( *((int *)v4 + 2) <= 0 )
        return v5;
      return BIO_ctrl(b->next_bio, cmd, num, ptr);
    case 10:
    case 13:
      v5 = *(_DWORD *)v4 - *((_DWORD *)v4 + 1);
      if ( v5 <= 0 )
        return BIO_ctrl(b->next_bio, cmd, num, ptr);
      return v5;
    case 11:
      break;
    case 12:
      v8 = (evp_cipher_ctx_st *)(ptr[8] + 20);
      EVP_CIPHER_CTX_init(v8);
      result = EVP_CIPHER_CTX_copy((unsigned int)v8, v8, (evp_cipher_ctx_st *)(v4 + 20));
      v5 = result;
      if ( !result )
        return v5;
      ptr[3] = 1;
      return result;
    case 101:
      BIO_clear_flags(b, 15);
      v7 = BIO_ctrl(b->next_bio, cmd, num, ptr);
      BIO_copy_next_retry(b);
      return v7;
    case 113:
      return *((_DWORD *)v4 + 4);
    case 129:
      *ptr = v4 + 20;
      b->init = 1;
      return 1;
    default:
      return BIO_ctrl(b->next_bio, cmd, num, ptr);
  }
  while ( *(_DWORD *)v4 == *((_DWORD *)v4 + 1) )
  {
LABEL_10:
    if ( *((_DWORD *)v4 + 3) )
      return BIO_ctrl(b->next_bio, cmd, num, ptr);
    *((_DWORD *)v4 + 3) = 1;
    *((_DWORD *)v4 + 1) = 0;
    result = EVP_CipherFinal_ex((evp_cipher_ctx_st *)(v4 + 20), (unsigned __int8 *)v4 + 160, (int *)v4);
    *((_DWORD *)v4 + 4) = result;
    if ( result <= 0 )
      return result;
  }
  while ( 1 )
  {
    result = enc_write(b, 0, 0);
    if ( result < 0 )
      return result;
    if ( *(_DWORD *)v4 == *((_DWORD *)v4 + 1) )
      goto LABEL_10;
  }
}
