void __cdecl evp_pkey_set_cb_translate(bn_gencb_st *cb, evp_pkey_ctx_st *ctx)
{
  cb->ver = 2;
  cb->arg = ctx;
  cb->cb.cb_1 = (void (__cdecl *)(int, int, void *))trans_cb;
}
