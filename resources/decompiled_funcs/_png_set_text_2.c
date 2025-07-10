int __cdecl png_set_text_2(int a1, int a2, int a3, int a4)
{
  int v5; // [esp+0h] [ebp-24h]
  int v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  int count; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]
  unsigned __int8 *src; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  int v12; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  if ( !a1 || !a2 || !a4 )
    return 0;
  if ( a4 + *(_DWORD *)(a2 + 48) > *(_DWORD *)(a2 + 52) )
  {
    v11 = *(_DWORD *)(a2 + 52);
    v12 = *(_DWORD *)(a2 + 48);
    if ( *(_DWORD *)(a2 + 56) )
    {
      *(_DWORD *)(a2 + 52) = *(_DWORD *)(a2 + 48) + a4 + 8;
      src = *(unsigned __int8 **)(a2 + 56);
      *(_DWORD *)(a2 + 56) = png_malloc_warn(a1, 28 * *(_DWORD *)(a2 + 52));
      if ( !*(_DWORD *)(a2 + 56) )
      {
        *(_DWORD *)(a2 + 52) = v11;
        *(_DWORD *)(a2 + 56) = src;
        return 1;
      }
      memcpy(*(unsigned __int8 **)(a2 + 56), src, 28 * v11);
      png_free(a1, src);
    }
    else
    {
      *(_DWORD *)(a2 + 52) = a4 + 8;
      *(_DWORD *)(a2 + 48) = 0;
      *(_DWORD *)(a2 + 56) = png_malloc_warn(a1, 28 * *(_DWORD *)(a2 + 52));
      if ( !*(_DWORD *)(a2 + 56) )
      {
        *(_DWORD *)(a2 + 48) = v12;
        *(_DWORD *)(a2 + 52) = v11;
        return 1;
      }
      *(_DWORD *)(a2 + 184) |= 0x4000u;
    }
  }
  for ( i = 0; i < a4; ++i )
  {
    v6 = *(_DWORD *)(a2 + 56) + 28 * *(_DWORD *)(a2 + 48);
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
          *(_DWORD *)v6 = *(_DWORD *)(a3 + 28 * i);
        }
        else
        {
          v9 = 0;
          if ( *(int *)(a3 + 28 * i) <= 0 )
            *(_DWORD *)v6 = -1;
          else
            *(_DWORD *)v6 = 1;
        }
        *(_DWORD *)(v6 + 4) = png_malloc_warn(a1, v7 + v9 + count + v5 + 4);
        if ( !*(_DWORD *)(v6 + 4) )
          return 1;
        memcpy(*(unsigned __int8 **)(v6 + 4), *(unsigned __int8 **)(a3 + 28 * i + 4), count);
        *(_BYTE *)(*(_DWORD *)(v6 + 4) + count) = 0;
        if ( *(int *)(a3 + 28 * i) <= 0 )
        {
          *(_DWORD *)(v6 + 20) = 0;
          *(_DWORD *)(v6 + 24) = 0;
          *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 4) + count + 1;
        }
        else
        {
          *(_DWORD *)(v6 + 20) = *(_DWORD *)(v6 + 4) + count + 1;
          memcpy(*(unsigned __int8 **)(v6 + 20), *(unsigned __int8 **)(a3 + 28 * i + 20), v7);
          *(_BYTE *)(*(_DWORD *)(v6 + 20) + v7) = 0;
          *(_DWORD *)(v6 + 24) = *(_DWORD *)(v6 + 20) + v7 + 1;
          memcpy(*(unsigned __int8 **)(v6 + 24), *(unsigned __int8 **)(a3 + 28 * i + 24), v5);
          *(_BYTE *)(*(_DWORD *)(v6 + 24) + v5) = 0;
          *(_DWORD *)(v6 + 8) = *(_DWORD *)(v6 + 24) + v5 + 1;
        }
        if ( v9 )
          memcpy(*(unsigned __int8 **)(v6 + 8), *(unsigned __int8 **)(a3 + 28 * i + 8), v9);
        *(_BYTE *)(*(_DWORD *)(v6 + 8) + v9) = 0;
        if ( *(int *)v6 <= 0 )
        {
          *(_DWORD *)(v6 + 12) = v9;
          *(_DWORD *)(v6 + 16) = 0;
        }
        else
        {
          *(_DWORD *)(v6 + 12) = 0;
          *(_DWORD *)(v6 + 16) = v9;
        }
        ++*(_DWORD *)(a2 + 48);
      }
      else
      {
        png_warning(a1, "text compression mode is out of range");
      }
    }
  }
  return 0;
}
