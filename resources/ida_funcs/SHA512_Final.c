int __cdecl SHA512_Final(unsigned __int8 *md, SHA512state_st *c)
{
  unsigned int num; // ebx
  $61765161EF95A25BF6D9F15268D2C4E6 *p_u; // edi
  unsigned int v4; // ebx
  unsigned __int8 *v5; // eax
  unsigned int md_len; // ecx
  unsigned __int64 *v8; // esi
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  _BYTE *v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  unsigned int v19; // edx
  unsigned int v20; // ecx
  unsigned int v21; // edx
  unsigned int v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // ecx
  unsigned int v25; // edx
  unsigned int v26; // ecx
  unsigned int v27; // edx
  unsigned int v28; // ecx
  int v29; // ecx
  int v30; // esi

  num = c->num;
  p_u = &c->u;
  c->u.p[num] = 0x80;
  v4 = num + 1;
  if ( v4 > 0x70 )
  {
    memset((int)p_u + v4, 0, 128 - v4);
    v4 = 0;
    sha512_block_data_order(c, p_u, 1);
  }
  memset((int)p_u + v4, 0, 112 - v4);
  c->u.p[127] = c->Nl;
  c->u.p[126] = BYTE1(c->Nl);
  c->u.p[125] = BYTE2(LODWORD(c->Nl));
  c->u.p[124] = HIBYTE(LODWORD(c->Nl));
  c->u.p[123] = HIDWORD(c->Nl);
  c->u.p[122] = BYTE1(HIDWORD(c->Nl));
  c->u.p[121] = BYTE6(c->Nl);
  c->u.p[120] = HIBYTE(c->Nl);
  c->u.p[119] = c->Nh;
  c->u.p[118] = BYTE1(c->Nh);
  c->u.p[117] = BYTE2(LODWORD(c->Nh));
  c->u.p[116] = HIBYTE(LODWORD(c->Nh));
  c->u.p[115] = HIDWORD(c->Nh);
  c->u.p[114] = BYTE1(HIDWORD(c->Nh));
  c->u.p[113] = BYTE6(c->Nh);
  c->u.p[112] = HIBYTE(c->Nh);
  sha512_block_data_order(c, p_u, 1);
  v5 = md;
  if ( !md )
    return 0;
  md_len = c->md_len;
  if ( md_len == 48 )
  {
    __SET_PAIR__(v20, v19, c->h[0]);
    *md = HIBYTE(c->h[0]);
    md[1] = BYTE2(v20);
    md[2] = BYTE1(v20);
    md[3] = v20;
    md[4] = HIBYTE(v19);
    md[5] = BYTE2(v19);
    md[6] = BYTE1(v19);
    md[7] = v19;
    __SET_PAIR__(v22, v21, c->h[1]);
    md[8] = HIBYTE(v22);
    md[9] = BYTE2(v22);
    md[10] = BYTE1(v22);
    md[11] = v22;
    md[12] = HIBYTE(v21);
    md[13] = BYTE2(v21);
    md[14] = BYTE1(v21);
    md[15] = v21;
    __SET_PAIR__(v24, v23, c->h[2]);
    md[16] = HIBYTE(v24);
    md[17] = BYTE2(v24);
    md[18] = BYTE1(v24);
    md[19] = v24;
    md[20] = HIBYTE(v23);
    md[21] = BYTE2(v23);
    md[22] = BYTE1(v23);
    md[23] = v23;
    __SET_PAIR__(v26, v25, c->h[3]);
    md[24] = HIBYTE(v26);
    md[25] = BYTE2(v26);
    md[26] = BYTE1(v26);
    md[27] = v26;
    md[28] = HIBYTE(v25);
    md[29] = BYTE2(v25);
    md[30] = BYTE1(v25);
    md[31] = v25;
    __SET_PAIR__(v28, v27, c->h[4]);
    md[32] = HIBYTE(v28);
    md[33] = BYTE2(v28);
    md[34] = BYTE1(v28);
    md[35] = v28;
    md[36] = HIBYTE(v27);
    md[37] = BYTE2(v27);
    md[38] = BYTE1(v27);
    md[39] = v27;
    v29 = c->h[5];
    v30 = HIDWORD(c->h[5]);
    md[40] = HIBYTE(v30);
    md[41] = BYTE2(v30);
    md[42] = BYTE1(v30);
    md[43] = v30;
    md[44] = HIBYTE(v29);
    md[45] = BYTE2(v29);
    md[46] = BYTE1(v29);
    md[47] = v29;
    return 1;
  }
  else
  {
    if ( md_len != 64 )
      return 0;
    v8 = &c->h[2];
    v9 = 2;
    do
    {
      v10 = *((_DWORD *)v8 - 3);
      v11 = *((_DWORD *)v8 - 4);
      v12 = v5 + 1;
      *(v12 - 1) = HIBYTE(v10);
      v12 += 2;
      *(v12 - 2) = BYTE2(v10);
      *(v12++ - 1) = BYTE1(v10);
      *(v12 - 1) = v10;
      *v12++ = HIBYTE(v11);
      *v12 = BYTE2(v11);
      v12 += 2;
      *(v12 - 1) = BYTE1(v11);
      *v12 = v11;
      v13 = *((_DWORD *)v8 - 2);
      ++v12;
      v14 = *((_DWORD *)v8 - 1);
      *v12++ = HIBYTE(v14);
      *v12++ = BYTE2(v14);
      *v12++ = BYTE1(v14);
      *v12++ = v14;
      *v12 = HIBYTE(v13);
      *++v12 = BYTE2(v13);
      v12[1] = BYTE1(v13);
      v12 += 2;
      *v12 = v13;
      v15 = *(_DWORD *)v8;
      v16 = *((_DWORD *)v8 + 1);
      *++v12 = HIBYTE(v16);
      *++v12 = BYTE2(v16);
      v12 += 2;
      *(v12++ - 1) = BYTE1(v16);
      *(v12 - 1) = v16;
      *v12++ = HIBYTE(v15);
      *v12 = BYTE2(v15);
      v12 += 2;
      *(v12 - 1) = BYTE1(v15);
      *v12 = v15;
      v17 = *((_DWORD *)v8 + 2);
      ++v12;
      v18 = *((_DWORD *)v8 + 3);
      *v12++ = HIBYTE(v18);
      *v12++ = BYTE2(v18);
      *v12++ = BYTE1(v18);
      *v12++ = v18;
      *v12++ = HIBYTE(v17);
      *v12++ = BYTE2(v17);
      *v12++ = BYTE1(v17);
      *v12 = v17;
      v5 = v12 + 1;
      v8 += 4;
      --v9;
    }
    while ( v9 );
    return 1;
  }
}
