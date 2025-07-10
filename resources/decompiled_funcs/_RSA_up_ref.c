BOOL __cdecl RSA_up_ref(rsa_st *r)
{
  return CRYPTO_add_lock(&r->references, 1, 9, ".\\crypto\\rsa\\rsa_lib.c", 252) > 1;
}
