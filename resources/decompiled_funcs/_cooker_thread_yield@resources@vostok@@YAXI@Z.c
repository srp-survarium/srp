void __thiscall vostok::resources::cooker_thread_yield(vostok::threading::event *this)
{
  vostok::threading::event::wait(
    this,
    (unsigned int)&dword_203E0 + (unsigned int)vostok::resources::g_resources_manager.m_variable);
}
