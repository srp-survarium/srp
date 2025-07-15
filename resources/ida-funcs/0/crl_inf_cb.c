int __cdecl crl_inf_cb(int operation, struct ASN1_VALUE_st **pval)
{
  stack_st *v2; // eax

  if ( *pval )
  {
    v2 = (stack_st *)*((_DWORD *)*pval + 5);
    if ( v2 )
    {
      if ( operation == 5 )
        sk_set_cmp_func(v2, (int (__cdecl *)(const void *, const void *))X509_REVOKED_cmp);
    }
  }
  return 1;
}
