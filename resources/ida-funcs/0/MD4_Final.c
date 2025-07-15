int __cdecl MD4_Final(unsigned __int8 *md, MD4state_st *c)
{
  unsigned int num; // ebx
  unsigned __int8 *data; // esi
  unsigned int v4; // ebx
  unsigned int A; // ecx

  num = c->num;
  data = (unsigned __int8 *)c->data;
  *((_BYTE *)c->data + num) = 0x80;
  v4 = num + 1;
  if ( v4 > 0x38 )
  {
    memset((int)&data[v4], 0, 64 - v4);
    v4 = 0;
    md4_block_data_order(c, data, 1u);
  }
  memset((int)&data[v4], 0, 56 - v4);
  c->data[14] = c->Nl;
  c->data[15] = c->Nh;
  md4_block_data_order(c, (unsigned __int8 *)c->data, 1u);
  c->num = 0;
  memset((int)c->data, 0, sizeof(c->data));
  A = c->A;
  *(_WORD *)md = c->A;
  md[2] = BYTE2(A);
  md[3] = HIBYTE(A);
  *((_DWORD *)md + 1) = c->B;
  *((_DWORD *)md + 2) = c->C;
  *((_DWORD *)md + 3) = c->D;
  return 1;
}
