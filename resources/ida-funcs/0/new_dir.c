int __usercall new_dir@<eax>(int a1@<ebx>, x509_lookup_st *lu)
{
  _DWORD *v2; // esi
  buf_mem_st *v3; // eax

  v2 = CRYPTO_malloc(8, ".\\crypto\\x509\\by_dir.c", 160);
  if ( !v2 )
    return 0;
  v3 = BUF_MEM_new(a1);
  *v2 = v3;
  if ( !v3 )
  {
    CRYPTO_free(v2);
    return 0;
  }
  v2[1] = 0;
  lu->method_data = (char *)v2;
  return 1;
}
