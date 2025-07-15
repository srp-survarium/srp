int __cdecl check_purpose_crl_sign(const x509_purpose_st *xp, const x509_st *x, int ca)
{
  int v3; // eax

  if ( !ca )
    return (x->ex_flags & 2) == 0 || (x->ex_kusage & 2) != 0;
  v3 = check_ca(x);
  return v3 != 2 ? v3 : 0;
}
