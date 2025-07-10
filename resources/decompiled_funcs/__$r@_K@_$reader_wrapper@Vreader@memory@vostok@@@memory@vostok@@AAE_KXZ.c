unsigned int __thiscall vostok::memory::reader_wrapper<vostok::memory::reader>::r<unsigned __int64>(
        vostok::memory::reader_wrapper<vostok::memory::reader> *this)
{
  unsigned int v1; // xmm0_4

  v1 = _mm_loadl_epi64((const __m128i *)*(_DWORD *)&this[4]).m128i_u32[0];
  *(_DWORD *)&this[4] += 8;
  return v1;
}
