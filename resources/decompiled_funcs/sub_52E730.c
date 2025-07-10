BOOL __cdecl sub_52E730(int a1, unsigned __int8 *a2)
{
  return *a2 < 0xC2u || (a2[1] & 0x80) == 0 || (a2[1] & 0xC0) == 0xC0;
}
