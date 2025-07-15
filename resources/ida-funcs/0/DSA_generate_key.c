int __cdecl DSA_generate_key(dsa_st *dsa)
{
  int (__cdecl *dsa_keygen)(dsa_st *); // eax

  dsa_keygen = dsa->meth->dsa_keygen;
  if ( dsa_keygen )
    return dsa_keygen(dsa);
  else
    return dsa_builtin_keygen(dsa);
}
