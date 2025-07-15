engine_st *__usercall ENGINE_get_cipher@<eax>(int a1@<ebx>, engine_st *e, int nid)
{
  int (__cdecl *ciphers)(engine_st *, const evp_cipher_st **, const int **, int); // eax

  ciphers = e->ciphers;
  if ( ciphers && ciphers(e, (const evp_cipher_st **)&e, 0, nid) )
    return e;
  ERR_put_error(a1, 0x26u, 185, 146, ".\\crypto\\engine\\tb_cipher.c", 126);
  return 0;
}
