unsigned int __cdecl X509_NAME_cmp(X509_name_st *a, X509_name_st *b)
{
  unsigned int result; // eax
  unsigned int canon_enclen; // ecx
  unsigned __int8 *canon_enc; // edx
  unsigned __int8 *v5; // esi
  int v6; // eax

  if ( (!a->canon_enc || a->modified) && i2d_X509_NAME(a, 0) < 0 )
    return -2;
  if ( (!b->canon_enc || b->modified) && i2d_X509_NAME(b, 0) < 0 )
    return -2;
  canon_enclen = a->canon_enclen;
  result = canon_enclen - b->canon_enclen;
  if ( !result )
  {
    canon_enc = b->canon_enc;
    v5 = a->canon_enc;
    if ( canon_enclen < 4 )
    {
LABEL_13:
      if ( !canon_enclen )
        return 0;
    }
    else
    {
      while ( *(_DWORD *)v5 == *(_DWORD *)canon_enc )
      {
        canon_enclen -= 4;
        canon_enc += 4;
        v5 += 4;
        if ( canon_enclen < 4 )
          goto LABEL_13;
      }
    }
    v6 = *v5 - *canon_enc;
    if ( v6 )
      return (v6 >> 31) | 1;
    if ( canon_enclen > 1 )
    {
      v6 = v5[1] - canon_enc[1];
      if ( v6 )
        return (v6 >> 31) | 1;
      if ( canon_enclen > 2 )
      {
        v6 = v5[2] - canon_enc[2];
        if ( !v6 )
        {
          if ( canon_enclen > 3 )
          {
            v6 = v5[3] - canon_enc[3];
            return (v6 >> 31) | 1;
          }
          return 0;
        }
        return (v6 >> 31) | 1;
      }
    }
    return 0;
  }
  return result;
}
