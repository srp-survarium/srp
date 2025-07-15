void __cdecl oggpack_write(oggpack_buffer *b, unsigned int value, unsigned int bits)
{
  int storage; // eax
  unsigned __int8 *v4; // eax
  int endbyte; // ecx
  unsigned int v6; // eax
  int endbit; // ecx
  int v8; // edi
  int v9; // edx

  if ( bits > 0x20 )
    goto err;
  storage = b->storage;
  if ( b->endbyte < storage - 4 )
    goto LABEL_7;
  if ( !b->ptr )
    return;
  if ( storage > 2147483391 || (v4 = (unsigned __int8 *)ogg_realloc_impl(b->buffer, storage + 256)) == 0 )
  {
err:
    oggpack_writeclear(b);
    return;
  }
  endbyte = b->endbyte;
  b->storage += 256;
  b->buffer = v4;
  b->ptr = &v4[endbyte];
LABEL_7:
  v6 = mask_1[bits] & value;
  endbit = b->endbit;
  v8 = endbit + bits;
  *b->ptr |= (_BYTE)v6 << endbit;
  if ( (int)(endbit + bits) >= 8 )
  {
    b->ptr[1] = v6 >> (8 - LOBYTE(b->endbit));
    if ( v8 >= 16 )
    {
      b->ptr[2] = v6 >> (16 - LOBYTE(b->endbit));
      if ( v8 >= 24 )
      {
        b->ptr[3] = v6 >> (24 - LOBYTE(b->endbit));
        if ( v8 >= 32 )
        {
          v9 = b->endbit;
          if ( v9 )
            b->ptr[4] = v6 >> (32 - v9);
          else
            b->ptr[4] = 0;
        }
      }
    }
  }
  b->endbyte += v8 / 8;
  b->ptr += v8 / 8;
  b->endbit = v8 & 7;
}
