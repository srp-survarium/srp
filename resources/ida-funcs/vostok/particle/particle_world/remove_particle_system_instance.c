void __thiscall vostok::particle::particle_world::remove_particle_system_instance(
        vostok::particle::particle_world *this,
        vostok::particle::particle_system_instance_impl *in_instance)
{
  vostok::particle::particle_system_instance_impl *v3; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *next_of_object; // eax
  vostok::particle::particle_system_instance_impl *v6; // ecx
  vostok::particle::particle_system_instance_impl *v7; // ecx
  vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *v8; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v11; // [esp+10h] [ebp-4h] BYREF

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v11,
    &this->m_ticked_instances_list.m_first);
  while ( 1 )
  {
    m_object = v11.m_object;
    if ( !v11.m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      break;
    }
    if ( v11.m_object == in_instance )
    {
      vostok::particle::particle_system_instance::stop(v3, (survarium::pure_game_effect_emitter_base *)v11.m_object);
      vostok::particle::particle_system_instance_impl::remove_particles(v6, (int)m_object);
      v9.m_object = v7;
      vostok::resources::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::game_effect_emitter,vostok::resources::unmanaged_intrusive_base>(
        &v9,
        in_instance);
      vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
        v8,
        (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)&this->m_ticked_instances_list,
        v9);
      break;
    }
    v9.m_object = v3;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v9,
      &v11);
    next_of_object = vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(
                       &v10,
                       (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v9.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      next_of_object,
      &v11);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
}
