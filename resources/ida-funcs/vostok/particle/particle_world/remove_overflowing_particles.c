void __thiscall vostok::particle::particle_world::remove_overflowing_particles(vostok::particle::particle_world *this)
{
  survarium::game_camera *v1; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v2; // [esp-4h] [ebp-40h] BYREF
  vostok::resources::unmanaged_intrusive_base *object; // [esp+0h] [ebp-3Ch]
  vostok::particle::particle_world *thisa; // [esp+4h] [ebp-38h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *next_of_object; // [esp+Ch] [ebp-30h]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+14h] [ebp-28h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+18h] [ebp-24h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // [esp+24h] [ebp-18h]
  char v9; // [esp+2Bh] [ebp-11h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> result; // [esp+30h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> instance; // [esp+38h] [ebp-4h] BYREF

  thisa = this;
  instance.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_first);
  while ( instance.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    v9 = 0;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::particle::particle_system_instance_impl::remove_overflowing_particles(instance.m_object);
    v8 = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v2;
    v2.m_object = 0;
    if ( instance.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v8);
      v8->m_object = (survarium::weapon_user_animations_container *)instance.m_object;
      if ( v8->m_object )
      {
        object = &v8->m_object->vostok::resources::unmanaged_intrusive_base;
        vostok::threading::interlocked_increment(object);
      }
    }
    next_of_object = (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(&result, v2);
    v7.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v7,
      next_of_object);
    m_object = (vostok::particle::particle_system_instance_impl *)v7.m_object;
    v7.m_object = (vostok::ai::behaviour *)instance.m_object;
    instance.m_object = m_object;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v7);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
}
