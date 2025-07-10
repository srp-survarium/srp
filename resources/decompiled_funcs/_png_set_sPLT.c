void __cdecl png_set_sPLT(int a1, int a2, int a3, int a4)
{
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int count; // [esp+8h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( a1 && a2 )
  {
    dst = (unsigned __int8 *)png_malloc_warn(a1, 16 * (a4 + *(_DWORD *)(a2 + 216)));
    if ( dst )
    {
      memcpy(dst, *(unsigned __int8 **)(a2 + 212), 16 * *(_DWORD *)(a2 + 216));
      png_free(a1, *(void **)(a2 + 212));
      *(_DWORD *)(a2 + 212) = 0;
      for ( i = 0; i < a4; ++i )
      {
        v5 = (int)&dst[16 * *(_DWORD *)(a2 + 216) + 16 * i];
        v4 = a3 + 16 * i;
        count = lstrlenA(*(LPCSTR *)v4) + 1;
        *(_DWORD *)v5 = png_malloc_warn(a1, count);
        if ( *(_DWORD *)v5 )
        {
          memcpy(*(unsigned __int8 **)v5, *(unsigned __int8 **)v4, count);
          *(_DWORD *)(v5 + 8) = png_malloc_warn(a1, 10 * *(_DWORD *)(v4 + 12));
          if ( *(_DWORD *)(v5 + 8) )
          {
            memcpy(*(unsigned __int8 **)(v5 + 8), *(unsigned __int8 **)(v4 + 8), 10 * *(_DWORD *)(v4 + 12));
            *(_DWORD *)(v5 + 12) = *(_DWORD *)(v4 + 12);
            *(_BYTE *)(v5 + 4) = *(_BYTE *)(v4 + 4);
          }
          else
          {
            png_warning(a1, "Out of memory while processing sPLT chunk");
            png_free(a1, *(void **)v5);
            *(_DWORD *)v5 = 0;
          }
        }
        else
        {
          png_warning(a1, "Out of memory while processing sPLT chunk");
        }
      }
      *(_DWORD *)(a2 + 212) = dst;
      *(_DWORD *)(a2 + 216) += a4;
      *(_DWORD *)(a2 + 8) |= 0x2000u;
      *(_DWORD *)(a2 + 184) |= 0x20u;
    }
    else
    {
      png_warning(a1, "No memory for sPLT palettes");
    }
  }
}
