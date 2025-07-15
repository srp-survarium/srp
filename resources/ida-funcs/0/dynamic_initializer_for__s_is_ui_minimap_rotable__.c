int __thiscall dynamic_initializer_for__s_is_ui_minimap_rotable__(vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_is_ui_minimap_rotable,
    "is_ui_minimap_fixed",
    1,
    command_type_user_specific,
    execution_filter_general);
  s_is_ui_minimap_rotable.m_value = &is_ui_minimap_fixed;
  s_is_ui_minimap_rotable.m_min = 0;
  s_is_ui_minimap_rotable.m_max = 1;
  s_is_ui_minimap_rotable.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_is_ui_minimap_rotable.m_need_args = 1;
  return atexit(dynamic_atexit_destructor_for__s_is_ui_minimap_rotable__);
}
