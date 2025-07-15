int __cdecl SHA_Update(SHAstate_st *c, const __m128i *data_, unsigned int len)
{
  unsigned int v3; // edi
  __m128i *v4; // ebp
  unsigned int Nl; // eax
  unsigned int v6; // ecx
  unsigned int num; // eax
  unsigned int *data; // ebp
  unsigned int v10; // ebx
  unsigned int v11; // ebx

  v3 = len;
  v4 = (__m128i *)data_;
  if ( len )
  {
    Nl = c->Nl;
    v6 = Nl + 8 * len;
    if ( v6 < Nl )
      ++c->Nh;
    c->Nh += len >> 29;
    num = c->num;
    c->Nl = v6;
    if ( num )
    {
      data = c->data;
      if ( len < 0x40 && num + len < 0x40 )
      {
        memcpy((int)data + num, data_, len);
        c->num += len;
        return 1;
      }
      v10 = 64 - num;
      memcpy((int)data + num, data_, 64 - num);
      sha_block_data_order(c, (unsigned __int8 *)c->data, 1u);
      v3 = len - v10;
      c->num = 0;
      memset((int)c->data, 0, sizeof(c->data));
      v4 = (__m128i *)((char *)data_ + v10);
    }
    if ( v3 >> 6 )
    {
      sha_block_data_order(c, (unsigned __int8 *)v4, v3 >> 6);
      v11 = v3 >> 6 << 6;
      v4 = (__m128i *)((char *)v4 + v11);
      v3 -= v11;
    }
    if ( v3 )
    {
      c->num = v3;
      memcpy((int)c->data, v4, v3);
    }
  }
  return 1;
}
