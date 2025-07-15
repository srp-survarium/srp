int __thiscall rc2_meth_to_magic(evp_cipher_ctx_st *e)
{
  int ptr; // [esp+0h] [ebp-4h] BYREF

  EVP_CIPHER_CTX_ctrl(e, 2, 0, &ptr);
  if ( ptr == 128 )
    return 58;
  if ( ptr == 64 )
    return 120;
  return ptr != 40 ? 0 : 0xA0;
}
