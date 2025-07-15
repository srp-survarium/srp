engine_st *__usercall ENGINE_get_pkey_asn1_meth@<eax>(int a1@<ebx>, engine_st *e, int nid)
{
  int (__cdecl *pkey_asn1_meths)(engine_st *, evp_pkey_asn1_method_st **, const int **, int); // eax

  pkey_asn1_meths = e->pkey_asn1_meths;
  if ( pkey_asn1_meths && pkey_asn1_meths(e, (evp_pkey_asn1_method_st **)&e, 0, nid) )
    return e;
  ERR_put_error(a1, 0x26u, 193, 101, ".\\crypto\\engine\\tb_asnmth.c", 129);
  return 0;
}
