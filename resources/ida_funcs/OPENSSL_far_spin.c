int OPENSSL_far_spin()
{
  __int16 v0; // kr00_2
  int i; // eax

  v0 = __getcallerseflags();
  if ( (v0 & 0x200) != 0 )
  {
    for ( i = 0; ; ++i )
      ;
  }
  return 0;
}
