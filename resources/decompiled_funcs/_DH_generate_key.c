int __cdecl DH_generate_key(dh_st *dh)
{
  return ((int (*)(void))dh->meth->generate_key)();
}
