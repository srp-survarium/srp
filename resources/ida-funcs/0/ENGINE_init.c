int __usercall ENGINE_init@<eax>(int a1@<edi>, int a2@<ebx>, engine_st *e)
{
  int v4; // edi
  int (__cdecl *init)(engine_st *); // eax

  if ( e )
  {
    CRYPTO_lock(a1, a2, 9, 30, ".\\crypto\\engine\\eng_init.c", 129);
    v4 = 1;
    if ( e->funct_ref || (init = e->init) == 0 || (v4 = init(e)) != 0 )
    {
      ++e->struct_ref;
      ++e->funct_ref;
    }
    CRYPTO_lock(v4, a2, 10, 30, ".\\crypto\\engine\\eng_init.c", 131);
    return v4;
  }
  else
  {
    ERR_put_error(a2, 0x26u, 119, 67, ".\\crypto\\engine\\eng_init.c", 126);
    return 0;
  }
}
