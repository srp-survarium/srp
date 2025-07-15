void __cdecl free_dir(x509_lookup_st *lu)
{
  char *method_data; // esi
  stack_st *v2; // eax

  method_data = lu->method_data;
  v2 = (stack_st *)*((_DWORD *)method_data + 1);
  if ( v2 )
    sk_pop_free(v2, (void (__cdecl *)(void *))by_dir_entry_free);
  if ( *(_DWORD *)method_data )
    BUF_MEM_free(*(buf_mem_st **)method_data);
  CRYPTO_free(method_data);
}
