unsigned int __cdecl vostok::math::ceil(float value)
{
  signed int v1; // esi

  v1 = LODWORD(value) & ~(~(LODWORD(value) - 1) & 0x80000000);
  return -(~((v1 - 1) >> 31)
         ^ ((158 - (unsigned __int8)(v1 >> 23) - 96 + 64) >> 31)
         & (((v1 | 0xFF800000) << 8 >> (-98 - (v1 >> 23)))
          - (~((v1 - 1) >> 31) & ((v1 & (((1 << (-98 - (v1 >> 23) - 96)) - 1) >> 8)) == 0))));
}
