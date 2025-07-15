int __cdecl new_dir(x509_lookup_st *lu)
{
  buf_mem_st **v1; // esi
  buf_mem_st *v2; // eax

  v1 = (buf_mem_st **)CRYPTO_malloc(8, ".\\crypto\\x509\\by_dir.c", 160);
  if ( !v1 )
    return 0;
  v2 = BUF_MEM_new();
  *v1 = v2;
  if ( !v2 )
  {
    CRYPTO_free(v1);
    return 0;
  }
  v1[1] = 0;
  lu->method_data = (char *)v1;
  return 1;
}
