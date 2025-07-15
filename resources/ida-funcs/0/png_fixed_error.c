void __cdecl __noreturn png_fixed_error(int a1, int a2)
{
  unsigned __int8 dst[92]; // [esp+0h] [ebp-60h] BYREF
  int v3; // [esp+5Ch] [ebp-4h]

  memcpy((int)dst, (const __m128i *)"fixed point overflow in ", 0x18u);
  v3 = 0;
  if ( a2 )
  {
    while ( v3 < 63 && *(_BYTE *)(v3 + a2) )
    {
      dst[v3 + 24] = *(_BYTE *)(v3 + a2);
      ++v3;
    }
  }
  dst[v3 + 24] = 0;
  png_error(a1, (int)dst);
}
