int __cdecl png_handle_sCAL(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v4; // eax
  unsigned int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch] BYREF
  unsigned int v7; // [esp+8h] [ebp-8h] BYREF
  int v8; // [esp+Ch] [ebp-4h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before sCAL");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid sCAL after IDAT");
    return png_crc_finish(a1, a3);
  }
  else if ( a2 && (*(_DWORD *)(a2 + 8) & 0x4000) != 0 )
  {
    png_warning(a1, "Duplicate sCAL chunk");
    return png_crc_finish(a1, a3);
  }
  else if ( a3 >= 4 )
  {
    *(_DWORD *)(a1 + 680) = png_malloc_warn(a1, a3 + 1);
    if ( *(_DWORD *)(a1 + 680) )
    {
      v8 = a3;
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      *(_BYTE *)(*(_DWORD *)(a1 + 680) + a3) = 0;
      if ( png_crc_finish(a1, 0) )
      {
        png_free(a1, *(void **)(a1 + 680));
        result = a1;
        *(_DWORD *)(a1 + 680) = 0;
      }
      else if ( **(_BYTE **)(a1 + 680) == 1 || **(_BYTE **)(a1 + 680) == 2 )
      {
        v7 = 1;
        v6 = 0;
        if ( png_check_fp_number(*(_DWORD *)(a1 + 680), v8, &v6, &v7)
          && v7 < v8
          && (v4 = *(char *)(*(_DWORD *)(a1 + 680) + v7), ++v7, !v4) )
        {
          if ( (v6 & 0x188) == 0x108 )
          {
            v5 = v7;
            v6 = 0;
            if ( png_check_fp_number(*(_DWORD *)(a1 + 680), v8, &v6, &v7) && v7 == v8 )
            {
              if ( (v6 & 0x188) == 0x108 )
                png_set_sCAL_s(
                  a1,
                  a2,
                  **(char **)(a1 + 680),
                  (char *)(*(_DWORD *)(a1 + 680) + 1),
                  (char *)(v5 + *(_DWORD *)(a1 + 680)));
              else
                png_warning(a1, "Invalid sCAL chunk ignored: non-positive height");
            }
            else
            {
              png_warning(a1, "Invalid sCAL chunk ignored: bad height format");
            }
          }
          else
          {
            png_warning(a1, "Invalid sCAL chunk ignored: non-positive width");
          }
        }
        else
        {
          png_warning(a1, "Invalid sCAL chunk ignored: bad width format");
        }
        png_free(a1, *(void **)(a1 + 680));
        result = a1;
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        png_warning(a1, "Invalid sCAL ignored: invalid unit");
        result = png_free(a1, *(void **)(a1 + 680));
        *(_DWORD *)(a1 + 680) = 0;
      }
    }
    else
    {
      png_warning(a1, "Out of memory while processing sCAL chunk");
      return png_crc_finish(a1, a3);
    }
  }
  else
  {
    png_warning(a1, "sCAL chunk too short");
    return png_crc_finish(a1, a3);
  }
  return result;
}
