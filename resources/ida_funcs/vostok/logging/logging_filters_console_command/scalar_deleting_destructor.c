vostok::logging::logging_filters_console_command *__thiscall vostok::logging::logging_filters_console_command::`scalar deleting destructor'(
        vostok::logging::logging_filters_console_command *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)(&this->gap40 + 1));
  vostok::console_commands::console_command::~console_command(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
