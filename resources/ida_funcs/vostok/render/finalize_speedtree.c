void __thiscall vostok::render::finalize_speedtree(void *ecx0)
{
  vostok::resources::resources_manager::unregister_cook(speedtree_class);
  ((void (__thiscall *)(vostok::render::speedtree_cook *, _DWORD, void *))s_speedtree_cook.m_variable->~vostok::render::speedtree_cook)(
    s_speedtree_cook.m_variable,
    0,
    ecx0);
  s_speedtree_cook.m_initialized = 0;
  vostok::resources::resources_manager::unregister_cook(speedtree_instance_class);
  ((void (__cdecl *)(_DWORD))s_speedtree_instance_cook.m_variable->~vostok::render::speedtree_instance_cook)(0);
  s_speedtree_instance_cook.m_initialized = 0;
}
