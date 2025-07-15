void __cdecl vostok::render::register_texture_cook()
{
  int v0; // ecx
  int v1; // ecx

  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[4] = 0;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[8] = 7;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[12] = 1;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[16] = -1;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[20] = -4;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[24] = 8;
  *(_DWORD *)&s_texture_wrapper_cook.m_static_memory[28] = 0;
  *(_DWORD *)s_texture_wrapper_cook.m_static_memory = &vostok::render::texture_cook_wrapper::`vftable';
  _InterlockedExchange(&s_texture_wrapper_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(
    (int)&s_texture_wrapper_cook.m_initialized,
    s_texture_wrapper_cook.m_variable);
  *(_DWORD *)&s_texture_cook.m_static_memory[4] = 0;
  *(_DWORD *)&s_texture_cook.m_static_memory[8] = 8;
  *(_DWORD *)&s_texture_cook.m_static_memory[12] = 0;
  *(_DWORD *)&s_texture_cook.m_static_memory[16] = -4;
  *(_DWORD *)&s_texture_cook.m_static_memory[20] = -1;
  *(_DWORD *)&s_texture_cook.m_static_memory[24] = 49;
  *(_DWORD *)&s_texture_cook.m_static_memory[28] = 0;
  *(_DWORD *)s_texture_cook.m_static_memory = &vostok::render::texture_cook::`vftable';
  _InterlockedExchange(&s_texture_cook.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(v0, s_texture_cook.m_variable);
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[4] = 0;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[8] = 63;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[12] = 1;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[16] = -1;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[20] = -4;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[24] = 8;
  *(_DWORD *)&s_texture_options_binary_cooker.m_static_memory[28] = 0;
  *(_DWORD *)s_texture_options_binary_cooker.m_static_memory = &vostok::render::texture_options_binary_cooker::`vftable';
  v1 = _InterlockedExchange(&s_texture_options_binary_cooker.m_initialized, 1);
  vostok::resources::resources_manager::register_cook(v1, s_texture_options_binary_cooker.m_variable);
}
