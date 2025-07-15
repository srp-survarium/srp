int __cdecl png_set_text_2(int a1, _DWORD *a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-24h]
  int *v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  int count; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]
  __m128i *src; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  if ( !a1 || !a2 || !a4 )
    return 0;
  if ( a4 + a2[12] > a2[13] )
  {
    v11 = a2[13];
    v12 = a2[12];
    if ( a2[14] )
    {
      a2[13] = a2[12] + a4 + 8;
      src = (__m128i *)a2[14];
      a2[14] = png_malloc_warn(a1, 28 * a2[13]);
      if ( !a2[14] )
      {
        a2[13] = v11;
        a2[14] = src;
        return 1;
      }
      memcpy(a2[14], src, 28 * v11);
      png_free(a1, src);
    }
    else
    {
      a2[13] = a4 + 8;
      a2[12] = 0;
      a2[14] = png_malloc_warn(a1, 28 * a2[13]);
      if ( !a2[14] )
      {
        a2[12] = v12;
        a2[13] = v11;
        return 1;
      }
      a2[46] |= 0x4000u;
    }
  }
  for ( i = 0; i < a4; ++i )
  {
    v6 = (int *)(a2[14] + 28 * a2[12]);
    if ( *(_DWORD *)(a3 + 28 * i + 4) )
    {
      if ( *(int *)(a3 + 28 * i) >= -1 && *(int *)(a3 + 28 * i) < 3 )
      {
        count = lstrlenA(*(LPCSTR *)(a3 + 28 * i + 4));
        if ( *(int *)(a3 + 28 * i) > 0 )
        {
          if ( *(_DWORD *)(a3 + 28 * i + 20) )
            v7 = lstrlenA(*(LPCSTR *)(a3 + 28 * i + 20));
          else
            v7 = 0;
          if ( *(_DWORD *)(a3 + 28 * i + 24) )
            v5 = lstrlenA(*(LPCSTR *)(a3 + 28 * i + 24));
          else
            v5 = 0;
        }
        else
        {
          v7 = 0;
          v5 = 0;
        }
        if ( *(_DWORD *)(a3 + 28 * i + 8) && **(_BYTE **)(a3 + 28 * i + 8) )
        {
          v9 = lstrlenA(*(LPCSTR *)(a3 + 28 * i + 8));
          *v6 = *(_DWORD *)(a3 + 28 * i);
        }
        else
        {
          v9 = 0;
          if ( *(int *)(a3 + 28 * i) <= 0 )
            *v6 = -1;
          else
            *v6 = 1;
        }
        v6[1] = png_malloc_warn(a1, v7 + v9 + count + v5 + 4);
        if ( !v6[1] )
          return 1;
        memcpy(v6[1], *(const __m128i **)(a3 + 28 * i + 4), count);
        *(_BYTE *)(v6[1] + count) = 0;
        if ( *(int *)(a3 + 28 * i) <= 0 )
        {
          v6[5] = 0;
          v6[6] = 0;
          v6[2] = v6[1] + count + 1;
        }
        else
        {
          v6[5] = v6[1] + count + 1;
          memcpy(v6[5], *(const __m128i **)(a3 + 28 * i + 20), v7);
          *(_BYTE *)(v6[5] + v7) = 0;
          v6[6] = v6[5] + v7 + 1;
          memcpy(v6[6], *(const __m128i **)(a3 + 28 * i + 24), v5);
          *(_BYTE *)(v6[6] + v5) = 0;
          v6[2] = v6[6] + v5 + 1;
        }
        if ( v9 )
          memcpy(v6[2], *(const __m128i **)(a3 + 28 * i + 8), v9);
        *(_BYTE *)(v6[2] + v9) = 0;
        if ( *v6 <= 0 )
        {
          v6[3] = v9;
          v6[4] = 0;
        }
        else
        {
          v6[3] = 0;
          v6[4] = v9;
        }
        ++a2[12];
      }
      else
      {
        png_warning(a1, "text compression mode is out of range");
      }
    }
  }
  return 0;
}
