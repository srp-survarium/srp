void __thiscall vostok::render::one_way_render_channel::render_on_end_frame(
        vostok::render::one_way_render_channel *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *m_object; // ebx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  vostok::resources::unmanaged_resource *v4; // esi
  vostok::particle::particle_system_instance_impl *v5; // ecx
  const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v6; // edi
  vostok::resources::unmanaged_resource *v7; // esi
  vostok::particle::particle_system_instance_impl *v8; // ecx
  vostok::particle::particle_system_instance_impl *v9; // [esp+10h] [ebp-4h]
  vostok::particle::particle_system_instance_impl *v10; // [esp+10h] [ebp-4h]

  m_object = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)a2.m_object;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&a2.m_object->m_fat_it);
  while ( 1 )
  {
    v3 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)a2.m_object;
    if ( !a2.m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      break;
    }
    v4 = a2.m_object->m_lods[0].m_template.m_object;
    v9 = m_object[42].m_object;
    while ( v4 )
    {
      LOBYTE(v4->m_reconstruction_info_actuality_tick) = 0;
      if ( *((_DWORD *)&v4->m_parent_resources + 6) > (unsigned int)v9 )
      {
        LOBYTE(v4->m_reconstruction_info_actuality_tick) = 1;
        vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v4,
          &m_object[36].m_object);
      }
      else if ( v4 != m_object[16].m_object )
      {
        v4->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
        _InterlockedExchange(&m_object[17].m_object->m_flags.m_flags, (__int32)v4);
        m_object[17].m_object = (vostok::particle::particle_system_instance_impl *)v4;
      }
      v4 = (vostok::resources::unmanaged_resource *)*((_DWORD *)&v4->vostok::resources::resource_flags + 3);
    }
    v3[66].m_object = 0;
    v3[67].m_object = 0;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      v3 + 68,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&a2);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  v5 = m_object[40].m_object;
  m_object[40].m_object = 0;
  a2.m_object = v5;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &a2,
    m_object + 41);
  while ( 1 )
  {
    v6 = (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)a2.m_object;
    if ( !a2.m_object
      || !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      break;
    }
    v7 = a2.m_object->m_lods[0].m_template.m_object;
    v10 = m_object[42].m_object;
    while ( v7 )
    {
      LOBYTE(v7->m_reconstruction_info_actuality_tick) = 0;
      if ( *((_DWORD *)&v7->m_parent_resources + 6) > (unsigned int)v10 )
      {
        LOBYTE(v7->m_reconstruction_info_actuality_tick) = 1;
        vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
          (vostok::intrusive_list<vostok::render::base_command,vostok::render::base_command *,12,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *)v7,
          &m_object[36].m_object);
      }
      else if ( v7 != m_object[16].m_object )
      {
        v7->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags = 0;
        _InterlockedExchange(&m_object[17].m_object->m_flags.m_flags, (__int32)v7);
        m_object[17].m_object = (vostok::particle::particle_system_instance_impl *)v7;
      }
      v7 = (vostok::resources::unmanaged_resource *)*((_DWORD *)&v7->vostok::resources::resource_flags + 3);
    }
    v6[66].m_object = 0;
    v6[67].m_object = 0;
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      v6 + 68,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&a2);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  v8 = m_object[41].m_object;
  m_object[41].m_object = 0;
  a2.m_object = v8;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  ++m_object[42].m_object;
}
