int __cdecl ocsp_helper(const x509_purpose_st *xp, const x509_st *x, int ca)
{
  if ( ca )
    return check_ca(x);
  else
    return 1;
}
