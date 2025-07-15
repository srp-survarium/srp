int __usercall engine_free_util@<eax>(unsigned int a1@<edi>, engine_st *e, int locked)
{
  int v4; // eax
  int (__cdecl *destroy)(engine_st *); // eax

  if ( e )
  {
    if ( locked )
      v4 = CRYPTO_add_lock(&e->struct_ref, -1, 30, ".\\crypto\\engine\\eng_lib.c", 116);
    else
      v4 = --e->struct_ref;
    if ( v4 <= 0 )
    {
      engine_pkey_meths_free(e);
      engine_pkey_asn1_meths_free(e);
      destroy = e->destroy;
      if ( destroy )
        destroy(e);
      CRYPTO_free_ex_data(a1);
      CRYPTO_free(e);
    }
    return 1;
  }
  else
  {
    ERR_put_error(0x26u, 108, 67, ".\\crypto\\engine\\eng_lib.c", 112);
    return 0;
  }
}
