int __cdecl X509_CRL_match(const X509_crl_st *a, const X509_crl_st *b)
{
  unsigned __int8 *sha1_hash; // ecx
  unsigned int v3; // eax
  unsigned __int8 *i; // edx
  int v6; // eax

  sha1_hash = b->sha1_hash;
  v3 = 20;
  for ( i = a->sha1_hash; *(_DWORD *)i == *(_DWORD *)sha1_hash; i += 4 )
  {
    v3 -= 4;
    sha1_hash += 4;
    if ( v3 < 4 )
      return 0;
  }
  v6 = *i - *sha1_hash;
  if ( !v6 )
  {
    v6 = i[1] - sha1_hash[1];
    if ( !v6 )
    {
      v6 = i[2] - sha1_hash[2];
      if ( !v6 )
        v6 = i[3] - sha1_hash[3];
    }
  }
  return (v6 >> 31) | 1;
}
