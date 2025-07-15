void __thiscall vostok::console_commands::logging_filters_console_command::execute(
        vostok::console_commands::logging_filters_console_command *this,
        char *args)
{
  char *token; // eax
  int v3; // ecx
  const char *v4; // edi
  char *v5; // esi
  bool v6; // zf
  vostok::logging::verbosity v7; // eax
  vostok::logging::filter_tree *v8; // [esp-4h] [ebp-414h]
  unsigned int v9; // [esp+0h] [ebp-410h]
  char result[512]; // [esp+10h] [ebp-400h] BYREF
  char _Dst[512]; // [esp+210h] [ebp-200h] BYREF

  token = (char *)vostok::strings::get_token(0x20u, args, result, 0x200u);
  if ( token )
  {
    vostok::strings::get_token(0x20u, token, _Dst, 0x200u);
  }
  else
  {
    v3 = 1;
    v4 = uri;
    v5 = result;
    v6 = 1;
    do
    {
      if ( !v3 )
        break;
      v6 = *v5++ == *v4++;
      --v3;
    }
    while ( v6 );
    if ( v6 )
      goto LABEL_6;
    strcpy_s(_Dst, 0x200u, result);
    strcpy_s(result, 0x200u, uri);
  }
  v7 = vostok::logging::string_to_verbosity(_Dst);
  v3 = (int)v8;
  if ( v7 == invalid )
  {
LABEL_6:
    vostok::console_commands::console_command::on_invalid_syntax(
      (vostok::console_commands::console_command *)v3,
      (void (__thiscall ***)(const char **, char *))this,
      args);
    return;
  }
  vostok::logging::filter_tree::push_filter(v8, (int)this->m_filter_tree, result, v7, v9);
}
