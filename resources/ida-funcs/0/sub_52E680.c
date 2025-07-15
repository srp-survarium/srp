int __cdecl sub_52E680(int a1, unsigned __int8 *a2)
{
  return dword_88A300[8 * (unsigned __int8)byte_88A800[((int)*a2 >> 2) & 7] + 2 * (*a2 & 3) + (((int)a2[1] >> 5) & 1)]
       & (1 << (a2[1] & 0x1F));
}
