void __cdecl png_set_iCCP(int a1, int a2, char *lpString, char a4, unsigned __int8 *src, unsigned int size)
{
  unsigned __int8 *dst; // [esp+0h] [ebp-Ch]
  unsigned __int8 *v7; // [esp+4h] [ebp-8h]
  int count; // [esp+8h] [ebp-4h]

  if ( a1 && a2 && lpString && src )
  {
    count = lstrlenA(lpString) + 1;
    dst = (unsigned __int8 *)png_malloc_warn(a1, count);
    if ( dst )
    {
      memcpy(dst, (unsigned __int8 *)lpString, count);
      v7 = (unsigned __int8 *)png_malloc_warn(a1, size);
      if ( v7 )
      {
        memcpy(v7, src, size);
        png_free_data(a1, a2, 16, 0);
        *(_DWORD *)(a2 + 204) = size;
        *(_DWORD *)(a2 + 196) = dst;
        *(_DWORD *)(a2 + 200) = v7;
        *(_BYTE *)(a2 + 208) = a4;
        *(_DWORD *)(a2 + 184) |= 0x10u;
        *(_DWORD *)(a2 + 8) |= 0x1000u;
      }
      else
      {
        png_free(a1, dst);
        png_warning(a1, "Insufficient memory to process iCCP profile");
      }
    }
    else
    {
      png_warning(a1, "Insufficient memory to process iCCP chunk");
    }
  }
}
