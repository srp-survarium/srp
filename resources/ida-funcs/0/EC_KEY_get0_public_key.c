const rsa_meth_st *__cdecl EC_KEY_get0_public_key(const engine_st *e)
{
  return e->rsa_meth;
}
