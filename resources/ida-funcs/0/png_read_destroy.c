void __cdecl png_read_destroy(unsigned __int8 *src, int a2, int a3)
{
  int v3; // [esp+0h] [ebp-54h]
  __m128i dst[4]; // [esp+4h] [ebp-50h] BYREF
  int v5; // [esp+48h] [ebp-Ch]
  int v6; // [esp+4Ch] [ebp-8h]
  int v7; // [esp+50h] [ebp-4h]

  if ( a2 )
    png_info_destroy((int)src, a2);
  if ( a3 )
    png_info_destroy((int)src, a3);
  png_destroy_gamma_table((int)src);
  png_free((int)src, *((void **)src + 44));
  png_free((int)src, *((void **)src + 155));
  png_free((int)src, *((void **)src + 172));
  png_free((int)src, *((void **)src + 170));
  png_free((int)src, *((void **)src + 126));
  png_free((int)src, *((void **)src + 127));
  if ( (*((_DWORD *)src + 143) & 0x1000) != 0 )
    png_zfree((int)src, *((void **)src + 74));
  *((_DWORD *)src + 143) &= ~0x1000u;
  if ( (*((_DWORD *)src + 143) & 0x2000) != 0 )
    png_free((int)src, *((void **)src + 105));
  *((_DWORD *)src + 143) &= ~0x2000u;
  if ( (*((_DWORD *)src + 143) & 8) != 0 )
    png_free((int)src, *((void **)src + 128));
  *((_DWORD *)src + 143) &= ~8u;
  inflateEnd((z_stream_s *)(src + 120));
  png_free((int)src, *((void **)src + 115));
  memcpy((int)dst, (const __m128i *)src, sizeof(dst));
  v6 = *((_DWORD *)src + 17);
  v3 = *((_DWORD *)src + 18);
  v7 = *((_DWORD *)src + 19);
  v5 = *((_DWORD *)src + 154);
  memset((int)src, 0, 708);
  *((_DWORD *)src + 17) = v6;
  *((_DWORD *)src + 18) = v3;
  *((_DWORD *)src + 19) = v7;
  *((_DWORD *)src + 154) = v5;
  memcpy((int)src, dst, 0x40u);
}
