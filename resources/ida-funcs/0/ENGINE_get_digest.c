engine_st *__usercall ENGINE_get_digest@<eax>(int a1@<ebx>, engine_st *e, int nid)
{
  int (__cdecl *digests)(engine_st *, const env_md_st **, const int **, int); // eax

  digests = e->digests;
  if ( digests && digests(e, (const env_md_st **)&e, 0, nid) )
    return e;
  ERR_put_error(a1, 0x26u, 186, 147, ".\\crypto\\engine\\tb_digest.c", 126);
  return 0;
}
