engine_st *__cdecl ENGINE_get_pkey_asn1_meth(evp_pkey_asn1_method_st *e, int nid)
{
  int (__cdecl *pkey_size)(engine_st *, evp_pkey_asn1_method_st **, const int **, int); // eax

  pkey_size = (int (__cdecl *)(engine_st *, evp_pkey_asn1_method_st **, const int **, int))e->pkey_size;
  if ( pkey_size && pkey_size((engine_st *)e, &e, 0, nid) )
    return (engine_st *)e;
  ERR_put_error(0x26u, 193, 101, ".\\crypto\\engine\\tb_asnmth.c", 129);
  return 0;
}
