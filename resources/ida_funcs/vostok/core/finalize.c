void __thiscall vostok::core::finalize(vostok::tasks::thread_pool *this)
{
  vostok::command_line::key *v1; // ecx
  vostok::core::engine_vtbl *v2; // edx
  int (__thiscall *get_exit_code)(struct vostok::core::engine *); // eax
  int v4; // eax
  vostok::threading *v5; // [esp+0h] [ebp-210h]
  vostok::memory *v6; // [esp+0h] [ebp-210h]
  vostok::fixed_string<512> message; // [esp+4h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+210h] [ebp+0h] BYREF

  vostok::tasks::thread_pool::~thread_pool(this, (volatile int *)s_thread_pool.m_variable);
  s_thread_pool.m_initialized = 0;
  vostok::testing::finalize();
  vostok::strings::shared::manager::~manager(s_manager.m_variable);
  s_manager.m_initialized = 0;
  vostok::threading::finalize(v5);
  vostok::memory::finalize(v6);
  vostok::fs_new::synchronous_device_interface::~synchronous_device_interface(s_core_synchronous_device.m_variable);
  s_core_synchronous_device.m_initialized = 0;
  vostok::debug::finalize();
  s_initialized_1 = 0;
  if ( vostok::testing::run_tests_command_line(v1) )
  {
    message.m_max_end = (char *)&retaddr;
    message.m_begin = message.m_buffer;
    v2 = s_engine_0->__vftable;
    message.m_end = message.m_buffer;
    get_exit_code = v2->get_exit_code;
    message.m_buffer[0] = 0;
    v4 = get_exit_code(s_engine_0);
    vostok::buffer_string::assignf(&message, "program exit code: %d", v4);
    vostok::debug::notify_xbox_debugger();
  }
}
