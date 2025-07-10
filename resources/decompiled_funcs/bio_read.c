unsigned int __cdecl bio_read(bio_st *bio, char *buf, unsigned int size_)
{
  unsigned __int8 *v4; // ebp
  _DWORD *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // ebx
  int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // edi
  bool v12; // zf

  BIO_clear_flags(bio, 15);
  if ( !bio->init )
    return 0;
  v4 = (unsigned __int8 *)buf;
  v5 = *(_DWORD **)(*(_DWORD *)bio->ptr + 32);
  v5[6] = 0;
  if ( !buf || !size_ )
    return 0;
  v6 = v5[2];
  if ( !v6 )
  {
    if ( !v5[1] )
    {
      BIO_set_flags(bio, 9);
      v7 = v5[4];
      if ( size_ > v7 )
        v5[6] = v7;
      else
        v5[6] = size_;
      return -1;
    }
    return 0;
  }
  if ( v6 < size_ )
    size_ = v5[2];
  v8 = size_;
  do
  {
    v9 = v5[3];
    v10 = v5[4];
    if ( v9 + v8 > v10 )
      v11 = v10 - v9;
    else
      v11 = v8;
    memcpy(v4, (unsigned __int8 *)(v9 + v5[5]), v11);
    v12 = v5[2] == v11;
    v5[2] -= v11;
    if ( v12 )
    {
      v5[3] = 0;
    }
    else
    {
      v5[3] += v11;
      if ( v5[3] == v5[4] )
        v5[3] = 0;
      v4 += v11;
    }
    v8 -= v11;
  }
  while ( v8 );
  return size_;
}
