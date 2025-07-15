void __thiscall vostok::sound::sound_spl_cook::delete_resource(
        vostok::sound::sound_spl_cook *this,
        vostok::resources::resource_base *res)
{
  _BYTE *v2; // esi

  vostok::math::curve_line_points<float,0>::free_memory(
    (vostok::math::curve_line_points<float,0> *)&vostok::memory::g_resources_unmanaged_allocator,
    (int)&res[1].m_children_resources.m_last);
  vostok::math::curve_line_points<float,0>::free_memory(
    (vostok::math::curve_line_points<float,0> *)&vostok::memory::g_resources_unmanaged_allocator,
    (int)&res[1].m_memory_usage_self);
  if ( res )
  {
    v2 = __RTCastToVoid((void **)&res->__vftable);
    ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))res->~vostok::resources::resource_base)(res, 0);
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      v2,
      "vostok::sound::sound_spl_cook::delete_resource",
      ".\\sound_spl_cook.cpp",
      43u);
  }
}
