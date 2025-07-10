BOOL __cdecl EC_KEY_up_ref(ec_key_st *r)
{
  return CRYPTO_add_lock(&r->references, 1, 33, ".\\crypto\\ec\\ec_key.c", 219) > 1;
}
