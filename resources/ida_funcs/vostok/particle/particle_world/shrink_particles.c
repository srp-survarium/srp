void __thiscall vostok::particle::particle_world::shrink_particles(
        vostok::particle::particle_world *this,
        float time_delta,
        float limit_over_total,
        unsigned int num_need_particles)
{
  survarium::game_camera *v4; // ecx
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v5; // [esp+8h] [ebp-40h] BYREF
  vostok::resources::unmanaged_intrusive_base *object; // [esp+Ch] [ebp-3Ch]
  vostok::particle::particle_world *thisa; // [esp+10h] [ebp-38h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *next_of_object; // [esp+18h] [ebp-30h]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+20h] [ebp-28h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+24h] [ebp-24h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+30h] [ebp-18h]
  char v12; // [esp+37h] [ebp-11h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> result; // [esp+3Ch] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> instance; // [esp+44h] [ebp-4h] BYREF

  thisa = this;
  instance.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_first);
  while ( instance.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    v12 = 0;
    survarium::weapon_user_dead_state::finalize(v4);
    vostok::particle::particle_system_instance_impl::shrink_particles(
      instance.m_object,
      time_delta,
      limit_over_total,
      num_need_particles);
    v11 = (vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v5;
    v5.m_object = 0;
    if ( instance.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v11);
      v11->m_object = (survarium::weapon_user_animations_container *)instance.m_object;
      if ( v11->m_object )
      {
        object = &v11->m_object->vostok::resources::unmanaged_intrusive_base;
        vostok::threading::interlocked_increment(object);
      }
    }
    next_of_object = (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(&result, v5);
    v10.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v10,
      next_of_object);
    m_object = (vostok::particle::particle_system_instance_impl *)v10.m_object;
    v10.m_object = (vostok::ai::behaviour *)instance.m_object;
    instance.m_object = m_object;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
}
