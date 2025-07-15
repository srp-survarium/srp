int survarium::_dynamic_initializer_for__cc_warmup_camera_position__()
{
  vostok::math::float3 v1; // [esp+Ch] [ebp-Ch]

  *(_QWORD *)&v1.x = 0x447A0000447A0000LL;
  v1.z = 1000.0;
  cc_warmup_camera_position.m_prev = vostok::console_commands::s_console_command_root;
  if ( vostok::console_commands::s_console_command_root )
    vostok::console_commands::s_console_command_root->m_next = &cc_warmup_camera_position;
  vostok::console_commands::s_console_command_root = &cc_warmup_camera_position;
  *(_QWORD *)&cc_warmup_camera_position.m_min.x = 0xC47A0000C47A0000uLL;
  cc_warmup_camera_position.m_value = &s_warmup_camera_position;
  cc_warmup_camera_position.m_min.z = -1000.0;
  cc_warmup_camera_position.m_max = v1;
  cc_warmup_camera_position.m_need_args = 1;
  cc_warmup_camera_position.__vftable = (vostok::console_commands::cc_float3_vtbl *)stru_95AF78.m_key_bindings[53].m_keyboard;
  return atexit(survarium::_dynamic_atexit_destructor_for__cc_warmup_camera_position__);
}
