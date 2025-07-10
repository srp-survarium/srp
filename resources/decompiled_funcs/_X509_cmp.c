int __usercall X509_cmp@<eax>(unsigned int a1@<edi>, x509_st *a, x509_st *b)
{
  unsigned int v3; // eax
  unsigned __int8 *sha1_hash; // ecx
  unsigned __int8 *i; // edx
  int v7; // eax

  X509_check_purpose(a1, a, -1, 0);
  X509_check_purpose((unsigned int)b, b, -1, 0);
  v3 = 20;
  sha1_hash = b->sha1_hash;
  for ( i = a->sha1_hash; *(_DWORD *)i == *(_DWORD *)sha1_hash; i += 4 )
  {
    v3 -= 4;
    sha1_hash += 4;
    if ( v3 < 4 )
      return 0;
  }
  v7 = *i - *sha1_hash;
  if ( !v7 )
  {
    v7 = i[1] - sha1_hash[1];
    if ( !v7 )
    {
      v7 = i[2] - sha1_hash[2];
      if ( !v7 )
        v7 = i[3] - sha1_hash[3];
    }
  }
  return (v7 >> 31) | 1;
}
