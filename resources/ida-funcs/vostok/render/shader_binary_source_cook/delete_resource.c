void __thiscall vostok::render::shader_binary_source_cook::delete_resource(
        vostok::render::shader_binary_source_cook *this,
        vostok::resources::resource_base *resource_to_destroy)
{
  vostok::resources::resource_base *v2; // esi
  vostok::resources::resource_link *m_first; // eax
  vostok::memory::doug_lea_allocator *v4; // edi
  vostok::memory::doug_lea_allocator *v5; // ecx
  const char *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+4h] [ebp-Ch]
  unsigned int v8; // [esp+8h] [ebp-8h]
  char *v9; // [esp+Ch] [ebp-4h]

  v2 = resource_to_destroy;
  if ( *((_DWORD *)&resource_to_destroy[1].m_parent_resources + 6) )
  {
    resource_to_destroy = (vostok::resources::resource_base *)*((_DWORD *)&resource_to_destroy[1].m_parent_resources + 6);
    if ( vostok::memory::g_mt_allocator.m_use_memory_monitor )
      vostok::memory::monitor::on_free((void **)&resource_to_destroy, (vostok::command_line::key *)this);
    pt3free((int)this, (char *)resource_to_destroy);
    *((_DWORD *)&v2[1].m_parent_resources + 6) = 0;
    *((_DWORD *)&v2[1].m_parent_resources + 6) = 0;
  }
  m_first = v2[1].m_parent_resources.m_first;
  if ( m_first )
    ((void (__stdcall *)(vostok::resources::resource_link *))m_first->resource->m_flags.m_flags)(v2[1].m_parent_resources.m_first);
  v4 = vostok::render::g_allocator;
  v9 = __RTCastToVoid((void **)&v2->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))v2->~vostok::resources::resource_base)(v2, 0);
  vostok::memory::doug_lea_allocator::free_impl(v5, (int)v4, v9, v6, v7, v8);
}
