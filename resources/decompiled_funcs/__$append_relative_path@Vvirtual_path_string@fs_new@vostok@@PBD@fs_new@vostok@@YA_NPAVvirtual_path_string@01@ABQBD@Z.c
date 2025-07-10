char __cdecl vostok::fs_new::append_relative_path<vostok::fs_new::virtual_path_string,char const *>(
        vostok::fs_new::native_path_string *in_out_path,
        const char **in_relative_path)
{
  const char *v2; // eax
  char s; // [esp+17h] [ebp-11h] BYREF
  unsigned int last_slash; // [esp+18h] [ebp-10h]
  char up_token[4]; // [esp+1Ch] [ebp-Ch] BYREF
  unsigned int up_token_length; // [esp+20h] [ebp-8h]
  const char *relative_path; // [esp+24h] [ebp-4h] BYREF

  strcpy(up_token, "../");
  up_token_length = vostok::strings::length(up_token);
  relative_path = *in_relative_path;
  while ( 1 )
  {
    strstr((unsigned __int8 *)relative_path, (unsigned __int8 *)up_token);
    if ( v2 != relative_path )
      break;
    relative_path += up_token_length;
    last_slash = vostok::fs_new::path_string_impl::rfind(in_out_path, 47);
    if ( last_slash == -1 )
    {
      if ( !vostok::fs_new::path_string_impl::length(in_out_path) )
        return 0;
      vostok::fs_new::path_string_impl::set_length(in_out_path, 0);
    }
    else
    {
      vostok::fs_new::path_string_impl::set_length(in_out_path, last_slash);
    }
  }
  if ( *relative_path )
  {
    if ( vostok::fs_new::path_string_impl::length(in_out_path) )
    {
      s = 47;
      vostok::fs_new::path_string_impl::operator+=<char>(in_out_path, &s);
    }
    vostok::fs_new::path_string_impl::append_with_conversion<char const *>(in_out_path, &relative_path);
  }
  return 1;
}
