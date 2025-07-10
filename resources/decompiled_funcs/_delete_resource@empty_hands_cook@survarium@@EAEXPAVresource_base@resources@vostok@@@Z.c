void __thiscall survarium::empty_hands_cook::delete_resource(
        survarium::empty_hands_cook *this,
        vostok::resources::resource_base *resource)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *m_current_quality_level; // esi
  unsigned int m_target_quality_level; // ebx
  char *v4; // eax
  malloc_state *v5; // esi

  m_current_quality_level = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)resource[1].m_current_quality_level;
  m_target_quality_level = resource[1].m_target_quality_level;
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  for ( ; m_target_quality_level; --m_target_quality_level )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(m_current_quality_level++);
  v4 = __RTCastToVoid((void **)&resource->__vftable);
  if ( v4 )
  {
    v5 = *(malloc_state **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v5, v4);
  }
}
