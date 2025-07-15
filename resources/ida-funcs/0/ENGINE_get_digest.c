engine_st *__cdecl ENGINE_get_digest(const env_md_st *e, int nid)
{
  int (__cdecl *verify)(engine_st *, const env_md_st **, const int **, int); // eax

  verify = (int (__cdecl *)(engine_st *, const env_md_st **, const int **, int))e->verify;
  if ( verify && verify((engine_st *)e, &e, 0, nid) )
    return (engine_st *)e;
  ERR_put_error(0x26u, 186, 147, ".\\crypto\\engine\\tb_digest.c", 126);
  return 0;
}
