void __cdecl vostok::sound::role_to_string(XAUDIO2_DEVICE_ROLE role, vostok::fixed_string<2048> *dest)
{
  if ( role )
  {
    if ( (role & 1) != 0 )
      vostok::buffer_string::operator+=(dest, "DefaultConsoleDevice ");
    if ( (role & 2) != 0 )
      vostok::buffer_string::operator+=(dest, "DefaultMultimediaDevice ");
    if ( (role & 4) != 0 )
      vostok::buffer_string::operator+=(dest, "DefaultCommunicationsDevice ");
    if ( (role & 8) != 0 )
      vostok::buffer_string::operator+=(dest, "DefaultGameDevice ");
    if ( (role & 0xF) != 0 )
      vostok::buffer_string::operator+=(dest, "GlobalDefaultDevice ");
  }
  else
  {
    vostok::buffer_string::operator+=(dest, "NotDefaultDevice ");
  }
}
