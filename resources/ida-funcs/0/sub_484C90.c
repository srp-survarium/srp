int __usercall sub_484C90@<eax>(_DWORD *a1@<eax>, _BYTE *a2)
{
  _DWORD *v4; // esi
  bool v5; // sf
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  char v12; // bl
  int v13; // edx
  int v14; // edi
  int v15; // edi
  int v16; // ecx
  bool v17; // cc
  int v19; // esi
  char v20; // [esp+14h] [ebp+4h]

  v4 = (_DWORD *)a1[106];
  if ( (int)v4[3] < 0x8000 )
  {
    while ( 1 )
    {
      v5 = --v4[4] < 0;
      if ( v5 )
        break;
LABEL_13:
      v4[3] *= 2;
      if ( (int)v4[3] >= 0x8000 )
        goto LABEL_14;
    }
    if ( !a1[99] )
    {
      v6 = sub_484C50(a1);
      if ( v6 != 255 )
      {
LABEL_10:
        v8 = v6 | (v4[2] << 8);
        v5 = v4[4] + 8 < 0;
        v4[4] += 8;
        v9 = v4[4];
        v4[2] = v8;
        if ( v5 )
        {
          v4[4] = v9 + 1;
          if ( v9 == -1 )
            v4[3] = 0x8000;
        }
        goto LABEL_13;
      }
      do
        v7 = sub_484C50(a1);
      while ( v7 == 255 );
      if ( !v7 )
      {
        v6 = 255;
        goto LABEL_10;
      }
      a1[99] = v7;
    }
    v6 = 0;
    goto LABEL_10;
  }
LABEL_14:
  v10 = (unsigned __int8)*a2;
  v11 = v4[4];
  v12 = jpeg_aritab[*a2 & 0x7F];
  v20 = BYTE1(jpeg_aritab[*a2 & 0x7F]);
  v13 = jpeg_aritab[*a2 & 0x7F] >> 16;
  v14 = v4[3] - v13;
  v4[3] = v14;
  v15 = v14 << v11;
  v16 = v4[2];
  if ( v16 < v15 )
  {
    v19 = v4[3];
    if ( v19 < 0x8000 )
    {
      if ( v19 < v13 )
      {
        *a2 = v12 ^ v10 & 0x80;
        return (v10 ^ 0x80) >> 7;
      }
      *a2 = v20 ^ v10 & 0x80;
    }
    return v10 >> 7;
  }
  else
  {
    v17 = v4[3] < v13;
    v4[2] = v16 - v15;
    v4[3] = v13;
    if ( v17 )
    {
      *a2 = v20 ^ v10 & 0x80;
    }
    else
    {
      *a2 = v12 ^ v10 & 0x80;
      v10 ^= 0x80u;
    }
    return v10 >> 7;
  }
}
