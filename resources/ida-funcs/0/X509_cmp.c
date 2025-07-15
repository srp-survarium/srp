int __usercall X509_cmp@<eax>(int a1@<edi>, int a2@<ebx>, x509_st *a, x509_st *b)
{
  unsigned int v4; // eax
  unsigned __int8 *sha1_hash; // ecx
  unsigned __int8 *i; // edx
  int v8; // eax

  X509_check_purpose(a1, a2, a, -1, 0);
  X509_check_purpose((int)b, a2, b, -1, 0);
  v4 = 20;
  sha1_hash = b->sha1_hash;
  for ( i = a->sha1_hash; *(_DWORD *)i == *(_DWORD *)sha1_hash; i += 4 )
  {
    v4 -= 4;
    sha1_hash += 4;
    if ( v4 < 4 )
      return 0;
  }
  v8 = *i - *sha1_hash;
  if ( !v8 )
  {
    v8 = i[1] - sha1_hash[1];
    if ( !v8 )
    {
      v8 = i[2] - sha1_hash[2];
      if ( !v8 )
        v8 = i[3] - sha1_hash[3];
    }
  }
  return (v8 >> 31) | 1;
}
