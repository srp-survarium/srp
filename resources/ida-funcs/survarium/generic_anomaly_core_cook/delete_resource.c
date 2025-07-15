void __thiscall survarium::generic_anomaly_core_cook::delete_resource(
        survarium::generic_anomaly_core_cook *this,
        vostok::resources::resource_base *resource)
{
  char *v3; // ebp
  vostok::resources::memory_type **p_m_memory_type_data; // eax
  vostok::resources::memory_type *v5; // edi
  vostok::memory::doug_lea_allocator *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // esi
  const char *v8; // [esp+0h] [ebp-10h]
  const char *v9; // [esp+4h] [ebp-Ch]
  unsigned int v10; // [esp+8h] [ebp-8h]

  v3 = __RTCastToVoid((void **)&resource->__vftable);
  if ( resource )
    p_m_memory_type_data = &resource[-1].m_memory_type_data;
  else
    p_m_memory_type_data = 0;
  v5 = p_m_memory_type_data[101];
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))resource->~vostok::resources::resource_base)(
    resource,
    0);
  if ( v5 )
  {
    v7 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v3[this->get_derived_resource_size(this)];
    do
    {
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v7++);
      v5 = (vostok::resources::memory_type *)((char *)v5 - 1);
    }
    while ( v5 );
  }
  if ( v3 )
    vostok::memory::doug_lea_allocator::free_impl(v6, (int)survarium::g_allocator, v3, v8, v9, v10);
}
