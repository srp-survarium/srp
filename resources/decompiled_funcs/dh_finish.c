int __cdecl dh_finish(dh_st *dh)
{
  if ( dh->method_mont_p )
    BN_MONT_CTX_free(dh->method_mont_p);
  return 1;
}
