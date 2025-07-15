void __usercall load_builtin_compressions(int a1@<edi>, int a2@<ebx>)
{
  char *v2; // esi
  comp_method_st *v3; // eax
  stack_st_SSL_COMP *v4; // ecx

  CRYPTO_lock(a1, a2, 5, 16, ".\\ssl\\ssl_ciph.c", 420);
  if ( ssl_comp_methods )
  {
    CRYPTO_lock(a1, a2, 6, 16, ".\\ssl\\ssl_ciph.c", 458);
  }
  else
  {
    CRYPTO_lock(a1, a2, 6, 16, ".\\ssl\\ssl_ciph.c", 423);
    CRYPTO_lock(a1, a2, 9, 16, ".\\ssl\\ssl_ciph.c", 424);
    if ( !ssl_comp_methods )
    {
      CRYPTO_mem_ctrl(a1, a2, 3);
      ssl_comp_methods = (stack_st_SSL_COMP *)sk_new((int (__cdecl *)(const void *, const void *))sk_comp_cmp);
      if ( ssl_comp_methods )
      {
        v2 = (char *)CRYPTO_malloc(12, ".\\ssl\\ssl_ciph.c", 435);
        if ( v2 )
        {
          v3 = COMP_zlib();
          *((_DWORD *)v2 + 2) = v3;
          if ( !v3 || v3->type )
          {
            v4 = ssl_comp_methods;
            *(_DWORD *)v2 = 1;
            *((_DWORD *)v2 + 1) = v3->name;
            sk_push(&v4->stack, v2);
          }
          else
          {
            CRYPTO_free(v2);
          }
        }
        sk_sort(a1, &ssl_comp_methods->stack);
      }
      CRYPTO_mem_ctrl(a1, a2, 2);
    }
    CRYPTO_lock(a1, a2, 10, 16, ".\\ssl\\ssl_ciph.c", 456);
  }
}
