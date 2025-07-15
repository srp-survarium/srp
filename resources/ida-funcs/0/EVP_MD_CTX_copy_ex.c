int __usercall EVP_MD_CTX_copy_ex@<eax>(int a1@<ebx>, env_md_ctx_st *out, const env_md_ctx_st *in)
{
  void *md_data; // ebx
  int ctx_size; // eax
  evp_pkey_ctx_st *v6; // eax
  void *v7; // eax
  int (__cdecl *copy)(env_md_ctx_st *, const env_md_ctx_st *); // eax

  if ( in && in->digest )
  {
    if ( in->engine && !ENGINE_init((int)in, a1, in->engine) )
    {
      ERR_put_error(a1, 6u, 110, 38, ".\\crypto\\evp\\digest.c", 281);
      return 0;
    }
    if ( out->digest == in->digest )
    {
      md_data = out->md_data;
      EVP_MD_CTX_set_flags(out, 4);
    }
    else
    {
      md_data = 0;
    }
    EVP_MD_CTX_cleanup((int)in, (int)md_data, out);
    *out = *in;
    if ( in->md_data )
    {
      ctx_size = out->digest->ctx_size;
      if ( ctx_size )
      {
        if ( md_data )
        {
          out->md_data = md_data;
        }
        else
        {
          v7 = CRYPTO_malloc(ctx_size, ".\\crypto\\evp\\digest.c", 301);
          out->md_data = v7;
          if ( !v7 )
          {
            ERR_put_error(0, 6u, 110, 65, ".\\crypto\\evp\\digest.c", 304);
            return 0;
          }
        }
        memcpy((int)out->md_data, (const __m128i *)in->md_data, out->digest->ctx_size);
      }
    }
    out->update = in->update;
    if ( !in->pctx || (v6 = EVP_PKEY_CTX_dup((int)md_data, (int)in, in->pctx), (out->pctx = v6) != 0) )
    {
      copy = out->digest->copy;
      if ( copy )
        return copy(out, in);
      else
        return 1;
    }
    else
    {
      EVP_MD_CTX_cleanup((int)in, (int)md_data, out);
      return 0;
    }
  }
  else
  {
    ERR_put_error(a1, 6u, 110, 111, ".\\crypto\\evp\\digest.c", 274);
    return 0;
  }
}
