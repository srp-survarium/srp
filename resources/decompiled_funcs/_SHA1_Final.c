int __cdecl SHA1_Final(unsigned __int8 *md, SHAstate_st *c)
{
  unsigned int num; // ebx
  unsigned int *data; // esi
  unsigned int v4; // ebx
  unsigned int h0; // ecx
  unsigned int h1; // ecx
  unsigned int h2; // ecx
  unsigned int h3; // ecx
  unsigned int h4; // ecx

  num = c->num;
  data = c->data;
  *((_BYTE *)c->data + num) = 0x80;
  v4 = num + 1;
  if ( v4 > 0x38 )
  {
    memset((int)data + v4, 0, 64 - v4);
    v4 = 0;
    sha1_block_data_order(c, data, 1);
  }
  memset((int)data + v4, 0, 56 - v4);
  LOBYTE(c->data[14]) = HIBYTE(c->Nh);
  BYTE1(c->data[14]) = BYTE2(c->Nh);
  BYTE2(c->data[14]) = BYTE1(c->Nh);
  HIBYTE(c->data[14]) = c->Nh;
  LOBYTE(c->data[15]) = HIBYTE(c->Nl);
  BYTE1(c->data[15]) = BYTE2(c->Nl);
  BYTE2(c->data[15]) = BYTE1(c->Nl);
  HIBYTE(c->data[15]) = c->Nl;
  sha1_block_data_order(c, c->data, 1);
  c->num = 0;
  memset((int)c->data, 0, sizeof(c->data));
  h0 = c->h0;
  *md = HIBYTE(c->h0);
  md[1] = BYTE2(h0);
  md[2] = BYTE1(h0);
  md[3] = h0;
  h1 = c->h1;
  md[4] = HIBYTE(h1);
  md[5] = BYTE2(h1);
  md[6] = BYTE1(h1);
  md[7] = h1;
  h2 = c->h2;
  md[8] = HIBYTE(h2);
  md[9] = BYTE2(h2);
  md[10] = BYTE1(h2);
  md[11] = h2;
  h3 = c->h3;
  md[12] = HIBYTE(h3);
  md[13] = BYTE2(h3);
  md[14] = BYTE1(h3);
  md[15] = h3;
  h4 = c->h4;
  md[16] = HIBYTE(h4);
  md[17] = BYTE2(h4);
  md[18] = BYTE1(h4);
  md[19] = h4;
  return 1;
}
