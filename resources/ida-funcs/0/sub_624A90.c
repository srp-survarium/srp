int __cdecl sub_624A90(
        __int16 a1,
        _BYTE **a2,
        _BYTE **a3,
        int *a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int *a9,
        int *a10,
        int a11,
        _DWORD *a12,
        _DWORD *a13)
{
  int v14; // [esp+0h] [ebp-54h]
  int v15; // [esp+4h] [ebp-50h]
  __int16 v16; // [esp+8h] [ebp-4Ch]
  int v17; // [esp+Ch] [ebp-48h]
  int v18; // [esp+10h] [ebp-44h]
  _BYTE *v19; // [esp+14h] [ebp-40h]
  int v20; // [esp+18h] [ebp-3Ch]
  int v21; // [esp+1Ch] [ebp-38h]
  int v22; // [esp+20h] [ebp-34h] BYREF
  __int16 v23; // [esp+24h] [ebp-30h]
  __int16 v24; // [esp+26h] [ebp-2Eh]
  int v25; // [esp+28h] [ebp-2Ch] BYREF
  _BYTE *v26; // [esp+2Ch] [ebp-28h] BYREF
  _BYTE *v27; // [esp+30h] [ebp-24h] BYREF
  int v28; // [esp+34h] [ebp-20h]
  int v29; // [esp+38h] [ebp-1Ch] BYREF
  _BYTE *v30; // [esp+3Ch] [ebp-18h]
  _BYTE *v31; // [esp+40h] [ebp-14h]
  int v32; // [esp+44h] [ebp-10h]
  int v33; // [esp+48h] [ebp-Ch] BYREF
  int v34; // [esp+4Ch] [ebp-8h] BYREF
  _BYTE *v35; // [esp+50h] [ebp-4h]

  v26 = *a3;
  v27 = *a2;
  v31 = v27;
  v19 = v27;
  v30 = 0;
  v28 = 0;
  v34 = a11;
  v35 = v27;
  v20 = -2;
  v32 = -2;
  v33 = a7 + 6;
  if ( *v27 == 127 )
  {
    v28 = (unsigned __int8)v27[4] | ((unsigned __int8)v27[3] << 8);
    v23 = v28;
    v22 = a12[8];
    v24 = 0;
    a12[8] = &v22;
  }
  v27[1] = 0;
  v27[2] = 0;
  v27 += a7 + 3;
  v18 = a12[14];
  v21 = v18;
  while ( 1 )
  {
    if ( a6 )
      a12[14] = v21;
    if ( a5 )
    {
      *v27++ = 118;
      v30 = v27;
      *v27 = 0;
      v27[1] = 0;
      v27 += 2;
      v33 += 3;
    }
    if ( !sub_624FE0(&a1, &v27, &v26, a4, &v25, &v29, &v34, a8, a12, a13 != 0 ? &v33 : 0) )
    {
      *a3 = v26;
      return 0;
    }
    if ( a12[14] > v18 )
      v18 = a12[14];
    if ( !a13 )
    {
      if ( *v31 == 113 )
      {
        if ( v32 >= 0 && v32 != v25 )
        {
          if ( v20 < 0 )
            v20 = v32;
          v32 = -1;
        }
        if ( v32 < 0 && v25 >= 0 && v29 < 0 )
          v29 = v25;
        v20 = (v20 & 0xFFFFFDFF) == (v29 & 0xFFFFFDFF) ? v29 | v20 : -1;
      }
      else
      {
        v32 = v25;
        v20 = v29;
      }
      if ( a5 )
      {
        *v27 = 0;
        v17 = sub_6245C0((int)v31, (a1 & 0x800) != 0, 0, (int)a12);
        if ( v17 == -3 )
        {
          a12[23] = 1;
        }
        else
        {
          if ( v17 < 0 )
          {
            if ( v17 == -2 )
              v14 = 36;
            else
              v14 = v17 != -4 ? 25 : 70;
            *a4 = v14;
            *a3 = v26;
            return 0;
          }
          *v30 = BYTE1(v17);
          v30[1] = v17;
        }
      }
    }
    if ( *v26 != 124 )
      break;
    if ( a13 )
    {
      v27 = &(*a2)[a7 + 3];
      v33 += 3;
    }
    else
    {
      *v27 = 113;
      v27[1] = (unsigned __int16)((_WORD)v27 - (_WORD)v31) >> 8;
      v27[2] = (_BYTE)v27 - (_BYTE)v31;
      v31 = v27;
      v35 = v27;
      v27 += 3;
    }
    ++v26;
  }
  if ( !a13 )
  {
    v16 = (_WORD)v27 - (_WORD)v31;
    do
    {
      v15 = (unsigned __int8)v31[2] | ((unsigned __int8)v31[1] << 8);
      v31[1] = HIBYTE(v16);
      v31[2] = v16;
      v16 = v15;
      v31 -= v15;
    }
    while ( v15 > 0 );
  }
  *v27 = 114;
  v27[1] = (unsigned __int16)((_WORD)v27 - (_WORD)v19) >> 8;
  v27[2] = (_BYTE)v27 - (_BYTE)v19;
  v27 += 3;
  if ( v28 > 0 )
  {
    if ( *(_WORD *)(a12[8] + 6) )
    {
      sub_624F30(v19 + 3, v19, v27 - v19);
      *v19 = 123;
      v27 += 3;
      v19[1] = (unsigned __int16)((_WORD)v27 - (_WORD)v19) >> 8;
      v19[2] = (_BYTE)v27 - (_BYTE)v19;
      *v27 = 114;
      v27[1] = (unsigned __int16)((_WORD)v27 - (_WORD)v19) >> 8;
      v27[2] = (_BYTE)v27 - (_BYTE)v19;
      v27 += 3;
      v33 += 6;
    }
    a12[8] = *(_DWORD *)a12[8];
  }
  a12[14] = v18;
  *a2 = v27;
  *a3 = v26;
  *a9 = v32;
  *a10 = v20;
  if ( a13 )
  {
    if ( 2147483627 - *a13 < v33 )
    {
      *a4 = 20;
      return 0;
    }
    *a13 += v33;
  }
  return 1;
}
