unsigned __int8 *__cdecl png_decompress_chunk(int a1, int a2, unsigned int a3, unsigned int count, _DWORD *a5)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v6; // [esp+0h] [ebp-114h]
  _BYTE v7[256]; // [esp+4h] [ebp-110h] BYREF
  int v8; // [esp+108h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+10Ch] [ebp-8h]
  unsigned int v10; // [esp+110h] [ebp-4h]

  if ( count <= a3 )
  {
    if ( a2 )
    {
      png_warning_parameter_signed((int)v7, 1, 1, a2);
      png_formatted_warning(a1, (int)v7, "Unknown compression type @1");
    }
    else
    {
      v10 = sub_364840(a1, count + *(_DWORD *)(a1 + 680), a3 - count, 0, 0);
      if ( count >= 0xFFFFFFFE || v10 >= -2 - count || *(_DWORD *)(a1 + 652) && v10 + count >= *(_DWORD *)(a1 + 652) - 1 )
      {
        png_warning(a1, "Exceeded size limit while expanding chunk");
      }
      else if ( v10 )
      {
        v8 = 0;
        dst = (unsigned __int8 *)png_malloc_warn(a1, count + v10 + 1);
        if ( dst )
        {
          memcpy(dst, *(unsigned __int8 **)(a1 + 680), count);
          v8 = sub_364840(a1, count + *(_DWORD *)(a1 + 680), a3 - count, &dst[count], v10);
          dst[v10 + count] = 0;
          if ( v8 == v10 )
          {
            png_free(a1, *(void **)(a1 + 680));
            result = dst;
            *(_DWORD *)(a1 + 680) = dst;
            *a5 = v10 + count;
            return result;
          }
          png_warning(a1, "png_inflate logic error");
          png_free(a1, dst);
        }
        else
        {
          png_warning(a1, "Not enough memory to decompress chunk");
        }
      }
    }
  }
  else
  {
    png_warning(a1, "invalid chunklength");
    count = 0;
  }
  result = (unsigned __int8 *)png_malloc_warn(a1, count + 1);
  v6 = result;
  if ( result )
  {
    if ( count )
      memcpy(result, *(unsigned __int8 **)(a1 + 680), count);
    png_free(a1, *(void **)(a1 + 680));
    *(_DWORD *)(a1 + 680) = v6;
    result = (unsigned __int8 *)count;
    *(_BYTE *)(*(_DWORD *)(a1 + 680) + count) = 0;
  }
  *a5 = count;
  return result;
}
