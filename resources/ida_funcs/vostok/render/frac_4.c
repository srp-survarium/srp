__m128 __cdecl vostok::render::frac_4(float v)
{
  signed int v1; // eax
  __int128 v2; // xmm1

  v1 = vostok::math::floor(v);
  v2 = LODWORD(v) & 0x7FFFFFFF;
  *(float *)&v2 = COERCE_FLOAT(LODWORD(v) & 0x7FFFFFFF) - (float)((v1 >> 31) ^ ((v1 >> 31) + v1));
  return (__m128)v2;
}
