unsigned int __cdecl err_string_data_LHASH_HASH(_DWORD *a1)
{
  unsigned int v1; // ecx

  v1 = *a1 ^ ((unsigned int)(*a1 ^ (*a1 >> 12)) >> 12) & 0xFFF;
  return v1 ^ (13 * (v1 % 0x13));
}
