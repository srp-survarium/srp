int __thiscall vostok::render::_dynamic_initializer_for__s_use_one_material__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_use_one_material,
    "use_one_material",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_use_one_material.m_value = &s_use_one_material_value;
  s_use_one_material.m_min = 0;
  s_use_one_material.m_max = 1;
  s_use_one_material.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_use_one_material.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_use_one_material__);
}
