const ecdsa_method *__cdecl ENGINE_get_ECDSA(const engine_st *e)
{
  return e->ecdsa_meth;
}
