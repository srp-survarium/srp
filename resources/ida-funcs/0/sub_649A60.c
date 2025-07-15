int __cdecl sub_649A60(int a1, _BYTE *a2)
{
  return dword_72DD78[8 * (unsigned __int8)byte_72E278[16 * (*a2 & 0xF) + (((int)(unsigned __int8)a2[1] >> 2) & 0xF)]
                    + 2 * (a2[1] & 3)
                    + (((int)(unsigned __int8)a2[2] >> 5) & 1)]
       & (1 << (a2[2] & 0x1F));
}
