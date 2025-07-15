unsigned int __usercall oggpack_read@<eax>(oggpack_buffer *b@<edi>, unsigned int bits@<eax>)
{
  int storage; // ecx
  int endbit; // eax
  int v5; // esi
  unsigned __int8 *ptr; // ebp
  int v8; // ebx
  int v9; // edx
  unsigned int m; // [esp+8h] [ebp-4h]

  if ( bits > 0x20 )
    goto err_253;
  storage = b->storage;
  m = mask_1[bits];
  endbit = b->endbit;
  v5 = endbit + bits;
  if ( b->endbyte >= storage - 4 )
  {
    if ( b->endbyte <= storage - ((v5 + 7) >> 3) )
    {
      if ( !v5 )
        return 0;
      goto LABEL_6;
    }
err_253:
    v9 = b->storage;
    b->ptr = 0;
    b->endbyte = v9;
    b->endbit = 1;
    return -1;
  }
LABEL_6:
  ptr = b->ptr;
  v8 = *ptr >> endbit;
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
  b->ptr = &ptr[v5 / 8];
  b->endbyte += v5 / 8;
  b->endbit = v5 & 7;
  return m & v8;
}
