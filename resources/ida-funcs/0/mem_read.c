int __cdecl mem_read(bio_st *b, char *out, int outl)
{
  void *ptr; // esi
  int v4; // edi
  int num; // esi

  ptr = b->ptr;
  BIO_clear_flags(b, 15);
  if ( outl < 0 || (v4 = *(_DWORD *)ptr, (unsigned int)outl <= *(_DWORD *)ptr) )
    v4 = outl;
  if ( out && v4 > 0 )
  {
    memcpy((int)out, *((const __m128i **)ptr + 1), v4);
    *(_DWORD *)ptr -= v4;
    if ( (b->flags & 0x200) != 0 )
    {
      *((_DWORD *)ptr + 1) += v4;
      return v4;
    }
    memmove(*((_DWORD *)ptr + 1), (const __m128i *)(*((_DWORD *)ptr + 1) + v4), *(_DWORD *)ptr);
    return v4;
  }
  else
  {
    if ( *(_DWORD *)ptr )
      return v4;
    num = b->num;
    if ( num )
      BIO_set_flags(b, 9);
    return num;
  }
}
