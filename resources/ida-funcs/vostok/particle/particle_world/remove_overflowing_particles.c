void __usercall vostok::particle::particle_world::remove_overflowing_particles(
        vostok::particle::particle_world *this@<ecx>,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<eax>)
{
  vostok::particle::particle_system_instance_impl *v2; // ecx
  vostok::particle::particle_system_instance_impl *m_object; // esi
  vostok::particle::particle_emitter_instance *i; // edi
  unsigned int m_old_lod; // eax
  vostok::particle::particle_emitter_instance *j; // esi
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *next_of_object; // eax
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v8; // [esp-4h] [ebp-14h] BYREF
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+8h] [ebp-8h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v10; // [esp+Ch] [ebp-4h] BYREF

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v10,
    a2 + 101);
  while ( 1 )
  {
    m_object = v10.m_object;
    if ( !v10.m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      break;
    }
    for ( i = v10.m_object->m_lods[v10.m_object->m_current_lod].m_emitter_instance_list.m_first; i; i = i->m_next )
      i->remove_overflowing_particles(i);
    m_old_lod = m_object->m_old_lod;
    if ( m_object->m_current_lod != m_old_lod )
    {
      for ( j = m_object->m_lods[m_old_lod].m_emitter_instance_list.m_first; j; j = j->m_next )
        j->remove_overflowing_particles(j);
    }
    v8.m_object = v2;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v8,
      &v10);
    next_of_object = vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(
                       &v9,
                       (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v8.m_object);
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      next_of_object,
      &v10);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
}
