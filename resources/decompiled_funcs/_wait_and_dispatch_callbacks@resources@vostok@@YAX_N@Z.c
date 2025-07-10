void __thiscall vostok::resources::wait_and_dispatch_callbacks(vostok::resources::resources_manager *this)
{
  vostok::resources::resources_manager::wait_and_dispatch_callbacks(
    this,
    (bool)vostok::resources::g_resources_manager.m_variable,
    1);
}
