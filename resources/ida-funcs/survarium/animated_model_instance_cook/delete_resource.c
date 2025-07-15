void __thiscall survarium::animated_model_instance_cook::delete_resource(
        survarium::animated_model_instance_cook *this,
        vostok::resources::resource_base *resource)
{
  void (__thiscall ***m_thread_id)(void *, _DWORD); // edi
  vostok::animation::animation_player *v3; // ecx
  void *v4; // edi
  _BYTE *v5; // edi

  m_thread_id = (void (__thiscall ***)(void *, _DWORD))resource[1].m_parent_resources.m_thread_id;
  (**m_thread_id)(m_thread_id, 0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(
    &vostok::memory::g_resources_unmanaged_allocator,
    m_thread_id,
    "vostok::collision::delete_animated_object",
    ".\\api.cpp",
    324u);
  v4 = *(void **)&resource[1].m_parent_resources.gapC;
  if ( v4 )
  {
    vostok::animation::animation_player::~animation_player(v3, (BOOL)v4);
    vostok::memory::g_resources_unmanaged_allocator.call_free(
      &vostok::memory::g_resources_unmanaged_allocator,
      v4,
      "survarium::animated_model_instance_cook::delete_resource",
      ".\\animated_model_instance_cook.cpp",
      170u);
  }
  v5 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::g_resources_unmanaged_allocator.call_free(
    &vostok::memory::g_resources_unmanaged_allocator,
    v5,
    "survarium::animated_model_instance_cook::delete_resource",
    ".\\animated_model_instance_cook.cpp",
    171u);
}
