void __thiscall vostok::particle::particle_world::tick(
        vostok::particle::particle_world *this,
        float time_delta,
        const vostok::math::float4x4 *view_matrix)
{
  survarium::game_camera *v3; // ecx
  const vostok::math::float3 *v4; // eax
  survarium::game_camera *v5; // ecx
  survarium::game_camera *v6; // ecx
  survarium::game_camera *v7; // ecx
  survarium::game_camera *v8; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> max; // [esp+8h] [ebp-C0h] BYREF
  vostok::resources::unmanaged_intrusive_base *object; // [esp+Ch] [ebp-BCh]
  __int64 m_max_particles; // [esp+10h] [ebp-B8h]
  __int64 v12; // [esp+18h] [ebp-B0h]
  __int64 v13; // [esp+20h] [ebp-A8h]
  vostok::particle::particle_world *thisa; // [esp+28h] [ebp-A0h]
  vostok::particle::particle_system_instance_impl *v15; // [esp+30h] [ebp-98h]
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v16; // [esp+34h] [ebp-94h] BYREF
  vostok::resources::unmanaged_resource *v17; // [esp+38h] [ebp-90h]
  char v18; // [esp+3Fh] [ebp-89h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+40h] [ebp-88h] BYREF
  char v20; // [esp+47h] [ebp-81h]
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v21; // [esp+48h] [ebp-80h]
  vostok::particle::particle_system_instance_impl *v22; // [esp+4Ch] [ebp-7Ch]
  char v23; // [esp+53h] [ebp-75h]
  vostok::particle::particle_system_instance_impl *m_object; // [esp+54h] [ebp-74h]
  char v25; // [esp+5Bh] [ebp-6Dh]
  char v27; // [esp+63h] [ebp-65h]
  bool is_finished; // [esp+6Fh] [ebp-59h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> next; // [esp+70h] [ebp-58h] BYREF
  unsigned int num_need_new; // [esp+74h] [ebp-54h]
  float k; // [esp+78h] [ebp-50h] BYREF
  float total; // [esp+7Ch] [ebp-4Ch]
  vostok::math::float4x4 inv_view_matrix; // [esp+80h] [ebp-48h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> instance; // [esp+C0h] [ebp-8h] BYREF
  unsigned int num_particles; // [esp+C4h] [ebp-4h]
  float time_deltaa; // [esp+D0h] [ebp+8h]

  thisa = this;
  v13 = s_particle_simulation_speed_value;
  time_deltaa = (double)s_particle_simulation_speed_value / 100.0 * time_delta;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&inv_view_matrix);
  vostok::math::float4x4::try_invert(&inv_view_matrix, view_matrix);
  survarium::weapon_user_dead_state::finalize(v3);
  vostok::particle::particle_world::check_lods(thisa, v4);
  num_particles = vostok::particle::particle_world::calc_num_max_particles(thisa, time_deltaa);
  num_need_new = vostok::particle::particle_world::calc_num_new_particles(thisa, time_deltaa);
  v12 = num_need_new + num_particles;
  total = (float)v12;
  m_max_particles = thisa->m_max_particles;
  k = (double)m_max_particles / total;
  vostok::math::clamp<float>(&k, 0.001, 1.0);
  vostok::particle::particle_world::shrink_particles(thisa, time_deltaa, k, num_need_new);
  vostok::particle::particle_world::remove_overflowing_particles(thisa);
  instance.m_object = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance,
    (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&thisa->m_ticked_instances_list.m_first);
  while ( instance.m_object
        ? vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr
        : 0 )
  {
    is_finished = 0;
    v25 = 0;
    survarium::weapon_user_dead_state::finalize(v5);
    m_object = instance.m_object;
    if ( vostok::particle::particle_system_instance_impl::get_ticked(instance.m_object) )
    {
      v23 = 0;
      survarium::weapon_user_dead_state::finalize(v6);
      v22 = instance.m_object;
      is_finished = vostok::particle::particle_system_instance_impl::tick(instance.m_object, time_deltaa);
    }
    v21 = &v19;
    v7 = (survarium::game_camera *)&v19;
    v19.m_object = 0;
    if ( instance.m_object )
    {
      vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v21);
      v7 = (survarium::game_camera *)v21;
      v21->m_object = (survarium::weapon_user_animations_container *)instance.m_object;
      if ( v21->m_object )
      {
        object = &v21->m_object->vostok::resources::unmanaged_intrusive_base;
        vostok::threading::interlocked_increment(object);
      }
    }
    v20 = 0;
    survarium::weapon_user_dead_state::finalize(v7);
    vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base>(
      (vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&next,
      (const vostok::resources::resource_ptr<survarium::weapon_ammunition,vostok::resources::unmanaged_intrusive_base> *)&v19.m_object->m_aimed_stand_animations[1][5]);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v19);
    if ( is_finished )
    {
      v18 = 0;
      survarium::weapon_user_dead_state::finalize(v8);
      if ( !instance.m_object->m_child_played )
      {
        v17 = instance.m_object;
        max.m_object = instance.m_object;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          &max,
          (vostok::configs::binary_config *)instance.m_object);
        ((void (__thiscall *)(vostok::particle::particle_world *, vostok::resources::unmanaged_resource *))thisa->remove)(
          thisa,
          max.m_object);
      }
    }
    v16.m_object = 0;
    vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v16,
      (const vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&next);
    v15 = (vostok::particle::particle_system_instance_impl *)v16.m_object;
    v16.m_object = (vostok::ai::behaviour *)instance.m_object;
    instance.m_object = v15;
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v16);
    vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&next);
  }
  v27 = 0;
  survarium::weapon_user_dead_state::finalize(v5);
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&instance);
}
