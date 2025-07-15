int __usercall X509_check_trust@<eax>(int a1@<edi>, x509_st *x, int id, int flags)
{
  int v5; // eax
  char *v6; // eax

  if ( id == -1 )
    return 1;
  v5 = X509_TRUST_get_by_id(a1, id);
  if ( v5 == -1 )
    return default_trust(id, x, flags);
  if ( v5 >= 0 )
  {
    if ( v5 >= 8 )
      v6 = sk_value(&trtable->stack, v5 - 8);
    else
      v6 = (char *)&trstandard[v5];
  }
  else
  {
    v6 = 0;
  }
  return (*((int (__cdecl **)(char *, x509_st *))v6 + 2))(v6, x);
}
