void __usercall vostok::resources::cook_base::call_destroy_resource(
        vostok::resources::cook_base *this@<edi>,
        vostok::resources::unmanaged_resource *resource@<esi>)
{
  vostok::resources::vfs_sub_fat_resource *m_object; // ecx
  vostok::resources::vfs_sub_fat_resource *v3; // ebx
  unsigned int m_flags; // eax

  _InterlockedExchangeAdd(&resource->m_reference_count, 1u);
  vostok::threading::interlocked_or(
    &resource->vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags.vostok::resources::unmanaged_intrusive_base::vostok::resources::base_of_intrusive_base::m_flags,
    8u);
  m_object = resource->m_sub_fat.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = resource->m_sub_fat.m_object;
    m_object = (vostok::resources::vfs_sub_fat_resource *)((char *)m_object + 208);
    _InterlockedExchangeAdd((volatile signed __int32 *)m_object, 1u);
  }
  vostok::resources::child_resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base>::set_zero(
    (vostok::resources::child_resource_ptr<vostok::resources::vfs_sub_fat_resource,vostok::resources::unmanaged_intrusive_base> *)m_object,
    &resource->m_sub_fat.m_object);
  m_flags = this->m_flags.m_flags;
  if ( (m_flags & 0x20) == 0x20 )
    goto LABEL_9;
  if ( (m_flags & 0x10) != 0 && (m_flags & 8) == 0 )
  {
    ((void (__stdcall *)(vostok::resources::unmanaged_resource *))this->__vftable[1].deallocate_resource)(resource);
    goto LABEL_10;
  }
  if ( (m_flags & 0x18) != 0 )
LABEL_9:
    ((void (__stdcall *)(vostok::resources::unmanaged_resource *))((m_flags & 8) != 8 ? 0 : this)->__vftable[1].calculate_quality_levels_count)(resource);
  else
    ((void (__stdcall *)(vostok::resources::unmanaged_resource *))this->__vftable[1].cache_by_game_resources_manager)(resource);
LABEL_10:
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  }
}
