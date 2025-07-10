evp_pkey_ctx_st *__cdecl EVP_PKEY_CTX_new_id(int id, engine_st *e)
{
  return int_ctx_new(id, 0, e);
}
