void __userpurge vostok::input::receiver::mouse::mouse(
        vostok::input::receiver::mouse *this@<esi>,
        IDirectInput8A *direct_input@<eax>,
        vostok::input::world *input_world@<ecx>,
        HWND__ *window_handle)
{
  IDirectInputDevice8A **p_m_device; // edi
  const char *CommandLineA; // eax
  const char *v6; // eax
  bool v7; // zf
  int v8; // eax

  p_m_device = &this->m_device;
  this->__vftable = (vostok::input::receiver::mouse_vtbl *)&vostok::input::receiver::mouse::`vftable';
  this->m_window_handle = window_handle;
  this->m_device = 0;
  this->m_world = input_world;
  direct_input->CreateDevice(direct_input, &GUID_SysMouse, &this->m_device, 0);
  (*p_m_device)->SetDataFormat(*p_m_device, &c_dfDIMouse2);
  if ( vostok::debug::is_debugger_present() )
  {
    if ( !s_initialized_5 )
    {
      CommandLineA = GetCommandLineA();
      strcpy_s(
        (char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2] + 4,
        0x200u,
        CommandLineA);
      s_initialized_5 = 1;
    }
    if ( !vostok::command_line::key_is_set_impl(
            (const char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2]
          + 4,
            "mouse_lock") )
      goto LABEL_8;
  }
  if ( !s_initialized_5 )
  {
    v6 = GetCommandLineA();
    strcpy_s(
      (char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2] + 4,
      0x200u,
      v6);
    s_initialized_5 = 1;
  }
  v7 = !vostok::command_line::key_is_set_impl(
          (const char *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[2]
        + 4,
          "mouse_unlock");
  v8 = 1;
  if ( !v7 )
LABEL_8:
    v8 = 2;
  (*p_m_device)->SetCooperativeLevel(*p_m_device, window_handle, v8 | 4);
  *(_QWORD *)&this->m_current_state.x = 0;
  *(_QWORD *)&this->m_current_state.z = 0;
  *(_QWORD *)&this->m_previous_state.x = 0;
  *(_QWORD *)&this->m_previous_state.z = 0;
}
