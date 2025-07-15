int __cdecl X509_check_trust(x509_st *x, int id, int flags)
{
  int v4; // eax
  char *v5; // eax

  if ( id == -1 )
    return 1;
  v4 = X509_TRUST_get_by_id(id);
  if ( v4 == -1 )
    return default_trust(id, x, flags);
  if ( v4 >= 0 )
  {
    if ( v4 >= 8 )
      v5 = sk_value(&trtable->stack, v4 - 8);
    else
      v5 = (char *)&trstandard[v4];
  }
  else
  {
    v5 = 0;
  }
  return (*((int (__cdecl **)(char *, x509_st *))v5 + 2))(v5, x);
}
