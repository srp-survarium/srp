void __cdecl png_set_unknown_chunks(int a1, int a2, int a3, int a4)
{
  unsigned __int8 *src; // [esp+0h] [ebp-10h]
  unsigned __int8 *v5; // [esp+4h] [ebp-Ch]
  unsigned __int8 *dst; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( a1 && a2 && a4 )
  {
    dst = (unsigned __int8 *)png_malloc_warn(a1, 20 * (a4 + *(_DWORD *)(a2 + 192)));
    if ( dst )
    {
      memcpy(dst, *(unsigned __int8 **)(a2 + 188), 20 * *(_DWORD *)(a2 + 192));
      png_free(a1, *(void **)(a2 + 188));
      *(_DWORD *)(a2 + 188) = 0;
      for ( i = 0; i < a4; ++i )
      {
        v5 = &dst[20 * *(_DWORD *)(a2 + 192) + 20 * i];
        src = (unsigned __int8 *)(a3 + 20 * i);
        memcpy(v5, src, 5u);
        v5[4] = 0;
        *((_DWORD *)v5 + 3) = *((_DWORD *)src + 3);
        v5[16] = *(_DWORD *)(a1 + 108);
        if ( *((_DWORD *)src + 3) )
        {
          *((_DWORD *)v5 + 2) = png_malloc_warn(a1, *((_DWORD *)src + 3));
          if ( *((_DWORD *)v5 + 2) )
          {
            memcpy(*((unsigned __int8 **)v5 + 2), *((unsigned __int8 **)src + 2), *((_DWORD *)src + 3));
          }
          else
          {
            png_warning(a1, "Out of memory while processing unknown chunk");
            *((_DWORD *)v5 + 3) = 0;
          }
        }
        else
        {
          *((_DWORD *)v5 + 2) = 0;
        }
      }
      *(_DWORD *)(a2 + 188) = dst;
      *(_DWORD *)(a2 + 192) += a4;
      *(_DWORD *)(a2 + 184) |= 0x200u;
    }
    else
    {
      png_warning(a1, "Out of memory while processing unknown chunk");
    }
  }
}
