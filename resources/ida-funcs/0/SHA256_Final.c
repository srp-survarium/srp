int __cdecl SHA256_Final(unsigned __int8 *md, SHA256state_st *c)
{
  unsigned int num; // ebx
  unsigned int *data; // edi
  unsigned int v4; // ebx
  unsigned int md_len; // eax
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned int v9; // ecx
  _BYTE *v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // ecx
  unsigned __int8 *v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // ecx
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  _BYTE *v26; // eax

  num = c->num;
  data = c->data;
  *((_BYTE *)c->data + num) = 0x80;
  v4 = num + 1;
  if ( v4 > 0x38 )
  {
    memset((int)data + v4, 0, 64 - v4);
    v4 = 0;
    sha256_block_data_order(c, data, 1);
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
  sha256_block_data_order(c, c->data, 1);
  c->num = 0;
  memset((int)c->data, 0, sizeof(c->data));
  md_len = c->md_len;
  if ( md_len == 28 )
  {
    v20 = c->h[0];
    *md = HIBYTE(c->h[0]);
    md[1] = BYTE2(v20);
    md[2] = BYTE1(v20);
    md[3] = v20;
    v21 = c->h[1];
    md[4] = HIBYTE(v21);
    md[5] = BYTE2(v21);
    md[6] = BYTE1(v21);
    md[7] = v21;
    v22 = c->h[2];
    md[8] = HIBYTE(v22);
    md[9] = BYTE2(v22);
    md[10] = BYTE1(v22);
    md[11] = v22;
    v23 = c->h[3];
    md[12] = HIBYTE(v23);
    md[13] = BYTE2(v23);
    md[14] = BYTE1(v23);
    md[15] = v23;
    v24 = c->h[4];
    md[16] = HIBYTE(v24);
    md[17] = BYTE2(v24);
    md[18] = BYTE1(v24);
    md[19] = v24;
    v25 = c->h[5];
    md[20] = HIBYTE(v25);
    md[21] = BYTE2(v25);
    md[22] = BYTE1(v25);
    v18 = md + 23;
    md[23] = v25;
    v19 = c->h[6];
    goto LABEL_13;
  }
  if ( md_len == 32 )
  {
    v11 = c->h[0];
    *md = HIBYTE(c->h[0]);
    md[1] = BYTE2(v11);
    md[2] = BYTE1(v11);
    md[3] = v11;
    v12 = c->h[1];
    md[4] = HIBYTE(v12);
    md[5] = BYTE2(v12);
    md[6] = BYTE1(v12);
    md[7] = v12;
    v13 = c->h[2];
    md[8] = HIBYTE(v13);
    md[9] = BYTE2(v13);
    md[10] = BYTE1(v13);
    md[11] = v13;
    v14 = c->h[3];
    md[12] = HIBYTE(v14);
    md[13] = BYTE2(v14);
    md[14] = BYTE1(v14);
    md[15] = v14;
    v15 = c->h[4];
    md[16] = HIBYTE(v15);
    md[17] = BYTE2(v15);
    md[18] = BYTE1(v15);
    md[19] = v15;
    v16 = c->h[5];
    md[20] = HIBYTE(v16);
    md[21] = BYTE2(v16);
    md[22] = BYTE1(v16);
    md[23] = v16;
    v17 = c->h[6];
    md[24] = HIBYTE(v17);
    md[25] = BYTE2(v17);
    md[26] = BYTE1(v17);
    v18 = md + 27;
    md[27] = v17;
    v19 = c->h[7];
LABEL_13:
    v26 = v18 + 1;
    *v26++ = HIBYTE(v19);
    *v26++ = BYTE2(v19);
    *v26 = BYTE1(v19);
    v26[1] = v19;
    return 1;
  }
  if ( md_len > 0x20 )
    return 0;
  v7 = 0;
  if ( (md_len & 0xFFFFFFFC) == 0 )
    return 1;
  v8 = md;
  do
  {
    v9 = c->h[v7];
    *v8 = HIBYTE(v9);
    v10 = v8 + 1;
    *v10++ = BYTE2(v9);
    *v10++ = BYTE1(v9);
    *v10 = v9;
    ++v7;
    v8 = v10 + 1;
  }
  while ( v7 < c->md_len >> 2 );
  return 1;
}
