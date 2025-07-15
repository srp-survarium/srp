void __usercall CRYPTO_lock(int a1@<edi>, int a2@<ebx>, int mode, int type, char *file, int line)
{
  CRYPTO_dynlock_value *dynlock_value; // eax

  if ( type >= 0 )
  {
    if ( locking_callback )
      locking_callback(mode, type, file, line);
  }
  else if ( dynlock_lock_callback )
  {
    dynlock_value = CRYPTO_get_dynlock_value(type);
    if ( !dynlock_value )
      OpenSSLDie(a1, type, a2, ".\\crypto\\cryptlib.c", 591, "pointer != NULL");
    dynlock_lock_callback(mode, dynlock_value, file, line);
    CRYPTO_destroy_dynlockid(type);
  }
}
