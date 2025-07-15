unsigned int __cdecl err_string_data_LHASH_HASH(_DWORD *arg)
{
  unsigned int v1; // ecx

  v1 = *arg ^ ((unsigned int)(*arg ^ (*arg >> 12)) >> 12) & 0xFFF;
  return v1 ^ (13 * (v1 % 0x13));
}
