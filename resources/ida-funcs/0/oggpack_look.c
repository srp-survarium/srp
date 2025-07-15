int __usercall oggpack_look@<eax>(oggpack_buffer *b@<ecx>, unsigned int bits@<eax>)
{
  int endbit; // edi
  int storage; // eax
  int v5; // esi
  unsigned __int8 *ptr; // edx
  int v8; // eax
  unsigned int v9; // [esp+Ch] [ebp-4h]

  if ( bits > 0x20 )
    return -1;
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
    return -1;
  }
LABEL_6:
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
  return v9 & v8;
}
