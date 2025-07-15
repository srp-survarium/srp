void __cdecl __noreturn unexpected()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_unexpected;
  if ( v0 )
    v0();
  terminate();
}
