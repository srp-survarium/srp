unsigned int __thiscall vostok::particle::particle_world::calc_num_max_particles(
        vostok::particle::particle_world *this,
        float time_delta)
{
  survarium::game_camera *v2; // ecx
  unsigned int v3; // eax
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v5; // [esp+0h] [ebp-4Ch] BYREF
  vostok::resources::unmanaged_intrusive_base *object; // [esp+4h] [ebp-48h]
  vostok::particle::particle_world *thisa; // [esp+8h] [ebp-44h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *next_of_object; // [esp+10h] [ebp-3Ch]
  vostok::particle::particle_system_instance_impl *v9; // [esp+18h] [ebp-34h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+1Ch] [ebp-30h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+28h] [ebp-24h]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+2Ch] [ebp-20h]
  char v13; // [esp+33h] [ebp-19h]
  unsigned int v15; // [esp+38h] [ebp-14h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> result; // [esp+3Ch] [ebp-10h] BYREF
  unsigned int total_summ; // [esp+44h] [ebp-8h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> instance; // [esp+48h] [ebp-4h] BYREF

  thisa = this;
  total_summ = 0;
  instance.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_first);
  while ( instance.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    v13 = 0;
    survarium::weapon_user_dead_state::finalize(v2);
    m_object = instance.m_object;
    v3 = vostok::particle::particle_system_instance_impl::calc_num_max_particles(instance.m_object, time_delta);
    total_summ += v3;
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
    v9 = (vostok::particle::particle_system_instance_impl *)v10.m_object;
    v10.m_object = (vostok::ai::behaviour *)instance.m_object;
    instance.m_object = v9;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v10);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  }
  v15 = total_summ;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
  return v15;
}
