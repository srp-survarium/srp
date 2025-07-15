void __cdecl vostok::resources::finalize_thread_usage(bool calling_from_main_thread)
{
  vostok::resources::resources_manager::wait_and_dispatch_callbacks(
    vostok::resources::g_resources_manager.m_variable,
    (bool)vostok::resources::g_resources_manager.m_variable,
    calling_from_main_thread);
}
