int __cdecl _ms_p5_mp_test_fdiv()
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *IsProcessorFeaturePresent)(DWORD); // eax

  ModuleHandleA = GetModuleHandleA(&stru_984D24.m_working_macro_list.m_buffer[1].m_store[392]);
  if ( ModuleHandleA
    && (IsProcessorFeaturePresent = (BOOL (__stdcall *)(DWORD))GetProcAddress(
                                                                 ModuleHandleA,
                                                                 "IsProcessorFeaturePresent")) != 0 )
  {
    return IsProcessorFeaturePresent(0);
  }
  else
  {
    return _ms_p5_test_fdiv();
  }
}
