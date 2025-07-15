int __cdecl SHA512_Update(SHA512state_st *c, unsigned __int8 *_data, unsigned int len)
{
  unsigned int v3; // edi
  $61765161EF95A25BF6D9F15268D2C4E6 *p_u; // ebp
  unsigned int Nl_high; // ecx
  unsigned int Nl; // ebx
  unsigned __int64 v7; // rax
  unsigned int v8; // ebx
  unsigned __int8 *v9; // eax
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ebx

  v3 = len;
  p_u = &c->u;
  if ( len )
  {
    Nl_high = HIDWORD(c->Nl);
    Nl = c->Nl;
    v7 = __PAIR64__(Nl_high, Nl) + 8LL * len;
    if ( v7 < __PAIR64__(Nl_high, Nl) )
      ++c->Nh;
    LODWORD(c->Nl) = v7;
    LODWORD(v7) = c->num;
    HIDWORD(c->Nl) = HIDWORD(v7);
    if ( (_DWORD)v7 )
    {
      v8 = 128 - v7;
      v9 = (unsigned __int8 *)p_u + v7;
      if ( len < v8 )
      {
        memcpy(v9, _data, len);
        c->num += len;
        return 1;
      }
      memcpy(v9, _data, v8);
      v3 = len - v8;
      c->num = 0;
      v11 = &_data[v8];
      sha512_block_data_order(c, p_u, 1);
    }
    else
    {
      v11 = _data;
    }
    if ( v3 >= 0x80 )
    {
      sha512_block_data_order(c, v11, v3 >> 7);
      v12 = &v11[v3];
      v3 &= 0x7Fu;
      v11 = &v12[-v3];
    }
    if ( v3 )
    {
      memcpy((unsigned __int8 *)p_u, v11, v3);
      c->num = v3;
    }
  }
  return 1;
}
