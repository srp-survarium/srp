char *__cdecl vostok::core::application_name()
{
  int v0; // eax
  char Filename[512]; // [esp+4h] [ebp-200h] BYREF

  if ( !s_application_0[0] && GetModuleFileNameA(0, Filename, 0x200u) )
  {
    strrchr(Filename, 0x5Cu);
    if ( v0 )
      vostok::strings::copy<512>((char (*)[512])s_application_0, (char *)(v0 + 1));
    else
      strcpy_s(s_application_0, 0x200u, Filename);
  }
  return s_application_0;
}
