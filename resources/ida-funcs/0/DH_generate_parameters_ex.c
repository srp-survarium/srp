int __cdecl DH_generate_parameters_ex(dh_st *ret, int prime_len, int generator, bn_gencb_st *cb)
{
  int (*generate_params)(void); // eax

  generate_params = (int (*)(void))ret->meth->generate_params;
  if ( generate_params )
    return generate_params();
  else
    return dh_builtin_genparams(ret, prime_len, generator, cb);
}
