vostok::logging::verbosity __cdecl vostok::logging::string_to_verbosity(char *in_verbosity)
{
  int v1; // esi
  _DWORD v3[6]; // [esp+4h] [ebp-18h]

  v3[0] = 1;
  v3[1] = 2;
  v3[2] = 3;
  v3[3] = 4;
  v3[4] = 5;
  v3[5] = 6;
  v1 = 0;
  while ( _stricmp((char *)vostok::logging::verbosity_to_str[v3[v1]], in_verbosity) )
  {
    if ( (unsigned int)++v1 >= 6 )
      return 0;
  }
  return v3[v1];
}
