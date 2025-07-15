void __thiscall vostok::strings::finalize(vostok::strings::shared::manager *ecx0)
{
  vostok::strings::shared::manager::~manager(ecx0, s_manager.m_variable);
  s_manager.m_initialized = 0;
}
