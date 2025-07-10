int __cdecl __initmbctable()
{
  if ( !__mbctype_initialized )
  {
    _setmbcp(-3);
    __mbctype_initialized = 1;
  }
  return 0;
}
