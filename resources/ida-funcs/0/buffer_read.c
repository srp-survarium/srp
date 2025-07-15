int __cdecl buffer_read(bio_st *b, char *out, int outl)
{
  int result; // eax
  void *ptr; // esi
  signed int v6; // edi
  int v7; // edi
  int v8; // esi
  int v9; // [esp+0h] [ebp-4h]

  if ( !out )
    return 0;
  ptr = b->ptr;
  if ( !ptr || !b->next_bio )
    return 0;
  v9 = 0;
  BIO_clear_flags(b, 15);
  while ( 1 )
  {
    v6 = *((_DWORD *)ptr + 3);
    if ( v6 )
    {
      if ( v6 > outl )
        v6 = outl;
      memcpy((int)out, (const __m128i *)(*((_DWORD *)ptr + 4) + *((_DWORD *)ptr + 2)), v6);
      *((_DWORD *)ptr + 4) += v6;
      *((_DWORD *)ptr + 3) -= v6;
      v9 += v6;
      if ( outl == v6 )
        return v9;
      outl -= v6;
      out += v6;
    }
    if ( outl > *(_DWORD *)ptr )
    {
      while ( 1 )
      {
        v8 = BIO_read(outl, b->next_bio, out, outl);
        if ( v8 <= 0 )
          break;
        v9 += v8;
        if ( outl == v8 )
          return v9;
        out += v8;
        outl -= v8;
      }
      BIO_copy_next_retry(b);
      if ( v8 >= 0 )
        return v9;
      result = v9;
      if ( v9 <= 0 )
        return v8;
      return result;
    }
    v7 = BIO_read(outl, b->next_bio, *((char **)ptr + 2), *(_DWORD *)ptr);
    if ( v7 <= 0 )
      break;
    *((_DWORD *)ptr + 4) = 0;
    *((_DWORD *)ptr + 3) = v7;
  }
  BIO_copy_next_retry(b);
  if ( v7 >= 0 )
    return v9;
  result = v9;
  if ( v9 <= 0 )
    return v7;
  return result;
}
