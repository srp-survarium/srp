int __cdecl dsa_finish(dsa_st *dsa)
{
  if ( dsa->method_mont_p )
    BN_MONT_CTX_free(dsa->method_mont_p);
  return 1;
}
