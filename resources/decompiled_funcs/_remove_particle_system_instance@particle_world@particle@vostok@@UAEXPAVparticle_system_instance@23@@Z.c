void __thiscall vostok::particle::particle_world::remove_particle_system_instance(
        vostok::particle::particle_world *this,
        vostok::particle::particle_system_instance_impl *in_instance)
{
  survarium::game_camera *m_object; // ecx
  survarium::game_camera *v3; // ecx
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> time; // [esp+0h] [ebp-50h] BYREF
  vostok::resources::unmanaged_intrusive_base *object; // [esp+4h] [ebp-4Ch]
  vostok::particle::particle_world *thisa; // [esp+8h] [ebp-48h]
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *p_time; // [esp+10h] [ebp-40h]
  vostok::ai::sound_player *v8; // [esp+18h] [ebp-38h]
  char v9; // [esp+1Eh] [ebp-32h]
  char v10; // [esp+1Fh] [ebp-31h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v11; // [esp+20h] [ebp-30h]
  vostok::particle::particle_system_instance_impl *v12; // [esp+24h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v13; // [esp+28h] [ebp-28h] BYREF
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v14; // [esp+2Ch] [ebp-24h] BYREF
  char v15; // [esp+33h] [ebp-1Dh]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v16; // [esp+34h] [ebp-1Ch]
  vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> v18; // [esp+40h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> inst; // [esp+48h] [ebp-8h] BYREF
  bool found; // [esp+4Fh] [ebp-1h]

  thisa = this;
  inst.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&inst,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_ticked_instances_list.m_first);
  found = 0;
  while ( inst.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    if ( inst.m_object == in_instance )
    {
      found = 1;
      break;
    }
    v16 = &v14;
    v14.m_object = 0;
    m_object = (survarium::game_camera *)&v14;
    if ( inst.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v16);
      m_object = (survarium::game_camera *)inst.m_object;
      v16->m_object = (survarium::weapon_user_animations_container *)inst.m_object;
      if ( v16->m_object )
      {
        object = &v16->m_object->vostok::resources::unmanaged_intrusive_base;
        vostok::threading::interlocked_increment(object);
      }
    }
    v15 = 0;
    survarium::weapon_user_dead_state::finalize(m_object);
    vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
      &v18,
      (const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&v14.m_object->m_aimed_stand_animations[1][5]);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v14);
    v11 = (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18;
    v13.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v13,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18);
    v12 = (vostok::particle::particle_system_instance_impl *)v13.m_object;
    v13.m_object = (vostok::ai::behaviour *)inst.m_object;
    inst.m_object = v12;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v13);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v18);
  }
  if ( found )
  {
    v10 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)found);
    vostok::particle::particle_system_instance::stop(inst.m_object, 0.0);
    v9 = 0;
    survarium::weapon_user_dead_state::finalize(v3);
    vostok::particle::particle_system_instance_impl::remove_particles(inst.m_object);
    v8 = (vostok::ai::sound_player *)in_instance;
    time.m_object = (vostok::ai::sound_player *)in_instance;
    p_time = &time;
    vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &time,
      (vostok::ai::sound_player *)in_instance);
    vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::erase(
      &thisa->m_ticked_instances_list,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)time.m_object);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&inst);
  }
  else
  {
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&inst);
  }
}
