int __thiscall vostok::render::_dynamic_initializer_for__s_debug_use_skeletel_mesh_lods_cc__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_debug_use_skeletel_mesh_lods_cc,
    "r_debug_use_skeletel_mesh_lods",
    0,
    command_type_engine_internal,
    execution_filter_general);
  s_debug_use_skeletel_mesh_lods_cc.m_value = &s_debug_use_skeletel_mesh_lods;
  s_debug_use_skeletel_mesh_lods_cc.m_min = 0;
  s_debug_use_skeletel_mesh_lods_cc.m_max = 1;
  s_debug_use_skeletel_mesh_lods_cc.__vftable = (vostok::console_commands::cc_bool_vtbl *)&vostok::console_commands::cc_bool::`vftable';
  s_debug_use_skeletel_mesh_lods_cc.m_need_args = 1;
  return atexit(vostok::render::_dynamic_atexit_destructor_for__s_debug_use_skeletel_mesh_lods_cc__);
}
