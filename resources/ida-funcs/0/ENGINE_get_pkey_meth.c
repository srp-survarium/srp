engine_st *__usercall ENGINE_get_pkey_meth@<eax>(int a1@<ebx>, engine_st *e, int nid)
{
  int (__cdecl *pkey_meths)(engine_st *, evp_pkey_method_st **, const int **, int); // eax

  pkey_meths = e->pkey_meths;
  if ( pkey_meths && pkey_meths(e, (evp_pkey_method_st **)&e, 0, nid) )
    return e;
  ERR_put_error(a1, 0x26u, 192, 101, ".\\crypto\\engine\\tb_pkmeth.c", 127);
  return 0;
}
