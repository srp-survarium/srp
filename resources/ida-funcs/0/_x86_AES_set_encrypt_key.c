int __cdecl _x86_AES_set_encrypt_key(int a1, int *a2, int a3, int *a4)
{
  int *v4; // edi
  char *v5; // ebp
  int v7; // eax
  int v8; // ebx
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // ebx
  int v17; // ecx
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ebx
  int v27; // ecx
  int v28; // edx
  int v29; // ebx
  int v30; // ecx
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  int v38; // eax
  int v39; // eax

  v4 = a4;
  if ( !a2 || !a4 )
    return -1;
  v5 = (char *)&loc_7C79F9 + (_DWORD)&_LAES_Te[-2038879] + 3;
  switch ( a3 )
  {
    case 128:
      v7 = *a2;
      v8 = a2[1];
      v9 = a2[2];
      v10 = a2[3];
      *a4 = *a2;
      a4[1] = v8;
      a4[2] = v9;
      a4[3] = v10;
      v11 = 0;
      while ( 1 )
      {
        v12 = *(_DWORD *)&v5[4 * v11 + (_DWORD)&loc_7C74F8 - 8155512]
            ^ ((unsigned __int8)v5[HIBYTE(v10) - 128] << 16)
            ^ ((unsigned __int8)v5[BYTE2(v10) - 128] << 8)
            ^ (unsigned __int8)v5[BYTE1(v10) - 128]
            ^ ((unsigned __int8)v5[(unsigned __int8)v10 - 128] << 24)
            ^ v7;
        v4[4] = v12;
        v13 = v4[1] ^ v12;
        v4[5] = v13;
        v14 = v4[2] ^ v13;
        v4[6] = v14;
        v4[7] = v4[3] ^ v14;
        ++v11;
        v4 += 4;
        if ( v11 >= 10 )
          break;
        v7 = *v4;
        v10 = v4[3];
      }
      v4[20] = 10;
      return 0;
    case 192:
      v15 = *a2;
      v16 = a2[1];
      v17 = a2[2];
      v18 = a2[3];
      *a4 = *a2;
      a4[1] = v16;
      a4[2] = v17;
      a4[3] = v18;
      v19 = a2[5];
      a4[4] = a2[4];
      a4[5] = v19;
      v20 = 0;
      while ( 1 )
      {
        v21 = *(_DWORD *)&v5[4 * v20 + (_DWORD)&loc_7C74F8 - 8155512]
            ^ ((unsigned __int8)v5[HIBYTE(v19) - 128] << 16)
            ^ ((unsigned __int8)v5[BYTE2(v19) - 128] << 8)
            ^ (unsigned __int8)v5[BYTE1(v19) - 128]
            ^ ((unsigned __int8)v5[(unsigned __int8)v19 - 128] << 24)
            ^ v15;
        v4[6] = v21;
        v22 = v4[1] ^ v21;
        v4[7] = v22;
        v23 = v4[2] ^ v22;
        v4[8] = v23;
        v24 = v4[3] ^ v23;
        v4[9] = v24;
        if ( v20 == 7 )
          break;
        ++v20;
        v25 = v4[4] ^ v24;
        v4[10] = v25;
        v4[11] = v4[5] ^ v25;
        v4 += 6;
        v15 = *v4;
        v19 = v4[5];
      }
      v4[18] = 12;
      return 0;
    case 256:
      v26 = a2[1];
      v27 = a2[2];
      v28 = a2[3];
      *a4 = *a2;
      a4[1] = v26;
      a4[2] = v27;
      a4[3] = v28;
      v29 = a2[5];
      v30 = a2[6];
      v31 = a2[7];
      a4[4] = a2[4];
      a4[5] = v29;
      a4[6] = v30;
      a4[7] = v31;
      v32 = 0;
      while ( 1 )
      {
        v33 = *(_DWORD *)&v5[4 * v32 + (_DWORD)&loc_7C74F8 - 8155512]
            ^ ((unsigned __int8)v5[HIBYTE(v31) - 128] << 16)
            ^ ((unsigned __int8)v5[BYTE2(v31) - 128] << 8)
            ^ (unsigned __int8)v5[BYTE1(v31) - 128]
            ^ ((unsigned __int8)v5[(unsigned __int8)v31 - 128] << 24)
            ^ *v4;
        v4[8] = v33;
        v34 = v4[1] ^ v33;
        v4[9] = v34;
        v35 = v4[2] ^ v34;
        v4[10] = v35;
        v36 = v4[3] ^ v35;
        v4[11] = v36;
        if ( v32 == 6 )
          break;
        ++v32;
        v37 = ((unsigned __int8)v5[HIBYTE(v36) - 128] << 24)
            ^ ((unsigned __int8)v5[BYTE2(v36) - 128] << 16)
            ^ ((unsigned __int8)v5[BYTE1(v36) - 128] << 8)
            ^ (unsigned __int8)v5[(unsigned __int8)v36 - 128]
            ^ v4[4];
        v4[12] = v37;
        v38 = v4[5] ^ v37;
        v4[13] = v38;
        v39 = v4[6] ^ v38;
        v4[14] = v39;
        v4[15] = v4[7] ^ v39;
        v4 += 8;
        v31 = v4[7];
      }
      v4[12] = 14;
      return 0;
    default:
      return -2;
  }
}
