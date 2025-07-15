void __thiscall vostok::sound::sound_scene_cook::delete_resource(
        vostok::sound::sound_scene_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *m_next_in_increase_quality_queue; // esi
  vostok::memory::doug_lea_allocator *v3; // esi
  _BYTE *v4; // ebx
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]

  m_next_in_increase_quality_queue = resource[3].m_next_in_increase_quality_queue;
  if ( m_next_in_increase_quality_queue )
  {
    ((void (__stdcall *)(vostok::resources::resource_base *, _DWORD))m_next_in_increase_quality_queue->log_string)(
      m_next_in_increase_quality_queue,
      0);
    ((void (__stdcall *)(vostok::resources::resource_base *))m_next_in_increase_quality_queue->__vftable[2].decrease_quality)(m_next_in_increase_quality_queue);
  }
  v3 = vostok::sound::g_allocator;
  v4 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)v3, v4, v6, v7, v8);
}
