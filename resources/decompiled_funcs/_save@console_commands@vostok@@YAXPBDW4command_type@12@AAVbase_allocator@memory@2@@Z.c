void __usercall vostok::console_commands::save(const vostok::console_commands::command_type command_type@<eax>)
{
  const char *v1; // eax

  if ( command_type == command_type_user_specific )
  {
    v1 = s_engine_0->get_user_data_directory(s_engine_0);
    vostok::console_commands::save("user.cfg", v1);
  }
}
