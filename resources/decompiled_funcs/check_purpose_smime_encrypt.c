int __cdecl check_purpose_smime_encrypt(const x509_purpose_st *xp, const x509_st *x, int ca)
{
  unsigned int ex_flags; // ecx
  int result; // eax
  bool v5; // zf
  unsigned int ex_nscert; // eax

  ex_flags = x->ex_flags;
  if ( (ex_flags & 4) != 0 && (x->ex_xkusage & 4) == 0 )
    return 0;
  if ( !ca )
  {
    if ( (ex_flags & 8) == 0 || (ex_nscert = x->ex_nscert, (ex_nscert & 0x20) != 0) )
    {
      result = 1;
    }
    else
    {
      if ( (ex_nscert & 0x80u) == 0 )
        return 0;
      result = 2;
    }
    if ( (ex_flags & 2) == 0 )
      return result;
    v5 = (x->ex_kusage & 0x20) == 0;
LABEL_14:
    if ( !v5 )
      return result;
    return 0;
  }
  result = check_ca(x);
  if ( result )
  {
    if ( result != 5 )
      return result;
    v5 = (x->ex_nscert & 2) == 0;
    goto LABEL_14;
  }
  return 0;
}
