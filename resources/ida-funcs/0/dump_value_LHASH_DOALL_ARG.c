void __cdecl dump_value_LHASH_DOALL_ARG(const char **a1, bio_st *a2)
{
  const char *v2; // ecx

  v2 = a1[1];
  if ( v2 )
    BIO_printf(a2, "[%s] %s=%s\n", *a1, v2, a1[2]);
  else
    BIO_printf(a2, "[[%s]]\n", *a1);
}
