unsigned int __usercall ENGINE_init@<eax>(unsigned int a1@<edi>, engine_st *e)
{
  unsigned int v3; // edi
  int (__cdecl *init)(engine_st *); // eax

  if ( e )
  {
    CRYPTO_lock(a1, 9, 30, ".\\crypto\\engine\\eng_init.c", 129);
    v3 = 1;
    if ( e->funct_ref || (init = e->init) == 0 || (v3 = init(e)) != 0 )
    {
      ++e->struct_ref;
      ++e->funct_ref;
    }
    CRYPTO_lock(v3, 10, 30, ".\\crypto\\engine\\eng_init.c", 131);
    return v3;
  }
  else
  {
    ERR_put_error(0x26u, 119, 67, ".\\crypto\\engine\\eng_init.c", 126);
    return 0;
  }
}
