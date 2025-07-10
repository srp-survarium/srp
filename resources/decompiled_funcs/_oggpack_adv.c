void __usercall oggpack_adv(oggpack_buffer *b@<ecx>, int bits@<eax>)
{
  int v2; // esi
  int storage; // eax
  int endbyte; // edi

  v2 = b->endbit + bits;
  storage = b->storage;
  endbyte = b->endbyte;
  if ( b->endbyte <= storage - ((v2 + 7) >> 3) )
  {
    b->ptr += v2 / 8;
    storage = endbyte + v2 / 8;
    b->endbit = v2 & 7;
  }
  else
  {
    b->ptr = 0;
    b->endbit = 1;
  }
  b->endbyte = storage;
}
