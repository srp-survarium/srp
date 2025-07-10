void __thiscall survarium::weapon_cook::delete_resource(
        survarium::weapon_cook *this,
        vostok::resources::resource_base *resource)
{
  unsigned int v2; // edi
  vostok::memory::doug_lea_allocator *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // eax
  unsigned int *i; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v6; // ecx
  _BYTE *v7; // eax
  void *v8; // esi

  v2 = resource[19].m_quality_levels_count
     + LODWORD(resource[19].m_current_satisfaction)
     + LODWORD(resource[19].m_target_satisfaction);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  v3 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::memory::detail::call_destructor_predicate>(
    (vostok::resources::unmanaged_resource ***)&resource[19].m_parent_resources,
    v3);
  v4 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
  vostok::memory::detail::delete_array_helper_impl<vostok::memory::doug_lea_allocator,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::memory::detail::call_destructor_predicate>(
    (vostok::resources::unmanaged_resource ***)&resource[19].m_children_resources.m_last,
    v4);
  for ( i = &resource[19].m_target_quality_level; v2; --v2 )
  {
    v6 = (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)i++;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v6);
  }
  v7 = __RTCastToVoid((void **)&resource->__vftable);
  if ( v7 )
  {
    v8 = *(void **)(LODWORD(survarium::g_allocator.f_.f_) + 20);
    *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = 0;
    vostok_mspace_free(v8, v7);
  }
}
