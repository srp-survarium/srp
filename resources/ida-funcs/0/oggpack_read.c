int __usercall oggpack_read@<eax>(oggpack_buffer *b@<esi>, unsigned int bits@<eax>)
{
  int endbit; // edx
  int storage; // eax
  int v5; // edi
  int result; // eax
  unsigned __int8 *ptr; // ebx
  int v8; // eax
  unsigned int v9; // [esp+8h] [ebp-8h]
  int v10; // [esp+Ch] [ebp-4h]

  if ( bits > 0x20 )
    goto err_0;
  endbit = b->endbit;
  v9 = mask_1[bits];
  storage = b->storage;
  v5 = endbit + bits;
  if ( b->endbyte >= storage - 4 )
  {
    if ( b->endbyte <= storage - ((v5 + 7) >> 3) )
    {
      if ( !v5 )
        return 0;
      goto LABEL_6;
    }
err_0:
    v8 = b->storage;
    b->ptr = 0;
    b->endbyte = v8;
    b->endbit = 1;
    return -1;
  }
LABEL_6:
  ptr = b->ptr;
  v10 = *ptr >> endbit;
  if ( v5 > 8 )
  {
    v10 |= ptr[1] << (8 - endbit);
    if ( v5 > 16 )
    {
      v10 |= ptr[2] << (16 - endbit);
      if ( v5 > 24 )
      {
        v10 |= ptr[3] << (24 - endbit);
        if ( v5 > 32 )
        {
          if ( endbit )
            v10 |= ptr[4] << (32 - endbit);
        }
      }
    }
  }
  b->ptr = &ptr[v5 / 8];
  b->endbyte += v5 / 8;
  result = v9 & v10;
  b->endbit = v5 & 7;
  return result;
}
