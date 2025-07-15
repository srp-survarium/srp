char *__cdecl vostok::core::user_name()
{
  unsigned int pcbBuffer; // [esp+4h] [ebp-4h] BYREF

  if ( !s_initialized_8 )
  {
    pcbBuffer = 512;
    GetUserNameA(s_user, &pcbBuffer);
    s_initialized_8 = 1;
  }
  return s_user;
}
