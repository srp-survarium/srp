void __noreturn _purecall()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_decode_pointer(__pPurecall);
  if ( v0 )
    v0();
  _NMSG_WRITE(25);
  _set_abort_behavior(0, 1u);
  abort();
}
