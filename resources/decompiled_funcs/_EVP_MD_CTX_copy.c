int __cdecl EVP_MD_CTX_copy(env_md_ctx_st *out, const env_md_ctx_st *in)
{
  out->digest = 0;
  out->engine = 0;
  out->flags = 0;
  out->md_data = 0;
  out->pctx = 0;
  out->update = 0;
  return EVP_MD_CTX_copy_ex(out, in);
}
