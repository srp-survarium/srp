engine_st *__cdecl ENGINE_get_cipher(const evp_cipher_st *e, int nid)
{
  int (__cdecl *set_asn1_parameters)(engine_st *, const evp_cipher_st **, const int **, int); // eax

  set_asn1_parameters = (int (__cdecl *)(engine_st *, const evp_cipher_st **, const int **, int))e->set_asn1_parameters;
  if ( set_asn1_parameters && set_asn1_parameters((engine_st *)e, &e, 0, nid) )
    return (engine_st *)e;
  ERR_put_error(0x26u, 185, 146, ".\\crypto\\engine\\tb_cipher.c", 126);
  return 0;
}
