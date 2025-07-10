void __cdecl dump_value_LHASH_DOALL_ARG(const char **arg1, bio_st *arg2)
{
  const char *v2; // ecx

  v2 = arg1[1];
  if ( v2 )
    BIO_printf(arg2, "[%s] %s=%s\n", *arg1, v2, arg1[2]);
  else
    BIO_printf(arg2, "[[%s]]\n", *arg1);
}
