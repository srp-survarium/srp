int __cdecl png_handle_iCCP(int a1, int a2, unsigned int a3)
{
  int result; // eax
  _BYTE v4[256]; // [esp+0h] [ebp-128h] BYREF
  unsigned int count; // [esp+104h] [ebp-24h]
  unsigned int size; // [esp+108h] [ebp-20h]
  unsigned int *v7; // [esp+10Ch] [ebp-1Ch]
  unsigned __int8 *i; // [esp+110h] [ebp-18h]
  unsigned __int8 v9; // [esp+117h] [ebp-11h]
  unsigned int v10; // [esp+118h] [ebp-10h]
  int v11; // [esp+11Ch] [ebp-Ch] BYREF
  unsigned int v12; // [esp+120h] [ebp-8h]
  int v13; // [esp+124h] [ebp-4h]

  v10 = 0;
  if ( (*(_DWORD *)(a1 + 108) & 1) == 0 )
    png_error(a1, (int)"Missing IHDR before iCCP");
  if ( (*(_DWORD *)(a1 + 108) & 4) != 0 )
  {
    png_warning(a1, "Invalid iCCP after IDAT");
    return png_crc_finish(a1, a3);
  }
  else
  {
    if ( (*(_DWORD *)(a1 + 108) & 2) != 0 )
      png_warning(a1, "Out of place iCCP chunk");
    if ( (*(_DWORD *)(a1 + 108) & 0x4000) != 0 || a2 && (*(_DWORD *)(a2 + 8) & 0x1800) != 0 )
    {
      png_warning(a1, "Duplicate iCCP chunk");
      return png_crc_finish(a1, a3);
    }
    else
    {
      *(_DWORD *)(a1 + 108) |= 0x4000u;
      png_free(a1, *(void **)(a1 + 680));
      *(_DWORD *)(a1 + 680) = png_malloc(a1, a3 + 1);
      v13 = a3;
      png_crc_read((_DWORD *)a1, *(unsigned __int8 **)(a1 + 680), a3);
      if ( png_crc_finish(a1, v10) )
      {
        result = png_free(a1, *(void **)(a1 + 680));
        *(_DWORD *)(a1 + 680) = 0;
      }
      else
      {
        *(_BYTE *)(*(_DWORD *)(a1 + 680) + v13) = 0;
        for ( i = *(unsigned __int8 **)(a1 + 680); *i; ++i )
          ;
        if ( (unsigned int)++i < *(_DWORD *)(a1 + 680) + v13 - 1 )
        {
          v9 = *i++;
          if ( v9 )
          {
            png_warning(a1, "Ignoring nonzero compression type in iCCP chunk");
            v9 = 0;
          }
          count = (unsigned int)&i[-*(_DWORD *)(a1 + 680)];
          png_decompress_chunk(a1, v9, v13, count, &v11);
          v12 = v11 - count;
          if ( count <= v11 && v12 >= 4 )
          {
            v7 = (unsigned int *)(count + *(_DWORD *)(a1 + 680));
            size = _byteswap_ulong(*v7);
            if ( size < v12 )
              v12 = size;
            if ( size <= v12 )
            {
              png_set_iCCP(a1, a2, *(char **)(a1 + 680), v9, (unsigned __int8 *)(count + *(_DWORD *)(a1 + 680)), size);
              png_free(a1, *(void **)(a1 + 680));
              result = a1;
              *(_DWORD *)(a1 + 680) = 0;
            }
            else
            {
              png_free(a1, *(void **)(a1 + 680));
              *(_DWORD *)(a1 + 680) = 0;
              png_warning_parameter_unsigned((int)v4, 1, 1, size);
              png_warning_parameter_unsigned((int)v4, 2, 1, v12);
              return png_formatted_warning(
                       a1,
                       (int)v4,
                       "Ignoring iCCP chunk with declared size = @1 and actual length = @2");
            }
          }
          else
          {
            png_free(a1, *(void **)(a1 + 680));
            *(_DWORD *)(a1 + 680) = 0;
            return png_warning(a1, "Profile size field missing from iCCP chunk");
          }
        }
        else
        {
          png_free(a1, *(void **)(a1 + 680));
          *(_DWORD *)(a1 + 680) = 0;
          return png_warning(a1, "Malformed iCCP chunk");
        }
      }
    }
  }
  return result;
}
