void __cdecl png_set_pCAL(int a1, int a2, char *lpString, int a4, int a5, unsigned int a6, int a7, char *a8, int a9)
{
  unsigned int v9; // eax
  int i; // [esp+0h] [ebp-8h]
  int j; // [esp+0h] [ebp-8h]
  int count; // [esp+4h] [ebp-4h]
  int counta; // [esp+4h] [ebp-4h]
  int countb; // [esp+4h] [ebp-4h]

  if ( a1 && a2 )
  {
    count = lstrlenA(lpString) + 1;
    if ( a6 >= 4 )
      png_error(a1, (int)"Invalid pCAL equation type");
    for ( i = 0; i < a7; ++i )
    {
      v9 = lstrlenA(*(LPCSTR *)(a9 + 4 * i));
      if ( !png_check_fp_string(*(_DWORD *)(a9 + 4 * i), v9) )
        png_error(a1, (int)"Invalid format for pCAL parameter");
    }
    *(_DWORD *)(a2 + 160) = png_malloc_warn(a1, count);
    if ( *(_DWORD *)(a2 + 160) )
    {
      memcpy(*(unsigned __int8 **)(a2 + 160), (unsigned __int8 *)lpString, count);
      *(_DWORD *)(a2 + 164) = a4;
      *(_DWORD *)(a2 + 168) = a5;
      *(_BYTE *)(a2 + 180) = a6;
      *(_BYTE *)(a2 + 181) = a7;
      counta = lstrlenA(a8) + 1;
      *(_DWORD *)(a2 + 172) = png_malloc_warn(a1, counta);
      if ( *(_DWORD *)(a2 + 172) )
      {
        memcpy(*(unsigned __int8 **)(a2 + 172), (unsigned __int8 *)a8, counta);
        *(_DWORD *)(a2 + 176) = png_malloc_warn(a1, 4 * a7 + 4);
        if ( *(_DWORD *)(a2 + 176) )
        {
          memset(*(_DWORD *)(a2 + 176), 0, 4 * a7 + 4);
          for ( j = 0; j < a7; ++j )
          {
            countb = lstrlenA(*(LPCSTR *)(a9 + 4 * j)) + 1;
            *(_DWORD *)(*(_DWORD *)(a2 + 176) + 4 * j) = png_malloc_warn(a1, countb);
            if ( !*(_DWORD *)(*(_DWORD *)(a2 + 176) + 4 * j) )
            {
              png_warning(a1, "Insufficient memory for pCAL parameter");
              return;
            }
            memcpy(*(unsigned __int8 **)(*(_DWORD *)(a2 + 176) + 4 * j), *(unsigned __int8 **)(a9 + 4 * j), countb);
          }
          *(_DWORD *)(a2 + 8) |= 0x400u;
          *(_DWORD *)(a2 + 184) |= 0x80u;
        }
        else
        {
          png_warning(a1, "Insufficient memory for pCAL params");
        }
      }
      else
      {
        png_warning(a1, "Insufficient memory for pCAL units");
      }
    }
    else
    {
      png_warning(a1, "Insufficient memory for pCAL purpose");
    }
  }
}
