void __cdecl oggpack_write(oggpack_buffer *b, unsigned int value, unsigned int bits)
{
  vostok::memory::doug_lea_mt_allocator *v3; // ecx
  int storage; // eax
  unsigned __int8 *v5; // eax
  int endbyte; // ecx
  unsigned int v7; // eax
  int endbit; // ecx
  int v9; // edi
  int v10; // edx
  unsigned __int8 *buffer; // edi
  vostok::memory *v12; // [esp+0h] [ebp-8h]

  if ( bits <= 0x20 )
  {
    storage = b->storage;
    v3 = (vostok::memory::doug_lea_mt_allocator *)(storage - 4);
    if ( b->endbyte < storage - 4 )
      goto LABEL_7;
    if ( !b->ptr )
      return;
    if ( storage <= 2147483391 )
    {
      v5 = (unsigned __int8 *)realloc(b->buffer, storage + 256);
      if ( v5 )
      {
        endbyte = b->endbyte;
        b->storage += 256;
        b->buffer = v5;
        b->ptr = &v5[endbyte];
LABEL_7:
        v7 = mask_1[bits] & value;
        endbit = b->endbit;
        v9 = endbit + bits;
        *b->ptr |= (_BYTE)v7 << endbit;
        if ( (int)(endbit + bits) >= 8 )
        {
          b->ptr[1] = v7 >> (8 - LOBYTE(b->endbit));
          if ( v9 >= 16 )
          {
            b->ptr[2] = v7 >> (16 - LOBYTE(b->endbit));
            if ( v9 >= 24 )
            {
              b->ptr[3] = v7 >> (24 - LOBYTE(b->endbit));
              if ( v9 >= 32 )
              {
                v10 = b->endbit;
                if ( v10 )
                  b->ptr[4] = v7 >> (32 - v10);
                else
                  b->ptr[4] = 0;
              }
            }
          }
        }
        b->endbyte += v9 / 8;
        b->ptr += v9 / 8;
        b->endbit = v9 & 7;
        return;
      }
    }
  }
  buffer = b->buffer;
  if ( buffer )
  {
    if ( !vostok::memory::g_crt_allocator.__vftable )
      vostok::memory::initialize_crt_allocator(v12);
    vostok::memory::doug_lea_mt_allocator::free_impl(v3, buffer);
  }
  *(_QWORD *)&b->endbyte = 0;
  *(_QWORD *)&b->buffer = 0;
  b->storage = 0;
}
