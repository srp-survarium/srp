int __cdecl EVP_MD_CTX_copy_ex(env_md_ctx_st *out, const env_md_ctx_st *in)
{
  void *md_data; // ebx
  int ctx_size; // eax
  evp_pkey_ctx_st *v5; // eax
  void *v6; // eax
  int (__cdecl *copy)(env_md_ctx_st *, const env_md_ctx_st *); // eax

  if ( in && in->digest )
  {
    if ( in->engine && !ENGINE_init((unsigned int)in, in->engine) )
    {
      ERR_put_error(6u, 110, 38, ".\\crypto\\evp\\digest.c", 281);
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
    EVP_MD_CTX_cleanup((unsigned int)in, out);
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
          v6 = CRYPTO_malloc(ctx_size, ".\\crypto\\evp\\digest.c", 301);
          out->md_data = v6;
          if ( !v6 )
          {
            ERR_put_error(6u, 110, 65, ".\\crypto\\evp\\digest.c", 304);
            return 0;
          }
        }
        memcpy((unsigned __int8 *)out->md_data, (unsigned __int8 *)in->md_data, out->digest->ctx_size);
      }
    }
    out->update = in->update;
    if ( !in->pctx || (v5 = EVP_PKEY_CTX_dup(in->pctx), (out->pctx = v5) != 0) )
    {
      copy = out->digest->copy;
      if ( copy )
        return copy(out, in);
      else
        return 1;
    }
    else
    {
      EVP_MD_CTX_cleanup((unsigned int)in, out);
      return 0;
    }
  }
  else
  {
    ERR_put_error(6u, 110, 111, ".\\crypto\\evp\\digest.c", 274);
    return 0;
  }
}
