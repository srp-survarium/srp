int __thiscall survarium::_dynamic_initializer_for__cc_icon_name_offset__(
        vostok::console_commands::console_command *this)
{
  _BYTE v2[12]; // [esp+0h] [ebp-18h]

  *(float *)v2 = s_spot_max_distance;
  *(float *)&v2[4] = s_spot_max_distance;
  *(float *)&v2[8] = s_spot_max_distance;
  vostok::console_commands::console_command::console_command(
    this,
    (int)&cc_icon_name_offset,
    "icon_name_pos",
    1,
    command_type_engine_internal,
    execution_filter_general);
  cc_icon_name_offset.m_value = &survarium::s_icon_name_offset;
  cc_icon_name_offset.m_min.x = FLOAT_N100_0;
  cc_icon_name_offset.m_min.y = FLOAT_N100_0;
  cc_icon_name_offset.m_min.z = FLOAT_N100_0;
  cc_icon_name_offset.m_max = *(vostok::math::float3 *)v2;
  cc_icon_name_offset.m_need_args = 1;
  cc_icon_name_offset.__vftable = (vostok::console_commands::cc_float3_vtbl *)&vostok::console_commands::cc_float3::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_icon_name_offset__);
}
