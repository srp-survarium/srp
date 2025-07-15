int __cdecl png_handle_pCAL(int a1, int a2, unsigned int a3)
{
  int result; // eax
  int v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch]
  unsigned __int8 v6; // [esp+Bh] [ebp-25h]
  _BYTE *i; // [esp+10h] [ebp-20h]
  _BYTE *j; // [esp+10h] [ebp-20h]
  char *v9; // [esp+14h] [ebp-1Ch]
  _DWORD *pointer; // [esp+18h] [ebp-18h]
  unsigned __int8 v11; // [esp+1Fh] [ebp-11h]
  int k; // [esp+20h] [ebp-10h]
  unsigned int v13; // [esp+28h] [ebp-8h]

  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before pCAL");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid pCAL after IDAT");
    return png_crc_finish(a1, a3);
  }
  else if ( a2 && (*(_DWORD *)(a2 + 8) & 0x400) != 0 )
  {
    png_warning(a1, "Duplicate pCAL chunk");
    return png_crc_finish(a1, a3);
  }
  else
  {
    png_free(a1, *(void **)(a1 + 680));
    *(_DWORD *)(a1 + 680) = png_malloc_warn(a1, a3 + 1);
    if ( *(_DWORD *)(a1 + 680) )
    {
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      if ( png_crc_finish(a1, 0) )
      {
        result = png_free(a1, *(void **)(a1 + 680));
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 680) + a3) = 0;
        for ( i = *(_BYTE **)(a1 + 680); *i; ++i )
          ;
        v13 = a3 + *(_DWORD *)(a1 + 680);
        if ( v13 > (unsigned int)(i + 12) )
        {
          v5 = (unsigned __int8)i[4]
             + ((unsigned __int8)i[3] << 8)
             + ((unsigned __int8)i[2] << 16)
             + ((unsigned __int8)i[1] << 24);
          v4 = (unsigned __int8)i[8]
             + ((unsigned __int8)i[7] << 8)
             + ((unsigned __int8)i[6] << 16)
             + ((unsigned __int8)i[5] << 24);
          v11 = i[9];
          v6 = i[10];
          v9 = i + 11;
          if ( (v11 || v6 == 2) && (v11 != 1 || v6 == 3) && (v11 != 2 || v6 == 3) && (v11 != 3 || v6 == 4) )
          {
            if ( v11 >= 4u )
              png_warning(a1, "Unrecognized equation type for pCAL chunk");
            for ( j = i + 11; *j; ++j )
              ;
            pointer = (_DWORD *)png_malloc_warn(a1, 4 * v6);
            if ( pointer )
            {
              for ( k = 0; k < v6; ++k )
              {
                pointer[k] = ++j;
                while ( (unsigned int)j <= v13 && *j )
                  ++j;
                if ( (unsigned int)j > v13 )
                {
                  png_warning(a1, "Invalid pCAL data");
                  png_free(a1, *(void **)(a1 + 680));
                  *(_DWORD *)(a1 + 680) = 0;
                  return png_free(a1, pointer);
                }
              }
              png_set_pCAL(a1, a2, *(char **)(a1 + 680), v5, v4, v11, v6, v9, (int)pointer);
              png_free(a1, *(void **)(a1 + 680));
              *(_DWORD *)(a1 + 680) = 0;
              return png_free(a1, pointer);
            }
            else
            {
              png_free(a1, *(void **)(a1 + 680));
              *(_DWORD *)(a1 + 680) = 0;
              return png_warning(a1, "No memory for pCAL params");
            }
          }
          else
          {
            png_warning(a1, "Invalid pCAL parameters for equation type");
            png_free(a1, *(void **)(a1 + 680));
            result = a1;
            *(_DWORD *)(a1 + 680) = 0;
          }
        }
        else
        {
          png_warning(a1, "Invalid pCAL data");
          result = png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
        }
      }
    }
    else
    {
      return png_warning(a1, "No memory for pCAL purpose");
    }
  }
  return result;
}
