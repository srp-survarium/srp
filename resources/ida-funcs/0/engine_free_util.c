int __usercall engine_free_util@<eax>(int a1@<edi>, int a2@<ebx>, engine_st *e, int locked)
{
  int v5; // eax
  int (__cdecl *destroy)(engine_st *); // eax

  if ( e )
  {
    if ( locked )
      v5 = CRYPTO_add_lock(&e->struct_ref, -1, 30, ".\\crypto\\engine\\eng_lib.c", 116);
    else
      v5 = --e->struct_ref;
    if ( v5 <= 0 )
    {
      engine_pkey_meths_free(e);
      engine_pkey_asn1_meths_free(e);
      destroy = e->destroy;
      if ( destroy )
        destroy(e);
      CRYPTO_free_ex_data(a1, a2);
      CRYPTO_free(e);
    }
    return 1;
  }
  else
  {
    ERR_put_error(a2, 0x26u, 108, 67, ".\\crypto\\engine\\eng_lib.c", 112);
    return 0;
  }
}
