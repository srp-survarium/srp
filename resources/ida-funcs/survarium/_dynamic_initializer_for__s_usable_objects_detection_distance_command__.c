int __thiscall survarium::_dynamic_initializer_for__s_usable_objects_detection_distance_command__(
        vostok::console_commands::console_command *this)
{
  vostok::console_commands::console_command::console_command(
    this,
    (int)&s_usable_objects_detection_distance_command,
    "usable_objects_detection_distance",
    1,
    command_type_engine_internal,
    execution_filter_general);
  s_usable_objects_detection_distance_command.m_min = FLOAT_0_1;
  s_usable_objects_detection_distance_command.m_value = &survarium::s_usable_objects_detection_distance;
  s_usable_objects_detection_distance_command.m_max = FLOAT_5_0;
  s_usable_objects_detection_distance_command.m_need_args = 1;
  s_usable_objects_detection_distance_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&vostok::console_commands::cc_float::`vftable';
  return atexit(survarium::_dynamic_atexit_destructor_for__s_usable_objects_detection_distance_command__);
}
