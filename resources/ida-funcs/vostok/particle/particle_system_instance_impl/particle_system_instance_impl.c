void __thiscall vostok::particle::particle_system_instance_impl::particle_system_instance_impl(
        vostok::particle::particle_system_instance_impl *this,
        vostok::memory::base_allocator *allocator,
        vostok::memory::base_allocator_vtbl *a3)
{
  void **p_m_arena_start; // ecx
  int v4; // esi
  vostok::memory::base_allocator *v5; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v6; // ecx
  float v7; // xmm0_4
  vostok::math::float4x4 *v8; // ecx
  vostok::memory::base_allocator_vtbl *v9; // eax
  vostok::particle::particle_system_instance_impl *m_arena_start; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp+Ch] [ebp-44h] BYREF
  vostok::math::float4x4 v12; // [esp+10h] [ebp-40h] BYREF

  vostok::resources::unmanaged_resource::unmanaged_resource(this, allocator, fs_iterator_class);
  p_m_arena_start = &allocator[13].m_arena_start;
  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::particle::particle_system_instance::`vftable';
  v4 = 9;
  v5 = allocator + 14;
  do
  {
    *p_m_arena_start = 0;
    v5[-1].m_arena_end = 0;
    *(_DWORD *)&v5[-1].m_use_memory_monitor = 0;
    v5->__vftable = 0;
    p_m_arena_start += 8;
    v5 = (vostok::memory::base_allocator *)((char *)v5 + 32);
    --v4;
  }
  while ( v4 >= 0 );
  allocator[36].__vftable = a3;
  allocator[29].m_arena_start = 0;
  allocator->__vftable = (vostok::memory::base_allocator_vtbl *)&vostok::particle::particle_system_instance_impl::`vftable';
  allocator[36].m_arena_start = 0;
  allocator[36].m_arena_end = 0;
  allocator[38].__vftable = 0;
  allocator[38].m_arena_start = 0;
  LOBYTE(allocator[38].m_arena_end) = 0;
  v6 = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)_InterlockedExchange((volatile __int32 *)&allocator[37].m_arena_start, 0);
  v7 = s_bm_current_air_resistance;
  BYTE1(allocator[38].m_arena_end) = 0;
  BYTE2(allocator[38].m_arena_end) = 0;
  HIBYTE(allocator[38].m_arena_end) = 1;
  allocator[36].m_arena_id = 0;
  *(_DWORD *)&allocator[36].m_use_memory_monitor = 0;
  allocator[37].__vftable = (vostok::memory::base_allocator_vtbl *)1;
  *(&allocator[37].m_use_memory_monitor + 1) = 1;
  *(float *)&allocator[14].m_arena_start = v7;
  *(float *)&allocator[37].m_arena_id = v7;
  allocator[37].m_use_memory_monitor = 0;
  LOBYTE(allocator[38].m_arena_id) = 1;
  *(&allocator[37].m_use_memory_monitor + 2) = 0;
  *(&allocator[37].m_use_memory_monitor + 3) = 0;
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    v6,
    (vostok::particle::particle_system_instance_impl **)&allocator[36].m_arena_start);
  qmemcpy(&allocator[29].m_arena_id, vostok::math::float4x4::identity(v8, &v12), 0x40u);
  allocator[37].m_arena_end = 0;
  v9 = allocator[38].__vftable;
  allocator[38].__vftable = 0;
  v11.m_object = (vostok::particle::particle_system_instance_impl *)v9;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
  m_arena_start = (vostok::particle::particle_system_instance_impl *)allocator[38].m_arena_start;
  allocator[38].m_arena_start = 0;
  v11.m_object = m_arena_start;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
}
