char *__thiscall vostok::core::user_name(void *this)
{
  unsigned int buffer_size; // [esp+0h] [ebp-4h] BYREF

  buffer_size = (unsigned int)this;
  if ( !s_initialized_6 )
  {
    buffer_size = 512;
    GetUserNameA(s_user, &buffer_size);
    s_initialized_6 = 1;
  }
  return s_user;
}
