char __cdecl vostok::network_core::get_connection_info_from_string(
        char *buffer,
        char *dest_host,
        unsigned __int16 *dest_port)
{
  const char *v3; // eax
  int result; // [esp+4h] [ebp-Ch]
  unsigned int port; // [esp+8h] [ebp-8h] BYREF
  const char *delim; // [esp+Ch] [ebp-4h]

  strchr(buffer, 0x3Au);
  delim = v3;
  if ( !v3 )
    return 0;
  strncpy_s(dest_host, 0x40u, buffer, delim - buffer);
  result = sscanf_s((char *)delim + 1, "%d", &port);
  if ( !vostok::strings::length(dest_host) || result != 1 )
    return 0;
  *dest_port = port;
  return 1;
}
