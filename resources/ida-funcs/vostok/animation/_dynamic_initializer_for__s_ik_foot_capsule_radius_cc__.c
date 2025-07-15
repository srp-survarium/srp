int __thiscall vostok::animation::_dynamic_initializer_for__s_ik_foot_capsule_radius_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_ik_foot_capsule_radius_cc,
    "ik_foot_capsule_radius",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_ik_foot_capsule_radius_cc.m_min = FLOAT_0_0099999998;
  s_ik_foot_capsule_radius_cc.m_value = &s_ik_foot_capsule_radius_value;
  s_ik_foot_capsule_radius_cc.m_max = FLOAT_0_2;
  s_ik_foot_capsule_radius_cc.m_need_args = 1;
  s_ik_foot_capsule_radius_cc.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(vostok::animation::_dynamic_atexit_destructor_for__s_ik_foot_capsule_radius_cc__);
}
