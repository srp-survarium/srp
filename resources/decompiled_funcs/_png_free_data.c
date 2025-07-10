int __cdecl png_free_data(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int n; // [esp+0h] [ebp-14h]
  int m; // [esp+4h] [ebp-10h]
  int k; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( a1 && a2 )
  {
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x4000) != 0 )
    {
      if ( a4 == -1 )
      {
        for ( i = 0; i < *(_DWORD *)(a2 + 48); ++i )
          png_free_data(a1, a2, 0x4000, i);
        png_free(a1, *(void **)(a2 + 56));
        *(_DWORD *)(a2 + 56) = 0;
        *(_DWORD *)(a2 + 48) = 0;
      }
      else if ( *(_DWORD *)(a2 + 56) && *(_DWORD *)(*(_DWORD *)(a2 + 56) + 28 * a4 + 4) )
      {
        png_free(a1, *(void **)(*(_DWORD *)(a2 + 56) + 28 * a4 + 4));
        *(_DWORD *)(*(_DWORD *)(a2 + 56) + 28 * a4 + 4) = 0;
      }
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x2000) != 0 )
    {
      png_free(a1, *(void **)(a2 + 76));
      *(_DWORD *)(a2 + 76) = 0;
      *(_DWORD *)(a2 + 8) &= ~0x10u;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x100) != 0 )
    {
      png_free(a1, *(void **)(a2 + 224));
      png_free(a1, *(void **)(a2 + 228));
      *(_DWORD *)(a2 + 224) = 0;
      *(_DWORD *)(a2 + 228) = 0;
      *(_DWORD *)(a2 + 8) &= ~0x4000u;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x80) != 0 )
    {
      png_free(a1, *(void **)(a2 + 160));
      png_free(a1, *(void **)(a2 + 172));
      *(_DWORD *)(a2 + 160) = 0;
      *(_DWORD *)(a2 + 172) = 0;
      if ( *(_DWORD *)(a2 + 176) )
      {
        for ( j = 0; j < *(unsigned __int8 *)(a2 + 181); ++j )
        {
          png_free(a1, *(void **)(*(_DWORD *)(a2 + 176) + 4 * j));
          *(_DWORD *)(*(_DWORD *)(a2 + 176) + 4 * j) = 0;
        }
        png_free(a1, *(void **)(a2 + 176));
        *(_DWORD *)(a2 + 176) = 0;
      }
      *(_DWORD *)(a2 + 8) &= ~0x400u;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x10) != 0 )
    {
      png_free(a1, *(void **)(a2 + 196));
      png_free(a1, *(void **)(a2 + 200));
      *(_DWORD *)(a2 + 196) = 0;
      *(_DWORD *)(a2 + 200) = 0;
      *(_DWORD *)(a2 + 8) &= ~0x1000u;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x20) != 0 )
    {
      if ( a4 == -1 )
      {
        if ( *(_DWORD *)(a2 + 216) )
        {
          for ( k = 0; k < *(_DWORD *)(a2 + 216); ++k )
            png_free_data(a1, a2, 32, k);
          png_free(a1, *(void **)(a2 + 212));
          *(_DWORD *)(a2 + 212) = 0;
          *(_DWORD *)(a2 + 216) = 0;
        }
        *(_DWORD *)(a2 + 8) &= ~0x2000u;
      }
      else if ( *(_DWORD *)(a2 + 212) )
      {
        png_free(a1, *(void **)(*(_DWORD *)(a2 + 212) + 16 * a4));
        png_free(a1, *(void **)(*(_DWORD *)(a2 + 212) + 16 * a4 + 8));
        *(_DWORD *)(16 * a4 + *(_DWORD *)(a2 + 212)) = 0;
        *(_DWORD *)(*(_DWORD *)(a2 + 212) + 16 * a4 + 8) = 0;
      }
    }
    if ( *(_DWORD *)(a1 + 664) )
    {
      png_free(a1, *(void **)(a1 + 664));
      *(_DWORD *)(a1 + 664) = 0;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x200) != 0 )
    {
      if ( a4 == -1 )
      {
        if ( *(_DWORD *)(a2 + 192) )
        {
          for ( m = 0; m < *(_DWORD *)(a2 + 192); ++m )
            png_free_data(a1, a2, 512, m);
          png_free(a1, *(void **)(a2 + 188));
          *(_DWORD *)(a2 + 188) = 0;
          *(_DWORD *)(a2 + 192) = 0;
        }
      }
      else if ( *(_DWORD *)(a2 + 188) )
      {
        png_free(a1, *(void **)(*(_DWORD *)(a2 + 188) + 20 * a4 + 8));
        *(_DWORD *)(*(_DWORD *)(a2 + 188) + 20 * a4 + 8) = 0;
      }
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 8) != 0 )
    {
      png_free(a1, *(void **)(a2 + 124));
      *(_DWORD *)(a2 + 124) = 0;
      *(_DWORD *)(a2 + 8) &= ~0x40u;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x1000) != 0 )
    {
      png_zfree(a1, *(void **)(a2 + 16));
      *(_DWORD *)(a2 + 16) = 0;
      *(_DWORD *)(a2 + 8) &= ~8u;
      *(_WORD *)(a2 + 20) = 0;
    }
    if ( (*(_DWORD *)(a2 + 184) & a3 & 0x40) != 0 )
    {
      if ( *(_DWORD *)(a2 + 232) )
      {
        for ( n = 0; n < *(_DWORD *)(a2 + 4); ++n )
        {
          png_free(a1, *(void **)(*(_DWORD *)(a2 + 232) + 4 * n));
          *(_DWORD *)(*(_DWORD *)(a2 + 232) + 4 * n) = 0;
        }
        png_free(a1, *(void **)(a2 + 232));
        *(_DWORD *)(a2 + 232) = 0;
      }
      *(_DWORD *)(a2 + 8) &= ~0x8000u;
    }
    if ( a4 != -1 )
      a3 &= 0xFFFFBDDF;
    result = a2;
    *(_DWORD *)(a2 + 184) &= ~a3;
  }
  return result;
}
