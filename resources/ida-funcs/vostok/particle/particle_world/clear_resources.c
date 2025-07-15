void __thiscall vostok::particle::particle_world::clear_resources(vostok::particle::particle_world *this)
{
  vostok::particle::particle_system_instance *v2; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_system_instance_impl *v4; // ecx
  vostok::particle::particle_system_instance_impl *v5; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *next_of_object; // eax
  vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *p_m_ticked_instances_list; // edi
  vostok::threading::mutex *v8; // ebx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v9; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v10; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v12; // [esp+Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v13; // [esp+10h] [ebp-4h] BYREF

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v13,
    &this->m_ticked_instances_list.m_first);
  while ( 1 )
  {
    m_object = v13.m_object;
    if ( !v13.m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      break;
    }
    vostok::particle::particle_system_instance::stop(v2, (survarium::pure_game_effect_emitter_base *)v13.m_object);
    vostok::particle::particle_system_instance_impl::remove_particles(v4, (int)m_object);
    v11.m_object = v5;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v11,
      &v13);
    next_of_object = vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(
                       &v12,
                       (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v11.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      next_of_object,
      &v13);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v12);
  }
  p_m_ticked_instances_list = &this->m_ticked_instances_list;
  if ( this == (vostok::particle::particle_world *)-368 )
    v8 = 0;
  else
    v8 = &this->m_ticked_instances_list.vostok::threading::mutex;
  vostok::threading::mutex::lock((vostok::threading::mutex *)v2, (_RTL_CRITICAL_SECTION *)v8);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    v9,
    &p_m_ticked_instances_list->m_first.m_object);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    v10,
    &p_m_ticked_instances_list->m_last.m_object);
  p_m_ticked_instances_list->m_size = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)v8);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v13);
}
