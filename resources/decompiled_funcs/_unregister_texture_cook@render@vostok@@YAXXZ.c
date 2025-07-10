void __thiscall vostok::render::unregister_texture_cook(void *ecx0)
{
  vostok::resources::resources_manager::unregister_cook(texture_wrapper_class);
  ((void (__thiscall *)(vostok::render::texture_cook_wrapper *, _DWORD, void *))s_texture_wrapper_cook.m_variable->~vostok::render::texture_cook_wrapper)(
    s_texture_wrapper_cook.m_variable,
    0,
    ecx0);
  s_texture_wrapper_cook.m_initialized = 0;
  vostok::resources::resources_manager::unregister_cook(texture_class);
  ((void (__cdecl *)(_DWORD))s_texture_cook.m_variable->~vostok::render::texture_cook)(0);
  s_texture_cook.m_initialized = 0;
}
