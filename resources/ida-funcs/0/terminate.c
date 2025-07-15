void __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 )
    v0();
  abort();
}
