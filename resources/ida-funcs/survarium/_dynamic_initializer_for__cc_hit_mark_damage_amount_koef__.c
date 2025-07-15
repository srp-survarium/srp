int __thiscall survarium::_dynamic_initializer_for__cc_hit_mark_damage_amount_koef__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_hit_mark_damage_amount_koef,
    "hit_mark_damage_amount_koef",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_hit_mark_damage_amount_koef.m_min = FLOAT_0_1;
  cc_hit_mark_damage_amount_koef.m_value = &s_hit_mark_damage_amount_koef;
  cc_hit_mark_damage_amount_koef.m_max = FLOAT_10_0;
  cc_hit_mark_damage_amount_koef.m_need_args = 1;
  cc_hit_mark_damage_amount_koef.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_hit_mark_damage_amount_koef__);
}
