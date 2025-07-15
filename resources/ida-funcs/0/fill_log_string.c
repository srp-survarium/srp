void __usercall fill_log_string(
        const vostok::logging::log_format *format@<esi>,
        char *const dest,
        unsigned int dest_chars_count,
        char *const message_start,
        char *const message_end,
        vostok::logging::path_parts *path,
        vostok::logging::verbosity verbosity)
{
  char v8; // al
  char *i; // eax
  const char *v10; // eax
  char *v11; // eax
  int v12; // ecx
  char *v13; // eax
  char v14[1024]; // [esp+4h] [ebp-1020h] BYREF
  char buffer[512]; // [esp+404h] [ebp-C20h] BYREF
  char v16[512]; // [esp+604h] [ebp-A20h] BYREF
  char desta[512]; // [esp+804h] [ebp-820h] BYREF
  char v18[3][512]; // [esp+A04h] [ebp-620h] BYREF
  _DWORD v19[8]; // [esp+1004h] [ebp-20h]
  char v20; // [esp+103Bh] [ebp+17h]

  v8 = *message_end;
  *message_end = 0;
  v20 = v8;
  if ( format->enabled[2] )
  {
    vostok::logging::path_parts::concat2buffer((char (*)[512])buffer, path);
    for ( i = buffer; *i; ++i )
    {
      if ( *i == 47 )
        *i = 58;
    }
  }
  if ( format->enabled[1] )
  {
    v10 = vostok::threading::current_thread_logging_name();
    vostok::sprintf<512>((char (*)[512])&v14[512], "%-8s", v10);
  }
  if ( format->enabled[4] )
    vostok::logging::fill_local_time((char (*)[512])desta, 1);
  if ( format->enabled[3] )
    vostok::logging::fill_local_time((char (*)[512])v16, 0);
  if ( format->enabled[5] )
  {
    if ( verbosity == error )
    {
      v11 = "ERROR";
    }
    else if ( verbosity == warning )
    {
      v11 = "Warning";
    }
    else
    {
      v11 = (char *)vostok::logging::verbosity_name(verbosity);
    }
    vostok::strings::copy<512>(v18, v11);
  }
  v12 = 0;
  v13 = v14;
  do
  {
    v19[v12++] = v13;
    v13 += 512;
  }
  while ( v12 < 8 );
  v19[6] = message_start;
  vostok::sprintf(
    dest,
    dest_chars_count,
    format->string,
    v19[format->indexes[0]],
    v19[format->indexes[1]],
    v19[format->indexes[2]],
    v19[format->indexes[3]],
    v19[format->indexes[4]],
    v19[format->indexes[5]]);
  *message_end = v20;
}
