void __cdecl fill_log_string(
        vostok::buffer_string *dest,
        char *const message_start,
        char *const message_end,
        vostok::logging::path_parts *path,
        vostok::logging::verbosity verbosity,
        const vostok::logging::log_format *format)
{
  const char *v6; // eax
  const char *v7; // eax
  char *i; // [esp+Ch] [ebp-102Ch]
  int j; // [esp+10h] [ebp-1028h]
  _DWORD v10[8]; // [esp+14h] [ebp-1024h]
  char v11; // [esp+37h] [ebp-1001h]
  char v12[1024]; // [esp+38h] [ebp-1000h] BYREF
  char buffer[512]; // [esp+438h] [ebp-C00h] BYREF
  char v14[512]; // [esp+638h] [ebp-A00h] BYREF
  char desta[512]; // [esp+838h] [ebp-800h] BYREF
  char destination[512]; // [esp+A38h] [ebp-600h] BYREF

  v11 = *message_end;
  *message_end = 0;
  if ( format->enabled[2] )
  {
    vostok::logging::path_parts::concat2buffer(path, (char (*)[512])buffer);
    for ( i = buffer; *i; ++i )
    {
      if ( *i == 47 )
        *i = 58;
    }
  }
  if ( format->enabled[1] )
  {
    v6 = vostok::threading::current_thread_logging_name();
    vostok::sprintf<512>((char (*)[512])&v12[512], "%-8s", v6);
  }
  if ( format->enabled[4] )
    vostok::logging::fill_local_time((char (*)[512])desta, 1);
  if ( format->enabled[3] )
    vostok::logging::fill_local_time((char (*)[512])v14, 0);
  if ( format->enabled[5] )
  {
    v7 = vostok::logging::verbosity_to_string(verbosity);
    vostok::strings::copy<512>((char (*)[512])destination, v7);
  }
  for ( j = 0; j < 8; ++j )
    v10[j] = &v12[512 * j];
  v10[6] = message_start;
  vostok::buffer_string::assignf(
    dest,
    format->string,
    v10[format->indexes[0]],
    v10[format->indexes[1]],
    v10[format->indexes[2]],
    v10[format->indexes[3]],
    v10[format->indexes[4]],
    v10[format->indexes[5]]);
  *message_end = v11;
}
