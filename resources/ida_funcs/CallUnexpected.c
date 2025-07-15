void __cdecl __noreturn CallUnexpected()
{
  if ( _getptd()->_curexcspec )
    _inconsistency();
  unexpected();
}
