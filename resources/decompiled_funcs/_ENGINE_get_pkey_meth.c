engine_st *__cdecl ENGINE_get_pkey_meth(evp_pkey_method_st *e, int nid)
{
  int (__cdecl *verify_init)(engine_st *, evp_pkey_method_st **, const int **, int); // eax

  verify_init = (int (__cdecl *)(engine_st *, evp_pkey_method_st **, const int **, int))e->verify_init;
  if ( verify_init && verify_init((engine_st *)e, &e, 0, nid) )
    return (engine_st *)e;
  ERR_put_error(0x26u, 192, 101, ".\\crypto\\engine\\tb_pkmeth.c", 127);
  return 0;
}
