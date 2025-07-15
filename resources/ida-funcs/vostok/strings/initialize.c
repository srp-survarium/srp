void __cdecl vostok::strings::initialize()
{
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&s_manager, 0x2710u);
  *(_DWORD *)&s_manager.m_static_memory[131100] = 0;
  memset((int)&s_manager.m_static_memory[28], 0, (unsigned int)&loc_20000);
  _InterlockedExchange(&s_manager.m_initialized, 1);
}
