void __thiscall vostok::core::finalize_resources(vostok::resources::resources_manager *ecx0)
{
  vostok::resources::resources_manager::~resources_manager(ecx0);
  vostok::resources::g_resources_manager.m_initialized = 0;
}
