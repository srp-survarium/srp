int __thiscall survarium::_dynamic_initializer_for__cc_enemy_hit_mark_timeout_in_ms__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_enemy_hit_mark_timeout_in_ms,
    "enemy_hit_mark_timeout_in_ms",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_enemy_hit_mark_timeout_in_ms.m_min = 0;
  cc_enemy_hit_mark_timeout_in_ms.m_value = &s_enemy_hit_mark_timeout_in_ms;
  cc_enemy_hit_mark_timeout_in_ms.m_max = 5000;
  cc_enemy_hit_mark_timeout_in_ms.m_need_args = 1;
  cc_enemy_hit_mark_timeout_in_ms.__vftable = (vostok::console_commands::cc_u32_vtbl *)&vostok::console_commands::cc_u32::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_enemy_hit_mark_timeout_in_ms__);
}
