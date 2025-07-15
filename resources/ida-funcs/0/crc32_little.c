int __usercall crc32_little@<eax>(unsigned int crc@<eax>, const unsigned __int8 *buf@<ecx>, unsigned int len@<edx>)
{
  unsigned int v3; // esi
  unsigned int i; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  const unsigned __int8 *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // eax

  v3 = len;
  for ( i = ~crc; v3; --v3 )
  {
    if ( ((unsigned __int8)buf & 3) == 0 )
      break;
    i = crc_table[0][(unsigned __int8)(i ^ *buf++)] ^ (i >> 8);
  }
  if ( v3 >= 0x20 )
  {
    v5 = v3 >> 5;
    do
    {
      v6 = *(_DWORD *)buf ^ i;
      v7 = buf + 8;
      v8 = *((_DWORD *)v7 - 1)
         ^ crc_table[3][(unsigned __int8)v6]
         ^ crc_table[0][HIBYTE(v6)]
         ^ crc_table[2][BYTE1(v6)]
         ^ crc_table[1][BYTE2(v6)];
      v7 += 8;
      v9 = *((_DWORD *)v7 - 2)
         ^ crc_table[3][(unsigned __int8)v8]
         ^ crc_table[0][HIBYTE(v8)]
         ^ crc_table[2][BYTE1(v8)]
         ^ crc_table[1][BYTE2(v8)];
      v7 += 8;
      v10 = *((_DWORD *)v7 - 3)
          ^ crc_table[3][(unsigned __int8)v9]
          ^ crc_table[0][HIBYTE(v9)]
          ^ crc_table[2][BYTE1(v9)]
          ^ crc_table[1][BYTE2(v9)];
      v11 = *((_DWORD *)v7 - 2)
          ^ crc_table[3][(unsigned __int8)v10]
          ^ crc_table[0][HIBYTE(v10)]
          ^ crc_table[2][BYTE1(v10)]
          ^ crc_table[1][BYTE2(v10)];
      v12 = *((_DWORD *)v7 - 1)
          ^ crc_table[3][(unsigned __int8)v11]
          ^ crc_table[0][HIBYTE(v11)]
          ^ crc_table[2][BYTE1(v11)]
          ^ crc_table[1][BYTE2(v11)];
      v7 += 4;
      v13 = *((_DWORD *)v7 - 1)
          ^ crc_table[3][(unsigned __int8)v12]
          ^ crc_table[0][HIBYTE(v12)]
          ^ crc_table[2][BYTE1(v12)]
          ^ crc_table[1][BYTE2(v12)];
      buf = v7 + 4;
      v3 -= 32;
      v14 = *((_DWORD *)buf - 1)
          ^ crc_table[3][(unsigned __int8)v13]
          ^ crc_table[0][HIBYTE(v13)]
          ^ crc_table[2][BYTE1(v13)]
          ^ crc_table[1][BYTE2(v13)];
      i = crc_table[3][(unsigned __int8)v14]
        ^ crc_table[0][HIBYTE(v14)]
        ^ crc_table[2][BYTE1(v14)]
        ^ crc_table[1][BYTE2(v14)];
      --v5;
    }
    while ( v5 );
  }
  if ( v3 >= 4 )
  {
    v15 = v3 >> 2;
    do
    {
      v16 = *(_DWORD *)buf ^ i;
      buf += 4;
      v3 -= 4;
      --v15;
      i = crc_table[3][(unsigned __int8)v16]
        ^ crc_table[0][HIBYTE(v16)]
        ^ crc_table[2][BYTE1(v16)]
        ^ crc_table[1][BYTE2(v16)];
    }
    while ( v15 );
  }
  for ( ; v3; --v3 )
    i = crc_table[0][(unsigned __int8)(i ^ *buf++)] ^ (i >> 8);
  return ~i;
}
