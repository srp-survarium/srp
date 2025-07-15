void __thiscall survarium::object_wire::resources_ready(
        survarium::object_wire *this,
        vostok::resources::queries_result *data,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  char *m_data; // eax
  survarium::pure_game_effect_emitter_base *m_size; // ecx
  vostok::resources::queries_result *m_object; // esi
  boost::function1<void,vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> const &> *v8; // ecx
  const char *v9; // [esp+0h] [ebp-18h]
  const char *v10; // [esp+4h] [ebp-14h]
  unsigned int v11; // [esp+8h] [ebp-10h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v12; // [esp+14h] [ebp-4h] BYREF

  v3 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)data;
  m_data = (char *)data->m_queries[0].m_creation_data_from_user.m_data;
  m_size = (survarium::pure_game_effect_emitter_base *)data->m_queries[0].m_creation_data_from_user.m_size;
  v12.m_object = m_size;
  if ( m_data )
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)m_size,
      (int)survarium::g_allocator,
      m_data,
      v9,
      v10,
      v11);
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    v3 + 75);
  m_object = (vostok::resources::queries_result *)v12.m_object;
  data = 0;
  if ( v12.m_object )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
    data = m_object;
    _InterlockedExchangeAdd((volatile signed __int32 *)&m_object->m_queries[0].m_target_quality_level, 1u);
  }
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&data,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&this->m_visual);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v12);
  boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::operator()(
    v8,
    cb,
    (const vostok::memory::single_size_buffer_allocator<16,vostok::threading::single_threading_policy> *)this);
}
