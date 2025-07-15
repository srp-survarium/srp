void __cdecl x509_name_ex_free(struct ASN1_VALUE_st **pval)
{
  int v1; // esi

  if ( pval )
  {
    v1 = (int)*pval;
    if ( *pval )
    {
      BUF_MEM_free(*(buf_mem_st **)(v1 + 8));
      sk_pop_free(*(stack_st **)v1, (void (__cdecl *)(void *))X509_NAME_ENTRY_free);
      if ( *(_DWORD *)(v1 + 12) )
        CRYPTO_free(*(void **)(v1 + 12));
      CRYPTO_free((void *)v1);
      *pval = 0;
    }
  }
}
