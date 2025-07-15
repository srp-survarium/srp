unsigned int __thiscall bitreverse_0(void *x)
{
  unsigned int v1; // ecx
  unsigned int v2; // eax
  unsigned int v3; // ecx
  int v4; // edx

  v1 = __ROL4__(x, 16);
  v2 = (v1 << 8) ^ (unsigned int)&vostok::memory::s_CRT_arena[5508919] & ((v1 << 8) ^ (v1 >> 8));
  v3 = (16 * v2) ^ ((16 * v2) ^ (v2 >> 4)) & 0xF0F0F0F;
  v4 = 2 * ((4 * v3) ^ ((4 * v3) ^ (v3 >> 2)) & 0x33333333);
  return v4 ^ (v4 ^ (((4 * v3) ^ ((4 * v3) ^ (v3 >> 2)) & 0x33333333) >> 1)) & 0x55555555;
}
