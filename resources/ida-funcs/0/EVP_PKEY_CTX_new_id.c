evp_pkey_ctx_st *__usercall EVP_PKEY_CTX_new_id@<eax>(int a1@<edi>, int id, engine_st *e)
{
  return int_ctx_new(id, 0, a1, e);
}
