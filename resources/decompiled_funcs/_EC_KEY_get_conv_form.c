const ecdh_method *__cdecl EC_KEY_get_conv_form(const engine_st *e)
{
  return e->ecdh_meth;
}
