vostok::console_commands::cc_bool *__thiscall vostok::console_commands::console_command::`scalar deleting destructor'(
        vostok::console_commands::cc_bool *this,
        char a2)
{
  vostok::console_commands::console_command::~console_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
