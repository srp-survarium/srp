int __thiscall survarium::_dynamic_initializer_for__s_first_person_animations_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_first_person_animations_command,
    "first_person_animations",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_first_person_animations_command.m_value = &s_first_person_animations_only;
  s_first_person_animations_command.m_min = 0;
  s_first_person_animations_command.m_max = 1;
  s_first_person_animations_command.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_first_person_animations_command.m_need_args = 1;
  return atexit(survarium::_dynamic_atexit_destructor_for__s_first_person_animations_command__);
}
