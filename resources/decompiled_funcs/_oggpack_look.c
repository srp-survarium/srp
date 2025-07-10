unsigned int __fastcall oggpack_look(oggpack_buffer *b, unsigned int bits)
{
  int storage; // eax
  unsigned int v3; // ebx
  int endbit; // esi
  int v5; // edx
  unsigned __int8 *ptr; // edi
  int v8; // eax

  if ( bits > 0x20 )
    return -1;
  storage = b->storage;
  v3 = mask_1[bits];
  endbit = b->endbit;
  v5 = endbit + bits;
  if ( b->endbyte < storage - 4 )
    goto LABEL_7;
  if ( b->endbyte > storage - ((v5 + 7) >> 3) )
    return -1;
  if ( !v5 )
    return 0;
LABEL_7:
  ptr = b->ptr;
  v8 = *ptr >> LOBYTE(b->endbit);
  if ( v5 > 8 )
  {
    v8 |= ptr[1] << (8 - endbit);
    if ( v5 > 16 )
    {
      v8 |= ptr[2] << (16 - endbit);
      if ( v5 > 24 )
      {
        v8 |= ptr[3] << (24 - endbit);
        if ( v5 > 32 )
        {
          if ( endbit )
            v8 |= ptr[4] << (32 - endbit);
        }
      }
    }
  }
  return v3 & v8;
}
