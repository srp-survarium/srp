void __thiscall vostok::particle::particle_world::tick(
        vostok::particle::particle_world *this,
        float time_delta,
        const vostok::math::float4x4 *view_matrix)
{
  vostok::particle::particle_world *v3; // ebx
  vostok::particle::particle_world *v4; // ecx
  vostok::particle::particle_world *v5; // ecx
  int v6; // esi
  vostok::particle::particle_world *v7; // ecx
  vostok::particle::particle_world *v8; // eax
  double m_max_particles; // st7
  float v10; // xmm0_4
  vostok::particle::particle_world *v11; // ecx
  vostok::particle::particle_system_instance_impl *v12; // ecx
  bool v13; // zf
  void (__thiscall **p_remove)(vostok::particle::particle_world *, survarium::pure_game_effect_emitter_base *); // ebx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> time_deltaa[5]; // [esp+8h] [ebp-64h] BYREF
  bool v16; // [esp+1Fh] [ebp-4Dh]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> v17; // [esp+20h] [ebp-4Ch] BYREF
  vostok::particle::particle_world *v18; // [esp+24h] [ebp-48h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> object; // [esp+28h] [ebp-44h] BYREF
  vostok::math::float4x4 v20; // [esp+2Ch] [ebp-40h] BYREF
  float v21; // [esp+74h] [ebp+8h]

  v3 = this;
  v21 = s_particle_simulation_speed_value * time_delta;
  v18 = this;
  vostok::math::float4x4::try_invert(view_matrix, &v20);
  vostok::particle::particle_world::check_lods(
    v4,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
    (const vostok::math::float3 *)&v20.lines[3]);
  v6 = vostok::particle::particle_world::calc_num_max_particles(
         v5,
         (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
         v21);
  v8 = (vostok::particle::particle_world *)vostok::particle::particle_world::calc_num_new_particles(
                                             v7,
                                             (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
                                             v21);
  m_max_particles = (double)v3->m_max_particles;
  object.m_object = (vostok::particle::particle_system_instance_impl *)((char *)v8 + v6);
  *(float *)&v17.m_object = m_max_particles / (double)((unsigned int)v8 + v6);
  if ( *(float *)&v17.m_object > 0.001 )
  {
    v10 = s_bm_current_air_resistance;
    if ( s_bm_current_air_resistance >= *(float *)&v17.m_object )
      goto LABEL_4;
  }
  else
  {
    v10 = epsilon_3_4;
  }
  *(float *)&v17.m_object = v10;
LABEL_4:
  vostok::particle::particle_world::shrink_particles(
    v8,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3,
    v21,
    *(float *)&v17.m_object,
    (unsigned int)v8);
  vostok::particle::particle_world::remove_overflowing_particles(
    v11,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v3);
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v17,
    &v3->m_ticked_instances_list.m_first);
  while ( *(float *)&v17.m_object != 0.0
       && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v13 = !v17.m_object->m_ticked;
    v16 = 0;
    if ( !v13 )
      v16 = vostok::particle::particle_system_instance_impl::tick(v12, (int)v17.m_object, v21);
    time_deltaa[0].m_object = (survarium::pure_game_effect_emitter_base *)v12;
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)time_deltaa,
      &v17);
    vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,724,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::get_next_of_object(
      &object,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)time_deltaa[0].m_object);
    if ( v16 && !v17.m_object->m_child_played )
    {
      p_remove = (void (__thiscall **)(vostok::particle::particle_world *, survarium::pure_game_effect_emitter_base *))&v3->remove;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
        time_deltaa,
        (survarium::pure_game_effect_emitter_base *)v17.m_object);
      (*p_remove)(v18, time_deltaa[0].m_object);
      v3 = v18;
    }
    vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
      &object,
      &v17);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&object);
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v17);
}
