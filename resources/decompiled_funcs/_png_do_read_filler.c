int __cdecl png_do_read_filler(int a1, int a2, __int16 a3, char a4)
{
  int result; // eax
  _BYTE *v5; // [esp+0h] [ebp-4Ch]
  _BYTE *v6; // [esp+0h] [ebp-4Ch]
  _BYTE *v7; // [esp+4h] [ebp-48h]
  _BYTE *v8; // [esp+4h] [ebp-48h]
  _BYTE *v9; // [esp+8h] [ebp-44h]
  _BYTE *v10; // [esp+8h] [ebp-44h]
  _BYTE *v11; // [esp+Ch] [ebp-40h]
  _BYTE *v12; // [esp+Ch] [ebp-40h]
  _BYTE *v13; // [esp+10h] [ebp-3Ch]
  _BYTE *v14; // [esp+10h] [ebp-3Ch]
  _BYTE *v15; // [esp+14h] [ebp-38h]
  _BYTE *v16; // [esp+14h] [ebp-38h]
  _BYTE *v17; // [esp+18h] [ebp-34h]
  _BYTE *v18; // [esp+18h] [ebp-34h]
  _BYTE *v19; // [esp+1Ch] [ebp-30h]
  _BYTE *v20; // [esp+1Ch] [ebp-30h]
  _BYTE *v21; // [esp+20h] [ebp-2Ch]
  _BYTE *v22; // [esp+20h] [ebp-2Ch]
  _BYTE *v23; // [esp+24h] [ebp-28h]
  _BYTE *v24; // [esp+24h] [ebp-28h]
  _BYTE *v25; // [esp+28h] [ebp-24h]
  _BYTE *v26; // [esp+28h] [ebp-24h]
  _BYTE *v27; // [esp+2Ch] [ebp-20h]
  _BYTE *v28; // [esp+2Ch] [ebp-20h]
  _BYTE *v29; // [esp+30h] [ebp-1Ch]
  _BYTE *v30; // [esp+30h] [ebp-1Ch]
  _BYTE *v31; // [esp+34h] [ebp-18h]
  _BYTE *v32; // [esp+38h] [ebp-14h]
  _BYTE *v33; // [esp+38h] [ebp-14h]
  _BYTE *v34; // [esp+3Ch] [ebp-10h]
  unsigned int v35; // [esp+40h] [ebp-Ch]
  unsigned int n; // [esp+44h] [ebp-8h]
  unsigned int ii; // [esp+44h] [ebp-8h]
  unsigned int jj; // [esp+44h] [ebp-8h]
  unsigned int kk; // [esp+44h] [ebp-8h]
  unsigned int i; // [esp+44h] [ebp-8h]
  unsigned int j; // [esp+44h] [ebp-8h]
  unsigned int k; // [esp+44h] [ebp-8h]
  unsigned int m; // [esp+44h] [ebp-8h]

  v35 = *(_DWORD *)a1;
  result = (unsigned __int8)a3;
  if ( *(_BYTE *)(a1 + 8) )
  {
    if ( *(_BYTE *)(a1 + 8) == 2 )
    {
      result = a1;
      if ( *(_BYTE *)(a1 + 9) == 8 )
      {
        if ( a4 < 0 )
        {
          v19 = (_BYTE *)(a2 + 3 * v35);
          v17 = &v19[v35];
          for ( i = 1; i < v35; ++i )
          {
            v18 = v17 - 1;
            *v18 = a3;
            v20 = v19 - 1;
            *--v18 = *v20--;
            *--v18 = *v20;
            v19 = v20 - 1;
            v17 = v18 - 1;
            *v17 = *v19;
          }
          *(v17 - 1) = a3;
          *(_BYTE *)(a1 + 10) = 4;
          *(_BYTE *)(a1 + 11) = 32;
          result = 4 * v35;
          *(_DWORD *)(a1 + 4) = 4 * v35;
        }
        else
        {
          v15 = (_BYTE *)(a2 + 3 * v35);
          v13 = &v15[v35];
          for ( j = 0; j < v35; ++j )
          {
            v16 = v15 - 1;
            v14 = v13 - 1;
            *v14 = *v16--;
            *--v14 = *v16;
            v15 = v16 - 1;
            *--v14 = *v15;
            v13 = v14 - 1;
            *v13 = a3;
          }
          *(_BYTE *)(a1 + 10) = 4;
          *(_BYTE *)(a1 + 11) = 32;
          result = a1;
          *(_DWORD *)(a1 + 4) = 4 * v35;
        }
      }
      else if ( *(_BYTE *)(a1 + 9) == 16 )
      {
        if ( a4 < 0 )
        {
          v11 = (_BYTE *)(a2 + 6 * v35);
          v9 = &v11[2 * v35];
          for ( k = 1; k < v35; ++k )
          {
            v10 = v9 - 1;
            *v10-- = HIBYTE(a3);
            *v10 = a3;
            v12 = v11 - 1;
            *--v10 = *v12--;
            *--v10 = *v12--;
            *--v10 = *v12--;
            *--v10 = *v12--;
            *--v10 = *v12;
            v11 = v12 - 1;
            v9 = v10 - 1;
            *v9 = *v11;
          }
          *((_WORD *)v9 - 1) = a3;
          *(_BYTE *)(a1 + 10) = 4;
          *(_BYTE *)(a1 + 11) = 64;
          result = 8 * v35;
          *(_DWORD *)(a1 + 4) = 8 * v35;
        }
        else
        {
          v7 = (_BYTE *)(a2 + 6 * v35);
          v5 = &v7[2 * v35];
          for ( m = 0; m < v35; ++m )
          {
            v8 = v7 - 1;
            v6 = v5 - 1;
            *v6 = *v8--;
            *--v6 = *v8--;
            *--v6 = *v8--;
            *--v6 = *v8--;
            *--v6 = *v8;
            v7 = v8 - 1;
            *--v6 = *v7;
            *--v6 = HIBYTE(a3);
            v5 = v6 - 1;
            *v5 = a3;
          }
          *(_BYTE *)(a1 + 10) = 4;
          result = a1;
          *(_BYTE *)(a1 + 11) = 64;
          *(_DWORD *)(a1 + 4) = 8 * v35;
        }
      }
    }
  }
  else if ( *(_BYTE *)(a1 + 9) == 8 )
  {
    if ( a4 < 0 )
    {
      v34 = (_BYTE *)(v35 + a2);
      v32 = (_BYTE *)(v35 + v35 + a2);
      for ( n = 1; n < v35; ++n )
      {
        v33 = v32 - 1;
        *v33 = a3;
        --v34;
        v32 = v33 - 1;
        *v32 = *v34;
      }
      *(v32 - 1) = a3;
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 16;
      result = a1;
      *(_DWORD *)(a1 + 4) = 2 * v35;
    }
    else
    {
      v31 = (_BYTE *)(v35 + a2);
      v29 = (_BYTE *)(v35 + v35 + a2);
      for ( ii = 0; ii < v35; ++ii )
      {
        --v31;
        v30 = v29 - 1;
        *v30 = *v31;
        v29 = v30 - 1;
        *v29 = a3;
      }
      *(_BYTE *)(a1 + 10) = 2;
      *(_BYTE *)(a1 + 11) = 16;
      result = 2 * v35;
      *(_DWORD *)(a1 + 4) = 2 * v35;
    }
  }
  else
  {
    result = *(unsigned __int8 *)(a1 + 9);
    if ( result == 16 )
    {
      if ( a4 < 0 )
      {
        v27 = (_BYTE *)(a2 + 2 * v35);
        v25 = &v27[2 * v35];
        for ( jj = 1; jj < v35; ++jj )
        {
          v26 = v25 - 1;
          *v26-- = HIBYTE(a3);
          *v26 = a3;
          v28 = v27 - 1;
          *--v26 = *v28;
          v27 = v28 - 1;
          v25 = v26 - 1;
          *v25 = *v27;
        }
        *((_WORD *)v25 - 1) = a3;
        *(_BYTE *)(a1 + 10) = 2;
        result = a1;
        *(_BYTE *)(a1 + 11) = 32;
        *(_DWORD *)(a1 + 4) = 4 * v35;
      }
      else
      {
        v23 = (_BYTE *)(a2 + 2 * v35);
        v21 = &v23[2 * v35];
        for ( kk = 0; kk < v35; ++kk )
        {
          v24 = v23 - 1;
          v22 = v21 - 1;
          *v22 = *v24;
          v23 = v24 - 1;
          *--v22 = *v23;
          *--v22 = HIBYTE(a3);
          v21 = v22 - 1;
          *v21 = a3;
        }
        *(_BYTE *)(a1 + 10) = 2;
        *(_BYTE *)(a1 + 11) = 32;
        result = a1;
        *(_DWORD *)(a1 + 4) = 4 * v35;
      }
    }
  }
  return result;
}
