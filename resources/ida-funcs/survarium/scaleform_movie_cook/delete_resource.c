void __thiscall survarium::scaleform_movie_cook::delete_resource(
        survarium::scaleform_movie_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_link *m_last; // eax
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // ebx
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]

  m_last = resource[1].m_children_resources.m_last;
  m_last->resource = 0;
  m_last->next_link = 0;
  m_last->quality_value = 0;
  operator delete(m_last);
  v3 = survarium::g_allocator;
  v4 = __RTCastToVoid((void **)&resource->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)v3, v4, v6, v7, v8);
}
