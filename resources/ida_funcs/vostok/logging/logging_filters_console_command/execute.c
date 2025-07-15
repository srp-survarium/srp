void __thiscall vostok::logging::logging_filters_console_command::execute(
        vostok::logging::logging_filters_console_command *this,
        char *args)
{
  vostok::console_commands::console_command *v2; // ecx
  vostok::logging::verbosity t_verb; // [esp+38h] [ebp-40Ch]
  char initiator[512]; // [esp+3Ch] [ebp-408h] BYREF
  const char *s; // [esp+240h] [ebp-204h]
  char verbosity[512]; // [esp+244h] [ebp-200h] BYREF

  s = vostok::strings::get_token(args, initiator, 0x200u, 32);
  if ( s )
  {
    vostok::strings::get_token((char *)s, verbosity, 0x200u, 32);
  }
  else
  {
    if ( vostok::strings::equal(initiator, (const char *)&buf) )
    {
      vostok::console_commands::console_command::on_invalid_syntax(v2, (const char **)this, args);
      return;
    }
    vostok::strings::copy<512>((char (*)[512])verbosity, initiator);
    vostok::strings::copy<512>((char (*)[512])initiator, (const char *)&buf);
  }
  t_verb = vostok::logging::string_to_verbosity(verbosity);
  if ( t_verb )
    vostok::logging::push_filter(this->m_filter_tree, (vostok::fixed_string<16> *)initiator, t_verb, 0xFFFFFFFF);
  else
    vostok::console_commands::console_command::on_invalid_syntax(
      (vostok::console_commands::console_command *)args,
      (const char **)this,
      args);
}
