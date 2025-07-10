int __cdecl md_ctrl(bio_st *b, int cmd, int num, void *ptr)
{
  env_md_ctx_st *v4; // eax
  int v5; // edi
  int result; // eax
  int v7; // edi

  v4 = (env_md_ctx_st *)b->ptr;
  switch ( cmd )
  {
    case 1:
      if ( !b->init )
        goto LABEL_7;
      v5 = EVP_DigestInit_ex(v4, v4->digest, 0);
      if ( v5 <= 0 )
        goto LABEL_16;
      result = BIO_ctrl(b->next_bio, cmd, num, ptr);
      break;
    case 12:
      EVP_MD_CTX_copy_ex(*((env_md_ctx_st **)ptr + 8), (const env_md_ctx_st *)b->ptr);
      b->init = 1;
      result = 1;
      break;
    case 101:
      BIO_clear_flags(b, 15);
      v7 = BIO_ctrl(b->next_bio, cmd, num, ptr);
      BIO_copy_next_retry(b);
      result = v7;
      break;
    case 111:
      result = EVP_DigestInit_ex(v4, (const env_md_st *)ptr, 0);
      v5 = result;
      if ( result <= 0 )
        goto LABEL_16;
      b->init = 1;
      break;
    case 112:
      if ( !b->init )
        goto LABEL_7;
      *(_DWORD *)ptr = v4->digest;
      result = 1;
      break;
    case 120:
      *(_DWORD *)ptr = v4;
      b->init = 1;
      result = 1;
      break;
    case 148:
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
      v5 = BIO_ctrl(b->next_bio, cmd, num, ptr);
LABEL_16:
      result = v5;
      break;
  }
  return result;
}
