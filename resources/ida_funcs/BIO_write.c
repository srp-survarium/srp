unsigned int __cdecl bio_write(bio_st *bio, char *buf, unsigned int num_)
{
  unsigned __int8 *v3; // ebp
  _DWORD *ptr; // edi
  bool v5; // zf
  int v7; // ecx
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // esi

  BIO_clear_flags(bio, 15);
  if ( !bio->init )
    return 0;
  v3 = (unsigned __int8 *)buf;
  if ( !buf || !num_ )
    return 0;
  ptr = bio->ptr;
  v5 = ptr[1] == 0;
  ptr[6] = 0;
  if ( v5 )
  {
    v7 = ptr[2];
    v8 = ptr[4];
    if ( v7 == v8 )
    {
      BIO_set_flags(bio, 10);
      return -1;
    }
    else
    {
      v9 = v8 - v7;
      if ( num_ > v9 )
        num_ = v9;
      v10 = num_;
      do
      {
        v11 = ptr[2] + ptr[3];
        v12 = ptr[4];
        if ( v11 >= v12 )
          v11 -= v12;
        if ( v11 + v10 > v12 )
          v13 = v12 - v11;
        else
          v13 = v10;
        memcpy((unsigned __int8 *)(v11 + ptr[5]), v3, v13);
        ptr[2] += v13;
        v10 -= v13;
        v3 += v13;
      }
      while ( v10 );
      return num_;
    }
  }
  else
  {
    ERR_put_error(0x20u, 113, 124, ".\\crypto\\bio\\bss_bio.c", 372);
    return -1;
  }
}
