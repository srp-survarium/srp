int __cdecl x509_object_cmp(const x509_object_st *const *a, const x509_object_st *const *b)
{
  _DWORD *v2; // ecx
  _DWORD *v3; // edx
  int result; // eax

  v2 = *a;
  v3 = *b;
  result = **(_DWORD **)a - **(_DWORD **)b;
  if ( !result )
  {
    if ( **(_DWORD **)a == 1 )
    {
      return X509_subject_name_cmp((const x509_st *)v2[1], (const x509_st *)v3[1]);
    }
    else if ( **(_DWORD **)a == 2 )
    {
      return X509_CRL_cmp((const X509_crl_st *)v2[1], (const X509_crl_st *)v3[1]);
    }
  }
  return result;
}
