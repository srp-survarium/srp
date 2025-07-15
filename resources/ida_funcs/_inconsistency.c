void __cdecl __noreturn _inconsistency()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_decode_pointer(__pInconsistency);
  if ( v0 )
    v0();
  terminate();
}
