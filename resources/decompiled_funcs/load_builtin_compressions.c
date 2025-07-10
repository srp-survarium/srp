void __usercall load_builtin_compressions(unsigned int a1@<edi>)
{
  char *v1; // esi
  comp_method_st *v2; // eax
  stack_st_SSL_COMP *v3; // ecx

  CRYPTO_lock(a1, 5, 16, ".\\ssl\\ssl_ciph.c", 420);
  if ( ssl_comp_methods )
  {
    CRYPTO_lock(a1, 6, 16, ".\\ssl\\ssl_ciph.c", 458);
  }
  else
  {
    CRYPTO_lock(a1, 6, 16, ".\\ssl\\ssl_ciph.c", 423);
    CRYPTO_lock(a1, 9, 16, ".\\ssl\\ssl_ciph.c", 424);
    if ( !ssl_comp_methods )
    {
      CRYPTO_mem_ctrl(a1, 3);
      ssl_comp_methods = (stack_st_SSL_COMP *)sk_new((int (__cdecl *)(const void *, const void *))sk_comp_cmp);
      if ( ssl_comp_methods )
      {
        v1 = (char *)CRYPTO_malloc(12, ".\\ssl\\ssl_ciph.c", 435);
        if ( v1 )
        {
          v2 = COMP_zlib();
          *((_DWORD *)v1 + 2) = v2;
          if ( !v2 || v2->type )
          {
            v3 = ssl_comp_methods;
            *(_DWORD *)v1 = 1;
            *((_DWORD *)v1 + 1) = v2->name;
            sk_push(&v3->stack, v1);
          }
          else
          {
            CRYPTO_free(v1);
          }
        }
        sk_sort(&ssl_comp_methods->stack);
      }
      CRYPTO_mem_ctrl(a1, 2);
    }
    CRYPTO_lock(a1, 10, 16, ".\\ssl\\ssl_ciph.c", 456);
  }
}
