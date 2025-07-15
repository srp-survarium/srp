void __cdecl _initp_misc_initcrit(int (__stdcall *enull)(_RTL_CRITICAL_SECTION *, unsigned int))
{
  _pfnInitCritSecAndSpinCount = enull;
}
