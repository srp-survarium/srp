void __thiscall vostok::render::grass_cook::delete_resource(
        vostok::render::grass_cook *this,
        vostok::resources::resource_base *resource)
{
  unsigned int m_uid; // edi

  m_uid = resource[2].m_uid;
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  if ( m_uid )
    (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)m_uid + 68))(m_uid, 0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(
    &vostok::memory::g_resources_unmanaged_allocator,
    resource,
    "vostok::render::grass_cook::delete_resource",
    ".\\grass_cook.cpp",
    369u);
}
