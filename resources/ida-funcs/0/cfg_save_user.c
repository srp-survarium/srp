void __thiscall cfg_save_user(void *this)
{
  vostok::console_commands::save(command_type_user_specific, (int)this);
}
