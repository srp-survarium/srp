void __cdecl cleanup1_LHASH_DOALL(_DWORD *arg)
{
  *(_DWORD *)(arg[1] + 8) = 0;
  *(_DWORD *)(arg[1] + 20) |= 0xDu;
}
