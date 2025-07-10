int survarium::_dynamic_initializer_for__s_usable_objects_detection_distance_command__()
{
  s_usable_objects_detection_distance_command.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &s_usable_objects_detection_distance_command;
  s_usable_objects_detection_distance_command.m_min = FLOAT_0_1;
  vostok::console_commands::s_console_command_root = &s_usable_objects_detection_distance_command;
  s_usable_objects_detection_distance_command.m_value = &s_usable_objects_detection_distance;
  s_usable_objects_detection_distance_command.m_max = 5.0;
  s_usable_objects_detection_distance_command.m_need_args = 1;
  s_usable_objects_detection_distance_command.__vftable = (vostok::console_commands::cc_float_vtbl *)&stru_95AF78.m_key_bindings[48];
  return atexit(survarium::_dynamic_atexit_destructor_for__s_usable_objects_detection_distance_command__);
}
