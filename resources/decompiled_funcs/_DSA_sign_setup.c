int __cdecl DSA_sign_setup(dsa_st *dsa)
{
  return ((int (*)(void))dsa->meth->dsa_sign_setup)();
}
