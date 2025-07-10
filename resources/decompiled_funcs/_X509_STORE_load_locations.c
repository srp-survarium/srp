int __cdecl X509_STORE_load_locations(x509_store_st *ctx, const char *file, const char *path)
{
  x509_lookup_method_st *v3; // eax
  x509_lookup_st *v4; // eax
  x509_lookup_method_st *v6; // eax
  x509_lookup_st *v7; // eax

  if ( file )
  {
    v3 = X509_LOOKUP_file();
    v4 = X509_STORE_add_lookup(ctx, v3);
    if ( !v4 || X509_LOOKUP_ctrl(v4) != 1 )
      return 0;
  }
  if ( path )
  {
    v6 = X509_LOOKUP_hash_dir();
    v7 = X509_STORE_add_lookup(ctx, v6);
    if ( !v7 || X509_LOOKUP_ctrl(v7) != 1 )
      return 0;
  }
  else if ( !file )
  {
    return 0;
  }
  return 1;
}
