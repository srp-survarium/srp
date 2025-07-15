int __cdecl md_ctrl(bio_st *b, engine_st *cmd, int num, void *ptr)
{
  env_md_ctx_st *v4; // eax
  int v5; // edi
  int result; // eax
  int v7; // edi

  v4 = (env_md_ctx_st *)b->ptr;
  switch ( (unsigned int)cmd )
  {
    case 1u:
      if ( !b->init )
        goto LABEL_7;
      v5 = EVP_DigestInit_ex(cmd, v4, v4->digest, 0);
      if ( v5 <= 0 )
        goto LABEL_16;
      result = BIO_ctrl((int)cmd, b->next_bio, (int)cmd, num, ptr);
      break;
    case 0xCu:
      EVP_MD_CTX_copy_ex((int)cmd, *((env_md_ctx_st **)ptr + 8), (const env_md_ctx_st *)b->ptr);
      b->init = 1;
      result = 1;
      break;
    case 0x65u:
      BIO_clear_flags(b, 15);
      v7 = BIO_ctrl((int)cmd, b->next_bio, (int)cmd, num, ptr);
      BIO_copy_next_retry(b);
      result = v7;
      break;
    case 0x6Fu:
      result = EVP_DigestInit_ex(cmd, v4, (const env_md_st *)ptr, 0);
      v5 = result;
      if ( result <= 0 )
        goto LABEL_16;
      b->init = 1;
      break;
    case 0x70u:
      if ( !b->init )
        goto LABEL_7;
      *(_DWORD *)ptr = v4->digest;
      result = 1;
      break;
    case 0x78u:
      *(_DWORD *)ptr = v4;
      b->init = 1;
      result = 1;
      break;
    case 0x94u:
      if ( b->init )
      {
        b->ptr = ptr;
        result = 1;
      }
      else
      {
LABEL_7:
        result = 0;
      }
      break;
    default:
      v5 = BIO_ctrl((int)cmd, b->next_bio, (int)cmd, num, ptr);
LABEL_16:
      result = v5;
      break;
  }
  return result;
}
