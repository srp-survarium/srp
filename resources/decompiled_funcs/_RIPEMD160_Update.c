int __cdecl RIPEMD160_Update(RIPEMD160state_st *c, unsigned __int8 *data_, unsigned int len)
{
  unsigned int v3; // edi
  unsigned __int8 *v4; // ebp
  unsigned int Nl; // eax
  unsigned int v6; // ecx
  unsigned int num; // eax
  unsigned int *data; // ebp
  unsigned int v10; // ebx
  unsigned int v11; // ebx

  v3 = len;
  v4 = data_;
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
        memcpy((unsigned __int8 *)data + num, data_, len);
        c->num += len;
        return 1;
      }
      v10 = 64 - num;
      memcpy((unsigned __int8 *)data + num, data_, 64 - num);
      ripemd160_block_asm_data_order(c, c->data, 1);
      v3 = len - v10;
      c->num = 0;
      memset((int)c->data, 0, sizeof(c->data));
      v4 = &data_[v10];
    }
    if ( v3 >> 6 )
    {
      ripemd160_block_asm_data_order(c, v4, v3 >> 6);
      v11 = v3 >> 6 << 6;
      v4 += v11;
      v3 -= v11;
    }
    if ( v3 )
    {
      c->num = v3;
      memcpy((unsigned __int8 *)c->data, v4, v3);
    }
  }
  return 1;
}
