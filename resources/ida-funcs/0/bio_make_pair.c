int __cdecl bio_make_pair(bio_st *bio1, bio_st *bio2)
{
  _DWORD *ptr; // esi
  _DWORD *v3; // edi
  void *v4; // eax
  int result; // eax
  void *v6; // eax

  ptr = bio1->ptr;
  v3 = bio2->ptr;
  if ( *ptr || *v3 )
  {
    ERR_put_error(0, 0x20u, 121, 123, ".\\crypto\\bio\\bss_bio.c", 716);
    return 0;
  }
  else
  {
    if ( !ptr[5] )
    {
      v4 = CRYPTO_malloc(ptr[4], ".\\crypto\\bio\\bss_bio.c", 722);
      ptr[5] = v4;
      if ( !v4 )
      {
        ERR_put_error(0, 0x20u, 121, 65, ".\\crypto\\bio\\bss_bio.c", 725);
        return 0;
      }
      ptr[2] = 0;
      ptr[3] = 0;
    }
    if ( !v3[5] )
    {
      v6 = CRYPTO_malloc(v3[4], ".\\crypto\\bio\\bss_bio.c", 734);
      v3[5] = v6;
      if ( !v6 )
      {
        ERR_put_error(0, 0x20u, 121, 65, ".\\crypto\\bio\\bss_bio.c", 737);
        return 0;
      }
      v3[2] = 0;
      v3[3] = 0;
    }
    *ptr = bio2;
    ptr[1] = 0;
    ptr[6] = 0;
    v3[1] = 0;
    v3[6] = 0;
    *v3 = bio1;
    result = 1;
    bio1->init = 1;
    bio2->init = 1;
  }
  return result;
}
