unsigned int __usercall bio_nwrite0@<eax>(bio_st *bio@<ebx>, char **buf)
{
  unsigned int result; // eax
  _DWORD *ptr; // esi
  bool v4; // zf
  unsigned int v5; // edx
  int v6; // edi
  unsigned int v7; // ecx

  BIO_clear_flags(bio, 15);
  if ( !bio->init )
    return 0;
  ptr = bio->ptr;
  v4 = ptr[1] == 0;
  ptr[6] = 0;
  if ( v4 )
  {
    v5 = ptr[4];
    v6 = ptr[2];
    if ( v6 == v5 )
    {
      BIO_set_flags(bio, 10);
      return -1;
    }
    else
    {
      v7 = v6 + ptr[3];
      result = v5 - v6;
      if ( v7 >= v5 )
        v7 -= v5;
      if ( v7 + result > v5 )
        result = v5 - v7;
      if ( buf )
        *buf = (char *)(v7 + ptr[5]);
    }
  }
  else
  {
    ERR_put_error((int)bio, 0x20u, 122, 124, ".\\crypto\\bio\\bss_bio.c", 450);
    return -1;
  }
  return result;
}
