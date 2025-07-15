void __cdecl jcopy_block_row(const __m128i *src, unsigned __int8 *dst, int a3)
{
  memcpy((int)dst, src, a3 << 7);
}
