BOOL _get_sse2_info()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int cpu_feature; // [esp+18h] [ebp-4h]

  cpu_feature = 0;
  v0 = __readeflags();
  __writeeflags(((unsigned int)&loc_1FFFFE + 2) ^ v0);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    cpu_feature = _EDX;
  }
  return ((unsigned int)&vostok::memory::s_CRT_arena[55905848] & cpu_feature) != 0 && has_osfxsr_set();
}
